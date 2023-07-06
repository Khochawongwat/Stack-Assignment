#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            string expression = argv[i];
            bool balanced = true;
            bool stopped = false;
            Stack stack;
            int countOpen = 0;
            int countClose = 0;
          
            for (char c : expression) {
                switch (c) {
                    case '[':
                    case '{':
                    case '(':
                        stack.push(c);
                        countOpen++;
                        break;
                    case ')': {
                        char k = stack.pop();
                        if (k != '(') {
                            balanced = false;
                            stopped = true;
                        }else{
                          countClose++;
                        }
                        break;
                    }
                    case ']': {
                        char k = stack.pop();
                        if (k != '[') {
                            balanced = false;
                            stopped = true;
                        }else{
                          countClose++;
                        }
                        break;
                    }
                    case '}': {
                        char k = stack.pop();
                        if (k != '{') {
                            balanced = false;
                            stopped = true;
                        }else{
                          countClose++;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            
            if(!stopped) balanced = stack.isEmpty();
            
            if (balanced) {
                cout << expression << ": Match" << endl;
            } else {
                cout << expression << ": Not Match";
                if(countClose < countOpen){
                  cout << " > Too many open parentheses";
                }else if(countClose > countOpen){
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
