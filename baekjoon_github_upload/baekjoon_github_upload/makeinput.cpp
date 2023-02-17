#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	string line;
	ofstream file("input.txt");
	if (file.is_open()) {
		for (int i = 0; i < 1000000; i++) {
			file << i << " ";
		}
		file.close();
	}
	else {
		cout << "error" << endl;
		return 1;
	}
	return 0;
}
