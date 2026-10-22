package main

import "fmt"

// QNode — узел очереди
type QNode struct {
	Value string
	Next  *QNode
}

// Queue — сама очередь
type Queue struct {
	Head *QNode
	Tail *QNode
	Size int
}

// Push — добавление элемента в конец очереди
func (q *Queue) Push(value string) {
	newNode := &QNode{Value: value}

	// Если очередь пуста, новый узел становится и началом, и концом
	if q.Head == nil {
		q.Head = newNode
		q.Tail = newNode
	} else {
		// Иначе привязываем к текущему хвосту и сдвигаем хвост
		q.Tail.Next = newNode
		q.Tail = newNode
	}
	q.Size++
}

// Pop — удаление элемента из начала очереди
func (q *Queue) Pop() {
	if q.Head == nil {
		fmt.Println("Очередь пустая, нечего удалять")
		return
	}

	// Сдвигаем указатель начала на следующий элемент
	q.Head = q.Head.Next

	// Если очередь опустела, обнуляем и хвост
	if q.Head == nil {
		q.Tail = nil
	}
	q.Size--
}

// Print — вывод очереди в консоль
func (q *Queue) Print() {
	if q.Head == nil {
		fmt.Println("Очередь пустая, нечего выводить")
		return
	}

	for curr := q.Head; curr != nil; curr = curr.Next {
		fmt.Printf("%s ", curr.Value)
	}
	fmt.Println()
}

// Clear — очистка очереди
func (q *Queue) Clear() {
	if q.Head == nil {
		fmt.Println("Очередь пустая, нечего удалять")
		return
	}

	// В Go достаточно просто отвязать голову и хвост.
	// Сборщик мусора сам удалит все узлы из памяти.
	q.Head = nil
	q.Tail = nil
	q.Size = 0
}
