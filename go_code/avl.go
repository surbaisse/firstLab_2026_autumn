package main

import "fmt"
import "bufio"
// TNode — узел AVL-дерева
type TNode struct {
	Value  string
	Height int
	Left   *TNode
	Right  *TNode
}

// AVLTree — само дерево
type AVLTree struct {
	Root *TNode
	Size int // Храним размер, чтобы не считать его каждый раз через рекурсию
}

// height — вспомогательная функция (аналог unsigned char height(TNode* p))
func height(p *TNode) int {
	if p == nil {
		return 0
	}
	return p.Height
}

// balanceFactor — разница высот (правая - левая)
func balanceFactor(p *TNode) int {
	return height(p.Right) - height(p.Left)
}

// fixHeight — обновляет высоту узла
func fixHeight(p *TNode) {
	hl := height(p.Left)
	hr := height(p.Right)
	if hl > hr {
		p.Height = hl + 1
	} else {
		p.Height = hr + 1
	}
}

// rotateRight — правый поворот
func rotateRight(p *TNode) *TNode {
	q := p.Left
	p.Left = q.Right
	q.Right = p
	fixHeight(p)
	fixHeight(q)
	return q
}

// rotateLeft — левый поворот
func rotateLeft(q *TNode) *TNode {
	p := q.Right
	q.Right = p.Left
	p.Left = q
	fixHeight(q)
	fixHeight(p)
	return p
}

// balance — балансировка узла
func balance(p *TNode) *TNode {
	fixHeight(p)
	bf := balanceFactor(p)

	if bf == 2 {
		if balanceFactor(p.Right) < 0 {
			p.Right = rotateRight(p.Right)
		}
		return rotateLeft(p)
	}
	if bf == -2 {
		if balanceFactor(p.Left) > 0 {
			p.Left = rotateLeft(p.Left)
		}
		return rotateRight(p)
	}
	return p
}

// ----------------------------------------------------------------------
// Вставка (Insert)
// ----------------------------------------------------------------------

// insertNode — рекурсивная вставка, возвращает (новый корень, был_ли_добавлен)
func insertNode(p *TNode, value string) (*TNode, bool) {
	if p == nil {
		return &TNode{Value: value, Height: 1}, true
	}

	var inserted bool
	if value < p.Value {
		p.Left, inserted = insertNode(p.Left, value)
	} else if value > p.Value {
		p.Right, inserted = insertNode(p.Right, value)
	} else {
		// Дубликат, ничего не добавляем
		return p, false
	}

	return balance(p), inserted
}

// Add — публичный метод для добавления элемента в дерево
func (t *AVLTree) Add(value string) {
	var inserted bool
	t.Root, inserted = insertNode(t.Root, value)
	if inserted {
		t.Size++
	}
}

// ----------------------------------------------------------------------
// Удаление (Delete)
// ----------------------------------------------------------------------

// findMin — ищет самый левый узел (минимум)
func findMin(p *TNode) *TNode {
	for p.Left != nil {
		p = p.Left
	}
	return p
}

// removeMin — удаляет минимальный узел и возвращает новый корень поддерева
func removeMin(p *TNode) *TNode {
	if p.Left == nil {
		return p.Right
	}
	p.Left = removeMin(p.Left)
	return balance(p)
}

// removeNode — рекурсивное удаление, возвращает (новый корень, был_ли_удален)
func removeNode(p *TNode, value string) (*TNode, bool) {
	if p == nil {
		return nil, false
	}

	var removed bool
	if value < p.Value {
		p.Left, removed = removeNode(p.Left, value)
	} else if value > p.Value {
		p.Right, removed = removeNode(p.Right, value)
	} else {
		// Нашли узел для удаления
		removed = true
		
		if p.Right == nil {
			return p.Left, true // В Go старый p просто удалит сборщик мусора
		}
		if p.Left == nil {
			return p.Right, true
		}

		// Если есть оба потомка, ищем минимум в правом поддереве
		minNode := findMin(p.Right)
		minNode.Right = removeMin(p.Right)
		minNode.Left = p.Left
		
		// Возвращаем сбалансированный узел вместо удаленного
		return balance(minNode), true
	}

	return balance(p), removed
}

// Delete — публичный метод для удаления элемента
func (t *AVLTree) Delete(value string) {
	var removed bool
	t.Root, removed = removeNode(t.Root, value)
	if removed {
		t.Size--
	}
}

// ----------------------------------------------------------------------
// Очистка (Clear)
// ----------------------------------------------------------------------

// Clear — очищает дерево (в Go достаточно просто отвязать корень, 
// сборщик мусора удалит все узлы сам)
func (t *AVLTree) Clear() {
	t.Root = nil
	t.Size = 0
}

// ----------------------------------------------------------------------
// Вывод (PrintInOrder)
// ----------------------------------------------------------------------

// printInOrder — рекурсивный симметричный обход
func printInOrder(p *TNode, out func(string)) {
	if p == nil {
		return
	}
	printInOrder(p.Left, out)
	out(p.Value)
	printInOrder(p.Right, out)
}

// PrintInOrder — публичный метод для вывода дерева
func (t *AVLTree) PrintInOrder() {
	if t.Root == nil {
		fmt.Println("Дерево пусто")
		return
	}
	printInOrder(t.Root, func(v string) {
		fmt.Printf("%s ", v)
	})
	fmt.Println()
}


func (t *AVLTree) printInOrderToFile(p *TNode, w *bufio.Writer) {
	if p == nil {
		return
	}
	t.printInOrderToFile(p.Left, w)
	fmt.Fprintf(w, "ITEM %s\n", p.Value)
	t.printInOrderToFile(p.Right, w)
}
