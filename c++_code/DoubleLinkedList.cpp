#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

int ListSize(DoubleList* dList) {
    int sz = 0;
    DNode* temp = dList->head;
    while (temp != nullptr) {
        sz++;
        temp = temp->next;
    }
    return sz;
}
void OutputHList(DoubleList* dList) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr) {
        cout << temp->listValue << " ";
        temp = temp->next;
    }
    cout << endl;
}
void OutputTList(DoubleList* dList){
	if (dList -> tail == nullptr){
		cout << "Список пуст\n";
		return;
	}
	DNode* temp = dList -> tail;
	while (temp != nullptr){
		cout << temp -> listValue << " ";
		temp = temp -> prev;
	}
	cout << endl;
}

void AddAfter(DoubleList* dList, string line1, string line2, int* sz) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr && temp->listValue != line2) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Элемент \"" << line2 << "\" не найден в списке\n";
        return;
    }
    DNode* newDNode = new DNode{temp, temp->next, line1};
    if (temp->next != nullptr) {
        temp->next->prev = newDNode;
    } else {
        dList->tail = newDNode;
    }
    temp->next = newDNode;
    if (sz != nullptr) {
        (*sz)++;
    }
}

void AddStart(DoubleList* dList, string line1, int* sz) {
    DNode* newDNode = new DNode{nullptr, dList->head, line1};
    if (dList->head != nullptr) {
        dList->head->prev = newDNode;
    } else {
        dList->tail = newDNode;
    }
    dList->head = newDNode;
    (*sz)++;
}

void AddBefore(DoubleList* dList, string line1, string line2, int* sz) {
    if (dList->head == nullptr) {
        cout << "Список пуст, элемент добавлен в самое начало\n";
        DNode* newDNode = new DNode{nullptr, nullptr, line1};
        dList->head = newDNode;
        dList->tail = newDNode;
        (*sz)++;
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr && temp->listValue != line2) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Элемент \"" << line2 << "\" не найден в списке\n";
        return;
    }
    if (temp == dList->head) {
        AddStart(dList, line1, sz);
        return;
    }
    DNode* prevNode = temp->prev; 
    DNode* newDNode = new DNode{prevNode, temp, line1};
    prevNode->next = newDNode;
    temp->prev = newDNode;
    (*sz)++;
}

void AddEnd(DoubleList* dList, string line1) {
    if (dList->tail == nullptr && dList->head == nullptr) {
        DNode* newDNode = new DNode{nullptr, nullptr, line1}; 
        dList->head = newDNode;
        dList->tail = newDNode;	
        return;
    }
    
    DNode* newDNode = new DNode{dList->tail, nullptr, line1};
    dList->tail = newDNode;
    dList->tail->prev->next = dList->tail;
}

void AddEnd(DoubleList* dList, string line1, int* sz) {
    if (dList->tail == nullptr && dList->head == nullptr) {
        DNode* newDNode = new DNode{nullptr, nullptr, line1}; 
        dList->head = newDNode;
        dList->tail = newDNode;
        (*sz)++;
        return;
    }
    
    DNode* newDNode = new DNode{dList->tail, nullptr, line1};
    dList->tail = newDNode;
    dList->tail->prev->next = dList->tail;
    (*sz)++; 
}

void DeleteEnd(DoubleList* dList, int* sz) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    if (dList->head->next == nullptr) {
        delete dList -> head;
        dList -> head = nullptr;
		dList -> tail = nullptr; 
		(*sz)--;
        return;
    }
	DNode* saveDNode = dList -> tail -> prev;
	saveDNode -> next = nullptr;
    delete dList -> tail;
	dList -> tail = saveDNode;
	(*sz)--;
}

void DeleteStart(DoubleList* dList, int* sz) {
    if (dList->head == nullptr && dList -> tail == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    if (dList->head->next == nullptr) {
        delete dList->head;
        dList -> head = nullptr;
		dList -> tail = nullptr;
		(*sz)--;
        return;
    }
    DNode* saveDNode = dList->head->next;
    saveDNode->prev = nullptr;
    delete dList->head;
    dList->head = saveDNode;
	(*sz)--;
}

void DeleteByValue(DoubleList* dList, string line1, int* sz) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr && temp->listValue != line1) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Элемент \"" << line1 << "\" не найден в списке\n";
        return;
    }
    if (temp == dList->head) {
        DeleteStart(dList, sz);
        return;
    }
    if (temp == dList->tail) {
        DeleteEnd(dList, sz);
        return;
    }
    DNode* prevDNode = temp->prev;
    DNode* nextDNode = temp->next;
    prevDNode->next = nextDNode;
    nextDNode->prev = prevDNode;
    delete temp;
    (*sz)--;
}

void DeleteBefore(DoubleList* dList, string line1, int* sz) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr && temp->listValue != line1) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Элемент \"" << line1 << "\" не найден в списке\n";
        return;
    }
    if (temp == dList->head) {
        cout << "Перед элементом \"" << line1 << "\" нет элементов для удаления\n";
        return;
    }
    DNode* toDelete = temp->prev;
    temp->prev = toDelete->prev;
    if (toDelete->prev != nullptr) {
        toDelete->prev->next = temp;
    } else {
        dList->head = temp;
    }
    delete toDelete;
    (*sz)--;
}

void DeleteAfter(DoubleList* dList, string line1, int* sz) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr && temp->listValue != line1) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Элемент \"" << line1 << "\" не найден в списке\n";
        return;
    }
    if (temp->next == nullptr) {
        cout << "После элемента \"" << line1 << "\" нет элементов для удаления\n";
        return;
    }
    DNode* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != nullptr) {
        toDelete->next->prev = temp;
    } else {
        dList->tail = temp;
    }
    delete toDelete;
    (*sz)--;
}

void DeleteList(DoubleList* dList, int* sz) {
    if (dList->head == nullptr && dList -> tail == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    DNode* temp = dList->head;
    while (temp != nullptr) {
        DNode* nextDNode = temp -> next;
        delete temp;
        temp = nextDNode;
		(*sz)--;
    }
    dList -> head = nullptr;
	dList -> tail = nullptr;
}


int GetPositionByValue(DoubleList* dList, string line1) {
    if (dList->head == nullptr) {
        cout << "Список пуст\n";
        return -1; 
    }

    DNode* temp = dList->head;
    int position = 0;

    while (temp != nullptr) {
        if (temp->listValue == line1) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    cout << "Элемент \"" << line1 << "\" не найден в списке\n";
    return -1;
}




