#pragma once
#include <iostream>
#include "Random.h"
#include "Button.h"
using namespace std;

struct node {
    Button key;
    node* next;
    node* prev;
};

struct list {
    node* head;
    node* tail;
};

// Định nghĩa hàm createNode ở đây
inline node* createNode(Button data) {
    node* p = new node;
    p->key = data;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

list createList(node* p);
void addHead(list &L, Button data);
void addTail(list &L, Button data);
void removeHead(list &L);
void removeTail(list &L);
void removePos(list &L, int pos);
void addPos(list &L, int pos, Button data);