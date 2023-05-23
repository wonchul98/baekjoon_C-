#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

vector<int> ins;
ll N, M ,sum = 0; //N: 아이들 수, M: 놀이 기구 수
bool print = true;
ll rmd_sum(ll a) {
	ll rmd = 0;
	
	for (int i = 0; i < ins.size(); i++) {
		rmd += a / ins[i];
	}
	if (print) cout << "remainder of " << a << ": " << rmd + M<< endl;
	return rmd + M;
}

int get_rst(ll floor) {
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
		ll left = 1, right = 1;
		while (rmd_sum(right) < N) {
			if(print)cout << "right: " << right << endl;
			right *= 2;
			
		}
		if (print)cout << "final right: " << right << endl;
		ll floor = 0;
		while (left < right) {
			ll mid = (left + right) / 2;
			if (print)cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
			if (rmd_sum(mid) < N) left = mid;
			else right = mid;
			if (right - left == 1 && rmd_sum(right) >= N && rmd_sum(left) < N) { //무한루프 방지
				floor = right;
				break;
			}
			floor = mid;
		}
		if (print)cout << "floor: " << floor << endl;
		cout << get_rst(floor) + 1<< endl;
 	}
	return 0;
}