#include<iostream>

using namespace std;

int arr[11] = { 0, };
int N, H, M, cnt = 0;

void show_array();

int main() {
	
	
	cin >> N >> H >> M;
	for (int i = 0; i < H; i++) {
		int a, b;
		cin >> a >> b;
		arr[b]++;
		arr[b + 1]++;
	}
	for (int i = 1; i < N; i++) {
		if (arr[i] % 2 == 1) {
			arr[i]++;
			arr[i + 1]++;
			if (arr[i] > M || arr[i+1] > M) {
				cout << "-1";
				return 0;
			}
			cnt++;
		}
		
		//show_array();
	}
	if (arr[N] % 2 == 0)cout << cnt;
	else cout << "-1";
	return 0;
}

void show_array() {
	for (int i = 1; i <= N; i++) {
		cout << "arr[" << i << "]: " << arr[i] << " ";
	}
	cout << endl;
}