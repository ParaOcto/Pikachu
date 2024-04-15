#include "Linkedlist.h"

void addHead(list &L, Button data) {
    node* p = createNode(data);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    }
    else {
        p->next = L.head;
        p->prev = NULL;
        L.head = p;
    }
}

void addTail(list &L, Button data) {
    node* p = createNode(data);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
        L.tail->next = NULL;
    }
}

void removeHead(list &L) {
    node* p = L.head;
    if (p == NULL) return;
    if (p->next == NULL) {
        L.head = L.tail = NULL;
        delete p;
    }
    else {
        L.head = L.head->next;
        delete p;
        L.head->prev = NULL;
    }
}

void removeTail(list &L) {
    node* p = L.head;
    if (p == NULL) return;
    if (p->next == NULL) {
        L.head = L.tail = NULL;
        delete p;
    }
    else {
        while (p->next != L.tail) p = p->next;
        delete L.tail;
        L.tail = p;
        L.tail->next = NULL;
    }
}

void removePos(list &L, int pos) {
    if (pos == 0) {
        removeHead(L);
        return;
    }
    node* p = L.head;
    for (int i = 0; p != NULL && i < pos; i++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) return;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

void addPos(list &L, int pos, Button data){
    if (pos == 0){
        addHead(L, data);
        return;
    }
    node* p = L.head;
    for (int i = 0; p != NULL && i < pos; i++)    p = p->next;
    node* pHead = createNode(data);
    pHead->next = p;
    pHead->prev = p->prev;
    p->prev->next = pHead;
    p->prev = p;


}