/*
	Лабиринт
Имеется прямоугольный лабиринт размерами N × M. В лабиринте имеется вход, помеченный знаком @, выход, помеченный знаком #, стены, обозначенные знаком +. Свободные клетки обозначаются точкой.
Требуется определить наименьшее число ходов для того, чтобы, двигаясь по свободным клеткам, попасть из входа в выход. Движение возможно только по горизонтали и вертикали (до 4-х ходов из клетки, не находящейся на границе).
	Input format
N M
+@++
+.++
+...
+++#
	Output format
NumberOfMoves
	Examples
Input	Output
4 5
+.+++
@....
..++.
.+#..
	8
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct point {
	int x;
	int y;
	
	point() {}
	point(int x_in, int y_in) {
		x = x_in;
		y = y_in;
	}
};

struct table {
	queue <point> q;
	vector <vector<char> > body;
	vector <vector<int> > tab;
	int N, M;
	
	table (int N_in, int M_in) {
		N = N_in;
		M = M_in;
		body = vector <vector<char> > (N, vector<char>(M));
		tab = vector <vector<int> > (N, vector<int>(M));
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++) tab[i][j] = 2000000000;
	}
	
	
	void set (int x, int y, char val) {
		body[x][y] = val;
	} 
	
	char is (int x, int y) {
		if (x<0 || y<0 || x>=N || y>=M) return '+';
		return body[x][y];
	}
	
	void print_lab () {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cout << body[i][j] << ' ';
			}
			cout << endl;
		}
	}
	
	void print_tab () {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cout << tab[i][j] << ' ';
			}
			cout << endl;
		}
	}
	
	void compute (int x, int y) {
		if (is(x+1,y)!='+' && tab[x+1][y]>tab[x][y]+1){
			tab[x+1][y] = tab[x][y]+1;
			point tmp(x+1, y);
			q.push(tmp);
		}
		if (is(x-1,y)!='+' && tab[x-1][y]>tab[x][y]+1){
			tab[x-1][y] = tab[x][y]+1;
			point tmp(x-1, y);
			q.push(tmp);
		}
		if (is(x,y+1)!='+' && tab[x][y+1]>tab[x][y]+1){
			tab[x][y+1] = tab[x][y]+1;
			point tmp(x, y+1);
			q.push(tmp);
		}
		if (is(x,y-1)!='+' && tab[x][y-1]>tab[x][y]+1){
			tab[x][y-1] = tab[x][y]+1;
			point tmp(x, y-1);
			q.push(tmp);
		}
	}
	
	void solve(int x, int y) {
		point tmp(x, y);
		q.push(tmp);
		tab[x][y] = 0;	
		while(q.size()) {
			tmp = q.front();
			compute(tmp.x, tmp.y);
			q.pop();
		}
	}
		

};

int main () {
	
	int N, M;
	string str;
	
	point start;
	point exit;
	cin >> N >> M;
	
	table lab(N, M);

	for (int i=0; i<N; i++) {
		cin >> str;
		for (int j=0; j<M; j++) {
			lab.set(i, j, str[j]);
			if (str[j] == '@') {start.x = i; start.y = j;}
			if (str[j] == '#') {exit.x = i; exit.y = j;}
		}
	}
	
	lab.solve(start.x, start.y);	

	cout << lab.tab[exit.x][exit.y];
	return 0;
}
