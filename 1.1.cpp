1)	Создать стек из целых чисел. Вычислить произведение нечётных значений элементов стека. Организовать просмотр данных стека.
Решение:
#include <iostream>
#include <stack>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    stack<int> myStack;
    int product = 1

    myStack.push(3);
    myStack.push(6);
    myStack.push(5);
    myStack.push(7);
    myStack.push(2);

    
    cout << "Элементы стека:" << endl;
    stack<int> tempStack; 
    while (!myStack.empty()) {
        int current = myStack.top();
        cout << current << " ";
        tempStack.push(current);
        myStack.pop();
    }
    cout << endl;

    
    while (!tempStack.empty()) {
        int current = tempStack.top();
        if (current % 2 != 0) {
            product *= current;
        }
        tempStack.pop();
    }

    cout << "Произведение нечётных значений элементов: " << product << endl;

    return 0;
}
