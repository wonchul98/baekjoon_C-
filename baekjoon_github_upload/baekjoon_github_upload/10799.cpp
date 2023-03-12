#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<stack>
using namespace std;

int main() {
	int ans = 0;
	int stick = 0;
	stack<char> s;
	string input;
	freopen("input/10799_input.txt", "r", stdin);
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ')') {
			if (input[i - 1] == '(') {
				if (s.size() != 1) {
					ans += s.size() - 1;
				}
				s.pop();
			}
			else {
				stick++;
				s.pop();
			}
		}
		else {
			s.push(input[i]);
		}
	}
	cout << stick + ans << endl;
	return 0;
}
