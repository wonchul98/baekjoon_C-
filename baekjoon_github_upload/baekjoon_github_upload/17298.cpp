#include<iostream>
#include<stack>
using namespace std;
int N;
int arr[1000000];
int rst[1000000];
stack<int> s;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i]) { //s에 뭔가 있음 + s맨위보다 arr[i]가 더 큼
			s.pop();
		}
		if (s.empty()) {
			rst[i] = -1;
			s.push(arr[i]);
			continue;
		}
		else { //s.top() > arr[i]
			rst[i] = s.top();
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < N; i++) {
		cout << rst[i] << " ";
	}
	return 0;
}