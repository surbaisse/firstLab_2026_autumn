#include "ForwardLinkedList.h"
#include <iostream>
using namespace std;
//--------------ДОП ФУНКЦИИ----------------
int ListSize(ForwardList* fList){
	int sz = 0;
	FNode* temp = fList -> head;
	while (temp != nullptr){
		sz++;
		temp = temp -> next;
	}
	return sz;
}

void OutputList(ForwardList* fList){
	if (fList -> head == nullptr){
		cout << "Список пуст\n";
		return;
	}
	FNode* temp = fList -> head;
	while (temp != nullptr){
		cout << temp -> listValue << " ";
		temp = temp -> next;
	}
	cout << endl;
}

//---------ОПЕРАЦИИ ВСТАВКИ-------
void AddAfter(ForwardList* fList, string line1, string line2, int* sz){	
    if (fList->head == nullptr){
        cout << "Список пуст\n";
        return;
    }
    FNode* temp = fList->head;
    while (temp != nullptr && temp->listValue != line2){
        temp = temp->next;
    }
    if (temp == nullptr){
        cout << "Элемент \"" << line2 << "\" не найден в списке\n";
        return;
    }
    FNode* newFNode = new FNode{temp->next, line1};
    temp->next = newFNode;
    (*sz)++;
}

void AddStart(ForwardList* fList, string line1, int* sz){
	FNode* newFNode = new FNode{fList -> head, line1};
	fList -> head = newFNode;
	(*sz)++;
	return;
}

void AddBefore(ForwardList* fList, string line1, string line2, int* sz) {
    if (fList->head == nullptr) return;

    if (fList->head->listValue == line2) {
        FNode* newFNode = new FNode{fList->head, line1};
        fList->head = newFNode;
        (*sz)++;
        return;
    }

    FNode* temp = fList->head;
    while (temp->next != nullptr && temp->next->listValue != line2) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Элемент \"" << line2 << "\" не найден\n";
        return;
    }

    FNode* newFNode = new FNode{temp->next, line1};
    temp->next = newFNode;
    (*sz)++; 
}

void AddEnd(ForwardList* fList, string line1){
    if (fList->head == nullptr){
        FNode* newFNode = new FNode{nullptr, line1};
        fList->head = newFNode;
        return;	
    }
    
    FNode* temp = fList->head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    
    FNode* newFNode = new FNode{nullptr, line1};
    temp->next = newFNode;
}

void AddEnd(ForwardList* fList, string line1, int* sz){
    if (fList->head == nullptr){
        FNode* newFNode = new FNode{nullptr, line1};
        fList->head = newFNode;
        (*sz)++;
        return;	
    }
    
    FNode* temp = fList->head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    
    FNode* newFNode = new FNode{nullptr, line1};
    temp->next = newFNode;
    (*sz)++;
}

//----------ОПЕРАЦИИ УДАЛЕНИЯ-------------
void DeleteEnd(ForwardList* fList, int* sz){	
	if (fList -> head == nullptr){
		cout << "Список пуст\n";
		return;
	}
	FNode* temp = fList -> head;
	if (temp -> next == nullptr){
		delete temp;
		fList -> head = nullptr;
		(*sz)--;
		return;
	}
	// переход к последнему элементу 
	for (int i = 0; i < (*sz) - 2; i++){
		temp = temp -> next;
	}
	// Удаление последнего элемента
	if (temp -> next -> next == nullptr){
		delete temp -> next;
		temp -> next = nullptr;
		(*sz)--;
	}
	return;
}
void DeleteStart(ForwardList* fList, int* sz){
	//Проверил список существует или нет
	if (fList -> head == nullptr){
		cout << "Список пуст\n";
		return;
	}
	//частный случай если один элемент
	if (fList -> head -> next == nullptr){
		delete fList -> head;
		fList -> head = nullptr;
		(*sz)--;
		return;
	}
	//Удаление начального элемента
	FNode* saveFNode = fList -> head -> next;
	delete fList -> head;
	fList -> head = saveFNode;
	(*sz)--;
	return;
}

void DeleteByValue(ForwardList* fList, string line1, int* sz){
    if (fList->head == nullptr){
        cout << "Список пуст\n";
        return;
    }

    if (fList->head->listValue == line1) {
        FNode* toDelete = fList->head;
        fList->head = fList->head->next;
        delete toDelete;
        (*sz)--;
        return;
    }
    FNode* temp = fList->head;
    while (temp->next != nullptr && temp->next->listValue != line1){
        temp = temp->next;
    }

    if (temp->next == nullptr){
        cout << "Элемент \"" << line1 << "\" не найден в списке\n";
        return;
    }

    FNode* toDelete = temp->next; 
    temp->next = toDelete->next; 
    delete toDelete;
    (*sz)--;
}

void DeleteBefore(ForwardList* fList, string line1, int* sz) {
    if (fList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    if (fList->head->listValue == line1) {
        cout << "Перед элементом \"" << line1 << "\" нет элементов для удаления\n";
        return;
    }
    if (fList->head->next != nullptr && fList->head->next->listValue == line1) {
        FNode* toDelete = fList->head;
        fList->head = fList->head->next;
        delete toDelete;
        (*sz)--;
        return;
    }
    FNode* temp = fList->head;
    while (temp->next != nullptr && temp->next->next != nullptr 
           && temp->next->next->listValue != line1) {
        temp = temp->next;
    }
    if (temp->next == nullptr || temp->next->next == nullptr) {
        cout << "Элемент \"" << line1 << "\" не найден (или перед ним нет элемента)\n";
        return;
    }
    FNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    (*sz)--;
}

void DeleteAfter(ForwardList* fList, string line1, int* sz) {
    if (fList->head == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    FNode* temp = fList->head;
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
    FNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    (*sz)--;
}

void DeleteList(ForwardList* fList, int* sz){
    while (fList->head != nullptr){
        FNode* temp = fList->head;
        fList->head = fList->head->next;
        delete temp;
		(*sz)--;
    }
}



int GetPositionByValue(ForwardList* fList, string line1) {
    if (fList->head == nullptr) {
        cout << "Список пуст\n";
        return -1;
    }

    FNode* temp = fList->head;
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
