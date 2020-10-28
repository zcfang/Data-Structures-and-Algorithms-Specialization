#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::pair<char, int>> brackets;
    std::string text;

    std::getline(std::cin, text);
    for (std::size_t i = 0; i < text.size(); i++) {
        char element = text[i];
        if (element == '[' || element == '{' || element == '(') {
            brackets.push({element, i});
        } else if (element == ']') {
            if (brackets.empty() || brackets.top().first != '[') {
                std::cout << i + 1 << "\n";
                return 0;
            } else {
                brackets.pop();
            }
        } else if (element == ')') {
            if (brackets.empty() || brackets.top().first != '(') {
                std::cout << i + 1 << "\n";
                return 0;
            } else {
                brackets.pop();
            }
        } else if (element == '}') {
            if (brackets.empty() || brackets.top().first != '{') {
                std::cout << i + 1 << "\n";
                return 0;
            } else {
                brackets.pop();
            }
        }
    }
    if (brackets.empty()) {
        std::cout << "Success\n";
    } else {
        std::cout << brackets.top().second + 1 << "\n";
    }

    return 0;
}
