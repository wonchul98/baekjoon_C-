#include<iostream>
#include<deque>

using namespace std;

int main() {
	int n, param;
	string cmd;
	deque<int> dq;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> param;
			dq.push_front(param);
		}
		if (cmd == "push_back") {
			cin >> param;
			dq.push_back(param);
		}
		if (cmd == "size") {
			cout << dq.size() << endl;
		}
		if (cmd == "empty") {
			cout << dq.empty() << endl;
		}
		if (cmd == "back") {
			if (dq.empty()) { cout << "-1" << endl; }
			else cout << dq.back() << endl;
		}
		if (cmd == "front") {
			if (dq.empty()) { cout << "-1" << endl; }
			else cout << dq.front() << endl;
		}
		if (cmd == "pop_front") {
			if (dq.empty()) cout << "-1" << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		if (cmd == "pop_back") {
			if (dq.empty()) cout << "-1" << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
	}
	return 0;
}