#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int map[20][20];
int N, M, x, y, K;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1, -1, 0,0 };
deque<int> dice_r;
deque<int> dice_c;
void get_order(int order);
void print_dice();

int main() {
	dice_r.push_back(0);
	dice_r.push_back(0);
	dice_r.push_back(0);
	dice_r.push_back(0);

	dice_c.push_back(0);
	dice_c.push_back(0);
	dice_c.push_back(0);
	dice_c.push_back(0);


	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int order;
		cin >> order;
		get_order(order);
	}
	return 0;
}

void get_order(int order) {
	//cout << "order: " << order << endl;
	int n_x = x + dx[order];
	int n_y = y + dy[order];
	if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) {
		return;
	}
	
	//print_dice();
	//cout << "------------------------------------" << endl;
	if (order == 1) { //동쪽
		cout << dice_r[3] << endl;
		dice_r.push_front(dice_r.back());
		dice_r.pop_back();

		dice_c.pop_front();
		dice_c.push_front(dice_r[0]);
		
		dice_c[2] = dice_r[2];
	}
	else if (order == 2) { //서쪽
		cout << dice_r[1] << endl;
		dice_r.push_back(dice_r.front());
		dice_r.pop_front();

		dice_c.pop_front();
		dice_c.push_front(dice_r[0]);
		
		dice_c[2] = dice_r[2];
	}
	else if (order == 3) {// 북쪽
		cout << dice_c[3] << endl;
		dice_c.push_front(dice_c.back());
		dice_c.pop_back();

		dice_r.pop_front();
		dice_r.push_front(dice_c[0]);

		dice_r[2] = dice_c[2];
	}
	else { //남쪽
		cout << dice_c[1] << endl;
		dice_c.push_back(dice_c.front());
		dice_c.pop_front();

		dice_r.pop_front();
		dice_r.push_front(dice_c.front());
		dice_r[2] = dice_c[2];
	}
	/* 바닥면 확인 */
	if (map[n_x][n_y] != 0) {
		dice_c[2] = map[n_x][n_y];
		dice_r[2] = map[n_x][n_y];
		map[n_x][n_y] = 0;
	}
	else {
		map[n_x][n_y] = dice_c[2];
	}
	//print_dice();
	//cout << "///////////////////////////////////" << endl;
	x = n_x;
	y = n_y;
}
void print_dice() {

	for (int i = 0; i < dice_r.size(); i++) {
		cout << dice_r[i];
	}
	cout << "\n";
	for (int i = 0; i < dice_c.size(); i++) {
		cout << dice_c[i];
	}
	cout << "\n";
}
