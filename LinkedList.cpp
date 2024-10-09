#include <iostream>
using namespace std;

struct Node { //Cтруктура для хранения узла
    int data;
    Node* prev;
    Node* next;
};

struct DoubleLinkedList { //Структура для списка
    Node* head;
    Node* tail;
};

void initializeNode(Node* node, int value) { //1. Инициализация узла списка 
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
}

void initializeList(DoubleLinkedList* list) { //1. Инициализация самого списка
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
        Node* current = list->head;
        while (current && current->data < data) {
            current = current->next;
        }

        if (!current) { 
            list->tail->next = newNode;
            newNode->prev = list->tail;
            list->tail = newNode;
        } else if (current == list->head) { 
            newNode->next = list->head;
            list->head->prev = newNode;
            list->head = newNode;
        } else { 
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }}}


void deletenodevalue(DoubleLinkedList* list, int value) {//4. Удаление всех вхождений заданного по значению элемента
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
                }
            }
            delete nodeToDelete; 
            current = (nodeToDelete->next) ? nodeToDelete->next : list->head;
        } else {
            current = current->next; 
        }
    }
}

void clear(DoubleLinkedList* list) { //2. Освобождение памяти
    Node* current = list->head;
    while (current) {
        Node* nextNode = current->next; 
        delete current;            
        current = nextNode;              
    }
    list->head = nullptr; 
    list->tail = nullptr;
}

void print_list(DoubleLinkedList* list) { //7. Печать листа
    Node* current = list->head;
    while (current) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "None" << endl;
}

int main() {
    cout << "Компилируется файл..." << endl;
    DoubleLinkedList myList; 
    initializeList(&myList); 
    appendList(&myList, 10);
    appendList(&myList, 20);
    appendList(&myList, 12);
    appendList(&myList, 6);
    appendList(&myList, 12);
    appendList(&myList, 5);
    appendList(&myList, 1);
    
    cout << "Элементы списка: " << endl;
    print_list(&myList); 
    deletenodevalue(&myList, 12); 
    print_list(&myList); 
    
    clear(&myList);
    
    return 0;
}
