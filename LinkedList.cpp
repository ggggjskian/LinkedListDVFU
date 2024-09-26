#include <iostream>
using namespace std;
struct Node{ //Структура для создания узла списка
    int data;
    Node* prev;
    Node* next;
};

struct DoubleLinkedlist{ //Структура для создания всего списка
    Node* head;
    Node* tail;};

void initializeNode(Node* node, int value) { //Процедура инициализации узла
    node->data = value;
    node->prev = nullptr;
    node->next = nullptr;
}



void initializeList(DoubleLinkedlist* node) { //Процедура иниициализации списка
    node->head = nullptr;
    node->tail = nullptr;
}




void print_list (DoubleLinkedlist* temp){ //Процедура ввывода элементов списка
    Node* current = temp -> head;
    while (current){
        cout<<current->data<<endl;
        current=current->next;
    }

}

int main(){
    cout<<"Компилируется файл..."<<endl;

    return 0;
}