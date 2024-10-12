#include <iostream>
using namespace std;
struct Node { //Cтруктура для хранения узла

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

void appendList(DoubleLinkedList* list, int data) { //3. Добавление элемента(упорядоченный по возрастаниюю)
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
            if (nodeToDelete->next != nullptr) {
    current = nodeToDelete->next;
} else {
    current = list->head;
}        } else {
            current = current->next; 
        }
    }
}

void deletenodevalueAfter(DoubleLinkedList* list, int value) {//5. ***Удаление элемента после входящего
    Node* current = list->head;
    while (current) {
        if (current->data == value) {
            Node* nodeToDelete = current->next;
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
            if (nodeToDelete->next != nullptr) {
    current = nodeToDelete->next;
} else {
    current = list->head;
}        } else {
            current = current->next; 
        }
    }
}

int search_elem(DoubleLinkedList* list,int value){ //6. Поиск заданного элемента по значению
    Node* current = list->head;
    bool flag = false;
    int n = 1;
    while (current){
        if (current->data == value){
            flag=true;
            break;}
        else{
        current=current->next;
        n=n+1;
        }} 
    
    if (flag){
        return n;}
    else{
        return -1;
    }
}



void print_list(DoubleLinkedList* list) { //7. Печать листа
    cout<<"None"<<" <-> ";
    Node* current = list->head;
    while (current) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "None" << endl;
}

DoubleLinkedList Union(DoubleLinkedList* list1,DoubleLinkedList* list2){//8. Объединенме двух списков
    DoubleLinkedList unionlist;
    initializeList(&unionlist);
    Node* currentlist1=list1->head;
    while(currentlist1){
        appendList(&unionlist,currentlist1->data);
        currentlist1=currentlist1->next;
    }
    Node* currentlist2=list2->head;
     while(currentlist2){
        appendList(&unionlist, currentlist2->data);
        currentlist2=currentlist2->next;}

    return unionlist;   
}

int main() {
    cout << "Компилируется файл..." << endl;
    DoubleLinkedList list1; 
    DoubleLinkedList list2;
    initializeList(&list1); 
    initializeList(&list2); 
    //Первый список
    appendList(&list1, 10);
    appendList(&list1, 20);
    appendList(&list1, 12);
    appendList(&list1, 6);
    appendList(&list1, 12);
    appendList(&list1, 5);
    appendList(&list1, 1);
    cout << "Элементы списка 1: " << endl;
    print_list(&list1); 
    cout<<search_elem(&list1,20)<<endl; // Демонстрация поиска цифр
    cout<<search_elem(&list1,15)<<endl;

    //Вторый список
    appendList(&list2,3);
    appendList(&list2,7);
    appendList(&list2,2);
    appendList(&list2,1);
    appendList(&list2,-5);
    appendList(&list2,12);
    cout << "Элементы списка 2: " << endl;
    print_list(&list2);  

    //Список объединения
    cout<<"Элементы списка объединения:"<<endl;
    DoubleLinkedList U;
    U = Union(&list1,&list2);
    print_list(&U);
    clear(&list1);
    clear(&list2);
    clear(&U);
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

void appendList(DoubleLinkedList* list, int data) { //3. Добавление элемента(упорядоченный по возрастаниюю)
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
            if (nodeToDelete->next != nullptr) {
    current = nodeToDelete->next;
} else {
    current = list->head;
}

        } else {
            current = current->next; 
        }
    }
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
