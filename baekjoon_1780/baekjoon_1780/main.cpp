#include<iostream>
#include<cmath>
using namespace std;
int N;
int map[2187][2187];
void divide(int i, int j, int size);
int onecnt=0, monecnt=0, zcnt=0;

int main() {
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			map[i][j] = input;
		}
	}
	divide(0,0,N);
	cout << monecnt << "\n" << zcnt << "\n" << onecnt << endl;
}

void divide(int i, int j, int size) {
	//cout << "divide(" << i << "," << j << "," << size << ")" << endl;
	int start = map[i][j];
	if (size == 1) {
		if (start == -1) {
			monecnt++;
			//cout << monecnt << " " << zcnt << " " << onecnt << endl;
			return;
		}
		if (start == 1) {
			onecnt++;
			//cout << monecnt << " " << zcnt << " " << onecnt << endl;
			return;
		}
		if (start == 0) {
			zcnt++;
			//cout << monecnt << " " << zcnt << " " << onecnt << endl;
			return;
		}
	}
	bool flag = false;
	for (int k = 0; k < size; k++) {
		for (int l = 0; l < size; l++) {
			if (map[i + k][j + l] != start) {
				flag = true;
				break;
			}
		}
		if (flag)break;
	}
	if (flag) {
		for (int it = 0; it < 3; it++) {
			for (int it2 = 0; it2 < 3; it2++) {
				divide(i+it*(size/3), j+it2*(size/3), size / 3);
			}
		}
	}
	if (!flag) {
		switch (start) {
		case -1: monecnt++; break;
		case 0: zcnt++; break;
		case 1: onecnt++; break;
		}
		//cout << monecnt << " " << zcnt << " " << onecnt << endl;
		return;
	}

}