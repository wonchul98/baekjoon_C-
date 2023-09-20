#define INF 987654321
#include<iostream>
using namespace std;
int map[12][12] = { 0, };

bool able(int x, int y, int size);
void dfs(int x, int y, int cnt);
void fill(int x, int y, int size, int dest);
int num[6] = { 0,5,5,5,5,5 };
int min_count = INF;
void print_map();
int blank = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> map[i][j];
			if (map[i][j]) blank++;
		}
	}
	dfs(1, 1, 0);
	if (min_count == INF) cout << "-1" << endl;
	else cout << min_count << endl;
	return 0;
}

bool able(int x, int y, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[x + i][y + j] == 0) return false;
		}
	}
	//printf("able (%d, %d), size: %d\n", x, y, size);
	return true;
}

void dfs(int x, int y, int cnt) {
	bool flag = false;
	if (cnt >= min_count) return;
	//printf("dfs(%d, %d, %d)\n", x, y, cnt);
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			//cout << i << j << endl;
			if (map[i][j] == 1) {
				flag = true;
				//cout << "i: " << i << " j: " << j << endl;
				
				for (int size = 5; size >= 1; size--) {
					if (num[size] <= 0 || x + size - 1 > 10 || y + size - 1 > 10)continue;
					if (able(i, j, size)) {
						//cout << "num: " << num[size] << endl;
						fill(i, j, size, 0);
						blank -= size * size;
						dfs(x, y, cnt + 1);
						fill(i, j, size, 1);
						blank += size * size;
						
					}
				}

			}
			if (flag) break;
		}
		if (flag) break;
	}
	//cout << "cant go" << endl;
	//여기 온다는 것은 붙일게 남아있는데 못붙이거나 다 붙였다는 뜻
	if (blank==0) {
		//cout << "filled" << endl;
		min_count = min(cnt, min_count);
	}
	return;
	
}

void fill(int x, int y, int size, int dest) {
	//printf("fill: x: %d, y: %d, size: %d, dest: %d\n", x, y, size, dest);
	if (dest == 0) num[size]--; //1을 0으로 만들며 색종이 소모
	else num[size]++;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[x + i][y + j] = dest;
		}
	}
	//print_map();
}


void print_map() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout.width(3);
			cout << map[i][j];
		}
		cout << "\n";
	}
}