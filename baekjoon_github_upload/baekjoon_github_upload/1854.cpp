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
void answer();

bool print = false;
int n, m, k;
vector<vector<int>> dist(1001,vector<int>(1001,INF));
vector<priority_queue<int, vector<int> , less<int>>> town_dist(1001); //내림차순

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
	//freopen("input/1854_input.txt", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	} 

	town_dist[1].push(0); //시작점->시작점의 최소값은 0
}

void solution() {
	setting();
	dijkstra();
	answer();
}
	
void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; //second기준 오름차순
	pq.push(make_pair(1, 0));

	while (!pq.empty()) {
		int current = pq.top().first; //현재 노드 번호
		int distance = pq.top().second; //거리
		pq.pop();
		//if (min_dist[current] < distance) continue; //최소가 아닌경우 continue
		if (print)printf("현재 노드: (%d, %d)\n", current, distance);

		for (int i = 1; i <= n; i++) {
			int next, next_dist;
			//인접 노드
			if (dist[current][i] == INF) continue; //간선이 없는 경우
			else {
				next = i; //인접 노드 번호
				next_dist = distance + dist[current][next];
			}
			if (print)printf("next: %d, next_dist:%d, size: %d\n", next, next_dist, town_dist.at(next).size());
			if (town_dist.at(next).size() < k) { //k만큼 아직 못채운 경우
				town_dist.at(next).push(next_dist);
				pq.push(make_pair(next, next_dist));//pq에 삽입
			}
			else if (town_dist.at(next).top() > next_dist) { //k만큼 채웠는데 갱신
				if (print) cout << " top 갱신 " << endl;
				town_dist.at(next).pop();
				town_dist.at(next).push(next_dist);
				pq.push(make_pair(next, next_dist));//pq에 삽입
			}
			// k만큼 채웠지만 갱신을 못하는 경우에는 pq에 다시 넣지 않는다. 
		}
	}
}

void answer() {
	for (int i = 1; i <= n; i++) {
		if(print)cout << "i: " << i << endl;
		if (k > town_dist[i].size()) cout << "-1" << endl;
		else cout << town_dist[i].top() << endl;
	}
}


