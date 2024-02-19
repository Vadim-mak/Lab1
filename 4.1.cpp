1)	Создать линейный однонаправленный список из целых чисел. Определить среднее арифметическое значений элементов списка, кратных 4.
Решение:
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

float calculateAverage(Node* head) {
    int count = 0;
    int sum = 0;
        Node* current = head;
    while (current != nullptr) {
        if (current->data % 4 == 0) {
            count++;
            sum += current->data;
        }
        current = current->next;
    }

    if (count == 0) {
        return 0;
    }

    return static_cast<float>(sum) / count;
}

int main() {
    setlocale(LC_ALL,"ru");
    Node* head = nullptr;
        insertNode(head, 6);
    insertNode(head, 8);
    insertNode(head, 12);
    insertNode(head, 7);
    insertNode(head, 16);

    float average = calculateAverage(head);
    std::cout << "Среднее значение значений, кратное 4: " << average << std::endl;

    return 0;
}
