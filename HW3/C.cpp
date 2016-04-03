/*
	Ближайшие точки
На прямой расположено N точек с целочисленными координатами. Требуется найти пару точек, расстояние между которыми минимально.
	Input format
Первая строка входа содержит количество точек N(2 ≤ N ≤ 106). Вторая строка содержит N различных целых чисел Xi — координаты заданных точек числовой прямой. Числа в строке разделены пробелом. Значения всех координат Xii не превосходят 109 по абсолютной величине.
	Output format
В первой строке выхода необходимо вывести минимальное расстояние между двумя точками, заданными во входном файле. Во второй строке выходного файла необходимо вывести номера точек, которым соответствует найденное расстояние. Точки нумеруются натуральными числами от 1 до n в том порядке, в котором они заданы во входном файле. Если ответов несколько, выведите тот из них, в котором точки расположены левее других на числовой прямой. Первым выводится номер левой точки, далее через пробел – номер правой точки.

ВЫВЕСТИ НОМЕРА ТОЧЕК В ПОРЯДКЕ ВОЗРАСТАНИЯ


	Examples
Input	Output
5
	1
1 6 4 9 2
	1 5
*/


#include <iostream>
#include <vector>

using namespace std;

void qsort (long arr[], long left, long right) {
	if (right == left) return;
	long M = arr[right];
	long swap, r = right-1, l = left;
	if (r==l) {
		if (arr[r]>arr[r+1]) {
			swap = arr[r];
			arr[r] = arr[r+1];
			arr[r+1] = swap;
		}
		return;
	}
	while (l < r) {
		while (l<r && arr[l] <= M) l++;
		while (l<r && arr[r] >= M) r--;
		if (l<r) {
			swap = arr[l];
			arr[l] = arr[r];
			arr[r] = swap;
		}
	}
	if (arr[l] >= arr[right]) {
		swap = arr[l];
		arr[l] = arr[right];
		arr[right] = swap;
	}
	qsort(arr, left, l);
	qsort(arr, l, right);
}

int main () {
	
	long N;
	cin >> N;
	
	long arr[N], sorted_arr[N];
	
	for (long i=0; i<N; i++) {
		cin >> arr[i];
		sorted_arr[i] = arr[i];
	}
	qsort(sorted_arr, 0, N-1);

	long distindex, dist = sorted_arr[N-1] - sorted_arr[0];
	for (long i=1; i<N; i++) {
		if (sorted_arr[i] - sorted_arr[i-1] < dist) {
			dist = sorted_arr[i] - sorted_arr[i-1];
			distindex = i;
		}
	}

	cout << dist << "\n";
	for (long i=0; i<N; i++) {
		if (arr[i] == sorted_arr[distindex] || arr[i] == sorted_arr[distindex-1]) cout << (i+1) << ' ';
	}
	
	return 0;
}
