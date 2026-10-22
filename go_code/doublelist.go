package main

import "fmt"

// DNode — узел двусвязного списка
type DNode struct {
	Value string
	Prev  *DNode
	Next  *DNode
}

// DoubleList — сам список
type DoubleList struct {
	Head *DNode
	Tail *DNode
	Size int
}

// ----------------------------------------------------------------------
// Вспомогательные функции и вывод
// ----------------------------------------------------------------------

func (l *DoubleList) OutputHList() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	for curr := l.Head; curr != nil; curr = curr.Next {
		fmt.Printf("%s ", curr.Value)
	}
	fmt.Println()
}

func (l *DoubleList) OutputTList() {
	if l.Tail == nil {
		fmt.Println("Список пуст")
		return
	}
	for curr := l.Tail; curr != nil; curr = curr.Prev {
		fmt.Printf("%s ", curr.Value)
	}
	fmt.Println()
}

// ----------------------------------------------------------------------
// Вставка (Add)
// ----------------------------------------------------------------------

// AddAfterValue — добавить line1 после элемента line2
func (l *DoubleList) AddAfterValue(line1, line2 string) {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	curr := l.Head
	for curr != nil && curr.Value != line2 {
		curr = curr.Next
	}
	if curr == nil {
		fmt.Printf("Элемент \"%s\" не найден в списке\n", line2)
		return
	}
	
	// Вставка после curr
	newNode := &DNode{Value: line1, Prev: curr, Next: curr.Next}
	if curr.Next != nil {
		curr.Next.Prev = newNode
	} else {
		l.Tail = newNode
	}
	curr.Next = newNode
	l.Size++
}

// AddStart — добавить в начало
func (l *DoubleList) AddStart(line1 string) {
	newNode := &DNode{Value: line1, Prev: nil, Next: l.Head}
	if l.Head != nil {
		l.Head.Prev = newNode
	} else {
		l.Tail = newNode
	}
	l.Head = newNode
	l.Size++
}

// AddBeforeValue — добавить line1 перед элементом line2
func (l *DoubleList) AddBeforeValue(line1, line2 string) {
	if l.Head == nil {
		fmt.Println("Список пуст, элемент добавлен в самое начало")
		newNode := &DNode{Value: line1}
		l.Head = newNode
		l.Tail = newNode
		l.Size++
		return
	}
	curr := l.Head
	for curr != nil && curr.Value != line2 {
		curr = curr.Next
	}
	if curr == nil {
		fmt.Printf("Элемент \"%s\" не найден в списке\n", line2)
		return
	}
	if curr == l.Head {
		l.AddStart(line1)
		return
	}
	
	// Вставка перед curr
	newNode := &DNode{Value: line1, Prev: curr.Prev, Next: curr}
	curr.Prev.Next = newNode
	curr.Prev = newNode
	l.Size++
}

// AddEnd — добавить в конец
func (l *DoubleList) AddEnd(line1 string) {
	newNode := &DNode{Value: line1}
	if l.Head == nil {
		l.Head = newNode
		l.Tail = newNode
		l.Size++
		return
	}
	
	// Привязываем к старому хвосту
	newNode.Prev = l.Tail
	l.Tail.Next = newNode
	// Обновляем хвост
	l.Tail = newNode
	l.Size++
}

// ----------------------------------------------------------------------
// Удаление (Delete)
// ----------------------------------------------------------------------

// DeleteEnd — удалить с конца
func (l *DoubleList) DeleteEnd() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	if l.Head.Next == nil {
		l.Head = nil
		l.Tail = nil
		l.Size--
		return
	}
	l.Tail = l.Tail.Prev
	l.Tail.Next = nil
	l.Size--
}

// DeleteStart — удалить с начала
func (l *DoubleList) DeleteStart() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	if l.Head.Next == nil {
		l.Head = nil
		l.Tail = nil
		l.Size--
		return
	}
	l.Head = l.Head.Next
	l.Head.Prev = nil
	l.Size--
}

// DeleteByValue — удалить элемент по значению
func (l *DoubleList) DeleteByValue(line1 string) {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	curr := l.Head
	for curr != nil && curr.Value != line1 {
		curr = curr.Next
	}
	if curr == nil {
		fmt.Printf("Элемент \"%s\" не найден в списке\n", line1)
		return
	}
	
	if curr == l.Head {
		l.DeleteStart()
		return
	}
	if curr == l.Tail {
		l.DeleteEnd()
		return
	}
	
	// Удаление из середины
	curr.Prev.Next = curr.Next
	curr.Next.Prev = curr.Prev
	l.Size--
}

// DeleteBefore — удалить элемент перед line1
func (l *DoubleList) DeleteBefore(line1 string) {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	curr := l.Head
	for curr != nil && curr.Value != line1 {
		curr = curr.Next
	}
	if curr == nil {
		fmt.Printf("Элемент \"%s\" не найден в списке\n", line1)
		return
	}
	if curr == l.Head {
		fmt.Printf("Перед элементом \"%s\" нет элементов для удаления\n", line1)
		return
	}
	
	toDelete := curr.Prev
	curr.Prev = toDelete.Prev
	if toDelete.Prev != nil {
		toDelete.Prev.Next = curr
	} else {
		l.Head = curr
	}
	l.Size--
}

// DeleteAfter — удалить элемент после line1
func (l *DoubleList) DeleteAfter(line1 string) {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	curr := l.Head
	for curr != nil && curr.Value != line1 {
		curr = curr.Next
	}
	if curr == nil {
		fmt.Printf("Элемент \"%s\" не найден в списке\n", line1)
		return
	}
	if curr.Next == nil {
		fmt.Printf("После элемента \"%s\" нет элементов для удаления\n", line1)
		return
	}
	
	toDelete := curr.Next
	curr.Next = toDelete.Next
	if toDelete.Next != nil {
		toDelete.Next.Prev = curr
	} else {
		l.Tail = curr
	}
	l.Size--
}

// DeleteList — очистить список
func (l *DoubleList) DeleteList() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	l.Head = nil
	l.Tail = nil
	l.Size = 0
	// В Go старые узлы просто соберет сборщик мусора
}

// ----------------------------------------------------------------------
// Поиск (Get)
// ----------------------------------------------------------------------

func (l *DoubleList) GetPositionByValue(line1 string) int {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return -1
	}
	
	curr := l.Head
	position := 0
	for curr != nil {
		if curr.Value == line1 {
			return position
		}
		curr = curr.Next
		position++
	}
	
	fmt.Printf("Элемент \"%s\" не найден в списке\n", line1)
	return -1
}
