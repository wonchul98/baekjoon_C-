#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;

queue<pair<int, int>> curWaterQ, nextWaterQ,curSwanQ, nextSwanQ;

int R, C;
char l_array[1502][1502];

int flag = 0;
bool visited_arr[1501][1501];
bool visited(int a, int b);
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void waterBFS();
void swanBFS();
void print_arr();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int lx, ly;
    cin >> R >> C;
   
    for (int i = 1; i <= R; i++) {
        
        for (int j = 1; j <= C; j++) {
            cin >> l_array[i][j];
            visited_arr[i][j] = false;  
            if (l_array[i][j] == '.') curWaterQ.push(make_pair(i, j));
            if (l_array[i][j] == 'L') {
                curWaterQ.push(make_pair(i, j));
                lx = i;
                ly = j;
            }

        }
    }
    curSwanQ.push(make_pair(lx, ly));
    //visited_arr[lx][ly] = 1;
    int cnt = 0;

    while (!flag) {
        //cout << "//////////////////////\n";
        
        cout << "cnt: " << cnt << endl;
        waterBFS();
        curWaterQ = nextWaterQ;
        //cout << "swanBFS\n";
        swanBFS();
        curSwanQ = nextSwanQ;
        if (!flag) cnt++;
        
        while (!nextWaterQ.empty()) {
            l_array[nextWaterQ.front().first][nextWaterQ.front().second] = '.';
            nextWaterQ.pop();
            
        }

        while (!nextSwanQ.empty()) nextSwanQ.pop();
        //print_arr();
        
    }

    cout << cnt;
    return 0;
}

bool visited(int a, int b) {
    if (visited_arr[a][b] == true) return true;
    return false;
}

void waterBFS() {
    while (!curWaterQ.empty()) {
        //cout << "while in waterBFS " << curWaterQ.front().first << " " << curWaterQ.front().second << endl;
        for (int i = 0; i < 4; i++) {
            int newX = curWaterQ.front().first + dx[i];
            int newY = curWaterQ.front().second + dy[i];
            if ((newX > 0 || newX <= R) && (newY > 0 || newY <= C)) {
                if (l_array[newX][newY] == 'X') {
                    nextWaterQ.push(make_pair(newX, newY));
                }
            }
        }
        curWaterQ.pop();
    }
}

void swanBFS() {
    while (!curSwanQ.empty()&&!flag) {
        if (visited(curSwanQ.front().first, curSwanQ.front().second)) {
            curSwanQ.pop();
            continue;
        }
        //cout << "while in SwanBFS:" << curSwanQ.front().first << " " << curSwanQ.front().second << endl;
        visited_arr[curSwanQ.front().first][curSwanQ.front().second] = 1;

        for (int i = 0; i < 4; i++) {
            int newX = curSwanQ.front().first + dx[i];
            int newY = curSwanQ.front().second + dy[i];
            if (visited(newX, newY)) continue;
            else if ((newX > 0 || newX <= R) && newY > 0 || newY <= C) {
                if (l_array[newX][newY] == 'X') {
                    nextSwanQ.push(make_pair(newX, newY));
                    //cout << "1: " << newX << " " << newY << endl;
                }
                if (l_array[newX][newY] == '.') {
                    curSwanQ.push(make_pair(newX, newY));
                    //cout << "2: " << newX << " " << newY << endl;
                }
                if (l_array[newX][newY] == 'L') {
                    flag = 1;
                    //cout << "////found////" << endl;
                    while (!curSwanQ.empty()) curSwanQ.pop(); goto a;
                }
            }
        }
        curSwanQ.pop();
    }
a: return;
}

void print_arr() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << l_array[i][j];
        }
        cout << "\n";
    }
}