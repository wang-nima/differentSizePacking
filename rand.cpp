#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
	srand (time(NULL));
	freopen("input.txt", "w", stdout);
	cout << 250 << " " << 90 << endl;
	cout << 30 << endl;
	for (int i = 0; i < 30; i++) {
		int length, height;
		length = rand() % 81 + 10;		// 10 ~ 90
		height = rand() % 81 + 10;		// 10 ~ 90
		cout << length << " " << height << endl;
	}
	return 0;
}

