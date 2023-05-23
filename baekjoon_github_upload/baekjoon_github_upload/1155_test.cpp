#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    int N; //전체 디스크의 개수
    long long 	hanoi[3][3][31] = { 0, };
    char 		orders[6][3];
    freopen("input/1155_input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < 6; i++) {
        scanf("%s", orders[i]);
        orders[i][0] -= 'A';
        orders[i][1] -= 'A';
    }

    for (int i = 0; i < 6; i++) {
        int from = orders[i][0], to = orders[i][1];
        if (!hanoi[from][0][1] && !hanoi[from][1][1] && !hanoi[from][2][1]) hanoi[from][to][1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int from = 0; from < 3; from++) {
            for (int to = 0; to < 3; to++) {
                if (from != to) {
                    if (hanoi[from][3 - from - to][i - 1] && hanoi[3 - from - to][to][i - 1]) hanoi[from][to][i] = hanoi[from][3 - from - to][i - 1] + 1 + hanoi[3 - from - to][to][i - 1];
                    else if (hanoi[from][to][i - 1] && hanoi[to][from][i - 1]) hanoi[from][to][i] = 2 * hanoi[from][to][i - 1] + hanoi[to][from][i - 1] + 2;
                }
            }
        }
    }
    printf("%lld", hanoi[0][1][N] ? hanoi[0][1][N] : hanoi[0][2][N]);
}