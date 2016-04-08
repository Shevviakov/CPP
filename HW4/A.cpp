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


using namespace std;

int main () {
	
	int N, K;
	long long M=0, left=0, right=0;
	
	cin >> N >> K;
	
	int wires[N];
	
	for (int i=0; i<N; i++) {
		cin >> wires[i];
		right+=wires[i];
	}
	
	for (int i=0; i<N; i++) cout << wires[i] << ' ';
	cout << right;
	return 0;
}
