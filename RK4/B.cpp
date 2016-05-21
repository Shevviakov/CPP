/*
	Лошади
В скачках участвует 3 < N < 500 лошадей, пронумерованных, начиная с 1. Паниковский хочет знать, выиграет ли в забеге лошадь под номером 1 <  = M <  = N. Известно, что у всех лошадей различные скорости. Паниковский выяснил взаимное соотношение нескольких пар.
Первая строка содержит число лошадей и выбранную лошадь. Каждая последующая строка, кроме последней, содержит пару чисел P и Q, которая означает, что лошадь P быстрее лошади Q. Последняя строка содержит ограничитель входных данных 0. Все пары различны и корректны.
Требуется вывести Yes, если полученной информации достаточно для того, чтобы точно определить, может ли выиграть выбранная лошадь или No, если не может или приведённой информации недостаточно.
	Input format
N M
P1 Q1
P2 Q2
...
PN QN
0
	Output format
Yes | No
	Examples
Input	Output
3 1
1 2
1 3
0
	Yes
3 2
2 3
0
	No
4 2
3 1
2 3
0
	No
	Notes
Во втором и третьем примерах не гарантируется, что выиграет выбранная лошадь.
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs (int e, int N, vector<vector<int> > &G, int col[]) {
	if (col[e]) return;
	col[e] = 1;
	for (int i=1; i<N+1; i++) {
		if (G[e][i]) dfs(i, N, G, col);
	}
}


int main () {
	
	int N, M;
	
	cin >> N >> M;
	
	vector <vector<int> >  G(N+1, vector<int>(N+1));
	
	//initializing th graph matrix;
	for (int i=0; i<N+1; i++)
		for (int j=0; j<N+1; j++)
			G[i][j] = 0;

	int  p, q;
	cin >> p;
	while (p) {
		cin >> q;
		G[p][q] = G[q][p] = 1;
		cin >> p;
	}
	

	int col[N+1];
	for (int i=0; i<N+1; i++) col[i] = 0;
	
	dfs(1, N, G, col);
	
	for (int i=1; i<N+1; i++) if (!col[i]) {cout << "No"; return 0;}
	
	cout << "Yes";
	
	return 0;
}
