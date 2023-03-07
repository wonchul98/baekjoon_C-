#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> v;
int NGE(int a);

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		cout << NGE(i) << " ";
	}
}

int NGE(int a) {
	for (int i = a+1; i < N; i++) {
		if (v.at(i) > v.at(a)) {
			return v.at(i);
		}
		
	}
	return -1;
}