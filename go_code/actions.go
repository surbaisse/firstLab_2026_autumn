package main

import (
	"bufio"
	"fmt"
	"strconv"
)

// Structure — интерфейс, который реализуют все структуры данных (Список, Стек, Очередь, Дерево, Массив)
type Structure interface {
	Execute(cmd string, line1 string, line2 string) error
	Print()
	WriteToFile(w *bufio.Writer, name string)
	GetTypeName() string
}

// ----------------------------------------------------------------------
// ForwardList
// ----------------------------------------------------------------------
type ForwardListAction struct{ list *ForwardList }

func (a ForwardListAction) Execute(cmd string, line1 string, line2 string) error {
	switch cmd[1] {
	case 'A': // Add
		switch cmd[2] {
		case 'A': a.list.AddAfterValue(line1, line2)
		case 'S': a.list.AddStart(line1)
		case 'B': a.list.AddBeforeValue(line1, line2)
		case 'E': a.list.AddEnd(line1)
		}
	case 'D': // Delete
		switch cmd[2] {
		case 'L': a.list.DeleteList()
		case 'S': a.list.DeleteStart()
		case 'V': a.list.DeleteByValue(line1)
		case 'E': a.list.DeleteEnd()
		case 'A': a.list.DeleteAfter(line1)
		case 'B': a.list.DeleteBefore(line1)
		}
	case 'G': // Get
		pos := a.list.GetPositionByValue(line1)
		fmt.Println(pos)
	case 'S': // Size
		fmt.Println(a.list.Size)
	}
	return nil
}
func (a ForwardListAction) Print() { a.list.Print() }

func (a ForwardListAction) WriteToFile(w *bufio.Writer, name string) {
	fmt.Fprintf(w, "ForwardList %s\nSIZE %d\n", name, a.list.Size)
	for curr := a.list.Head; curr != nil; curr = curr.Next {
		fmt.Fprintf(w, "ITEM %s\n", curr.Value)
	}
}
func (a ForwardListAction) GetTypeName() string { return "ForwardList" }

// ----------------------------------------------------------------------
// DoubleList
// ----------------------------------------------------------------------
type DoubleListAction struct{ list *DoubleList }

func (a DoubleListAction) Execute(cmd string, line1 string, line2 string) error {
	switch cmd[1] {
	case 'A':
		switch cmd[2] {
		case 'A': a.list.AddAfterValue(line1, line2)
		case 'S': a.list.AddStart(line1)
		case 'B': a.list.AddBeforeValue(line1, line2)
		case 'E': a.list.AddEnd(line1)
		}
	case 'D':
		switch cmd[2] {
		case 'L': a.list.DeleteList()
		case 'S': a.list.DeleteStart()
		case 'V': a.list.DeleteByValue(line1)
		case 'E': a.list.DeleteEnd()
		case 'B': a.list.DeleteBefore(line1)
		case 'A': a.list.DeleteAfter(line1)
		}
	case 'G':
		pos := a.list.GetPositionByValue(line1)
		fmt.Println(pos)
	case 'O':
		if len(cmd) > 2 && cmd[2] == 'H' {
			a.list.OutputHList()
		} else if len(cmd) > 2 && cmd[2] == 'T' {
			a.list.OutputTList()
		}
	case 'S':
		fmt.Println(a.list.Size)
	}
	return nil
}
func (a DoubleListAction) Print() { a.list.OutputHList() }

func (a DoubleListAction) WriteToFile(w *bufio.Writer, name string) {
	fmt.Fprintf(w, "DoubleList %s\nSIZE %d\n", name, a.list.Size)
	for curr := a.list.Head; curr != nil; curr = curr.Next {
		fmt.Fprintf(w, "ITEM %s\n", curr.Value)
	}
}
func (a DoubleListAction) GetTypeName() string { return "DoubleList" }

// ----------------------------------------------------------------------
// Array (Динамический массив в Go — это просто срез (slice))
// ----------------------------------------------------------------------
type ArrayAction struct{ arr *Array }

func (a ArrayAction) Execute(cmd string, line1 string, line2 string) error {
	switch cmd[1] {
	case 'A':
		switch cmd[2] {
		case 'E': a.arr.AddEnd(line1)
		case 'I':
			idx, err := strconv.Atoi(line2)
			if err != nil { return err }
			a.arr.AddByIndex(line1, idx)
		}
	case 'G':
		idx, _ := strconv.Atoi(line1)
		val, err := a.arr.Get(idx)
		if err == nil { fmt.Println(val) } else { return err }
	case 'D':
		idx, _ := strconv.Atoi(line1)
		a.arr.DeleteByIndex(idx)
	case 'E':
		idx, _ := strconv.Atoi(line2)
		a.arr.Replace(idx, line1)
	}
	return nil
}
func (a ArrayAction) Print() { a.arr.Print() }

func (a ArrayAction) WriteToFile(w *bufio.Writer, name string) {
	fmt.Fprintf(w, "Array %s\nSIZE %d\n", name, len(a.arr.Data))
	for _, v := range a.arr.Data {
		fmt.Fprintf(w, "ITEM %s\n", v)
	}
}
func (a ArrayAction) GetTypeName() string { return "Array" }

// ----------------------------------------------------------------------
// Queue
// ----------------------------------------------------------------------
type QueueAction struct{ q *Queue }

func (a QueueAction) Execute(cmd string, line1 string, line2 string) error {
	switch cmd[1] {
	case 'A': a.q.Push(line1)
	case 'D': a.q.Pop()
	case 'C': a.q.Clear()
	}
	return nil
}
func (a QueueAction) Print() { a.q.Print() }

func (a QueueAction) WriteToFile(w *bufio.Writer, name string) {
	fmt.Fprintf(w, "Queue %s\nSIZE %d\n", name, a.q.Size)
	for curr := a.q.Head; curr != nil; curr = curr.Next {
		fmt.Fprintf(w, "ITEM %s\n", curr.Value)
	}
}
func (a QueueAction) GetTypeName() string { return "Queue" }

// ----------------------------------------------------------------------
// Stack
// ----------------------------------------------------------------------
type StackAction struct{ s *Stack }

func (a StackAction) Execute(cmd string, line1 string, line2 string) error {
	switch cmd[1] {
	case 'A': a.s.Push(line1)
	case 'D': a.s.Pop()
	case 'C': a.s.Clear()
	}
	return nil
}
func (a StackAction) Print() { a.s.Print() }

func (a StackAction) WriteToFile(w *bufio.Writer, name string) {
	fmt.Fprintf(w, "Stack %s\nSIZE %d\n", name, a.s.Size)
	for curr := a.s.Head; curr != nil; curr = curr.Next {
		fmt.Fprintf(w, "ITEM %s\n", curr.Value)
	}
}
func (a StackAction) GetTypeName() string { return "Stack" }

// ----------------------------------------------------------------------
// AVL Tree
// ----------------------------------------------------------------------
type TreeAction struct{ t *AVLTree }

func (a TreeAction) Execute(cmd string, line1 string, line2 string) error {
	switch cmd[1] {
	case 'A': a.t.Add(line1)
	case 'D': a.t.Delete(line1)
	case 'C': a.t.Clear()
	}
	return nil
}
func (a TreeAction) Print() { a.t.PrintInOrder() }

func (a TreeAction) WriteToFile(w *bufio.Writer, name string) {
	fmt.Fprintf(w, "AVL_Tree %s\nSIZE %d\n", name, a.t.Size)
	a.t.printInOrderToFile(a.t.Root, w)
}
func (a TreeAction) GetTypeName() string { return "AVL_Tree" }

// ----------------------------------------------------------------------
// Создание новой структуры (N)
// ----------------------------------------------------------------------
func ActionCreate(cmd string, name string, filename string) {
	if len(cmd) < 2 { return }
	var structType string
	switch cmd[1] {
	case 'F': structType = "Stack"
	case 'D': structType = "Queue"
	case 'A': structType = "Array"
	case 'S': structType = "ForwardList"
	case 'Q': structType = "DoubleList"
	case 'T': structType = "AVL_Tree"
	default: return
	}
	AddStructureToFile(filename, structType, name)
}
