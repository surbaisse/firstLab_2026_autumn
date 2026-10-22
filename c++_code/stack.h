#pragma once
#include <string>

struct SNode {
    SNode* next = nullptr;
    std::string stackValue;
};

struct Stack {
    SNode* head = nullptr;
};

void StackPush(Stack* stack, std::string value);
void StackPop(Stack* stack);
void StackPrint(Stack* stack);
void StackClear(Stack* stack);
