1)	Даны две непустые очереди; адреса начала и конца первой равны P1 и P2, а второй —    P3   и P4.   Элементы   каждой   из очередей    упорядочены по возрастанию (в направлении от начала очереди к концу). Объединить очереди в одну с сохранением упорядоченности элементов. Вывести указатели на начало и конец полученной очереди. Операции выделения и освобождения   памяти   не использовать,   поля    с    данными    (Data) не изменять.
Решение:
#include <iostream>

struct Node {
    int Data;
    Node* Next;
};

Node* mergeQueues(Node* P1, Node* P2, Node* P3, Node* P4) {
    Node* newHead = nullptr;
    Node* newTail = nullptr;

    while (P1 != nullptr && P3 != nullptr) {
        Node* smaller = nullptr;
        if (P1->Data < P3->Data) {
            smaller = P1;
            P1 = P1->Next;
        }
        else {
            smaller = P3;
            P3 = P3->Next;
        }

        if (newHead == nullptr) {
            newHead = smaller;
            newTail = smaller;
        }
        else {
            newTail->Next = smaller;
            newTail = newTail->Next;
        }
    }

    if (P1 != nullptr) {
        if (newHead == nullptr) {
            newHead = P1;
        }
        else {
            newTail->Next = P1;
        }
    }

    if (P3 != nullptr) {
        if (newHead == nullptr) {
            newHead = P3;
        }
        else {
            newTail->Next = P3;
        }
    }

    return newHead;
}

int main() {
    Node* P1 = new Node{ 1, nullptr };
    Node* P2 = new Node{ 3, nullptr };
    P1->Next = new Node{ 5, P2 };

    Node* P3 = new Node{ 2, nullptr };
    Node* P4 = new Node{ 4, nullptr };
    P3->Next = new Node{ 6, P4 };

    Node* mergedQueue = mergeQueues(P1, P2, P3, P4);

    Node* currentNode = mergedQueue;
    while (currentNode != nullptr) {
        std::cout << currentNode->Data << " ";
        currentNode = currentNode->Next;
    }

    while (mergedQueue != nullptr) {
        Node* temp = mergedQueue;
        mergedQueue = mergedQueue->Next;
        delete temp;
    }

    return 0;
}
