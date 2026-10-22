package main

import "fmt"

// SNode — узел стека
type SNode struct {
	Value string
	Next  *SNode
}

// Stack — сам стек
type Stack struct {
	Head *SNode
	Size int
}

// Push — добавление элемента в стек
func (s *Stack) Push(value string) {
	newNode := &SNode{Value: value, Next: s.Head}
	s.Head = newNode
	s.Size++
}

// Pop — удаление верхнего элемента
func (s *Stack) Pop() {
	if s.Head == nil {
		fmt.Println("Стек пуст, нечего удалять")
		return
	}
	
	// Просто сдвигаем голову на следующий элемент. 
	// Старый узел удалит сборщик мусора.
	s.Head = s.Head.Next
	s.Size--
}

// Print — вывод стека
func (s *Stack) Print() {
	if s.Head == nil {
		fmt.Println("Стек пуст, выводить нечего")
		return
	}

	for curr := s.Head; curr != nil; curr = curr.Next {
		fmt.Printf("%s ", curr.Value)
	}
	fmt.Println()
}

// Clear — очистка стека
func (s *Stack) Clear() {
	// В Go достаточно обнулить голову. 
	// Сборщик мусора сам удалит всю цепочку узлов.
	s.Head = nil
	s.Size = 0
}
