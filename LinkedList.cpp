#include <iostream>
using namespace std;

struct Node { // Структура для создания узла списка
    int data;
    Node* prev;
    Node* next;
};

struct DoubleLinkedList { // Структура для создания всего списка
    Node* head;
    Node* tail;
};

void initializeNode(Node* node, int value) { // Процедура инициализации узла
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
}

void initializeList(DoubleLinkedList* list) { // 1. Процедура инициализации списка
    list->head = nullptr;
    list->tail = nullptr;
}

void appendList(DoubleLinkedList* list, int data) { 
    Node* newNode = new Node; 
    initializeNode(newNode, data);
    
    if (!list->head) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}


void deletenodevalue(DoubleLinkedList* list, int value) {//4. Удаление всех узлов по значению
    Node* current = list->head;
    while (current) {
        if (current->data == value) {
            Node* nodeToDelete = current;
            if (nodeToDelete == list->head) { 
                list->head = nodeToDelete->next; 
                if (list->head) {
                    list->head->prev = nullptr; 
                }
            } else {
                nodeToDelete->prev->next = nodeToDelete->next;
            }

            if (nodeToDelete == list->tail) { 
                list->tail = nodeToDelete->prev; 
                if (list->tail) {
                    list->tail->next = nullptr;
                }
            } else {
                if (nodeToDelete->next) {
                    nodeToDelete->next->prev = nodeToDelete->prev; 
                }}
            delete nodeToDelete; 
            current = (nodeToDelete->next) ? nodeToDelete->next : list->head;
        } else {
            current = current->next; 
        } }}


void clear(DoubleLinkedList* list) { //3. Освобождение памяти, удаление всего списка
    Node* current = list->head;
    while (current) {
        Node* nextNode = current->next; 
        delete current;            
        current = nextNode;              
    }
    list->head = nullptr; 
    list->tail = nullptr;
}

void print_list(DoubleLinkedList* list) {  //7.Печать листа
    Node* current = list->head;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

int main() {
    cout << "Компилируется файл..." << endl;
    DoubleLinkedList myList; 
    initializeList(&myList); 
    appendList(&myList, 10);
    appendList(&myList, 20);
    appendList(&myList, 30);
    cout << "Элементы списка: " << endl;
    print_list(&myList); 
    clear(&myList);

    return 0;
}
