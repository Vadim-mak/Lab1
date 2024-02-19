2)	Создать линейный однонаправленный список строк. Удалить строку с минимальной длиной.
Решение:
#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
        Node(std::string str) : data(str), next(nullptr) {}
};

void deleteMinLengthNode(Node* head) {
    if (head == nullptr) {
        return;
    }
        Node* minNode = head;
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        if (current->data.length() < minNode->data.length()) {
            minNode = current;
        }

        current = current->next;
    }

    if (minNode == head) {
        head = head->next;
        delete minNode;
    }
    else {
        prev = head;
        while (prev->next != minNode) {
            prev = prev->next;
        }

        prev->next = minNode->next;
        delete minNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Node* head = new Node("hello");
    head->next = new Node("world");
    head->next->next = new Node("foo");
    head->next->next->next = new Node("bar");

        std::cout << "Изначальный список: ";
    printList(head);

    deleteMinLengthNode(head);

    std::cout << "Список после удаления минимальной длины: ";
    printList(head);

    return 0;
}
