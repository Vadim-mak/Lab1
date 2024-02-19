2)	Создать стек, информационными полями которого являются: монитор, диагональ и его цена. Добавить в стек сведения о новом мониторе. Организовать просмотр данных стека и определить количество мониторов с диагональю более 20 дюймов.

Решение:
#include <iostream>
#include <stack>
#include <string>

struct Monitor {
	std::string modelName;
	double diagonal;
	double price;
};

int main() {
	std::stack<Monitor> monitorStack;
    Monitor newMonitor{ "ExampleMonitor", 24.5, 300.0 };
    monitorStack.push(newMonitor);

    int numMonitorsAbove20Inches = 0;
    std::cout << "Monitor Stack:" << std::endl;

    while (!monitorStack.empty()) {
        Monitor currentMonitor = monitorStack.top();
        monitorStack.pop();

        std::cout << "Model: " << currentMonitor.modelName << ", Diagonal: " << currentMonitor.diagonal << " inches, Price: $" << currentMonitor.price << std::endl;

        if (currentMonitor.diagonal > 20.0) {
            numMonitorsAbove20Inches++;
        }
    }

    std::cout << "Number of monitors with diagonal above 20 inches: " << numMonitorsAbove20Inches << std::endl;

    return 0;
}
