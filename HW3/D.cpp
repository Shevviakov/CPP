/*
	Очень быстрая сортировка
Имеется рекуррентная последовательность A1, A2, ... , AN, строящаяся по следующему правилу:
A1=K
A{i+1}=(Ai * M)%(2^32 - 1)%L
Требуется найти сумму всех нечётных по порядку элементов в отсортированной по неубыванию последовательности по модулю L.
Для входных данных
5 7 13 100
последовательность будет такой:
{7, 7*13%100 = 91, 91*13%100 = 83, 83*13%100 = 79, 79*13%100 = 27}, то есть, {10, 91, 83, 79, 27}
Отсортированная последовательность {7, 27, 79, 83, 91}
Сумма элементов на нечётных местах = (10 + 79 + 91)%100 = 77
	Input format
N K M L
5000000 ≤ N ≤ 50000000, 0 ≤ K, L, M ≤ 2^32 - 1
	Output format
RESULT
	Examples
Input		Output
5 7 13 100
		77
	Notes
Для представления элементов последовательности используйте тип unsigned int. Для получения элемента последовательности — формулу a[i+1] = (unsigned int)((a[i]*(unsigned long long)M )&0xFFFFFFFFU)
*/


#include <iostream>
//#include <bitset>
using namespace std;


int main () {
	
	unsigned long K, L, M, N;
	unsigned long sum = 0;
	
	cin >> N >> K >> M >> L;
	
	unsigned int a[N], b[N], count1[2][256] = {}, count2[2][256] = {}, count3[2][256] = {}, count4[2][256] = {};

	a[0] = K;
	for (long i=1; i<N; i++) {
		a[i] = (unsigned int)((a[i-1]*(unsigned long long)M )&0xFFFFFFFFU);
		a[i] = a[i]%L;
	}
	
	
/*	
	for (long i=0; i<N; i++) {
		bitset<32> bst (a[i]);
		cout << bst << ' '<< a[i] << "\n";
	}
	
	cout << "\n\n\n";
*/

//++++ 8-0 bits sorting ++++	
	for (long i=0; i<N; i++) {
//		cout << a[i] << ' ' << (a[i] & 0x000000FFU) << "\n";
		count1[0][a[i] & 0x000000FFU]++;
		count2[0][(a[i] >> 8) & 0x000000FFU]++;
		count3[0][(a[i] >> 16) & 0x000000FFU]++;
		count4[0][(a[i] >> 24)]++;
	}
	
	for (int i=1; i<256; i++) {
		count1[1][i] = count1[0][i-1] + count1[1][i-1];
		count2[1][i] = count2[0][i-1] + count2[1][i-1];
		count3[1][i] = count3[0][i-1] + count3[1][i-1];
		count4[1][i] = count4[0][i-1] + count4[1][i-1];
	}
//	for (int i=0; i<256; i++) if (count[0][i] || count[0][i-1]) cout << i << ' ' << count[0][i] << ' ' << count[1][i] << "\n";
	
 
	for (long i=0; i<N; i++) {
		b[count1[1][a[i] & 0x000000FFU]++] = a[i];
	}

	for (long i=0; i<N; i++) {
		a[count2[1][(b[i] >> 8) & 0x000000FFU]++] = b[i];
	}

	for (long i=0; i<N; i++) {
		b[count3[1][(a[i] >> 16) & 0x000000FFU]++] = a[i];
	}

	for (long i=0; i<N; i++) {
		if ((count4[1][b[i] >> 24]++) % 2 == 0) sum+= b[i];
//		a[count4[1][b[i] >> 24]++] = b[i];
	}

/*
	for (long i=0; i<N; i+=2) {
//		count[(a[i] >> 16) & 0x000000FFU]++;
//		bitset<32> bst (a[i]);
//i		cout << bst << ' '<< (a[i]) << "\n";
		sum+=a[i];
	}
*/	
	sum = sum%L;
	cout << sum;
	return 0;
}
