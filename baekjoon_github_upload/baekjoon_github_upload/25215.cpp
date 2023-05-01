#include<iostream>
using namespace std;

string input;
bool s = true;
bool small(int a) {
	if (int(input[a]) >= 65 && int(input[a] <= 90)) return false;
	else return true;
}

int main() {
	cin >> input;
	int extra = 0;
	for (int i = 0; i < input.length(); i++) {
		//cout << input[i];
		if (s && !small(i)) {
			if (i < input.length() - 1 && !small(i + 1)) {//aAA
				s = !s; //마름모 활성화(대문자 입력)
				extra++;
				//cout << "◆" ;
			}
			else {//aAa
				extra++; //별 입력
				//cout << "★";
			}
		}
		else if (!s && small(i)) {
			if (i < input.length() - 1 && small(i + 1)) {//Aaa
				s = !s; //마름모 비활성화(소문자 입력)
				extra++;
				//cout << "◆";
			}
			else {
				extra++; //별입력
				//cout << "★";
			}
		}
		else continue;
	}
	cout << input.length() + extra << endl;
	return 0;
}