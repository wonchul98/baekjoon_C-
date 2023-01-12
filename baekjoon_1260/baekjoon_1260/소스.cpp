#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void bfs();
void dfs();
bool visited(int a);

int connected[1001][1001] = { 0, };
int visitedarr[1001] = { 0, };
int N, M, V;

int main() {
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		connected[input1][input2] = 1;
		connected[input2][input1] = 1;
	}
	dfs();
	bfs();
	
}

void bfs() {
	for (int i = 0; i <= 1000; i++) {
		visitedarr[i] = 0;
	}
	queue<int>Q;
	int cur = 0;
	Q.push(V);
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();
		if (visited(cur)) continue;
		visitedarr[cur] = 1;
		cout << cur << " ";
		
		for (int i = 1; i <= N; i++) {
			if (connected[cur][i] == 1 && !visited(i)) {
				Q.push(i);
			}
		}
	}
	cout << endl;
}

void dfs() {
	stack<int> st;
	int cur = 0;
	st.push(V);
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		for (int i = 1; i <= N; i++) {
			if (connected[cur][i] == 1 && !visited(i)) {
				st.push(cur);
				st.push(i);
				//cout << "break and push " << cur << endl;
				break;
			}
		}
		if (visited(cur)) continue;
		visitedarr[cur] = 1;
		cout << cur << " ";
	}
	cout << endl;
}

bool visited(int a) {
	if (visitedarr[a] == 1) return true;
	else return false;
}