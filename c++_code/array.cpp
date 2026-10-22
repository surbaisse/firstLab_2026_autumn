#include "array.h"
#include <iostream>
// написать на втором языке программирвоания rust или go
using namespace std;
// нужно что бы при операциях добавления программа гарантировала, что в массиве есть хотя бы 1 свободная ячейка.
// добавление в конец
void ArrAddEnd(string* array, string value, int* sz){
	array[(*sz)] = value;
	(*sz)++;
}
// добавлние по индексу
void ArrAddByIndex(string* array, string value, int index, int* sz){
	// проверка корректности index
	if (index > (*sz) || index < 0){
		cout << "wrong index\n";
		return;
	}
	// перемещение всей части массива врпаво всего что после индекса включая сам индекс
	for (int i = (*sz); i > index; i--){
		array[i] = array[i-1];
	}
	//сохранение элемента по индексу
	array[index] = value;
	(*sz)++;
	return;
}
// Получить элемент
string ArrGetElem(string* array, int index, int* sz){
	// Проверка массива на пустоту
	if ((*sz) == 0){
		cout << "Массив пустой, нечего выводить\n";
		return 0;
	}
	// Проверка на корректоность индекса 
	if (index >= (*sz) || index < 0){
		cout << "Wrong index\n";
		return 0;
	}
	// вывод элемента по индексу
	return array[index];	
}
// Удалить по индексу
void ArrDelByIndex(string* array, int index, int* sz){
	// проверка на пустоту массива
	if ((*sz) == 0){
		cout << "пустой массив, нечего удалять\n";	
		return;
	}
	// проверка на корретность индекса
	if (index >= (*sz) || index < 0){
		cout << "wrong index\n";
		return;
	}
	// смещение всего массива влево от индекса до конца массива, Элемент удалится сам по себе просто потому что перезапишем смещением.
	for (int i = index; i < (*sz)-1; i++){
		array[i] = array[i+1];	
	}
	(*sz)--;
	return;

}
// Заменить элемент по индексу на введеный
void ArrReplaceByIndex(string* array, string value, int index, int* sz){
	// проверка на пустоту массива
	if ((*sz) == 0){
		cout << "Массив пуст. Нечего заменить на value\n";	
		return;
	}
	// проверка на корретность индекса
	if (index >= (*sz) || index < 0){
		cout << "wrong index\n";
		return;
	}
	array[index] = value;
	return;
	
}
// Вывод массива
void ArrPrint(string* array, int* sz){
	// проверка на пустоту массива
	if ((*sz) == 0){
		cout << "пустой массив, нечего выводить\n";	
		return;
	}
	for (int i = 0; i < (*sz); i++){
		cout << array[i] << " ";
	}
	cout << endl;
}
// проверяет что бы было место куда добавлять элементы. 
void ArrCheckSize(string** array, int* sz, int* capacity){
	if ((*sz) == *capacity){
		//новый массив для перезаписи
		string* newArray = new string[(*capacity)+5];
		*(capacity) += 5;
		// перезапись старого в новый
		for (int i = 0; i < (*sz); i++){
			newArray[i] = (*array)[i];
		}
		delete[] *array;
		*array = newArray;
	}
}


