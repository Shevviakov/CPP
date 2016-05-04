/*
	Компоненты сильной связности
На вход подаётся описание ориентированного графа — необходимо найти число его компонент сильной связности. Компонентой сильной связности называется максимальное по включению множество вершин, каждые две вершины которого достижимы друг из друга.
	Input format
N≤1000 – число вершин
N строк вида
a(i,1) a(i,2) ... a(i,N), где a(i,j)=1, если в графе есть ребро из вершины i в вершину j.
	Output format
M – число компонент сильной связности
	Examples
Input	Output
3
0 1 1
1 0 1
0 0 0
	2
*/