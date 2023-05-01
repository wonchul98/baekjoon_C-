#include<iostream>
#include<vector>
#include<string>
using namespace std;
string input;

int main() {
	cin >> input;
	int sum = 0;
	while (stoi(input) > 0) {
		bool one = false;
		bool out = false;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '1') {
				one = true;
				if (input.length() == 1) {
					out = true;
					break;
				}
				input.erase(i, 1);
				sum++;
				//cout << "number: " << input << " sum: " << sum << endl;
			}
		}
		if (out) break;
		if (one) continue;
		int int_input = stoi(input);
		input = to_string(int_input - 1);
		sum++;
		//cout << "number: " << input << " sum: " << sum << endl;
	}
	if (stoi(input) == 1) cout << sum + 1 << endl;
	else cout << sum << endl;
	return 0;
}