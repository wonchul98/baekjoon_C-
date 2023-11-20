#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const int MAX_V = 20001;
const int INF = numeric_limits<int>::max();

vector<pair<int, int>> adj[MAX_V]; // 각 노드의 인접 리스트 (노드, 가중치)
int dist[MAX_V]; // 시작 노드로부터 각 노드까지의 최단 거리
int V, E, K; // V: 노드의 개수, E: 간선의 개수, K: 시작 노드

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙
    fill(dist, dist + V + 1, INF); // 모든 거리를 무한대로 초기화
    dist[start] = 0; // 시작 노드의 거리는 0
    pq.push({ 0, start }); // 시작 노드를 큐에 삽입

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // 현재 노드까지의 거리가 이미 알려진 최단 거리보다 긴 경우 무시
        if (dist[currentNode] < currentDist) continue;

        // 인접 노드 탐색
        for (auto& edge : adj[currentNode]) {
            int nextNode = edge.first;
            int weight = edge.second;
            int nextDist = currentDist + weight;

            // 더 짧은 경로 발견 시 업데이트
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({ nextDist, nextNode });
            }
        }
    }
}

int main() {
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w }); // 노드 u에서 v로 가는 가중치 w
    }

    dijkstra(K);

    // 결과 출력
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
