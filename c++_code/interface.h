#pragma once
#include <string>
#include "ForwardLinkedList.h"
#include "DoubleLinkedList.h"
#include "array.h"
#include "queue.h"
#include "stack.h"
#include "AVL_Tree.h"

void Action(ForwardList* fList, std::string cmd, std::string line1, std::string line2, int* sz);
void Action(DoubleList* dList, std::string cmd, std::string line1, std::string line2, int* sz);
void Action(std::string* array, int* capacity, int* sz, std::string cmd, std::string line1, std::string line2);
void Action(Queue* queue, std::string cmd, std::string line1);
void Action(Stack* stack, std::string cmd, std::string line1);
void Action(AVL_Tree* tree, std::string cmd, std::string line1);
void Action(std::string cmd, std::string name, std::string filename);
