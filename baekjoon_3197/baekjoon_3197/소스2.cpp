#include <iostream>
#include <queue>
using namespace std;

char map[1501][1501];
queue<pair<int, int> > willVisitQ;
queue<pair<int, int> > q;
queue<pair<int, int> > iceQ;
queue<pair<int, int> > nextIceQ;

bool isVisited[1501][1501];
int sizeX, sizeY;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pair<int, int> swan;

// 하루 지나면 얼음 녹는거 생각 -> bfs로 얼음을 녹인다
// 하루 지나면 녹을 얼음이 오리가 가는 경로에 있다면 -> 다음 오리가 탐색시작할 위치는 거기임
bool swan_bfs()
{
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (nextX <= 0 || nextX > sizeX || nextY <= 0 || nextY > sizeY || isVisited[nextY][nextX]) {
				continue;
			}
			if (map[nextY][nextX] == 'X') {
				willVisitQ.push(make_pair(nextX, nextY));
				// cout<<"다음에 탐사할 영역 X: "<<nextX<<"y : "<<nextY<<endl;
				isVisited[nextY][nextX] = true;
			}
			else if (map[nextY][nextX] == '.') {
				q.push(make_pair(nextX, nextY));
				isVisited[nextY][nextX] = true;
			}
			else if (map[nextY][nextX] == 'L') {
				while (!q.empty()) q.pop();
				return true;
			}
		}
	}
	return false;
}

void melt_bfs()
{
	int count = 0;
	while (!iceQ.empty()) {
		int nowX = iceQ.front().first;
		int nowY = iceQ.front().second;
		iceQ.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = dx[i] + nowX;
			int nextY = dy[i] + nowY;
			if (nextX <= 0 || nextX > sizeX || nextY <= 0 || nextY > sizeY || map[nextY][nextX] == '.') {
				continue;
			}
			//다음에 녹일 얼음
			if (map[nextY][nextX] == 'X') {
				// cout<<"다음에 녹일 얼음 X: "<<nextX<<"y : "<<nextY<<endl;
				count++;
				map[nextY][nextX] = '.';
				nextIceQ.push(make_pair(nextX, nextY));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sizeX = 100;
	sizeY = 100;
	cin >> sizeY >> sizeX;
	for (int i = 1; i <= sizeY; i++) {
		for (int j = 1; j <= sizeX; j++) {
			cin >> map[i][j];
			isVisited[i][j] = false;
			if (map[i][j] == 'L') {
				swan.first = j; //현재 오리의 x좌표
				swan.second = i; // 현재 오리의 y좌표
			}if (map[i][j] == '.' || map[i][j] == 'L') {
				iceQ.push(make_pair(j, i));
			}
		}
	}


	int ans = 0;
	willVisitQ.push(make_pair(swan.first, swan.second));
	isVisited[swan.second][swan.first] = true;
	while (!swan_bfs()) {
		q = willVisitQ;
		melt_bfs();
		iceQ = nextIceQ;
		// cout<<iceQ.size()<<endl;
		while (!nextIceQ.empty()) nextIceQ.pop();
		while (!willVisitQ.empty()) willVisitQ.pop();
		ans++;
	}
	cout << ans;
	return 0;
}
