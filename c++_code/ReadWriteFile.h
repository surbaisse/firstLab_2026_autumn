#pragma once
#include <string>
#include <fstream>
#include "ForwardLinkedList.h"
#include "DoubleLinkedList.h"
#include "array.h"
#include "queue.h"
#include "stack.h"
#include "AVL_Tree.h"

// Запись изменяемой структуры
void WriteStructure(ForwardList* fList, std::string filename, std::string name);
void WriteStructure(DoubleList* dList, std::string filename, std::string name);
void WriteStructure(std::string** array, int* capacity, int *sz, std::string filename, std::string name);
void WriteStructure(Queue* queue, std::string filename, std::string name);
void WriteStructure(Stack* stack, std::string filename, std::string name);
void WriteTreeItems(TNode* p, std::ofstream& oFile);
void WriteTree(AVL_Tree* tree, std::string filename, std::string name);

// Перепись файла
void RewriteFile(ForwardList* fList, std::string filename, std::string name);
void RewriteFile(DoubleList* dList, std::string filename, std::string name);	
void RewriteFile(std::string** array, std::string filename, std::string name);	
void RewriteFile(Queue* queue, std::string filename, std::string name);	
void RewriteFile(Stack* stack, std::string filename, std::string name);
void RewriteFile(AVL_Tree* tree, std::string filename, std::string name);

// добавление новой структуры в файл
void AddStructureToFile(std::string filename, std::string type, std::string name);

// Чтение структур из файла
void ReadForwardList(ForwardList* fList, std::string filename, std::string name, int* sz);
void ReadDoubleList(DoubleList* dList, std::string filename, std::string name, int* sz);
void ReadArray(std::string** array, int* capacity, int* sz, std::string filename, std::string name);
void ReadQueue(Queue* queue, std::string filename, std::string name);
void ReadStack(Stack* stack, std::string filename, std::string name);
void ReadTree(AVL_Tree* tree, std::string filename, std::string name);
