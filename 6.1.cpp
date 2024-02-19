1)	Создать циклический двунаправленный список из вещественных чисел. Удалить из списка элемент перед каждым элементом со значением 3.
Решение:
#include <iostream>

struct Node {
    double data;
    Node* prev;
    Node* next;
        Node(double val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        void insert(double val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeBefore3() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data == 3.0) {
                if (current == head) {
                    head = current->next;
                    head->prev = nullptr;
                    delete current;
                    current = head;
                    continue;
                }
                else {
                    Node* temp = current->prev;
                    temp->next = current->next;
                    current->next->prev = temp;
                    delete current;
                    current = temp;
                    continue;
                }
            }
            current = current->next;
        }
    }

    void printList() {
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
    DoublyLinkedList list;
    list.insert(2.0);
    list.insert(3.0);
    list.insert(4.0);
    list.insert(5.0);
    list.insert(6.0);
        std::cout << "Исходный список: ";
    list.printList();

    list.removeBefore3();

    std::cout << "Список после удаления: ";
    list.printList();

    return 0;
}
