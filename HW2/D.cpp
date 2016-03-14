/*
	Задача D
На вход подаётся N координат точек на плоскости. Необходимо найти такой треугольник максимальной площади, что одна из его сторон лежит на оси OX и при этом треугольник не имеет общих точек с осью OY.
	Входные данные
В первой строке дано число N ≤ 106. Далее следует N строк с координатами, разделёнными пробелом. Каждая координата имеет не более двух знаков после запятой.
*/


#include <iostream>
#include <cmath>

using namespace std;


int main () {
	int N;
	cin >> N;
	
	float X[N], Y[N];
	
	for (int i=0; i<N; i++) {
		cin >> X[i];
		cin >> Y[i];
	}
	
	float rminX=0, rmaxX=0, rY=0; //right semiarea
	float lminX=0, lmaxX=0, lY=0; //left semiarea

	for (int i=0; i<N; i++) {
		if (Y[i] == 0) { //point of triangle basis
			if (X[i] > 0) {
				if (X[i] > rmaxX) {
					if (rminX == 0) rminX = X[i];
					rmaxX = X[i];
				}
				if (X[i] < rminX) rminX = X[i];
			}
			if (X[i] < 0) {
				if (X[i] < lminX) {
					if (lmaxX == 0) lmaxX = X[i];
					lminX = X[i];
				}
				if (X[i] > lmaxX) lmaxX = X[i];
			}
		
		}
		else {
			if (X[i] > 0) rY = (abs(Y[i])>rY) ? abs(Y[i]) : rY;
			if (X[i] < 0) lY = (abs(Y[i])>lY) ? abs(Y[i]) : lY;
		}		
	}

	float S = (0.5*(rmaxX-rminX)*rY > 0.5*(lmaxX-lminX)*lY) ? 0.5*(rmaxX-rminX)*rY : 0.5*(lmaxX-lminX)*lY; 
	
	cout << S;
	return 0;
}
