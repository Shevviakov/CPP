#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	long long N, t, old;
	
	cin >> N;
	
	t = 1;
	while (1) {
		old = t;
		t = (N/t + t) / 2;
		cout << t << "\n";
		if (old == t) break;
	}

	return 0;
}
