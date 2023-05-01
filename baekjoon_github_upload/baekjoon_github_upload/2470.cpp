#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	freopen("input/2470_input.txt", "r", stdin);
	int N, minimum = 2000000000;
	int arr[100001];
	cin >> N;
	int plus_count = 0, minus_count = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > 0) plus_count++;
		else minus_count++;
	}
	sort(arr, arr+N);
	for (int i = 0; i < N; i++) {
		//cout << arr[i] << " ";
	}
	//cout << endl;
	//if (N == plus_count) cout << arr[0] << " " << arr[1]<<endl;
	//else if (N == minus_count) cout << arr[N-2] << " " << arr[N-1] << endl;
	//else {
		int left = 0, right = N - 1, val = arr[left] + arr[right];
		int left_ans = arr[left], right_ans = arr[right];
		while (left < right) {
			//cout << "left: " << left << " right: " << right << endl;
			val = arr[left] + arr[right];
			if (abs(minimum) > abs(val)) {
				minimum = val;
				//cout << "minimum: " << minimum << endl;
				left_ans = arr[left];
				right_ans = arr[right];
			}
			if (val == 0)break;
			else if (val > 0) right--;
			else left++;
		}
		cout << left_ans << " " << right_ans << endl;
	//}
}