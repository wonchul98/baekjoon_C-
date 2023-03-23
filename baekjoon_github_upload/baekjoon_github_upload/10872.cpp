#include<iostream>
using namespace std;
int fact(int a);

int main() {
	int n;
	cin >> n;
	cout << fact(n) << endl;
	return 0;
}

int fact(int a) {
	if (a <= 0) return 1;
	return a * fact(a - 1);
}