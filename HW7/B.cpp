/*
	Дороги
Имеются N городов. Каждые два города соединены не более, чем одной двунаправленной дорогой, всего дорог M. Имеется C компаний, пронумерованных от 1 до C. Каждая из дорог либо принадлежит одной из компаний, либо принадлежит государству, тогда владелец равен нулю.
Два города являются столицами — северной CN и южной CS. По законам страны на ЛЮБОМ из возможных путей между столицами должна иметься дорога, принадлежащая КАЖДОЙ из компаний.
Нужно вывести список всех компаний, для которых между столицами существует путь, на котором у этой компании нет ни одной дороги.
	Input format
N M C
a1 b1 c1
a2 b2 c2
...
aN bN cN
CN CS
	Output format
K
c1 c2 ... cK
	Examples
Input	Output
4 5 2
1 2 1
1 3 2
2 4 2
3 4 1
2 3 0
1 4
	2
	1 2 
4 4 2
1 2 1
1 3 2
2 4 2
3 4 1
1 4
	0
	Notes
Это — задача из заочного тура олимпиады по информатике.
https://olympiads.ru/zaoch/2015-16/zaoch/statements-20151126.pdf
*/
