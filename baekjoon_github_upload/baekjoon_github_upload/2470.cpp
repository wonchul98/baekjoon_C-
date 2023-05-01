#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	freopen("input/2470_input.txt", "r", stdin);
	int N, minimum = 2000000000;
	int arr[100001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	int left = 0, right = N - 1, val = arr[left] + arr[right];
	int left_ans = arr[left], right_ans = arr[right];
	while (left < right) {
		val = arr[left] + arr[right];
		if (abs(minimum) > abs(val)) {
			minimum = val;
			left_ans = arr[left];
			right_ans = arr[right];
		}
		if (val == 0)break;
		else if (val > 0) right--;
		else left++;
	}
	cout << left_ans << " " << right_ans << endl;
	
}