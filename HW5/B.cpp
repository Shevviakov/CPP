/*
	Турнирная таблица индивидуалов
В индивидуальном первенстве по Дартс, участникам необходимо было набрать максимальное число очков за попытку. Количество попыток не ограничивалось. В протокол комиссии попадало имя участника и результат за проделанную попытку. Итоговым результатом участника считалась лучшая попытка. Если результаты совпадают, первым считается игрок показавший данный результат раньше. Помогите организаторам выстроить участников по убыванию.
	Input format
Сначало задано число участников M (1≤M≤1000), затем число попыток всех участников N (1≤N≤100000). Далее идёт N строк вида
Имя очки
Участник не может набрать больше миллиарда очков за одну попытку.
	Output format
M строк с именами участников в порядке убывания занятых мест.
	Examples
Input	Output
4 6
Ivan 2
Boris 4
Ivan 4
Boris 2
Petr 4
David 8
	David 
	Boris 
	Ivan 
	Petr 
	Notes
В случае решения задачи без структур данных, задача оценивается в половину стоимости; в случае использовании одной из двух структур данных: АВЛ-дерево/хэш и куча, задача оценивается стандартно, в случае использовании двух структур данных — куча и либо АВЛ, либо хэш — задача оценивается в удвоенную стоимость.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct resultNode {
	int time;
	int score;
	string name;
};

struct standings {
	resultNode *body;
	unordered_map <string, int> m;
	int bodysize;
	int numnodes;
	
	standings(int maxsize) {
		body = new resultNode[maxsize+1];
		bodysize = maxsize;
		numnodes = 0;
	}
	
	void swap (int a, int b) {
		resultNode temp = body[a];
		body[a] = body[b];
		body[b] = temp;
		m[body[a].name] = a;
		m[body[b].name] = b;
	}
	
	bool l_gt_r (resultNode left, resultNode right) {
		if (left.score != right.score) return left.score > right.score;
		else return left.time < right.time;
	}
	
	void insert (resultNode node) {
		if (numnodes > bodysize) return;
		body[++numnodes] = node;
		m[node.name] = numnodes;
		for (int i=numnodes; i>1 && l_gt_r(body[i], body[i/2]); i/=2) 
			swap(i, i/2);
	}
	
	void heapify (int index) {
		for (;index <= numnodes;) {
			int left = 2 * index;
			int right = left + 1;
			int largest = index;
			if (left <= numnodes && l_gt_r (body[left], body[index])) largest = left;
			if (right <= numnodes && l_gt_r (body[right], body[largest])) largest = right;
			if (largest == index) break;
			swap(index, largest);
			index = largest;
		}
	}
	
	void increasePriority(resultNode newres) {
		int index = m[newres.name];
		resultNode oldres = body[index];
		if (l_gt_r(newres, oldres)) {
			body[index] = newres;
			for (;index>1 && l_gt_r(body[index], body[index/2]); index/=2)
				swap(index, index/2);
		}
//		heapify(index);
	}
	
	resultNode extractMin () {
		resultNode ans = body[1];
		body[1] = body[numnodes--];
		heapify(1);
		return ans;
	}
	
	void newresult (string name, int score, int time) {
		resultNode node;
		node.name = name;
		node.score = score;
		node.time = time;
		
		if (m[name]) increasePriority(node);
		else insert(node);
	}
	
	void printNode(int i) {
		cout << '(' << body[i].name << ',' << body[i].score << ',' << body[i].time << ')' << endl;
	}
	void print (int i, int level) {
		if (i*2 <= numnodes) print (i*2, level+1);
		for (int i=0; i<level; i++) cout << ' ';
		printNode(i);
		if (i*2+1 <= numnodes) print (i*2+1, level+1);
	}
};


int main () {
	int M, N;
	cin >> M >> N;
	
	standings *table = new standings(M);
	
	int score;
	string name;
	for (int i=0; i<N; i++) {
		cin >> name >> score;
		table->newresult(name, score, i);
//		table->print(1, 0);
//		cout << "============\n";		
	}
	
	for (int i=0; i<M; i++) {
		resultNode node = table->extractMin();
		cout << node.name << endl;
	}
	
	return 0;
}
