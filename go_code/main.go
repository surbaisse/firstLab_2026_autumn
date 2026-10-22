package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var filename, queryStr string

	// 1. Парсим аргументы командной строки (--file и --querry)
	for i := 1; i < len(os.Args); i++ {
		if os.Args[i] == "--file" && i+1 < len(os.Args) {
			filename = strings.TrimPrefix(os.Args[i+1], "file ")
		}
		if os.Args[i] == "--querry" && i+1 < len(os.Args) {
			queryStr = os.Args[i+1]
		}
	}

	// 2. Разбиваем запрос на слова (cmd name line1 line2)
	parts := strings.Fields(queryStr)
	cmd := "0"
	name := "0"
	line1 := "0"
	line2 := "0"

	if len(parts) > 0 { cmd = parts[0] }
	if len(parts) > 1 { name = parts[1] }
	if len(parts) > 2 { line1 = parts[2] }
	if len(parts) > 3 { line2 = parts[3] }

	fmt.Printf("filename: %s\ncmd: %s\nnameOfStruct: %s\nline1: %s\nline2: %s\n\n", filename, cmd, name, line1, line2)

	// Переменная интерфейсного типа, в которую мы положим нужную структуру
	var st Structure

	// 3. Создаем нужную структуру по первой букве команды и читаем её из файла
	switch cmd[0] {
	case 'F':
		list := &ForwardList{}
		ReadForwardList(list, filename, name)
		st = ForwardListAction{list}
	case 'D':
		list := &DoubleList{}
		ReadDoubleList(list, filename, name)
		st = DoubleListAction{list}
	case 'A':
		arr := NewArray(5)
		ReadArray(arr, filename, name)
		st = ArrayAction{arr}
	case 'Q':
		q := &Queue{}
		ReadQueue(q, filename, name)
		st = QueueAction{q}
	case 'S':
		s := &Stack{}
		ReadStack(s, filename, name)
		st = StackAction{s}
	case 'T':
		t := &AVLTree{}
		ReadTree(t, filename, name)
		st = TreeAction{t}
	case 'N':
		ActionCreate(cmd, name, filename)
		return
	default:
		fmt.Println("unknown command")
		return
	}

	// 4. Выполняем команду
	if st != nil {
		err := st.Execute(cmd, line1, line2)
		if err != nil {
			fmt.Println("Ошибка:", err)
		}
		
		// Выводим структуру после действия
		st.Print() 
		
		// Сохраняем изменения обратно в файл
		WriteStructure(st, filename, name)
	}
}
