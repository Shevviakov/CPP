/*
	Спелеологи
Гора состоит из N пещер и M тоннелей между ними. Каждый тоннель имеет определённую длину.
Спелеологи, исследующие гору, находятся в пещере S, выход наружу находится в пещере F.
Продвигаясь по пещерам, спелеологи оставили K не очень хорошо затушенных костров, и вот в какой-то момент времени произошёл толчок и все костры стали дымить. Дым распространяется по всем тоннелям, ведущим от пещеры, одновременно со скоростью 1 метр в секунду. Как только дым доходит до какой-либо пещеры, он начинает распространяться по всем тоннелям, ведущим из неё. Сами спелеологи, почувствовав толчок, стали пробираться к выходу со скоростью 1 метр в секунду. Вопрос состоит в том, успеют ли они добраться до выхода прежде чем столкнутся с дымом.
	Input format
N M K f1 f2 ... fk
s1 d1 w1
s2 d2 w2
...
sn dn wn
S F
Первая строка содержит количество пещер N, количество тоннелей M и количество костров K.
Вторая строка содержит номера пещер с кострами
Далее следует N строк, содержащих описание i-го тоннеля — si и di, соответственно, начало и конец тоннеля, wi — длина тоннеля в метрах. Тоннели двунаправленные.
Последняя строка — числа S, номер пещеры со спелеологами и F — номер пещеры, являющейся выходом.
3≤N≤10000
3≤M≤100000
1≤K≤100
1≤wi≤10000
	Output format
Result — число секунд, требующихся спелеологам для выхода из пещеры или -1, если дым успевает их настичь или они не могут выйти из пещеры совсем.
	Examples
Input	Output
6 5 1
6
1 2 20
2 3 2
3 4 1
2 5 1
5 6 3
4 1
	23
6 6 2
4 1
4 1 1
6 5 1
2 4 1
1 5 2
5 6 2
5 1 2
3 6
	-1
*/