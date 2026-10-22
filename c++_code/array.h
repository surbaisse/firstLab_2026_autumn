#pragma once
#include <string>

void ArrAddEnd(std::string* array, std::string value, int* sz);
void ArrAddByIndex(std::string* array, std::string value, int index, int* sz);
std::string ArrGetElem(std::string* array, int index, int* sz);
void ArrDelByIndex(std::string* array, int index, int* sz);
void ArrReplaceByIndex(std::string* array, std::string value, int index, int* sz);
void ArrPrint(std::string* array, int* sz);
void ArrCheckSize(std::string** array, int* sz, int* capacity);
