#include<iostream>
#include<stack>
using namespace std;


int main() {
	int n, param;
	cin >> n;
	string cmd;
	stack<int> st;
	for (int i = n; i > 0;i--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> param;
			st.push(param);
			
		}
		else if (cmd == "size") {
			cout << st.size()<<endl;
			
		}
		else if (cmd == "empty") {
			if (st.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (cmd == "pop") {
			if (!st.empty()) {
				cout << st.top() << endl;
				st.pop();
			}
			else { cout << "-1" << endl; }
		}
		else {
			if(!st.empty()) cout << st.top() << endl;
			else { cout << "-1" << endl; }
		}
	}
	return 0;
}