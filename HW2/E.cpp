/*
	Польский калькулятор
Для вычисления арифметических выражений на практике удобно использовать польскую запись. В ней операции записывают перед операндами, а не между как мы привыкли. Таким образом
 -  2 1 = (2 - 1)
и
 -   *   /  15  -  7  +  1 1 3  +  2  +  1 1  =  15  /  (7  -  (1  +  1))  *  3  -  (2  +  (1  +  1))
Вам необходимо написать калькулятор, который вычисляет значение арифметического выражения в префиксной записи. Размеры операндов и результаты операций не превосходят 1000.

Входные данные				Результат работы
+ 1 2
					3
- * / 15 - 7 + 1 1 3 + 2 + 1 1
					5
*/


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main () {
	
	vector <string> vec, stck;
	string s;

	while (cin >> s) {
		vec.push_back(s);
	}
	
	for (int i=0; i<vec.size(); i++) {
		if (vec[i] == "*") {stck.push_back("*"); continue;}
		if (vec[i] == "/") {stck.push_back("/"); continue;}
		if (vec[i] == "-") {stck.push_back("-"); continue;}
		if (vec[i] == "+") {stck.push_back("+"); continue;}
		
		if (!atoi(stck.back())) {stck.push_back(vec[i]); continue;}
		else {
			/*
			while (последний элемент число) {
				вытащить число и знак операции
				посчитать
			}
			*/
		}	
		//calculating		
		
	}
		
	for (int i=0; i<stck.size(); i++) cout << stck[i] << "\n";
	return 0;
}
