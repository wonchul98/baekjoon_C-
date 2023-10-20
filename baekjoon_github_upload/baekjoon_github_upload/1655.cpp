#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> s_pq;
priority_queue<int, vector<int>, greater<>> b_pq;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int mid;
	int s_size=0, b_size=0;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (i == 0) {
			mid = input;
			cout << "mid: ";
			cout << mid << "\n";
			continue;
		}
		
		if (input > mid) {
			if (b_size - s_size == 1) {
				s_pq.push(mid);
				s_size++;
				b_pq.push(input);
				mid = b_pq.top();
				b_pq.pop();
			}
			else {
				b_pq.push(input);
				b_size++;
			}
		}
		else  { //input <= mid
			if (s_size - b_size == 1) {
				b_pq.push(mid);
				b_size++;
				s_pq.push(input);
				mid = s_pq.top();
				s_pq.pop();
			}
			else if (s_size == b_size) {
				s_pq.push(input);
				b_pq.push(mid);
				b_size++;
				mid = s_pq.top();
				s_pq.pop();
			}
			else { //b_size가 더 큰 경우
				s_pq.push(input);
				s_size++;
			}
		}
		printf("i: %d, s_size: %d, b_size: %d, mid: %d\n", i, s_size, b_size, mid);
		cout << "mid: ";
		cout << mid << "\n";
	}
	return 0;
}