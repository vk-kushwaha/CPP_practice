#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1; // Assuming -1 as an invalid value when the stack is empty
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; // Assuming -1 as an invalid value when the stack is empty
    }
};

int main() {
    int n;
    cin >> n;
     cin.ignore(); // Consume the newline after n

    MinStack myStack;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        istringstream iss(line);
        string operation;
        iss >> operation;

        if (operation == "push") {
            int x;
            iss >> x;
            myStack.push(x);
        } else if (operation == "pop") {
            myStack.pop();
        } else if (operation == "top") {
            cout << myStack.top() << " ";
        } else if (operation == "getMin") {
            cout << myStack.getMin() << " ";
        }
    }

    return 0;
}
