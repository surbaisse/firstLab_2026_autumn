#pragma once
#include <string>

struct FNode {
    FNode* next = nullptr;
    std::string listValue;
};

struct ForwardList {
    FNode* head = nullptr;
};

int ListSize(ForwardList* fList);
void OutputList(ForwardList* fList);
void AddAfter(ForwardList* fList, std::string line1, std::string line2, int* sz);	
void AddStart(ForwardList* fList, std::string line1, int* sz);
void AddBefore(ForwardList* fList, std::string line1, std::string line2, int* sz);
void AddEnd(ForwardList* fList, std::string line1, int* sz);
void AddEnd(ForwardList* fList, std::string line1);
void DeleteEnd(ForwardList* fList, int* sz);	
void DeleteStart(ForwardList* fList, int* sz);
void DeleteByValue(ForwardList* fList, std::string line1, int* sz);
void DeleteBefore(ForwardList* fList, std::string line1, int* sz);
void DeleteAfter(ForwardList* fList, std::string line1, int* sz);
void DeleteList(ForwardList* fList, int* sz);
int GetPositionByValue(ForwardList* fList, std::string line1);
