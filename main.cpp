#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int bin_length, bin_height;

struct Rectangle {
	int length;
	int width;
	Rectangle(int a, int b) {
		length = max(a,b);
		width = min(a,b);
	}
	// select long and big rectangle first
	bool operator < (const Rectangle& x) const {
		return length != x.length ? length > x.length : width > x.width;
	}
};

struct Level {
	vector<Rectangle> l;
	int remaining_length;
	Level() {
		l.clear();
		remaining_length = bin_height;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	cin >> bin_length >> bin_height;
	int num;
	cin >> num;
	vector<Rectangle> all_rect;
	all_rect.reserve(num);
	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		all_rect.push_back(Rectangle(a,b));
	}
	sort(all_rect.begin(), all_rect.end());
	//for (int i = 0; i < num; i++) {
	//	cout << all_rect[i].length << " " << all_rect[i].width << endl;
	//}
	vector<Level> levels;
	// put first item to start iteration
	levels.push_back(Level());
	levels.back().l.push_back(all_rect[0]);
	levels.back().remaining_length -= all_rect[0].width;

	// first fit
	for (int i = 1; i < num; i++) {
		bool found = false;
		for (int j = 0; j < levels.size(); j++) {
			if (all_rect[i].width < levels[j].remaining_length) {
				levels[j].l.push_back(all_rect[i]);
				levels[j].remaining_length -= all_rect[i].width;
				found = true;
				break;
			}
		}
		if (found == false) {
			levels.push_back(Level());
			levels.back().l.push_back(all_rect[i]);
			levels.back().remaining_length -= all_rect[i].width;
		}
	}
	
	int start_point_x = 0;
	int start_point_y = 0;


	//cout << levels.size() << endl;
	freopen("data.txt", "w", stdout);
	cout << num << endl;
	for (int i = 0; i < levels.size(); i++) {
		for (int j = 0; j < levels[i].l.size(); j++) {
			Rectangle temp = levels[i].l[j];
			cout << start_point_x << " " << start_point_y << " " << temp.length << " " << temp.width << endl;
			start_point_y += temp.width;
		}
		start_point_x += levels[i].l[0].length;
		start_point_y = 0;
	}
	
	return 0;
}
