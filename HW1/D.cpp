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

void eEuclid (long long a, long long b, long long &x, long long &y, long long &d) {
	
	if (a == 0) {
		d = b;
		x = 0;
		y = 1;
		return;
	}

	long long x1, y1;
	
	eEuclid (b%a, a, x1, y1, d);
	
	x = y1 - (b / a) * x1;
	y = x1;
	
}


int main () {
	
	long long a, b, c, x, y, d;	

	cin >> a;
	cin >> b;
	cin >> c;

	eEuclid (a, b, x, y, d);

	if (c%d != 0) {
		cout << "No";
		return 0;
	}
	
	long long x0, y0;
	
	x *= c/d;
	y *= c/d;


	if (x <= 0) {
		while (x <= 0) {
			if (b/d >= 0) {x += b/d; y -= a/d;}
			else {x -= b/d; y += a/d;}
		}
	} else {
		while (x > 0) {
			if (b/d >= 0) {x -= b/d; y += a/d;}
			else {x += b/d; y -= a/d;}
		}
			if (b/d >= 0) {x += b/d; y -= a/d;}
			else {x -= b/d; y += a/d;}
}

	cout << x << " " << y;
	
	
	return 0;
}
