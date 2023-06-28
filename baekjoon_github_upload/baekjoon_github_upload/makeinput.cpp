#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	string line;
	ofstream file("input.txt");
	if (file.is_open()) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				if ((i + j) % 2 == 0) file << 1;
				else file << 0;
			}
			file << "\n";
		}
		file.close();
	}
	else {
		cout << "error" << endl;
		return 1;
	}
	return 0;
}
