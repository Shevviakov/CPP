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
#include <sstream>

using namespace std;

int main () {
	
	vector <string> vec, stck;
	string s;
	
	while (cin >> s) {
		vec.push_back(s);
	}
	
	for (int i=0; i<vec.size(); i++) {
		
		stck.push_back(vec[i]);
		
		//calculating
		while (stck.size()>=3 && atoi(stck[stck.size()-1].c_str()) && atoi(stck[stck.size()-2].c_str())) {
			int b = atoi(stck.back().c_str());
			stck.pop_back();
			
			int a = atoi(stck.back().c_str());
			stck.pop_back();
			
			string op = stck.back();
			stck.pop_back();
			
			int ans;
			
			if (op == "+") ans = a+b;
			if (op == "-") ans = a-b;
			if (op == "/") ans = a/b;
			if (op == "*") ans = a*b;
			
			stringstream ss;
			ss << ans;
			stck.push_back(ss.str());
		}	
	}
		
	cout << stck.back();
	return 0;
}
