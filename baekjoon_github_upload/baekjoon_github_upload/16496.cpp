#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include<iostream>
#include<queue>
#include<cmath>
#include<string>
using namespace std;
struct cmp {
	bool operator()(pair<ll, int>& a, pair<ll, int>& b) {
		return a.first < b.first; //첫번째 인자 기준 내림차순
	}
};
pair<ll, int> make_number(int input);
bool print = false;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, cmp> pq;
int N;

int main() {
	freopen("input/16496_input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(make_number(input));
	}
	bool only_zero = true;
	string ans;
	while (!pq.empty()) {
		if (pq.top().second != 0) only_zero = false;
		ans.append(to_string(pq.top().second));
		pq.pop();
	}
	if (only_zero) cout << "0" << endl;
	else cout << ans << endl;
	
	return 0;
}

pair<ll,int> make_number(int input) {
	int cnt = 0;
	int save_input = input;
	int nums[10] = { 0, };
	if (input < 10) {
		cnt = 1;
		nums[0] = input;
	}
	else {
		while (input != 0) {
			nums[cnt] = input % 10;
			cnt++;
			input /= 10;
		}
	}
	ll return_val = 0;
	for (int i = 0; i <= 9; i++) { //연속 수를 만드는 코드
		return_val += nums[(cnt-1)-(i%cnt)] * (pow(10, 9 - i));
	}
	
	return make_pair(return_val,save_input);
}