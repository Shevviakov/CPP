/*
	Слияние
На вход подаётся число N, равное размерам двух неубывающих последовательностей.
Далее следуют N элементов первой последовательности и N элементов второй последовательности.
Требуется вывести последние девять цифр суммы элементов последовательности, которая получилась бы из всех элементов первой и второй последовательностей, стоящих на нечётных местах.
	Input format
N
A1
A2
...
AN
B1
B2
...
BN
	Output format
Result
	Examples
Input	Output
5
1
1
3
7
9
3
7
8
9
10
	28
*/

#include <iostream>
#include <vector>

using namespace std;

int main () {
	vector <int> arr;
	int N, num, ans = 0, iter = 0;

	cin >> N;
	
	for (int i=0; i<N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	
	for (int i=0; i<N; i++) {
		cin >> num;
		while (iter < N && arr[iter] <= num) {
			if ((iter+i+1)%2) {ans = (ans + arr[iter] % 1000000000) % 1000000000;}
			iter++;
		}
		if ((iter+i+1)%2) {ans = (ans + num % 1000000000) % 1000000000;} 
	}
	
	while (iter < N) {
		if ((iter+N+1)%2) {ans = (ans + arr[iter] % 1000000000) % 1000000000;}
		iter++;
	} 

	ans = ans % 1000000000;
	
	cout << ans;

	return 0;
}
