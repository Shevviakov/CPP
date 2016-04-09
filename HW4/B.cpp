/*
	Унимодальный массив
На вход подаётся число N≤1000 и унимодальный массив a размера N: элементы a расположены таким образом, что
a[1]<a[2]
a[2]<a[3]
...
a[k-1]<a[k]>a[k+1]
a[k+1]>a[k+2]
a[k+2]>a[k+3]
...
a[N-1]>a[N].
Требуется найти a[k]
	Input format
N
a[1] a[2] ... a[N]
	Output format
a[k]
	Examples
Input			Output
10
1 3 5 7 9 10 8 6 4 2
			10
	Notes
Не смотря на то, что все тесту пройдут решение, работающее за линейное время (т.к. необходимо считать вход), вы должны продемонстрировать поиск искомого элемента за O(log N).
*/

#include <iostream>

using namespace std;

int getelem (int a[], int l, int r) {
	int m = (r-l)/2 + l;
	
	if (a[m-1] < a[m] && a[m] > a[m+1]) return a[m];
	if (a[m-1] < a[m] && a[m] < a[m+1]) getelem(a, m, r);
	if (a[m-1] > a[m] && a[m] > a[m+1]) getelem(a, l, m);
}

int main () {
	int N;
	cin >> N;
	
	int arr[N];
	
	for (int i=0; i<N; i++) cin >> arr[i];
	
	cout << getelem (arr, 0, N-1);
	
	return 0;
}

