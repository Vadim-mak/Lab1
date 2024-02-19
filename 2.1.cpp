1)	Создать стек целочисленных значений, для реализации используя односвязные списки. Реализовать операции добавления (push) и удаления (pop) элемента из стека. Добавьте в стек числа 4, 3, 1, 2, 4 и распеча тайте содержимое стека. Удалите один элемент из стека, и распечатайте содержимое стека еще раз. Найдите минимальный элемент, принадлежащий стеку.
Решение:
#include <iostream>

struct Node {
	int data;
	Node* next;
};

class Stack {
private:
	Node* top;

public:
	Stack() {
		top = nullptr;
	}
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void printStack() {
        Node* curr = top;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    int findMin() {
        if (top == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        int min = top->data;
        Node* curr = top->next;
        while (curr != nullptr) {
            if (curr->data < min) {
                min = curr->data;
            }
            curr = curr->next;
        }
        return min;
    }
};

int main() {
    Stack stack;
    stack.push(4);
    stack.push(3);
    stack.push(1);
    stack.push(2);
    stack.push(4);
    std::cout << "Stack contents: ";
    stack.printStack();

    stack.pop();

    std::cout << "After pop operation, stack contents: ";
    stack.printStack();

    std::cout << "Minimum element in the stack: " << stack.findMin() << std::endl;

    return 0;
}
