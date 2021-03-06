/*
	Лексикографическая сортировка
Натуральные числа от 1 до N упорядочены лексикографически. Например, для N=25 результат этого упорядочения будет таким: 1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 21, 22, 23, 24, 25, 3, 4, 5, 6, 7, 8, 9.
Требуется написать программу, которая определит, на каком месте оказалось число K.
	Input format
Вход содержит два натуральных числа N и K, записанных через пробел (1≤K≤N≤3·10^7).
	Output format
Выход должен содержать одно натуральное число – номер места, на котором оказалось число K.
	Examples
Input	Output
25 11
	3
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main () {
	long N, K, pos = 0;
	stringstream ss;
	string numstr, Kstr;
	
	cin >> N >> K;
	
	ss << K;
	ss >> Kstr;
	
	for (long i=1; i<=N; i++) {
		stringstream ss;
		ss << i;
		ss >> numstr;
		if (Kstr.compare(numstr) >= 0) pos++;
	}
	
	cout << pos;
	
	return 0;
}
