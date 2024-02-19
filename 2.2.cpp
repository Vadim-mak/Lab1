2)	Даны две непустые очереди; адреса начала и конца первой равны P1   и P2, а второй — P3 и P4. Очереди содержат одинаковое количество элементов. Объединить очереди в одну, в которой элементы исходных очередей чередуются (начиная с первого элемента первой очереди). Вывести указатели на начало и конец полученной очереди. Операции выделения и освобождения памяти не использовать.
Решение:
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* mergeQueues(Node* P1, Node* P2, Node* P3, Node* P4) {
    Node* head = nullptr;
    Node* tail = nullptr;

    while (P1 != nullptr && P3 != nullptr) {
        if (head == nullptr) {
            head = P1;
            tail = P1;
            P1 = P1->next;
        }
        else {
            tail->next = P1;
            tail = tail->next;
            P1 = P1->next;
        }

        tail->next = P3;
        tail = P3;
        P3 = P3->next;
    }

    while (P2 != nullptr && P4 != nullptr) {
        if (head == nullptr) {
            head = P2;
            tail = P2;
            P2 = P2->next;
        }
        else {
            tail->next = P2;
            tail = tail->next;
            P2 = P2->next;
        }

        tail->next = P4;
        tail = P4;
        P4 = P4->next;
    }

    return head;
}

int main() {
    Node* P1 = new Node{ 1, new Node{3, nullptr} };
    Node* P2 = new Node{ 2, new Node{4, nullptr} };
    Node* P3 = new Node{ 5, new Node{7, nullptr} };
    Node* P4 = new Node{ 6, new Node{8, nullptr} };

    Node* mergedQueue = mergeQueues(P1, P2, P3, P4);

    Node* current = mergedQueue;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
    }
