#include<iostream>
#include<vector>
#include<stack>

using namespace std;

stack<int> visiting;
int visitingArr[100001] = { false, };
bool visited[100001] = { false, };
bool isCycle[100001] = { false, };
int nextNode[100001] = { 0 , };
int ans = 0;
int N;

void init() {
	fill_n(nextNode, N + 1, 0);
	fill_n(visitingArr, N + 1, false);
	fill_n(visited, N+1, false);
	fill_n(isCycle, N+1, false);
	ans = 0;
}

void dfs(int idx) {
	//printf("dfs(%d)\n", idx);
	visiting.push(idx);
	visitingArr[idx] = true;
	visited[idx] = true;
	
	if (visited[nextNode[idx]] && isCycle[nextNode[idx]]) { // 이미 형성된 cycle을 만난 경우
		//cout << "case 1" << endl;
		while (!visiting.empty()) {
			visitingArr[visiting.top()] = false;
			visiting.pop();
		}
		return;
	}
	else if(visited[nextNode[idx]] && !isCycle[nextNode[idx]]){ // 이미 방문은 했는데 cycle은 아닌 경우
		if (visitingArr[nextNode[idx]]) { //현재 방문 중이 노드인 경우 -> 사이클임
			//cout << "case 2" << endl;
			//cout << "현재 방문 중이 노드인 경우 -> 사이클임" << endl;

			while (visiting.top() != nextNode[idx]) {
				isCycle[visiting.top()] = true;
				visitingArr[visiting.top()] = false;
				visiting.pop();
				ans++;
			}
			isCycle[visiting.top()] = true;
			visiting.pop();
			ans++;
			while (!visiting.empty()) {
				visitingArr[visiting.top()] = false;
				visiting.pop();
			}
			return;
		}
		else {
			//cout << "case 3" << endl;
			while (!visiting.empty()) { //아닌 경우 -> 아무것도 아님
				visitingArr[visiting.top()] = false;
				visiting.pop();
			}
			return;
		}
		
	}
	dfs(nextNode[idx]);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		init();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int node;
			cin >> node;
			nextNode[i] = node;
			if (i == node) {
				visited[i] = true;
				isCycle[i] = true;
				ans++;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << N - ans << endl;

	}
	system("pause");
	return 0;
}