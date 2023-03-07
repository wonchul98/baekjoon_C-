#include<iostream>
#include<queue>
using namespace std;

int main() {
	int param, n;
	queue<int> q;
	cin >> n;
	string cmd;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> param;
			q.push(param);
		}
		if (cmd == "size") {
			cout << q.size() << endl;
		}
		if (cmd == "front") {
			if (!q.empty()) cout << q.front() << endl;
			else {
				cout << "-1" << endl;
			}
		}
		if (cmd == "back") {
			if (q.empty()) cout << "-1" << endl;
			else cout << q.back() << endl;
		}
		if (cmd == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else cout << "-1" << endl;
		}
		if (cmd == "empty") {
			cout << q.empty() << endl;
		}
	}
	return 0;
}