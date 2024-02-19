1)	Создать линейный однонаправленный список из вещественных чисел. Удалить из списка элемент перед каждым элементом со значением 55.
Решение:
#include <iostream>

struct Node {
    double data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
        void insert(double value) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }

    void deleteElementBefore55() {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->next != NULL) {
            if (current->next->data == 55) {
                if (prev == NULL) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }

                Node* temp = current;
                current = current->next;
                delete temp;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList list;
        list.insert(60);
    list.insert(55);
    list.insert(40);
    list.insert(55);
    list.insert(30);
    list.insert(20);
    list.insert(55);

    std::cout << "Исходный список:" << std::endl;
    list.display();

    list.deleteElementBefore55();

    std::cout << "Список после удаления элементов до 55:" << std::endl;
    list.display();

    return 0;
}
