#include <iostream>
#include <string>
#include <cassert>
#include <stack>

class Stack {
public:
    Stack() {

    }

    void push(int x) {
        regular_stack.push(x);
        if (min_stack.empty() || min_stack.top() >= x)
            min_stack.push(x);
        if (max_stack.empty() || max_stack.top() <= x)
            max_stack.push(x);
    }

    void pop() {
        if (regular_stack.top() == min_stack.top())
            min_stack.pop();
        if (regular_stack.top() == max_stack.top())
            max_stack.pop();
        regular_stack.pop();
    }

    int top() {
        return regular_stack.top();
    }

    int get_min() {
        return min_stack.top();
    }

    int get_max() {
        return max_stack.top();
    }

private:
    std::stack<int> regular_stack;
    std::stack<int> min_stack;
    std::stack<int> max_stack;
};

int main() {
    int num_queries = 0;
    std::cin >> num_queries;

    std::string query;
    std::string value;

    Stack stack;

    for (int i = 0; i < num_queries; ++i) {
        std::cin >> query;
        if (query == "push") {
            std::cin >> value;
            stack.push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.pop();
        }
        else if (query == "max") {
            std::cout << stack.get_max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}