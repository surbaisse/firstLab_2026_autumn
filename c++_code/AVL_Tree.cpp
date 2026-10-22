#include "AVL_Tree.h"
#include <iostream>
using namespace std;

unsigned char height(TNode* p) { return p ? p->height : 0; }
int balanceFactor(TNode* p) { return height(p->right) - height(p->left); }

void fixHeight(TNode* p) {
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

TNode* rotateRight(TNode* p) {
    TNode* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p); fixHeight(q);
    return q;
}

TNode* rotateLeft(TNode* q) {
    TNode* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q); fixHeight(p);
    return p;
}

TNode* balance(TNode* p) {
    fixHeight(p);
    if (balanceFactor(p) == 2) {
        if (balanceFactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if (balanceFactor(p) == -2) {
        if (balanceFactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p;
}

// добавление элемента

TNode* insertNode(TNode* p, int value) {
    if (!p) return new TNode(value);

    if (value < p->treeValue)
        p->left  = insertNode(p->left,  value);
    else if (value > p->treeValue)
        p->right = insertNode(p->right, value);
    else
        return p;

    return balance(p);
}

void TreeAddElem(AVL_Tree* tree, int value) {
    tree->root = insertNode(tree->root, value);
}

// удаление элемента

TNode* findMin(TNode* p) {
    return p->left ? findMin(p->left) : p;
}

TNode* removeMin(TNode* p) {
    if (!p->left) return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

TNode* removeNode(TNode* p, int value) {
    if (!p) return nullptr;

    if (value < p->treeValue)
        p->left  = removeNode(p->left,  value);
    else if (value > p->treeValue)
        p->right = removeNode(p->right, value);
    else {
        TNode* l = p->left;
        TNode* r = p->right;
        
        if (!r) {
            delete p;
            return l;
        }
        if (!l) {
            delete p;
            return r;
        }
        TNode* minNode = findMin(r);
        minNode->right = removeMin(r); 
        minNode->left  = l;
        delete p;
        return balance(minNode);
    }

    return balance(p);
}

void TreeDelElem(AVL_Tree* tree, int value) {
    tree->root = removeNode(tree->root, value);
}

// inorder вывод
void printInOrder(TNode* p) {
    if (!p) return;
    printInOrder(p->left);
    cout << p->treeValue << " ";
    printInOrder(p->right);
}

void TreePrintInOrder(const AVL_Tree* tree) {
    printInOrder(tree->root);
    cout << endl;
}

// pre-order 
void printPreOrder(TNode* p) {
    if (!p) return;
    cout << p->treeValue << " ";
    printPreOrder(p->left);
    printPreOrder(p->right);
}

void TreePrintPreOrder(const AVL_Tree* tree) {
    printPreOrder(tree->root);
    cout << endl;
}

// post-order
void printPostOrder(TNode* p) {
    if (!p) return;
    printPostOrder(p->left);
    printPostOrder(p->right);
    cout << p->treeValue << " ";
}

void TreePrintPostOrder(const AVL_Tree* tree) {
    printPostOrder(tree->root);
    cout << endl;
}




int TreeSize(TNode* p) {
    if (!p) return 0;
    return 1 + TreeSize(p->left) + TreeSize(p->right);
}

void TreeClearNode(TNode* p) {
    if (!p) return;
    TreeClearNode(p->left);
    TreeClearNode(p->right);
    delete p;
}

void TreeClear(AVL_Tree* tree) {
    TreeClearNode(tree->root);
    tree->root = nullptr;
}




	/*
	нужно определить куда спускать по условию: меньше текущего узла - влево, больше текущего узла - вправо.
	при спуске вниз по дереву нужно записать в стек указатель на узел дерева.
	Спускаться вниз до тех пор пока не найдется место для элемента и параллельно записывать путь.
	Далее нужно рассчитать высоту добавленного узла и подниматься по стеку изменяя высоту узлов.
	на каждом подъеме по стеку проверять баланс

	bfactor = heightLeft - heightRight

	если bfactor будет вне допустимых значений, то нужно посмотреть на знак получившегося bfactor 
	-bfactor > 0 левое поддерево выше
	-bfactor < 0 правое поддерево выше
	Далее нужно будет спуститься вниз к поддереву где дизбаланс и посмотреть на знак bfactor текуещго узла.
	
	из полученных данных узнать какой поворот выполнять
	- для случая > > правый поворот
	- для случая < < левый поворот
	- для случая > < левый-правый поворот
	- для случая < > правый-левый поворот

	при поворотах менять высоту для затрагиваемых узлов
	*/
