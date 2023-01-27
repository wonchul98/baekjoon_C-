#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>

using namespace std;

int N;
int arr[1000] = { 0, };

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int dp1[1000];
	int dp2[1000];
	fill_n(dp1, 1000, 1);
	fill_n(dp2, 1000, 1);
	int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		//cout << "i: " << i << endl;
		//cout << "arr[i]: " << arr[i] << endl;
		int arr_max1 = 1;
		
		for (int j = 0; j < i; j++) { //Áõ°¡
			//cout << "j: " << j << endl;
			//cout << "arr[j]: " << arr[j] << endl;
			if (arr[j] < arr[i]&&dp1[j]+dp1[i] > arr_max1) {
				arr_max1 = dp1[j] + dp1[i];
			}
		}
		dp1[i] = arr_max1;
		//cout << "dp1["<<i<<"]"<<dp1[i] << endl;
		
	}
	for (int i = N - 2; i >= 0; i--) {
		int arr_max2 = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i] && dp2[j] + dp2[i] > arr_max2) {
				arr_max2 = dp2[j] + dp2[i];
			}
		}
		dp2[i] = arr_max2;
		//cout << "dp2[" << i << "]" << dp2[i] << endl;
		
	}
	for (int i = 0; i < N; i++) {
		if (max < dp1[i] + dp2[i]) max = dp1[i] + dp2[i];
	}
	cout << max -1;
}