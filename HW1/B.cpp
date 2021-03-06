/*
	Второй максимум
На вход подаётся число N ≤ 1000000, далее следует N строк, в каждой из которых записано число от 0 до 10000000. Необходимо найти второй максимум среди этих чисел. Т.е. число, которое стоит вторым в отсортированной последовательности – если максимум встречается дважды, то второй максимум оказывается равным первому.

	Формат входных данных
N
a1
a2
...
aN

	Формат результата
max2
*/


#include <iostream>

using namespace std;

int main () {

	long int N, num, max1=0, max2=0;

	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> num;
		if (num >= max1) {
			max2 = max1;
			max1 = num;
			continue;
		}
		if (num >= max2) {
			max2 = num;
		}
	}

	cout << max2;

	return 0;
}
