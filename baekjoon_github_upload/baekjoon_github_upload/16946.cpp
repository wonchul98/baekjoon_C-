#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, section_idx = 1, section_size = 0;
int dx[4] = { 0 , 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int map[1000][1000];
int section_map[1000][1000] = { 0, };
int answer_map[1000][1000] = { 0, };
void build_section_map();
void build_answer_map();
bool visited_section(int a, int b);
void DFS(int a, int b);
bool print = true;
void print_section_map();
void print_map();
void print_answer_map();
vector<int> s_size;
int main() {
	s_size.push_back(0);
	freopen("input/16946_input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = int(input[j]) - '0';
		}
	}
	if(print) print_map();
	build_section_map();
	if (print) print_section_map();
	build_answer_map();
	print_answer_map();
	return 0;
}

void build_section_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && !visited_section(i, j)) { //해당 벽이 아직 section이 없다면
				/*DFS실행*/
				section_size = 0;
				DFS(i, j);
				s_size.push_back(section_size%10);
				if(print) cout << "section_idx: " << section_idx << " section_size: " << section_size << endl;
				section_idx++;
				
			}
			
		}
	}
}

void build_answer_map() {
	int ans = 0, n_x, n_y;
	vector<int> sections;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				ans = 0;
				for (int k = 0; k < 4; k++) {
					n_x = i + dx[k]; n_y = j + dy[k];
					if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
					if(section_map[n_x][n_y]!=0){
						sections.push_back(section_map[n_x][n_y]);
					}
				}
				sort(sections.begin(), sections.end());
				sections.erase(unique(sections.begin(), sections.end()), sections.end());
				if(print) cout << i << " " << j << "에서의 인접 section" << endl;
				for (int k = 0; k < sections.size(); k++) {
					if(print) cout << sections[k] << endl;
					ans += s_size[sections[k]];
				}
				while (!sections.empty()) sections.pop_back();
				answer_map[i][j] = (ans + 1)%10;
			}
		}
	}
}

bool visited_section(int a, int b) {
	if (section_map[a][b] == 0) return false;
	else return true;
}

void DFS(int a, int b){
	section_size++;
	if (print) cout << "DFS(" << a << "," << b << ")\n";
	section_map[a][b] = section_idx;
	for (int k = 0; k < 4; k++) {
		int n_x = a + dx[k], n_y = b + dy[k];
		if (print) cout << "DFS(" << a << "," << b << "): " << "n_x: " << n_x << " n_y: " << n_y << endl;
		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
		if (!visited_section(n_x, n_y) && map[n_x][n_y] == 0) {
			DFS(n_x, n_y);
		}
	}
		
}

void print_section_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << section_map[i][j] << " ";
		}
		cout << "\n";
	}
}

void print_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void print_answer_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << answer_map[i][j];
		}
		cout << "\n";
	}
}