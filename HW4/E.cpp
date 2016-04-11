/*
	Сотовая связь
В городе имеется несколько операторов мобильной связи, каждый из которых располагает несколькими вышками. У каждой вышки свои координаты и своя зона уверенного приёма. Абонент находится в точке с заданными координатами. Требуется определить количество операторов мобильной связи в городе и определить, для скольких вышек у абонента, находящегося в данной точке, имеется устойчивая связь.
В первой строке входного файла содержится целое число N(1 ≤ N ≤ 10000 — количество базовых станций.
Далее следует N пар строк, в первой строке содержится имя оператора, во второй — два целых числа с координатами станции Xi и Yi ( - 10000 ≤ Xi, YI ≤ 10000), за которыми следует целочисленный радиус уверенного приёма Ri(1 ≤ Ri ≤ 10000).
В последней строке — координаты абонента Xa и Ya.
Названия операторов — строки, не содержащие пробелов и состоящие из букв латинского алфавита и цифр.
В первой строке выходного файла нужно вывести количество операторов K, K ≤ 1000.
В следующих K строках требуется вывести название оператора ( в порядке их появления во входном файле) и через пробел количество базовых станций, доступных для абонента.
	Input format
N
name1
X1 Y1 R1
...
namen
Xn Yn Zn
Xa Ya
	Output format
K
name1 c1
name2 c2
...
nameK cK
	Examples
Input		Output
8
Merizon
-7 -5 2
K-Mobile
-3 -5 4
BTT
-2 -4 2
WarpLine
-1 -4 5
Telephone
-4 -6 2
BTT
-1 -6 4
Near2
-6 -2 4
Merizon
7 7 6
3 5
		6
		Merizon 1
		K-Mobile 0
		BTT 0
		WarpLine 0
		Telephone 0
		Near2 0
5
op2
0 3 1
op1
-6 9 0
op2
-7 6 3
op1
-9 1 2
op3
-2 -1 3
4 3
		3
		op2 0
		op1 0
		op3 0
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class oper {
	public:
		string name;
		int stations;
};

class baseStation {
	public:
	string oper;
	long X, Y, R;
	
	void set (string op, long cX, long cY, long cR) {
		oper = op;
		X = cX;
		Y = cY;
		R = cR;
	}
};

void addStation (vector <oper> &opers, baseStation bst, long clientX, long clientY) {
	for (int i=0; i<opers.size(); i++) {
		if (bst.oper == opers[i].name) {
			if ((clientX-bst.X)*(clientX-bst.X)+(clientY-bst.Y)*(clientY-bst.Y) <= bst.R*bst.R) {opers[i].stations++; return;}

		cout << "(clientX  clientY) = " << clientX << ' ' << clientY << endl;
		cout << "(bst.X bst.Y) = " << bst.X << ' ' << bst.Y << endl;
		cout << "(clientX-bst.X) = " << (clientX-bst.X) << endl;
		cout << "(clientY-bst.Y) = " << (clientY-bst.Y) << endl;
		
	}
	}
	oper op;
	op.name = bst.oper;
	op.stations = 0;
	if ((clientX-bst.X)*(clientX-bst.X)+(clientY-bst.Y)*(clientY-bst.Y) <= bst.R*bst.R) {op.stations++;}
	opers.push_back(op);
}	

int main () {

	string str;
	vector <baseStation> arr;
	vector <oper> opers;
	baseStation bst;

	int N;
	long X, Y, R;
	long clientX, clientY;
	
	cin >> N;

	
	for (int i=0; i<N; i++) {
		cin >> str;
		cin >> X >> Y >> R;
		bst.set (str, X, Y, R);
		arr.push_back(bst);
	}

	cin >> clientX >> clientY;
/*	
	for (int i=0; i<N; i++) {
		addStation (opers, arr[i], clientX, clientY);
	}	
	
	cout << opers.size() << endl;
	for (int i=0; i<opers.size(); i++) cout << opers[i].name << ' ' << opers[i].stations << endl; 
*/	
	return 0;
}

