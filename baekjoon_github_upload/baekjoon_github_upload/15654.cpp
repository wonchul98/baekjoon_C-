
#include<iostream>
using namespace std;
#define MAXN 100000
int n, m;
int arr[MAXN] = { 0, };
bool visited[MAXN] = { 0, };
int dfs(int a);
int main() {
	//fio();
	cin >> n >> m ;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << dfs(0);
	return 0;
}

int dfs(int d) {
	if (d == m) {
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			arr[d] = visited[i];
			visited[i] = true;
			dfs(d+1);
			visited[i] = false;

		}
	}
}