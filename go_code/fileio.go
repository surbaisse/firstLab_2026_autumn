package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// ----------------------------------------------------------------------
// ЗАПИСЬ В ФАЙЛ (общая функция для всех)
// ----------------------------------------------------------------------

// WriteStructure записывает структуру в файл, заменяя старую версию с тем же именем.
func WriteStructure(st Structure, filename string, name string) error {
	// 1. Создаем временный файл в той же директории
	tmpFile, err := os.CreateTemp(".", "temp_*.txt")
	if err != nil {
		return fmt.Errorf("не удалось создать временный файл: %w", err)
	}
	tmpName := tmpFile.Name()
	defer os.Remove(tmpName) // Удалим, если произойдет ошибка или паника

	writer := bufio.NewWriter(tmpFile)

	// 2. Пишем новую структуру
	st.WriteToFile(writer, name)

	// 3. Читаем старый файл и копируем всё, КРОМЕ старой версии этой структуры
	oldFile, err := os.Open(filename)
	if err == nil {
		scanner := bufio.NewScanner(oldFile)
		header := st.GetTypeName() + " " + name
		skipMode := false
		skipLines := 0

		for scanner.Scan() {
			line := scanner.Text()

			if skipMode {
				skipLines--
				if skipLines == 0 {
					skipMode = false
				}
				continue
			}

			if line == header {
				// Нашли старую версию. Читаем SIZE N и пропускаем N строк ITEM
				if scanner.Scan() {
					sizeLine := scanner.Text()
					n, _ := strconv.Atoi(strings.TrimPrefix(sizeLine, "SIZE "))
					skipLines = n
					skipMode = true
				}
				continue
			}
			
			writer.WriteString(line + "\n")
		}
		oldFile.Close()
	}

	writer.Flush()
	tmpFile.Close()

	// 4. Атомарная замена (сначала удаляем старый, потом переименовываем)
	_ = os.Remove(filename) 
	return os.Rename(tmpName, filename)
}

// AddStructureToFile создает пустую структуру в начале файла
func AddStructureToFile(filename string, structType string, name string) error {
	tmpFile, err := os.CreateTemp(".", "temp_*.txt")
	if err != nil {
		return err
	}
	tmpName := tmpFile.Name()
	defer os.Remove(tmpName)

	writer := bufio.NewWriter(tmpFile)

	// Пишем новую структуру
	writer.WriteString(fmt.Sprintf("%s %s\nSIZE 0\n", structType, name))

	// Дописываем старый файл
	oldFile, err := os.Open(filename)
	if err == nil {
		scanner := bufio.NewScanner(oldFile)
		for scanner.Scan() {
			writer.WriteString(scanner.Text() + "\n")
		}
		oldFile.Close()
	}

	writer.Flush()
	tmpFile.Close()

	_ = os.Remove(filename)
	return os.Rename(tmpName, filename)
}

// ----------------------------------------------------------------------
// ЧТЕНИЕ ИЗ ФАЙЛА (общая вспомогательная функция)
// ----------------------------------------------------------------------

// readLinesFromFile ищет структуру в файле и возвращает срез строк (элементов ITEM)
func readLinesFromFile(filename, typeName, name string) ([]string, error) {
	file, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var items []string
	scanner := bufio.NewScanner(file)
	header := typeName + " " + name

	for scanner.Scan() {
		line := scanner.Text()
		if line == header {
			// Читаем следующую строку (размер)
			if !scanner.Scan() { break }
			sizeLine := scanner.Text()
			n, err := strconv.Atoi(strings.TrimPrefix(sizeLine, "SIZE "))
			if err != nil { return nil, err }

			// Читаем n строк
			for i := 0; i < n; i++ {
				if !scanner.Scan() { break }
				itemLine := scanner.Text()
				if strings.HasPrefix(itemLine, "ITEM ") {
					items = append(items, strings.TrimPrefix(itemLine, "ITEM "))
				}
			}
			return items, nil // Нашли и прочитали
		}
	}

	fmt.Printf("such structure named like \"%s\" didnt find\n", name)
	return nil, nil
}

// ----------------------------------------------------------------------
// ОБЕРТКИ ДЛЯ КАЖДОЙ СТРУКТУРЫ (чтобы читать данные)
// ----------------------------------------------------------------------

func ReadForwardList(list *ForwardList, filename string, name string) {
	items, _ := readLinesFromFile(filename, "ForwardList", name)
	for _, item := range items { list.AddEnd(item) }
}

func ReadDoubleList(list *DoubleList, filename string, name string) {
	items, _ := readLinesFromFile(filename, "DoubleList", name)
	for _, item := range items { list.AddEnd(item) }
}

func ReadArray(arr *Array, filename string, name string) {
	items, _ := readLinesFromFile(filename, "Array", name)
	for _, item := range items { arr.AddEnd(item) }
}

func ReadQueue(q *Queue, filename string, name string) {
	items, _ := readLinesFromFile(filename, "Queue", name)
	for _, item := range items { q.Push(item) }
}

func ReadStack(s *Stack, filename string, name string) {
	items, _ := readLinesFromFile(filename, "Stack", name)
	for _, item := range items { s.Push(item) }
}

func ReadTree(t *AVLTree, filename string, name string) {
	items, _ := readLinesFromFile(filename, "AVL_Tree", name)
	for _, item := range items { t.Add(item) }
}


