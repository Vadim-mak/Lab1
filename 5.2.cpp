2)	Создать линейный двунаправленный список из целых чисел. Вставить в список число 11 после каждого элемента, равного 9.


Решение:

#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
        void insertEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(int data, int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                Node* newNode = new Node;
                newNode->data = data;

                newNode->prev = current;
                newNode->next = current->next;

                if (current->next == nullptr) {
                    tail = newNode;
                }
                else {
                    current->next->prev = newNode;
                }
                current->next = newNode;

                current = newNode->next;
            }
            else {
                current = current->next;
            }
        }
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList list;
        list.insertEnd(9);
    list.insertEnd(3);
    list.insertEnd(9);
    list.insertEnd(5);
    list.insertEnd(7);

    std::cout << "Исходный список ";
    list.display();

    list.insertAfter(11, 9);

    std::cout << "Список после вставки 11 после каждых 9:";
    list.display();

    return 0;
}
