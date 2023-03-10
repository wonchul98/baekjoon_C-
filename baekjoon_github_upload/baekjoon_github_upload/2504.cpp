#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main() {
	stack<char> s;
	string input;
	char one = '1';
	cout << (int)one << endl;
	//cin >> input;
	for (int i = 0; i < input.size(); i++) {
		s.push(input[i]);
		if (input[i] == ']') {
			if(s.top() == '['){
				s.pop();
				s.push(51);
			}
			if((int)s.top() - 58 <= 0){}

		}
	}
	return 0;
}