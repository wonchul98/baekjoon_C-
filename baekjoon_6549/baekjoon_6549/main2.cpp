#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

#define INF 2000000000

using namespace std;

long long map[1000001] = { 0, };
long long tree[1000001] = { 0, };
long long T = 1;
long long max_rst;
void solve(long long left, long long right);
void clear();
int make_tree(int start, int end, int node);
void show_tree();
long long min(int start, int end, int node, int left, int right);

int main() {
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
	while (1) {
		cin >> T;
		if (T == 0) break;
		for (int i = 0; i < T; i++) {
			cin >> map[i];
		}
		//cout << endl;
		make_tree(0, T - 1, 1);
		//show_tree();
		solve(0, T - 1);
		cout << max_rst << endl;
		clear();
	}

}

void solve(long long left, long long right){
	//cout << "solve " << left << " " << right << endl;
	if (left > right) return;
	if (left == right) {
		max_rst = max(max_rst, map[left]);
		return;
	}
	long long idx = min(0, T-1, 1, left, right);
	//cout << "idx: " << idx << endl;
 	long long rst = map[idx] * (right - left + 1);
	if (rst > max_rst) {
		max_rst = rst;
		//cout << "max_rst: " << max_rst << endl;
	}
	solve(left, idx - 1);
	solve(idx + 1, right);
}
void clear(){
	max_rst = 0;
	for (int i = 0; i < T; i++) {
		map[i] = 0;
	}
	for (int i = 0; i < 4 * T; i++) {
		tree[i] = 0;
	}
}
int make_tree(int start, int end, int node){
	//cout << "make_tree(" << start << "," << end << "," << node <<")" << endl;
	if (start == end) {
		//cout << "tree node: " << node << " start: " << start << endl;
		return tree[node] = start;
	}
	int mid = (start + end) / 2;
	int left_idx = make_tree(start, mid, node * 2);
	int right_idx = make_tree(mid + 1, end, node * 2 + 1);
	//cout << "left_idx: " << left_idx << "right_idx: " << right_idx << endl;
	//cout << map[left_idx] << " " << map[right_idx] << endl;
	int rst = map[left_idx] > map[right_idx] ? right_idx : left_idx;
	//cout << "tree node: " << node << " put: " << rst << endl;
	return tree[node] = rst;
}
long long min(int start, int end, int node, int left, int right){
	//cout << "min(" << start << "," << end << "," << node << "," << left << "," << right << ")" << endl;
	if (left > end || right < start) return INF;
	if (left <= start && right >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	//cout << "mid: " << mid << endl;
	int left_idx = min(start, mid, node * 2, left, right);
	int right_idx = min(mid + 1, end, node * 2 + 1, left, right);
	if (left_idx == INF) return right_idx;
	else if (right_idx == INF) return left_idx;
	else return map[left_idx] < map[right_idx] ? left_idx : right_idx;
}

void show_tree() {
	for (int i = 0; i < 4*T; i++) {
		cout << tree[i] << endl;
	}

}