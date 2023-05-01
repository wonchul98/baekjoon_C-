#include<iostream>
#include<vector>
using namespace std;
string input;

int main() {
	cin >> input;
	int sum = 0;
	bool zero_on = false;
	int zero_cnt = 0;
	for (int i = input.length() - 1; i >= 0; i--) {
		int now = int(input[i]) - int('0');
		if (now == 0) {
			zero_on = true;
			zero_cnt++;
		}
		else if (now == 1) {
			zero_on = false;
			zero_cnt = 0;
			sum++;
		}
		else {
			if (zero_on) {
				sum += 9 * zero_cnt + now;
				zero_on = false;
				zero_cnt = 0;
			}
			else {
				sum += now;
			}
		}
		//cout << "now: " << now << " zero_on: " << zero_on << " zero_cnt: " << zero_cnt << " sum: " << sum << endl;
	}
	cout << sum << endl;
	return 0;
}