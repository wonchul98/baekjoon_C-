#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
string arr;
string get_s();
string get_b();
int  main() {
	cin >> arr;
	cout << get_b() << endl;
	cout << get_s() << endl;
	
	return 0;
}

string get_b() {
	string rst;
	int M_cnt = 0;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == 'M') {
			M_cnt++;
			if (i == arr.length() - 1) {
				for (int j = 0; j < M_cnt; j++) {
					rst += '1';
				}
			}
		}
		else if (arr[i] == 'K') {
			rst += '5';
			for (int j = 0; j < M_cnt; j++) {
				rst += '0';
			}
			M_cnt = 0;
		}
	}
	return rst;
}

string get_s() {
	string rst;
	int M_cnt = 0;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == 'M') {
			M_cnt++;
			if (i == arr.length() - 1) {
				rst += '1';
				for (int j = 0; j < M_cnt - 1; j++) {
					rst += '0';
				}
			}
		}
		else if (arr[i] == 'K') {
			if (M_cnt != 0) {
				rst += '1';
				for (int j = 0; j < M_cnt - 1; j++) {
					rst += '0';
				}
				rst += '5';
			}
			else {
				rst += '5';
			}
			M_cnt = 0;
		}
	}
	return rst;
}