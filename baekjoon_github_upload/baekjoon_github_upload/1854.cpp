#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void setting();
void dijkstra();
void solution();
void sorting();

bool print = true;
int n, m, k;
vector<vector<int>> dist(1000,vector<int>(1000,INF));
vector<vector<int>> town_dist;
int min_dist[1001]; // 0 -> i ������ �ּ� �Ÿ�
bool visited[1001];

struct cmp {
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}

void setting() {
	if (print) cout << "setting" << endl;
	freopen("input/1854_input.txt", "r", stdin);
	cin >> n >> m >> k;

	// ���� ���� ����
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << i << j << endl;
			dist[i].push_back(INF);
		}
	}*/
	cout << "1" << endl;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	} 
	cout << "1" << endl;
	//min_dist �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		min_dist[i] = INF;
	}
	cout << "1" << endl;
	min_dist[1] = 0;
}

void solution() {
	setting();
	dijkstra();
	sorting();
}
	
void dijkstra() {
	if (print) cout << "dijkstra" << endl;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push(make_pair(1, 0));
	while (!pq.empty()) {
		int current = pq.top().first; //���� ��� ��ȣ
		int distance = pq.top().second; //�Ÿ�
		printf("���� ���: (%d, %d)\n", current, distance);
		pq.pop();
		if (min_dist[current] < distance) continue; //�ּҰ� �ƴѰ�� continue

		for (int i = 1; i <= n; i++) {
			int next, next_dist;
			//���� ����
			if (dist[current][i] == INF) continue; 
			else {
				next = i; //���� ��� ��ȣ
				next_dist = distance + dist[current][next];
			}
			printf("next: %d, next_dist:%d\n", next, next_dist);
			town_dist.at(next).push_back(next_dist);
			printf("town_dist[%d]�� %d push\n", next, next_dist);
			if (next_dist < min_dist[next]) {//current�� ������ ���°� �� ���� ���
				min_dist[next] = next_dist; //min_dist ����
				pq.push(make_pair(next, next_dist));//pq�� ����
			}
		}
	}
}

void sorting() {
	if (print) cout << "sorting" << endl;
	for (int i = 1; i <= n; i++) {
		sort(town_dist[i].begin(), town_dist[i].end());
		if (k > town_dist[i].size()) cout << "-1" << endl;
		else cout << town_dist[i][k] << endl;
	}

}


