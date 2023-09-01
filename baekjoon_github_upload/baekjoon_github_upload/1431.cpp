#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

struct compare {
	bool operator()(string& left, string& right) {
		if (left.length() != right.length()) {
			//cout << "case 1" << endl;
			return left.length() > right.length();
		}
		int left_add = 0; int right_add = 0;
		for (int i = 0; i < left.length(); i++) {
			if (left[i] >= '0' && left[i] <= '9') left_add -= (left[i] - 48);
			if (right[i] >= '0' && right[i] <= '9') right_add -= (right[i] - 48);
		}
		if (left_add != right_add){ //작은게 먼저 온다
			//cout << "case 2" << endl;
			return left_add < right_add;
		}
		else {
			//cout << "case 3" << endl;
			for (int i = 0; i < left.length(); i++) {
				
				if (left[i] < right[i]) return left > right;
			}
		}


	}
};
int main() {
	priority_queue<string, vector<string>, compare> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		pq.push(input);
	}
	while (!pq.empty()) {
		cout << pq.top() <<endl;
		pq.pop();
	}
	return 0;
}