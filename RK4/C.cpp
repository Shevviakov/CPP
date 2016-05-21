/*
	Трипростые числа
Трипростым называется число, любые три подряд идущие цифры которого составляют простое трёхзначное число.
Требуется найти количество N-значных трипростых чисел по модулю 1000000009
4 ≤ N ≤ 10000
	Input format
N
	Output format
NumberOf3PrimeNumbersMod1000000009
	Examples
Input	Output
4
	204
*/


#include <iostream>

using namespace std;

int main () {
	bool simp[1000];
	
	for (int i=0; i<1000; i++) simp[i] = false;
	// simp initializing
simp[101] = true; simp[103] = true; simp[107] = true; simp[109] = true; simp[113] = true; simp[127] = true; simp[131] = true; simp[137] = true; simp[139] = true; simp[149] = true; simp[151] = true; simp[157] = true; simp[163] = true; simp[167] = true; simp[173] = true; simp[179] = true; simp[181] = true; simp[191] = true; simp[193] = true; simp[197] = true; simp[199] = true; simp[211] = true; simp[223] = true; simp[227] = true; simp[229] = true; simp[233] = true; simp[239] = true; simp[241] = true; simp[251] = true; simp[257] = true; simp[263] = true; simp[269] = true; simp[271] = true; simp[277] = true; simp[281] = true; simp[283] = true; simp[293] = true; simp[307] = true; simp[311] = true; simp[313] = true; simp[317] = true; simp[331] = true; simp[337] = true; simp[347] = true; simp[349] = true; simp[353] = true; simp[359] = true; simp[367] = true; simp[373] = true; simp[379] = true; simp[383] = true; simp[389] = true; simp[397] = true; simp[401] = true; simp[409] = true; simp[419] = true; simp[421] = true; simp[431] = true; simp[433] = true; simp[439] = true; simp[443] = true; simp[449] = true; simp[457] = true; simp[461] = true; simp[463] = true; simp[467] = true; simp[479] = true; simp[487] = true; simp[491] = true; simp[499] = true; simp[503] = true; simp[509] = true; simp[521] = true; simp[523] = true; simp[541] = true; simp[547] = true; simp[557] = true; simp[563] = true; simp[569] = true; simp[571] = true; simp[577] = true; simp[587] = true; simp[593] = true; simp[599] = true; simp[601] = true; simp[607] = true; simp[613] = true; simp[617] = true; simp[619] = true; simp[631] = true; simp[641] = true; simp[643] = true; simp[647] = true; simp[653] = true; simp[659] = true; simp[661] = true; simp[673] = true; simp[677] = true; simp[683] = true; simp[691] = true; simp[701] = true; simp[709] = true; simp[719] = true; simp[727] = true; simp[733] = true; simp[739] = true; simp[743] = true; simp[751] = true; simp[757] = true; simp[761] = true; simp[769] = true; simp[773] = true; simp[787] = true; simp[797] = true; simp[809] = true; simp[811] = true; simp[821] = true; simp[823] = true; simp[827] = true; simp[829] = true; simp[839] = true; simp[853] = true; simp[857] = true; simp[859] = true; simp[863] = true; simp[877] = true; simp[881] = true; simp[883] = true; simp[887] = true; simp[907] = true; simp[911] = true; simp[919] = true; simp[929] = true; simp[937] = true; simp[941] = true; simp[947] = true; simp[953] = true; simp[967] = true; simp[971] = true; simp[977] = true; simp[983] = true; simp[991] = true; simp[997] = true; 

	int N;
	cin >> N;
	
	long long a[N+1][10][10];
	
	for (int i=0; i<N+1; i++)
		for (int j=0; j<10; j++)
			for (int k=0; k<10; k++) a[i][j][k] = 0;
	
	
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			for (int k=0; k<10; k++) 
				a[3][j][i] += simp[k*100 + j*10 + i];
				
	long long temp = 0;

	for (int t=4; t<N+1; t++)
		for (int i=0; i<10; i++)
			for (int j=0; j<10; j++) {
				temp = 0;
				for (int k=1; k<10; k++)
					if (simp[k*100 + j*10 + i]) temp = (temp + a[t-1][k][j]%1000000009)%1000000009;
				a[t][j][i] = temp;
			}
		
	long long ans = 0;
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++) {
			ans = (ans + a[N][j][i]%1000000009)%1000000009;
		}
	cout << ans;
	
	return 0;
}
