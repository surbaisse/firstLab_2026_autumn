#pragma once
#include <string>

struct QNode {
    QNode* next = nullptr;
    std::string queueValue;
};

struct Queue {
    QNode* head = nullptr;
    QNode* tail = nullptr;
};

void QueuePush(Queue* queue, std::string value);
void QueuePop(Queue* queue);
void QueuePrint(Queue* queue);
void QueueClear(Queue* queue);
