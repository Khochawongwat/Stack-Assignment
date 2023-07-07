#include <iostream>
#include "stack.h"
#include <string>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(const string& expression, int& countOpen, int& countClose) {
    Stack stack;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
            countOpen++;
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty() || !isMatchingPair(stack.get_top(), c)) {
                countClose++;
                continue;
            }
            stack.pop();
            countOpen--;
        }
    }
    
    return stack.isEmpty() && countOpen == 0 && countClose == 0;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            string expression = argv[i];
            int countOpen = 0;
            int countClose = 0;
            bool balanced = isBalanced(expression, countOpen, countClose);
            
            if (balanced) {
                cout << expression << ": Match" << endl;
            } else {
                cout << expression << ": Not Match";
                if (countOpen > countClose) {
                    cout << " > Too many open parentheses";
                } else if (countClose > countOpen) {
                    cout << " > Too many close parentheses";
                }
                cout << endl;
            }
        }
    } else {
        cout << "No arguments provided." << endl;
    }

    return 0;
}
