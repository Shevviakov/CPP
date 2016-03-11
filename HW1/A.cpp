/*
На вход подаётся строка состоящая из букв a и b. Необходимо проверить одинаковое ли количество букв a и b в этой строке. Задачу необходимо решить, используя только стек и булевы переменные. Счётчики можно использовать только при чтении строки. Можете использовать как стек, написанный самостоятельно, так и стек из стандартной библиотеки.
Формат входных данных
Строка, состоящая из букв a и b.
Формат результата
YES, если букв a и b одинаковое количество и NO, если разное.
*/


#include <iostream>
#include <stack>

using namespace std;

int main () {
	
	stack <char> st;
	char c;
	while (cin) {
		cin.get(c);
		if (c == 'a' || c == 'b') {
			if (st.empty() || st.top() == c) st.push(c);
			else st.pop();
		}
	}

	if (st.empty()) {
		cout << "YES";
		return 0;
	}	
	
	cout << "NO";
	return 0;
}
