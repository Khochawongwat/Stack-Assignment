#ifndef stack_h
#define  stack_h
#include "node.h"
using namespace std;

class Stack {
private:
    NodePtr top;
    int size;

public:
    Stack(NodePtr t = nullptr);
    ~Stack();
    char get_top();
    void push(char x);
    char pop();
    void printall();
    void clear();
    bool isEmpty();
};

char Stack::get_top(){
  return top->get_value();
}
Stack::Stack(NodePtr t){
  if(t) {
    top=t;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(char x) {
    NodePtr newnode = new NODE(x);
    if (newnode) {
        newnode->set_next(top);
        top = newnode;
        size++;
    } else {
        cout << "No memory left for new nodes" << endl;
    }
}

char Stack::pop() {
    if (top) {
        NodePtr t = top;
        char value = t->get_value();
        top = t->get_next();
        delete t;
        size--;
        return value;
    }
    return 0;
}

void Stack::printall() {
    NodePtr t = top;
    while (t) {
        cout << t->get_value();
        t = t->get_next();
        if (t) {
            std::cout << " ";
        }
    }
    cout << endl;
}
void Stack::clear(){
   while (top) {
        NodePtr t = top;
        top = top->get_next();
        delete t;
    }
}
Stack::~Stack() {
    while (top) {
        NodePtr t = top;
        top = top->get_next();
        delete t;
    }
}

bool Stack::isEmpty(){
  if(top){
    return false;
  }
  return true;
}

#endif
