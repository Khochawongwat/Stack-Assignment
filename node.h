#ifndef node_h
#define  node_h
#include "iostream"

using namespace std;

class NODE{
	char data;
	NODE *nextPtr;
public:
	NODE(char);
	~NODE();
  char get_value();
	void set_next(NODE *);
	NODE* get_next();
};
typedef NODE* NodePtr;

NODE::NODE(char x){
	data=x;
	nextPtr=NULL;
}

char NODE::get_value(){
	return data;
}

NODE* NODE::get_next(){
	return nextPtr;

}

void NODE::set_next(NODE *t){
	 nextPtr=t;

}

NODE::~NODE(){
}


#endif