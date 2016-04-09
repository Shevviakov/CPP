/*
	Провода
На складе есть провода различной целочисленной длины. Их можно разрезать на части. Необходимо получить K кусочков одинаковой целочисленной и как можно большей длины. Найти максимальную длину M.
	Input format
В первой строке — количество проводов на складе N и необходимое количество кусочков K. В следующих K строках — длины проводов.
1 ≤ N ≤ 10000
1 ≤ K ≤ 10000
	Output format
M — максимальная длина, на которую можно разрезать все провода так, чтобы получилось не менее K кусочков.
	Examples
Input	Output
5 7
15
12
5
13
6
	6
*/

#include <iostream>
#include <algorithm>

using namespace std;

void wireLength (int wires[], int N, int K, long long left, long long right, long long &M) {
	int center = (right-left)/2 + left;
	if (center == left) return;
	int count = 0;
	
	for (int i=0; i<N && wires[i]>=center; i++) count += wires[i]/center;
	
	if (count >= K) {
		if (center > M) M = center;
		wireLength(wires, N, K, center, right, M);
	} else {
		wireLength(wires, N, K, left, center, M);
	}
}

int main () {
	
	int N, K;
	long long M=0, left=0, right=0;
	
	cin >> N >> K;
	
	int wires[N];
	
	for (int i=0; i<N; i++) {
		cin >> wires[i];
		right+=wires[i];
	}
	
	sort(wires, wires+N);
	reverse(wires, wires+N);
	
	wireLength(wires, N, K, left, right, M);
	
//	for (int i=0; i<N; i++) cout << wires[i] << ' ';
	cout << M;
	return 0;
}
