/*
	Кузнечик
Имеется лестница, в которой N ступенек. Кузнечик находится перед лестницей. Он прыгает только вверх и способен прыгнуть вверх не более, чем на M ступенек.
Определить, сколькими способами кузнечик может допрыгать да самой верхней ступеньки.
1≤M≤N≤30
Для N=5 и M=2 имеется 8 маршрутов: (1,2,3,4,5)
(1,2,3,5)
(1,2,4,5)
(1,3,4,5)
(1,3,5)
(2,3,4,5)
(2,3,5)
(2,4,5)
	Input format
N M - количество ступенек в лестнице и наибольший размер прыжка кузнечика.
	Output format
R - число способов, которыми кузнечик может допрыгать до самой верхней ступеньки.
	Examples
Input	Output
5 2
	8
*/

#include <iostream>

using namespace std;

int main () {
	
	int N, M;
	cin >> N >> M;
	
	int steps[N+1];
	
	for (int i=0; i<N+1; i++) steps[i] = 0;
	steps[0] = 1;
	
	for (int i=0; i<N+1; i++)
		for (int j=1; j<=M; j++) {
			if (i+j > N) break;
			steps[i+j] += steps[i];
		}
	
	cout << steps[N];
	return 0;
}
