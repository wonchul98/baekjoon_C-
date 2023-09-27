#include<iostream>
#include<string>
using namespace std;

int visited_arr[1501][1501] = { 0, };
int DFS_flag = 0;

void daypass(int R, int C, char** arr);
void show_array(int R, int C, char** arr);
void DFS(int R, int C, int cur_i, int cur_j, int start_i, int start_j, char** arr);
bool visited(int i, int j);

int main() {
	int R, C;
	cin >> R >> C;
	char** l_array = new char* [R+2];
	for(int i = 0;i<R+2;i++){
		l_array[i] = new char[C+2];
	}

	for (int i = 0; i <= R + 1; i++) {
		for (int j = 0; j <= C + 1; j++) {
			//cout << i << j << endl;
			l_array[i][j] = 's';
		}
	}

	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			//cout << "input in i:" << i << "j: " << j << input[j-1] << endl;
			l_array[i][j] = input[j-1];
		}
		//cout << endl;
	}
	DFS(R, C, 0, 0, 0, 0, l_array);
	if (DFS_flag) {
		cout << "0";
		return 0;
	}
	int cnt = 0;
	//cout << "-------------" << endl;
	while (!DFS_flag) {
		cnt++;
		daypass(R, C, l_array);
		//show_array(R, C, l_array);
		DFS(R, C, 0, 0,0,0,l_array);
		//cout << "-----------\n";
		//cout << "DFS_flag: " << DFS_flag<<endl;
		
		
	}
	cout << cnt;

	for (int i = 0; i < R+2; i++) {
		delete[] l_array[i];
	}

	delete[] l_array;
	return 0;
}

void daypass(int R, int C, char** l_array) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (l_array[i][j] == 'X') {
				if (l_array[i - 1][j] == '.' || l_array[i - 1][j] == 'L') l_array[i][j] = 'm';
				if (l_array[i + 1][j] == '.' || l_array[i + 1][j] == 'L') l_array[i][j] = 'm';
				if (l_array[i][j - 1] == '.' || l_array[i][j - 1] == 'L') l_array[i][j] = 'm';
				if (l_array[i][j + 1] == '.' || l_array[i][j + 1] == 'L') l_array[i][j] = 'm';

			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (l_array[i][j] == 'm') l_array[i][j] = '.';
		}
	}
}

void show_array(int R, int C, char** l_array) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << l_array[i][j];
		}
		cout << endl;
	}
}

void DFS(int R, int C, int cur_i, int cur_j, int start_i, int start_j, char** l_array) {
	if (DFS_flag) return;
	//cout << "DFS of " << cur_i << " " << cur_j << " " << start_i << " "<< start_j <<endl;
	if (cur_i == 0 || cur_j == 0) {
		
		int flag = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (l_array[i][j] == 'L') {
					flag = 1;
					start_i = i;
					start_j = j;
					break;
				}
			}
		}
		for (int i = 0; i <= R; i++) {
			for (int j = 0; j <= C; j++) {
				visited_arr[i][j] = 0;
			}
		}
		DFS(R, C, start_i, start_j, start_i, start_j, l_array);
	}
	

	visited_arr[cur_i][cur_j] = 1; //방문처리
	if (cur_i == 0 && cur_j == 0) return;

	if (l_array[cur_i][cur_j] == 'L' && (cur_i != start_i || cur_j != start_j)) {
		//cout << "founded" << endl;
		DFS_flag = 1;
		return ;
	}

	if (l_array[cur_i - 1][cur_j] == 'L' && (cur_i - 1 != start_i || cur_j != start_j)) {
		//cout << l_array[cur_i-1][cur_j] << endl;
		//cout << "founded L at" << cur_i - 1 << " " << cur_j<<endl;
		DFS_flag = 1;
		return;
	}
	if (l_array[cur_i + 1][cur_j] == 'L' && (cur_i + 1 != start_i || cur_j != start_j)) {
		//cout << "founded L at" << cur_i + 1 << " " << cur_j << endl;
		DFS_flag = 1;
		return;
	}
	if (l_array[cur_i][cur_j - 1] == 'L' && (cur_i != start_i || cur_j-1 != start_j)){
		//cout << "founded L at" << cur_i << " " << cur_j-1 << endl;
		DFS_flag = 1;
		return;
	}
	if (l_array[cur_i][cur_j + 1] == 'L' && (cur_i != start_i || cur_j+1!= start_j)) {
		//cout << "founded L at" << cur_i << " " << cur_j+1 << endl;
		DFS_flag = 1;
		return;
	}

	if (DFS_flag) return;
	
	if (l_array[cur_i - 1][cur_j] == '.' && !visited(cur_i - 1, cur_j)) {
		DFS(R, C, cur_i - 1, cur_j, start_i, start_j, l_array);
	}
	else return;
	if (l_array[cur_i + 1][cur_j] == '.' && !visited(cur_i+1, cur_j)) {
		DFS(R, C, cur_i + 1, cur_j,start_i, start_j, l_array);
	}
	if (l_array[cur_i][cur_j - 1] == '.' && !visited(cur_i, cur_j - 1)) {
		DFS(R, C, cur_i, cur_j - 1,start_i, start_j, l_array);
	}
	if (l_array[cur_i][cur_j + 1] == '.' && !visited(cur_i, cur_j + 1)) {
		DFS(R, C, cur_i, cur_j + 1,start_i, start_j, l_array);
	}
	return;
}

bool visited(int i, int j) {
	if (visited_arr[i][j] == 1) return 1;
	return 0;
}