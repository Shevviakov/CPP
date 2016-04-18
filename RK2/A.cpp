/*
	Поиск числа в таблице
На вход задачи подаётся число N, числовой двумерный массив a размера N × N и число x. Массив a обладает следующим свойством: a[i, j] ≤ a[i + 1, j], a[i, j] ≤ a[i, j + 1]. Необходимо проверить, встречается ли элемент x в массиве a.
	Input format
N
a[N, 1] a[N, 2] ... a[N, N]
a[N - 1, 1] a[N - 1, 2] ... a[N - 1, N]
...
a[1, 1] a[1, 2] ... a[1, N]
	Output format
yes/no
	Examples
Input	Output
2
0 2
0 1
1
	yes
	Notes
За переборное решение 0 баллов.
*/

#include <iostream>

using namespace std;

int main () {
	
	int N, x;
	cin >> N;
	
	int a[N][N];
	
	for (int i=N-1; i>=0; i--)
		for (int j=0; j<N; j++) {
			cin >> a[i][j];
		}
	
	cin >> x;
	
	
/*
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
*/

	int i=0, j=0;
	
	if (a[0][0] == x) {cout << "yes"; return 0;}
	if (a[0][0] > x) {cout << "no"; return 0;}
	if (a[N-1][N-1] < x) {cout << "no"; return 0;} 
	while (j<N-1 && a[0][j+1] <= x) j++;
	
	while (j>=0) {
		if (a[i][j] == x) {cout << "yes"; return 0;}
		if (i==N-1 || a[i+1][j] > x) {j--; continue;}
		if (a[i+1][j] <= x) {i++; continue;}
	}
	
	cout << "no";
	
	return 0;
}
