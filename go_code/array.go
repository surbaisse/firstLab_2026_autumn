package main

import "fmt"

// Array — обертка над срезом строк
type Array struct {
	Data []string
}

// NewArray — создает пустой массив с начальной емкостью (аналог new string[5])
func NewArray(capacity int) *Array {
	return &Array{
		Data: make([]string, 0, capacity),
	}
}

// ArrAddEnd — добавление в конец
func (a *Array) AddEnd(value string) {
	// append сам увеличивает capacity (в 2 раза), когда место заканчивается
	a.Data = append(a.Data, value)
}

// ArrAddByIndex — добавление по индексу
func (a *Array) AddByIndex(value string, index int) error {
	if index < 0 || index > len(a.Data) {
		return fmt.Errorf("wrong index %d", index)
	}

	// В Go нет встроенной функции для вставки по индексу, 
	// поэтому мы расширяем срез на 1 элемент и сдвигаем правую часть
	a.Data = append(a.Data, "")
	copy(a.Data[index+1:], a.Data[index:])
	a.Data[index] = value
	return nil
}

// ArrGetElem — получение элемента по индексу
func (a *Array) Get(index int) (string, error) {
	if len(a.Data) == 0 {
		return "", fmt.Errorf("массив пустой")
	}
	if index < 0 || index >= len(a.Data) {
		return "", fmt.Errorf("wrong index %d", index)
	}
	return a.Data[index], nil
}

// ArrDelByIndex — удаление по индексу
func (a *Array) DeleteByIndex(index int) error {
	if len(a.Data) == 0 {
		return fmt.Errorf("массив пустой")
	}
	if index < 0 || index >= len(a.Data) {
		return fmt.Errorf("wrong index %d", index)
	}

	// Удаление элемента из среза: берем всё до index и приклеиваем всё после index
	a.Data = append(a.Data[:index], a.Data[index+1:]...)
	return nil
}

// ArrReplaceByIndex — замена элемента по индексу
func (a *Array) Replace(index int, value string) error {
	if len(a.Data) == 0 {
		return fmt.Errorf("массив пустой")
	}
	if index < 0 || index >= len(a.Data) {
		return fmt.Errorf("wrong index %d", index)
	}
	a.Data[index] = value
	return nil
}

// ArrPrint — вывод массива
func (a *Array) Print() {
	if len(a.Data) == 0 {
		fmt.Println("Массив пустой, нечего выводить")
		return
	}
	for _, v := range a.Data {
		fmt.Printf("%s ", v)
	}
	fmt.Println()
}
