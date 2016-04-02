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
#include <deque>

using namespace std;


long num_pos (int index, deque <int> digits, bool last) {
	long long count = 0;
	if (index == digits.size()) return 1;
	if (!last)
		for (int i=0; i<10; i++)
			count+= num_pos (index+1, digits, false);
	else {
		for (int i=0; i<digits[index]; i++)
			count+= num_pos (index+1, digits, false);
		count+= num_pos (index+1, digits, true);
	}		
	return count;
}

int main () {
	long N, K;
	deque <int> Ndig, Kdig;
	
	//INPUT
	cin >> N >> K;
	
	
	//K AND N NUMBERS SPELLING
	long num = N;
	Ndig.push_front(num % 10);
	while (num/10) {
		num /= 10;
		Ndig.push_front(num % 10);
	}
	
	num = K;
	Kdig.push_front(num%10);
	while (num/10) {
		num /= 10;
		Kdig.push_front(num % 10);
	}
	
	cout << num_pos(0, Ndig, false);
	
	
	
	return 0;
}
