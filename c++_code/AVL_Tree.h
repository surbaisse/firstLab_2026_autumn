#pragma once
#include <string>

struct TNode {
    int treeValue;
    int height;
    TNode* right = nullptr;
    TNode* left = nullptr;

    TNode(int value) : treeValue(value), height(1), right(nullptr), left(nullptr) {}
};

struct AVL_Tree {
    TNode* root = nullptr;
};


unsigned char height(TNode* p);
int balanceFactor(TNode* p);
void fixHeight(TNode* p);
TNode* rotateRight(TNode* p);
TNode* rotateLeft(TNode* q);
TNode* balance(TNode* p);
TNode* insertNode(TNode* p, int value);
void TreeAddElem(AVL_Tree* tree, int value);
TNode* findMin(TNode* p);
TNode* removeMin(TNode* p);
TNode* removeNode(TNode* p, int value);
void TreeDelElem(AVL_Tree* tree, int value);
void printInOrder(TNode* p);
void TreePrintInOrder(const AVL_Tree* tree);
void printPreOrder(TNode* p);
void TreePrintPreOrder(const AVL_Tree* tree);
void printPostOrder(TNode* p);
void TreePrintPostOrder(const AVL_Tree* tree);
int TreeSize(TNode* p);
void TreeClearNode(TNode* p);
void TreeClear(AVL_Tree* tree);
