#include<iostream>
#include<utility>
#include<stack>

using namespace std;

int N;
stack<pair<int,int>> s;
int ans[500001] = { 0, };

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int target;
		cin >> target;
		while (!s.empty() && s.top().second <= target) {
			s.pop();
		}
		if (s.empty()) {
			ans[i] = 0;
		}
		else {
			ans[i] = s.top().first;
		}
		s.push(make_pair(i, target));
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}