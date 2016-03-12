/*
	Далёкие произведения.
Имеется последовательность натуральных чисел, длина которой больше 8. Признаком конца последовательности является отрицательное число, не входящее в последовательность. Найти максимальное произведение двух элементов последовательности, отстоящих друг от друга не менее, чем на 8. Гарантируется, что ответ меньше 2000000000.
	Формат входных данных
1 2 3 4 5 6 7 8 9 10 -1
	Формат результата
20
*/


#include <iostream>
#include <queue>

using namespace std;

int main () {
	long int mult = 0;
	int num, max = 0;
	queue <int> q;

	for (int i=0; i<8; i++) {
		cin >> num;
		q.push(num);
	}

/* 	cout << q.size() << "\n";
	while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
	} */
	

	while (num>=0) {
		cin >> num;
		if (q.front() > max) max = q.front();
		q.pop();
		if (max*num > mult) mult = max*num;
		q.push(num);
	}
	
	cout << mult;
	
}
