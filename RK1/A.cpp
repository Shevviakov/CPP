/*
	Максимальное произведение кратное 15
На вход подаётся число N ≤ 1000000, далее следует N строк, в каждой из которых записано число от 0 до 10000000. Необходимо найти максимальное произведение чисел, записанных в двух разных строках, которое делится на 15.
	Input format
N
x1
x2
x3
...
xn
	Output format
MAX
*/

#include <iostream>
#include <stdio.h>

using namespace std;


int main () {
	long long N, num;
	long long max3 = 0, max5 = 0, max15 = 0, max = 0;
	long long ans = 0;
	
	cin >> N;

//	cout << N << "\n\n";

	for (int i=0; i<N; i++) {
		scanf("%lld", &num);
//		cout << num << ' ';
		if (num%3 == 0) {
 			if (num%5 == 0) { //delitsya na 15
//				cout << "15\n";
				if (num>max15) {
					if (max15>max) {max = max15;}
					max15 = num;
					continue;
				}
				if (num>max) {max=num; continue;}
			}
			else {//delitsya na 3
//				cout << "3\n";
				if (num>max3) {max3 = num;}
			}
		}
		else {
			if (num%5 == 0) { //delitsya na 5
//				cout << "5\n";
				if (num>max5) {max5 = num;}
			}
			else { //ne delitsya ni na 3, ni na 5
//				cout << "nope\n";
				if (num>max) {max = num;}
			}
		}
	}

//	cout << "max3 " << max3 << "\n";
//	cout << "max5 " << max5 << "\n";
//	cout << "max 15 " << max15 << "\n";
//	cout << "max " << max << "\n";

	if (max3*max5>ans) {ans = max3*max5;}
	if (max15*max3>ans) {ans = max15*max3 ;}
	if (max15*max5>ans) {ans = max15*max5;}
	if (max15*max>ans) {ans = max15*max;}
	
	cout << ans;

	return 0;
}
