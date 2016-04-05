#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	node *left, *right;
	char op;
	double val;
	node (char myop) {
		left = right = NULL;
		op = myop;
		val = 0;
	}
	node (double myval) {
		left = right = NULL;
		op = '@';
		val = myval;
	}
	~node () {
		printf ("destruct '%c'\n", op);
	}
};

double evaluate (node *elem) {
	if (elem -> op == '@') return elem -> val;
	
	double left, right;
	left = evaluate (elem -> left);
	right = evaluate (elem -> right);
	
	switch (elem -> op) {
		case '+' : return (left + right);
		case '-' : return (left - right);
		case '*' : return (left * right);
		case '/' : return (left / right);
	}
}

void destroy () {
	
}


int main () {	
	node *root = new node('+');
	root -> left = new node (5.0);
	root -> right = new node ('-');
	root -> right -> left = new node(15.0);
	node* r1 = root -> right -> right = new node ('*');
	r1 -> left = new node (4.0);
	r1 -> right = new node (5.0);
	
	cout << evaluate(root);
	
	return 0;
}
