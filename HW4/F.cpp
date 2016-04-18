/*
	Кодирование по Хаффману с кучей
Кодирование по Хаффману можно строить эффективно используя минимальную кучу — необходимо построить кучу с минимальным свойством для узлов будущего дерева, с ключами-частотами, дальше извлекать по два элемента с минимальной частотой, назначать им родителя и возвращать его в кучу.
Реализуйте данный алгоритм для построения кода Хаффмана. В качестве результата выведите стоимость кода. Стоимостью кода называется величина , где fi – частота i-го символа, а di – его глубина в дереве. Корень имеет глубину 0 (глубина равна длине кода символа).
	Input format
N – число частот
a1 a2 ... aN – N частот.
	Output format
стоимость кода
	Examples
Input	Output
4
1 3 4 2
	19
	Notes
Решения не через кучу оцениваются в половину стоимости задачи.
*/

#include <iostream>
#include <vector>

using namespace std;

struct trnode {
	int weight;
	trnode *left, *right;
	
	trnode (int prior) {
		left = right = NULL;
		weight = prior;
	}
};

struct bhnode {
	int priority;
	trnode *node;
	
};

struct binary_heap {
	bhnode *body;
	int bodysize;
	int numnodes;

	binary_heap (int maxsize) {
		body = new bhnode[maxsize + 1];
		bodysize = maxsize;
		numnodes = 0;
	}

	void swap (int a, int b) {
		bhnode temp = body[a];
		body[a] = body[b];
		body[b] = temp;
	}
	
	bhnode *fetchMin () {
		return numnodes == 0 ? 0 : body+1;
	}
	
	bhnode extractMin() {
		bhnode ans;
		if (numnodes < 1) return ans;
		ans = body[1];
		body[1] = body[numnodes--];
		heapify(1);
		return ans;
	}
	
	int insert (bhnode node) {
		if (numnodes > bodysize) {
			return -1;
		}
		body[++numnodes] = node;
		for (int i=numnodes; i>1 && body[i].priority < body[i/2].priority; i /= 2) {
			swap(i, i/2);
		}
	}
	
	void heapify (int index) {
		for (;;) {
			int left = index + index; int right = left + 1;
			int largest = index;
			if (left <= numnodes && body[left].priority < body[index].priority) largest = left;
			if (right <= numnodes && body[right].priority < body[largest].priority) largest = right;
			if (largest == index) break;
			swap(index, largest);
			index = largest;
		}
	}
};


trnode* createTree (binary_heap *heap, int N) {
	trnode *root;
	while (heap->numnodes > 1) {
		bhnode a = heap->extractMin();
		trnode *right;
		if (a.node) {right = a.node;}
		else {right = new trnode(a.priority);}

		bhnode b = heap->extractMin();
		trnode *left;
		if (b.node) {left = b.node;}
		else {left = new trnode(b.priority);}
		
		trnode *node = new trnode (a.priority+b.priority);
		node->left = left;
		node->right = right;
		
		bhnode bnode;
		bnode.priority = node->weight;
		bnode.node = node;
		
		heap->insert(bnode);
		
		root = node;
	}
	return root;
}

void printTree (trnode *root, int level) {
	for (int i=0; i<level; i++) cout << ' ';
	cout << root->weight << endl;
	if (root->left) {printTree(root->left, level+1);}
	if (root->right) {printTree(root->right, level+1);}
}
	
void countTree (trnode *root, int &count, int level) {
	if (!root->left && !root->right) {count += level*root->weight; return;}
	if (root->left) {countTree(root->left, count, level+1);}
	if (root->right) {countTree(root->right, count, level+1);}
} 

int main () {
	
	int N;
	cin >> N;
	
	binary_heap *heap = new binary_heap(N);
	
	bhnode temp;
	temp.node = NULL;
	int prior;
	
	for (int i=0; i<N; i++) {
		cin >> prior;
		temp.priority = prior;
		heap->insert(temp);
	}
	
	trnode *root = createTree(heap, N);
	
//	printTree (root, 0);
	
	int count = 0;
	countTree (root, count, 0);
	cout << count;
	
	return 0;
}
