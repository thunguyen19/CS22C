/**
 * ThuMinh Nguyen
 * CIS 22C
 * Stack.cpp
 */

#include "Stack.h"
#include <assert.h>
#include <iostream>

using namespace std;

Stack::Stack() :
		top(NULL), length(0) {
}

Stack::~Stack() {
	NodePtr temp = top;
	NodePtr temp2 = top;
	while (temp != NULL) {
		temp = temp->next;
		delete temp2;
		temp2 = temp;
	}
}
Stack::Stack(const Stack &stack) :
		length(stack.length) {
	if (stack.top == NULL) {
		top = NULL;
	} else {
		top = new Node;
		top->data = stack.top->data;
		NodePtr temp;
		temp = stack.top;
		NodePtr qtemp = top; //create temporary iterator
		while (temp->next != NULL) {
			qtemp->next = new Node;
			qtemp = qtemp->next;
			temp = temp->next;
			qtemp->data = temp->data;
		}
	}
	return;
}

bool Stack::operator==(const Stack &stack) {
	if (length != stack.length)
		return false;
	NodePtr temp1 = top;
	NodePtr temp2 = stack.top;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

void Stack::pop() //remove start
{
	assert(length != 0);
	if (length == 1) {
		delete top;
		top = NULL;
		length = 0;
	} else {
		NodePtr temp = top;
		temp->next = top->next;
		top = top->next;
		delete temp;
		length--;
	}
	return;
}

void Stack::push(string data) //add start
		{
	if (length == 0) {
		top = new Node(data);
	} else {
		NodePtr N = new Node(data);
		N->next = top;
		top = N;
	}
	length++;
	return;
}

void Stack::print() {
	NodePtr temp;
	temp = top;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

string Stack::get_top() {
	assert(length != 0);
	return top->data;
}

int Stack::get_length() {
	return length;
}

