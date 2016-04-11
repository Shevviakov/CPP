/*
	Обход раскрашенного дерева
На вход задачи подаётся дерево, каждый узел которого покрашен в белый, чёрный или серый цвет. Необходимо найти сколько вершин на путях от корня к листьям имеют белый цвет, при условии что до попадания в белую вершину путь прошёл через чёрную.
	Input format
Деревья закодированы скобочными выражениями. После открывающей скобки идёт цвет вершины b, w или g и если у узла есть потомки, то потомки перечислены через запятую. Длина описания дерева не превосходит 10000 символов.
	Output format
N – число искомых вершин
	Examples
Input					Output
(g,(w),(b,(w),(g,(w))),(b,(w)))
					3
(w,(b),(b,(g,(w),(b))))
					1
*/

#include <iostream>
#include <vector>

using namespace std;

class node {
	public:
	node *parent;
	char color;
	vector <node*> children;
	
	node(node* par) {
		parent = par;
	}
	
};

node* createTree (node *par) {
	node *elem;
	char ch;
	while (cin >> ch) {
		switch (ch) {
			case '(':
				elem = new node(par);
				break;
			case ',':
				elem->children.push_back(createTree(elem));
				break;
			case 'w':
				elem->color = 'w';
				break;
			case 'g':
				elem->color = 'g';
				break;
			case 'b':
				elem->color = 'b';
				break;
			case ')':
				return elem;
		}
	}
}

void printTree(node *elem) {
	cout << '(' << elem->color;
	for (int i=0; i<elem->children.size(); i++) {
		cout << ',';
		printTree(elem->children[i]);
	}
	cout << ')';
}

int countTree (node *elem, bool black) {
	int count=0;
	if (elem->color == 'b') black = true;
	if (black && elem->color == 'w') count++;
	for (int i=0; i<elem->children.size(); i++) {
		count += countTree(elem->children[i], black);
	}
	return count;
}

int main () {
	
	char ch;
	
	node *root;
	
	root = createTree(NULL);
	
	cout << countTree(root, false);
	
	return 0;
}
