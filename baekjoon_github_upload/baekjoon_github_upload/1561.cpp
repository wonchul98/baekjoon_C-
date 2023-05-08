#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> ins;
int N, M ,sum = 0; //N: 아이들 수, M: 놀이 기구 수
bool print = false;
int rmd_sum(int a) {
	int rmd = 0;
	
	for (int i = 0; i < ins.size(); i++) {
		rmd += a / ins[i];
	}
	if (print) cout << "remainder of " << a << ": " << rmd + M<< endl;
	return rmd + M;
}

int get_rst(int floor) {
	vector<int> Q;
	for (int i = 0; i < ins.size(); i++) {
		if (floor % ins[i] == 0) {
			Q.push_back(i);
		}
	}
	
	return Q[Q.size() - rmd_sum(floor) + N - 1];
}

int main() {
	freopen("input/1561_input.txt", "r", stdin);
	cin >> N >> M;
	int num;
	for (int i = 0; i < M; i++) {
		cin >> num;
		sum += num;
		ins.push_back(num);
	}
	if (N <= M) { //case 1
		cout << N << endl;
		return 0;
	}
	else { // case 2
		int left = 1, right = 1;
		while (rmd_sum(right) <= N) {
			if(print)cout << "right: " << right << endl;
			right *= 2;
		}
		if (print)cout << "final right: " << right << endl;
		int floor = 0;
		while (left < right) {
			if (rmd_sum(left) == N) {
				floor = left;
				break;
			}
			else if (rmd_sum(right) == N){
				floor = right;
				break;
			}
			int mid = (left + right) / 2;
			if (print)cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
			if (rmd_sum(mid) == N) {
				floor = mid;
				break;
			}
			if (rmd_sum(mid) <= N) left = mid;
			else right = mid;
		}
		if (print)cout << "floor: " << floor << endl;
		while (rmd_sum(floor-1)==N) {
			floor--;
		}
		cout << get_rst(floor) + 1<< endl;
 	}
	return 0;
}