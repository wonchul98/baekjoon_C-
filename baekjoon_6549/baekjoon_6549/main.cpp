#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int map[100000] = { 0, };
int tree[400000] = { 0, };
int T = 1;
int solve();
void clear();
int make_tree(int start, int end, int node);
int sum(int start, int end, int node, int left, int right);


int main() {
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	while (1) {
		cin >> T;
		if (T == 0) break;
		for (int i = 0; i < T; i++) {
			cin >> map[i];
		}
		cout << solve() << endl;
		clear();
	}

}

int solve() {
	int max = 0;
	//make_tree(0, T - 1, 1);
	for (int i = 0; i < T; i++) {
		int left = i; 
		int right = i;
		for (int j = i - 1; j >= 0; j--) {
			//cout << "left: map[j]: " << map[j] << " map[i]: " << map[i] << endl;
			if (map[j] < map[i]) { 
				left = j + 1; 
				break; 
			}
			if (j == 0) left = 0;
		}
		for (int j = i + 1; j < T; j++) {
			//cout << "right: map[j]: " << map[j] << " map[i]: " << map[i] << endl;
			if (map[j] < map[i]) {
				right = j - 1;
				break; 
			}
			if (j == T - 1) right = T - 1;
		}
		//int sum1 = sum(0, T - 1, 1, left, right);
		int sum1 = map[i] * (right - left + 1);
		//cout << "i: " << i << " left: " << left << " right : " << right << endl;
		if (max < sum1) { max = sum1; 
		//cout << "max: " << max << endl;
		}
	}
	return max;
}

void clear() {
	for (int i = 0; i < T; i++) {
		map[i] = 0;
	}
	for (int i = 0; i < 4*T; i++) {
		tree[i] = 0;
	}
}

int make_tree(int start, int end, int node) {
	//cout << "maketree(" << start << "," << end << "," << node << ")" << endl;
	if (start == end) return tree[node] = map[start];
	int mid = (start + end) / 2;
	left_idx = 
	return tree[node] = make_tree(start, mid, node * 2) + make_tree(mid+1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {
	//cout << "sum(" << start << "," << end << "," << node << "," << left << "," << right << ")" << endl;
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node * 2 + 1, left, right);
}