/*
	Коды Грея
Даны все строки длины N, состоящие из нулей и единиц. Говорят, что они образуют код Грея, если они идут в таком порядке, что каждая следующая строка отличается от предыдущей ровно в одной позиции.
Пример кода Грея размерности 2:
00 01 11 10
Необходимо вывести код Грея размера N (вход задачи), начиная со строки, состоящей из одних нулей в порядке, описанном в примечании.
	Примечания
Задачу можно решать рекурсивно: для того чтобы вывести код Грея размера N необходимо сначала вывести код Грея длины N - 1, приписав к каждой строке слева 0, затем вывести код Грея размера N - 1 в обратном порядке, приписав к каждой строке слева 1.
*/

#include <iostream>
#include <string>

using namespace std;

void gray_code (int N, int direct, string s) {
	if (N == 0) {
		cout << s << "\n";
	} else {
		if (direct == 0) {
			gray_code (N-1, 0, s+'0');
			gray_code (N-1, 1, s+'1');
		} else {
			gray_code (N-1, 0, s+'1');
			gray_code (N-1, 1, s+'0');
		}
	}

}

int main () {

	int N;

	cin >> N;
	
	gray_code(N-1, 0,  "0");
	gray_code(N-1, 1, "1");
		
	return 0;
}
