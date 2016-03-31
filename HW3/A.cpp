/*
	Подсчёт частот
На вход подаётся строка, состоящая из букв A-Z. Необходимо вывести все буквы, которые встречаются в строке в порядке убывания частот вместе с частотой. В случае равенства частот первой должна идти буква, которая встречается в алфавите раньше.
	Input format
Строка из букв A-Z
	Output format
L1 N1
L2 N2
...
Lk Nk
где Li - буква, а Ni — число вхождений буквы в строку
*/

#include <iostream>

using namespace std;

int main () {
	
	long long count[26] = {};
	char c;

	while (cin >> c) {
		count[c-'A']++;
	}
	
	long long buf, arrsort[26];
	
	for (int i=0; i<26; i++) {
		arrsort[i] = count[i];
	}

	bool resort;
	do {
		resort = false;
		for (int i=0; i<25; i++) {
			if (arrsort[i+1] > arrsort[i]) {
				resort = true;
				buf = arrsort[i];
				arrsort[i] = arrsort[i+1];
				arrsort[i+1] = buf;
			}
		}
	} while (resort);
	
	int j = -1;

	for (int i=0; i<26 && arrsort[i]; i++) {
		if (i && arrsort[i-1] != arrsort[i]) j=-1;
		while (count[++j] != arrsort[i]);
		cout << (char)('A'+j) << ' ' << count[j] << "\n";
	}
	
	return 0;
}
