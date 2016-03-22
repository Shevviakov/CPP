/*
	Последовательность
Имеется последовательность строк
1. a
2. baa
3. cbaabaa
4. dcbaabaacbaabaa
5 ...
Каждая последующая строка формируется из повторения предыдущей строки и дописывания в начала очередной буквы по алфавиту.
Найти подстроку от K - й буквы в N - й строке до L - й.
	Input format
N K L
1≤N≤26
K,L≤1,K≤L и они принадлежат строке.
Нумерация символов строки с единицы.
	Output format
Искомая подстрока.
	Examples
Input	Output
3 2 4
	baa
*/

#include <iostream>

using namespace std;

void func (char n, long long &pos, long long K, long long L) {
	if (++pos>L) return; 
	if (pos >= K && pos <= L) {cout << n;}
	if (n-'a' > 0) {func (n-1, pos, K, L);}
	if (++pos>L) return;
	if (pos >= K && pos <= L) {cout << n;}
	if (n-'a' > 0) {func (n-1, pos, K, L);}
}

int main() {
	int N;
	long long K, L;
	long long pos = 1;

	cin >> N >> K >> L;
	
	if (K==1) cout << (char)('a'+N-1);
	func ('a'+N-2, pos, K, L);	
	
	return 0;	
}
