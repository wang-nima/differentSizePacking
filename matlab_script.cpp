#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("data.txt","r",stdin);
	freopen("script.txt","w",stdout);
	int num;
	cin >> num;
	int x, y, length, height;
	for (int i = 0; i < num; i++) {
		cin >> x >> y >> length >> height;
		printf("rectangle('Position',[%d,%d,%d,%d]);\n", x, y, length, height);
	}
	freopen("data2.txt","r",stdin);
	freopen("script2.txt","w",stdout);
	int fig = 1;
	printf("close all;\n");
	while (cin >> num) {
		printf("figure(%d);\n", fig);
		printf("axis equal;\n");
		printf("axis([0 250 0 90]);\n");
		fig++;
		for (int i = 0; i < num; i++) {
			cin >> x >> y >> length >> height;
			printf("rectangle('Position',[%d,%d,%d,%d]);\n", x, y, length, height);
		}
	}
	return 0;
}
