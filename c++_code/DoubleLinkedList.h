#pragma once
#include <string>

struct DNode {
    DNode* prev = nullptr;
    DNode* next = nullptr;
    std::string listValue;
};

struct DoubleList {
    DNode* head = nullptr;
    DNode* tail = nullptr;
};

int ListSize(DoubleList* dList);
void OutputHList(DoubleList* dList);
void OutputTList(DoubleList* dList);
void AddAfter(DoubleList* dList, std::string line1, std::string line2, int* sz);
void AddStart(DoubleList* dList, std::string line1, int* sz);
void AddBefore(DoubleList* dList, std::string line1, std::string line2, int* sz);
void AddEnd(DoubleList* dList, std::string line1, int* sz);
void AddEnd(DoubleList* dList, std::string line1);
void DeleteEnd(DoubleList* dList, int* sz);
void DeleteStart(DoubleList* dList, int* sz);
void DeleteByValue(DoubleList* dList, std::string line1, int* sz);
void DeleteBefore(DoubleList* dList, std::string line1, int* sz);
void DeleteAfter(DoubleList* dList, std::string line1, int* sz);
void DeleteList(DoubleList* dList, int* sz);
int GetPositionByValue(DoubleList* dList, std::string line1);
