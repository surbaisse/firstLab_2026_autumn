package main

import "fmt"

// FNode — узел односвязного списка
type FNode struct {
	Value string
	Next  *FNode
}

// ForwardList — сам список
type ForwardList struct {
	Head *FNode
	Size int
}

// ----------------------------------------------------------------------
// Вспомогательные функции и вывод
// ----------------------------------------------------------------------

func (l *ForwardList) Print() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	for curr := l.Head; curr != nil; curr = curr.Next {
		fmt.Printf("%s ", curr.Value)
	}
	fmt.Println()
}

// ----------------------------------------------------------------------
// Вставка (Add)
// ----------------------------------------------------------------------

// AddAfterValue — добавить line1 после элемента line2
func (l *ForwardList) AddAfterValue(line1, line2 string) {
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
	
	newNode := &FNode{Value: line1, Next: curr.Next}
	curr.Next = newNode
	l.Size++
}

// AddStart — добавить в начало
func (l *ForwardList) AddStart(line1 string) {
	newNode := &FNode{Value: line1, Next: l.Head}
	l.Head = newNode
	l.Size++
}

// AddBeforeValue — добавить line1 перед элементом line2
func (l *ForwardList) AddBeforeValue(line1, line2 string) {
	if l.Head == nil {
		return
	}

	if l.Head.Value == line2 {
		l.AddStart(line1)
		return
	}

	curr := l.Head
	for curr.Next != nil && curr.Next.Value != line2 {
		curr = curr.Next
	}

	if curr.Next == nil {
		fmt.Printf("Элемент \"%s\" не найден\n", line2)
		return
	}

	newNode := &FNode{Value: line1, Next: curr.Next}
	curr.Next = newNode
	l.Size++
}

// AddEnd — добавить в конец
func (l *ForwardList) AddEnd(line1 string) {
	newNode := &FNode{Value: line1}
	
	if l.Head == nil {
		l.Head = newNode
		l.Size++
		return
	}

	curr := l.Head
	for curr.Next != nil {
		curr = curr.Next
	}
	curr.Next = newNode
	l.Size++
}

// ----------------------------------------------------------------------
// Удаление (Delete)
// ----------------------------------------------------------------------

// DeleteEnd — удалить последний элемент
func (l *ForwardList) DeleteEnd() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}

	if l.Head.Next == nil {
		l.Head = nil
		l.Size--
		return
	}

	curr := l.Head
	// Идем до предпоследнего элемента
	for curr.Next.Next != nil {
		curr = curr.Next
	}
	curr.Next = nil
	l.Size--
}

// DeleteStart — удалить первый элемент
func (l *ForwardList) DeleteStart() {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}
	l.Head = l.Head.Next
	l.Size--
}

// DeleteByValue — удалить элемент по значению
func (l *ForwardList) DeleteByValue(line1 string) {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}

	if l.Head.Value == line1 {
		l.DeleteStart()
		return
	}

	curr := l.Head
	for curr.Next != nil && curr.Next.Value != line1 {
		curr = curr.Next
	}

	if curr.Next == nil {
		fmt.Printf("Элемент \"%s\" не найден в списке\n", line1)
		return
	}

	curr.Next = curr.Next.Next
	l.Size--
}

// DeleteBefore — удалить элемент перед line1
func (l *ForwardList) DeleteBefore(line1 string) {
	if l.Head == nil {
		fmt.Println("Список пуст")
		return
	}

	if l.Head.Value == line1 {
		fmt.Printf("Перед элементом \"%s\" нет элементов для удаления\n", line1)
		return
	}

	if l.Head.Next != nil && l.Head.Next.Value == line1 {
		l.DeleteStart()
		return
	}

	curr := l.Head
	for curr.Next != nil && curr.Next.Next != nil && curr.Next.Next.Value != line1 {
		curr = curr.Next
	}

	if curr.Next == nil || curr.Next.Next == nil {
		fmt.Printf("Элемент \"%s\" не найден (или перед ним нет элемента)\n", line1)
		return
	}

	curr.Next = curr.Next.Next
	l.Size--
}

// DeleteAfter — удалить элемент после line1
func (l *ForwardList) DeleteAfter(line1 string) {
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

	curr.Next = curr.Next.Next
	l.Size--
}

// DeleteList — очистить список
func (l *ForwardList) DeleteList() {
	l.Head = nil
	l.Size = 0
}

// ----------------------------------------------------------------------
// Поиск (Get)
// ----------------------------------------------------------------------

func (l *ForwardList) GetPositionByValue(line1 string) int {
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
