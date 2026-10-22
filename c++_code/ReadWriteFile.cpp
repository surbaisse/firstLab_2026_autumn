#include "ReadWriteFile.h"
#include <iostream>
using namespace std;
	
void WriteStructure(ForwardList* fList, string filename, string name){
	ofstream oFile("temp.txt");

	int sz = 0;
	FNode* curr = fList -> head;
	while (curr != nullptr){
		sz++;	
		curr = curr -> next;
	}
	curr = fList -> head;

	oFile << "ForwardList " << name << '\n';
	oFile << "SIZE " << sz << '\n';
	for (int i = 0; i < sz; i++){
		oFile << "ITEM " << curr -> listValue << '\n';
		curr = curr -> next;
	}
	oFile.close();
	return;
}

void WriteStructure(DoubleList* dList, string filename, string name){
	ofstream oFile("temp.txt");

	int sz = 0;
	DNode* curr = dList -> head;
	while (curr != nullptr){
		sz++;	
		curr = curr -> next;
	}
	curr = dList -> head;

	oFile << "DoubleList " << name << '\n';
	oFile << "SIZE " << sz << '\n';
	for (int i = 0; i < sz; i++){
		oFile << "ITEM " << curr -> listValue << '\n';
		curr = curr -> next;
	}
	oFile.close();
	return;
}

void WriteStructure(string** array, int* capacity, int *sz, string filename, string name){
	ofstream oFile("temp.txt");
	oFile << "Array " << name << '\n';
	oFile << "SIZE " << (*sz) << '\n';
	for (int i = 0; i < (*sz); i++){
		oFile << "ITEM " << (*array)[i] << '\n';
	}
	oFile.close();
	return;
}


void WriteStructure(Queue* queue, string filename, string name){
	ofstream oFile("temp.txt");

	int sz = 0;
	QNode* curr = queue -> head;
	while (curr != nullptr){
		sz++;	
		curr = curr -> next;
	}
	curr = queue -> head;

	oFile << "Queue " << name << '\n';
	oFile << "SIZE " << sz << '\n';
	for (int i = 0; i < sz; i++){
		oFile << "ITEM " << curr -> queueValue << '\n';
		curr = curr -> next;
	}
	oFile.close();
	return;
}

void WriteStructure(Stack* stack, string filename, string name){
	ofstream oFile("temp.txt");

	int sz = 0;
	SNode* curr = stack -> head;
	while (curr != nullptr){
		sz++;	
		curr = curr -> next;
	}
	curr = stack -> head;

	oFile << "Stack " << name << '\n';
	oFile << "SIZE " << sz << '\n';
	for (int i = 0; i < sz; i++){
		oFile << "ITEM " << curr -> stackValue << '\n';
		curr = curr -> next;
	}
	oFile.close();
	return;
}



void WriteTreeItems(TNode* p, ofstream& oFile) {
    if (!p) return;
    WriteTreeItems(p->left, oFile);
    oFile << "ITEM " << p->treeValue << '\n';
    WriteTreeItems(p->right, oFile);
}

void WriteTree(AVL_Tree* tree, string filename, string name) {
    ofstream oFile("temp.txt");
    int sz = TreeSize(tree->root);

    oFile << "AVL_Tree " << name << '\n';
    oFile << "SIZE " << sz << '\n';
    WriteTreeItems(tree->root, oFile);
    oFile.close();
}

void RewriteFile(ForwardList* fList, string filename, string name){	
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file \"" << filename << "\" didnt open\n";
	}
	ofstream oFile("temp.txt", ios::app);
	
	string line = "";
	int sz = 0;
	while (getline(iFile, line)){
		// нужно определить данная строчка это изменяемая структура?
		if (line == "ForwardList " + name){
			getline(iFile, line);
			sz = stoi(line.substr(5));
			for (int i = 0; i < sz+1; i++){
				getline(iFile, line);
			}
		}
		oFile << line << '\n';
	}
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());	
	return;
}

void RewriteFile(DoubleList* dList, string filename, string name){	
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file \"" << filename << "\" didnt open\n";
	}
	ofstream oFile("temp.txt", ios::app);
	
	string line = "";
	int sz = 0;
	while (getline(iFile, line)){
		// нужно определить данная строчка это изменяемая структура?
		if (line == "DoubleList " + name){
			getline(iFile, line);
			sz = stoi(line.substr(5));
			for (int i = 0; i < sz+1; i++){
				getline(iFile, line);
			}
		}
		oFile << line << '\n';
	}
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());	
	return;
}

void RewriteFile(string** array, string filename, string name){	
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file \"" << filename << "\" didnt open\n";
	}
	ofstream oFile("temp.txt", ios::app);
	
	string line = "";
	int sz = 0;
	while (getline(iFile, line)){
		// нужно определить данная строчка это изменяемая структура?
		if (line == "Array " + name){
			getline(iFile, line);
			sz = stoi(line.substr(5));
			for (int i = 0; i < sz+1; i++){
				getline(iFile, line);
			}
		}
		oFile << line << '\n';
	}
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());	
	return;
}

void RewriteFile(Queue* queue, string filename, string name){	
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file \"" << filename << "\" didnt open\n";
	}
	ofstream oFile("temp.txt", ios::app);
	
	string line = "";
	int sz = 0;
	while (getline(iFile, line)){
		// нужно определить данная строчка это изменяемая структура?
		if (line == "Queue " + name){
			getline(iFile, line);
			sz = stoi(line.substr(5));
			for (int i = 0; i < sz+1; i++){
				getline(iFile, line);
			}
		}
		oFile << line << '\n';
	}
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());	
	return;
}


void RewriteFile(Stack* stack, string filename, string name){
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file \"" << filename << "\" didnt open\n";
	}
	ofstream oFile("temp.txt", ios::app);
	
	string line = "";
	int sz = 0;
	while (getline(iFile, line)){
		// нужно определить данная строчка это изменяемая структура?
		if (line == "Stack " + name){
			getline(iFile, line);
			sz = stoi(line.substr(5));
			for (int i = 0; i < sz+1; i++){
				getline(iFile, line);
			}
		}
		oFile << line << '\n';
	}
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());	
	return;

}

void RewriteFile(AVL_Tree* tree, string filename, string name) {
    ifstream iFile(filename);
    if (!iFile.is_open()) {
        cout << "file \"" << filename << "\" didnt open\n";
    }
    ofstream oFile("temp.txt", ios::app);

    string line = "";
    int sz = 0;
    while (getline(iFile, line)) {
        if (line == "AVL_Tree " + name) {
            getline(iFile, line);
            sz = stoi(line.substr(5));
            // пропустить старые ITEM'ы
            for (int i = 0; i < sz; i++) getline(iFile, line);
            continue;   // не писать старые ITEM'ы
        }
        oFile << line << '\n';
    }

    iFile.close();
    oFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void ReadForwardList(ForwardList* fList, string filename, string name, int* sz){
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file didnt open\n";
		return;
	}
	
	// читает все строки до конца в файле.
	string line = "";
	while (getline(iFile, line)){
		// проверка "что за структура?".
		if (line == "ForwardList " + name){
			break;
		}
	}

	// нужная структура не найдена, выход из процедуры
	if (line != "ForwardList " + name){
		cout << "such structure named like \"" << name << "\" didnt find\n";
		return;
	}
	// нужная структура найдена и можно начинать брать из файла данные
	//берем размер структуры
	iFile >> line; iFile >> line;
	if (line == "0"){
		cout << "Структура пустая\n";
		return;
	}
	(*sz) = stoi(line);
	
	int szfor = (*sz); // нужно что бы не было бесконечного цикла т.к. в AddEnd sz увеличивается.
	for (int i = 0; i < szfor; i++){
		iFile >> line; iFile >> line;
		AddEnd(fList, line);
	}
}

void ReadDoubleList(DoubleList* dList, string filename, string name, int* sz){
	
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file didnt open\n";
		return;
	}
	// читает все строки до конца в файле.
	string line = "";
	while (getline(iFile, line)){
		// проверка "что за структура?".
		if (line == "DoubleList " + name){
			break;
		}
	}
	// нужная структура не найдена, выход из процедуры
	if (line != "DoubleList " + name){
		cout << "such structure named like \"" << name << "\" didnt find\n";
		return;
	}

	// нужная структура найдена и можно начинать брать из файла данные
	//берем размер структуры
	iFile >> line; iFile >> line;
	if (line == "0"){
		cout << "Структура пустая\n";
		return;
	}
	(*sz) = stoi(line);
	
	int szfor = (*sz); // нужно что бы не было бесконечного цикла т.к. в AddEnd sz увеличивается.
	for (int i = 0; i < szfor; i++){
		iFile >> line; iFile >> line;
		AddEnd(dList, line);
	}
	
	
}

void ReadArray(string** array, int* capacity, int* sz, string filename, string name){
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file didnt open\n";
		return;
	}
	// читает все строки до конца в файле.
	string line = "";
	while (getline(iFile, line)){
		// проверка "что за структура?".
		if (line == "Array " + name){
			break;
		}
	}
	// нужная структура не найдена, выход из процедуры
	if (line != "Array " + name){
		cout << "such structure named like \"" << name << "\" didnt find\n";
		return;
	}
	iFile >> line; iFile >> line;
	int szFile = stoi(line);
	for (int i = 0; i < szFile; i++){
		iFile >> line; iFile >> line;
		ArrCheckSize(array, sz, capacity);
		ArrAddEnd(*array, line, sz);	

	}
}

void ReadQueue(Queue* queue, string filename, string name){
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file didnt open\n";
		return;
	}
	// читает все строки до конца в файле.
	string line = "";
	while (iFile >> line){
		// проверка "что за структура?".
		if (line == "Queue"){
			iFile >> line;
			// Проверка имени структуры.
			if (line == name){
				break;
			}
		}
	}
	// нужная структура не найдена, выход из процедуры
	if (line != name){
		cout << "such structure named like \"" << name << "\" didnt find\n";
		return;
	}

	// нужная структура найдена и можно начинать брать из файла данные
	//берем размер структуры
	iFile >> line; iFile >> line;
	if (line == "0"){
		cout << "Стуктура пустая\n";
		return;
	}
	int size = stoi(line);

	for (int i = 0; i < size; i++){
		iFile >> line; iFile >> line;
		QueuePush(queue, line);
	}

}

void ReadStack(Stack* stack, string filename, string name){
	ifstream iFile(filename);
	if (!iFile.is_open()){
		cout << "file didnt open\n";
		return;
	}
	// читает все строки до конца в файле.
	string line = "";
	while (iFile >> line){
		// проверка "что за структура?".
		if (line == "Stack"){
			iFile >> line;
			// Проверка имени структуры.
			if (line == name){
				break;
			}
		}
	}
	// нужная структура не найдена, выход из процедуры
	if (line != name){
		cout << "such structure named like \"" << name << "\" didnt find\n";
		return;
	}

	// нужная структура найдена и можно начинать брать из файла данные
	//берем размер структуры
	iFile >> line; iFile >> line;
	if (line == "0"){
		cout << "Стуктура пустая\n";
		return;
	}
	int size = stoi(line);

	for (int i = 0; i < size; i++){
		iFile >> line; iFile >> line;
		StackPush(stack, line);
	}
}

void ReadTree(AVL_Tree* tree, string filename, string name) {
    ifstream iFile(filename);
    if (!iFile.is_open()) {
        cout << "file didnt open\n";
        return;
    }

    string line = "";
    while (iFile >> line) {
        if (line == "AVL_Tree") {
            iFile >> line;
            if (line == name) {
                break;
            }
        }
    }

    if (line != name) {
        cout << "such structure named like \"" << name << "\" didnt find\n";
        return;
    }

    iFile >> line; iFile >> line;   // "SIZE" и число
    if (line == "0") {
        cout << "Структура пустая\n";
        return;
    }
    int size = stoi(line);
    for (int i = 0; i < size; i++) {
        iFile >> line; iFile >> line;  // "ITEM" и значение
		int lineToSend = stoi(line);
        TreeAddElem(tree, lineToSend);
    }
}

void AddStructureToFile(string filename, string type, string name) {
    ifstream iFile(filename);
    
    ofstream oFile("temp.txt");

    // Записываем новую структуру в начало
    oFile << type << " " << name << '\n';
    oFile << "SIZE 0\n";

    // Дописываем старое содержимое
    string line;
    while (getline(iFile, line)) {
        oFile << line << '\n';
    }

    iFile.close();
    oFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}





