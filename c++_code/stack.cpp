#include "stack.h"
#include <iostream>
using namespace std;

void StackPush(Stack* stack, string value){
// добавление элемента
	SNode* newSNode = new SNode {stack -> head, value};
	stack -> head = newSNode;
	return;
}

void StackPop(Stack* stack){
// проверка ну пустой ли стек
	if (stack -> head == nullptr){
		cout << "Стек пуст, нечего удалять\n";
		return;
	}
// удаление элемента
	SNode* saveSNode = stack -> head -> next;
	delete stack -> head;
	stack -> head = saveSNode;
	return;
}

void StackPrint(Stack* stack){
// проверка не пустой ли стек
	if (stack -> head == nullptr){
		cout << "Стек пуст, выводить нечего\n";
		return;
	}
// вывод стека
	SNode* temp = stack -> head;
	while (temp != nullptr){
		cout << temp -> stackValue << " ";
		temp = temp -> next;
	}
	cout << endl;
	return;
}

void StackClear(Stack* stack){
// удаление стека поэлементно
	while (stack -> head != nullptr){
		StackPop(stack);
	}
	return;
}

