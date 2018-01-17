
/**
 * CIS 22C
 * Stack.cpp
 */

#include "Stack.h"
#include <assert.h>
#include <iostream>
using namespace std;

//default constructor
Stack::Stack(){}

//destructor
Stack::~Stack(){}

//copy constructor
Stack::Stack(const Stack &S):stack(S.stack){}

//overloading operator
bool Stack::operator==(const Stack &S){
	return (stack==S.stack);
}

void Stack::print(){
	stack.print();
}

void Stack::push(int data)
{
    stack.add_start(data);
}

void Stack::pop(){
	stack.remove_start();
}

int Stack::get_top(){
	return stack.get_start();
}

int Stack::get_size(){
	return stack.get_length();
}
