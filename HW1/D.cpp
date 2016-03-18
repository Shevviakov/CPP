/*
	Решение Диофантовых уравнений
В этой задаче необходимо реализовать расширенный алгоритм Евклида, который решает диофантовы уравнения: уравнения в целых числах вида ax + by = n, где a,b,n – целые входные параметры.
Формат входных данных
a b n
	Формат результата
No, если уравнение неразрешимо
x0 y0 – такое решение уравнения, что x0 минимальное возможное положительное целое число.
	Примеры
Входные данные	Результат работы
3 4 5
	3 -1
2 4 5
	No
*/


#include <iostream>

using namespace std;

void eEuclid (int*arr) { //[0] = x; [1] = y; [2] = d
	int a, b;

	if (arr[0] >= arr[1]) {a = arr[0]; b = arr[1];}
	else {b = arr[0]; a = arr[1];}
	
	if (b == 0) {arr[0] = 1; arr[1] = 0; arr[2] = a; return;}
	
	int arr2[3];
	arr2[0] = b;
	arr2[1] = a%b;
	
	eEuclid (arr2);
	
	arr[0] = arr2[1];
	arr[1] = arr2[0] - arr2[1]*a/b;
	arr[2] = arr2[2];
	return;		
}


int main() {
	
	int a, b, n;

	cin >> a;
	cin >> b;
	cin >> n;
	
	int arr[3];

	arr[0] = a;
	arr[1] = b;

	eEuclid(arr);
	
	int c = arr[2];
	cout << (arr[0] = a/c) << "\n";
	cout << (arr[1] = b/c) << "\n";
	
	eEuclid(arr);
	
	
	cout << arr[0] << "\n";
	cout << arr[1] << "\n";
//	cout << arr[2] << "\n";
	
	return 0;
}
