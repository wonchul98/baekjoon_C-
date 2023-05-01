#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
bool print = true;
int N;
int arr[100001];
int minus_arr[100001];
int plus_arr[100001];
int abs_arr[100001];
int p[100001] = {0,};
int sorted_p[100001] = { 0, };
int minimum = 987654321;
int min_f, min_s;

void near_z();
pair<int, int> get_near(int input);
void merge(int left, int right, int mid);
void merge_sort(int left, int right);

int main() {
	freopen("input/2470_input.txt", "r", stdin);
	cin >> N;
	
	int minus_count = 0;
	int plus_count = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > 0) {
			plus_arr[plus_count++] = arr[i];
		}
		else {
			minus_arr[minus_count++] = arr[i];
		}
	}
	sort(minus_arr, minus_arr + minus_count);
	sort(plus_arr, plus_arr + plus_count);
	minimum = abs(plus_arr[0]) + abs(plus_arr[1]);
	min_f = plus_arr[0];
	min_s = plus_arr[1];
	if (minimum > abs(minus_arr[minus_count - 2]) + abs(minus_arr[minus_count - 1])) {
		minimum = abs(minus_arr[minus_count - 2]) + abs(minus_arr[minus_count - 1]);
		min_f = minus_arr[minus_count - 2];
		min_s = minus_arr[minus_count - 1];
	}
	merge_sort(0, N - 1);
	for (int i = 0; i < N; i++) {
		if(print) cout << abs_arr[i] << " ";
	}
	if(print) cout << endl;
	if (plus_count == N) {//모두 양수
		if (print) cout << "모두 양수" << endl;
		cout << plus_arr[0] << " " << plus_arr[1] << endl;
	}
	else if (minus_count == N) {//모두 음수
		if (print) cout << "모두 음수" << endl;
		cout << minus_arr[N - 2] << " " << minus_arr[N - 1] << endl;
	}
	
	else {
		near_z();
	}
}

void merge(int left, int right, int mid) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (abs(arr[i]) <= abs(arr[j])) {
			abs_arr[k++] = arr[i++];
		}
		else abs_arr[k++] = arr[j++];
	}
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			abs_arr[k++] = arr[l];
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			abs_arr[k++] = arr[l];
		}
	}
	for (int l = left; l <= right; l++) {
		arr[l] = abs_arr[l];
	}

}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right, mid);
	}
}

pair<int, int> get_near(int input) {
	if (print) cout << "get_near(): " << input << endl;
	pair<int, int> ret;
	int ret_first = input, ret_second = input;
	while (abs_arr[ret_first] * abs_arr[input] > 0) { //부호가 같은 경우
		//if(print) cout << "ret_first, abs_arr[ret_first]: " << ret_first << " " << abs_arr[ret_first] << endl;
		if (ret_first == 0) break;
		ret_first--;
	}
	while (abs_arr[ret_second] * abs_arr[input] > 0) {
		//if (print) cout << "ret_second, abs_arr[ret_second]: " << ret_second << " " << abs_arr[ret_second] << endl;
		if (ret_second == N-1) break;
		ret_second++;
	}
	if (print) cout << "ret_first: " << ret_first << " ret_second: " << ret_second << endl;
	if (abs_arr[ret_first]*abs_arr[input] < 0) ret.first = ret_first; //부호가 다른경우
	else ret.first = 100001;
	if (abs_arr[ret_second] * abs_arr[input] < 0) ret.second = ret_second;//부호가 다른경우
	else ret.second = 100001;
	if (print) cout << "return pair(" << ret.first << "," << ret.second << ")" << endl;
	return ret;
}

void near_z() {
	if(print)cout << "near_z" << endl;
	for (int i = 0; i < N; i++) {
		if (print) cout << "============= i:" << i << "===============" << endl;
		bool b_left = false, b_right = false;
		pair<int,int> ret_get_near = get_near(i);
		int left = ret_get_near.first;
		int right = ret_get_near.second;
		int region_min;
		if (left == 100001) region_min = abs(abs_arr[i] + abs_arr[right]);
		else if (right == 100001) region_min = abs(abs_arr[i] + abs_arr[left]);
		else region_min = min(abs(abs_arr[i] + abs_arr[right]), abs(abs_arr[i] + abs_arr[left]));
		if (print) cout << "region_min: " << region_min << endl;
		if (left != 100001 && region_min == abs(abs_arr[i] + abs_arr[left])) {
			b_left = true;
		}
		else if(right != 100001 && region_min == abs(abs_arr[i] + abs_arr[right])) b_right = true;
		if (minimum > region_min) { //갱신
			minimum = region_min;
			if (print) cout << "minimum: " << minimum << endl;
			if (b_left) {
				min_f = min(abs_arr[i], abs_arr[left]);
				min_s = max(abs_arr[i], abs_arr[left]);
			}
			else {
				min_f = min(abs_arr[i], abs_arr[right]);
				min_s = max(abs_arr[i], abs_arr[right]);
			}
		}
	}
	cout << min_f << " " << min_s << endl;
}