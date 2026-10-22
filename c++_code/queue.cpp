#include "queue.h"
#include <iostream>
using namespace std;



void QueuePush(Queue* queue, string value){
	// частный случай для пустой очереди
	if (queue -> head == nullptr && queue -> tail == nullptr){
		queue -> head = new QNode{nullptr, value};
		queue -> tail = queue -> head;
		return;
	}
	// добавление элемента в конец
	QNode* newQNode = new QNode{nullptr, value};
	queue -> tail -> next = newQNode;
	queue -> tail = newQNode;
	return;
}

void QueuePop(Queue* queue){ // вернуть удаляемое значение (переделать)
	// проверка очереди на пустоту
	if (queue -> head == nullptr && queue -> tail == nullptr){
		cout << "Очередь пустая, нечего удалять\n";
		return;
	}
	//удаленеие элемента из очереди
	QNode* saveQNode = queue -> head -> next;
	if (queue -> head -> next == nullptr){
		queue -> tail = nullptr;
	}
	delete queue -> head;
	queue -> head = saveQNode;
	return;
}

void QueuePrint(Queue* queue){
	//проверка на пустую очередь
	if (queue -> head == nullptr && queue -> tail == nullptr){
		cout << "Очередь пустая, нечего выводить\n";
		return;
	}
	// вывод очереди в консоль
	QNode* temp = queue -> head;
	while (temp != nullptr){
		cout << temp -> queueValue << " ";
		temp = temp -> next;
	}
	cout << endl;
	return;
}

void QueueClear(Queue* queue){
	// проверка на пустую очередь
	if (queue -> head == nullptr && queue -> tail == nullptr){
		cout << "Очередь пустая, нечего удалять\n";
		return;
	}
	while (queue -> head != nullptr && queue -> tail != nullptr){
		QueuePop(queue);
	}
	return;
}

