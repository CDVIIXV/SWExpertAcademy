#include <iostream>
using namespace std;

const int mrow = 4, mcol = 4, maxSevenDigit = 9999999;
const int movement[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int map[mrow][mcol], answer;
bool check[maxSevenDigit + 1];

bool canMove(int row, int col);
void dfs(int row, int col, int count, int sum);

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        answer = 0;
        for (int i = 0; i <= maxSevenDigit; ++i)
            check[i] = false;
        for (int i = 0; i < mrow; ++i)
            for (int j = 0; j < mcol; ++j)
                cin >> map[i][j];
        for (int i = 0; i < mrow; ++i)
            for (int j = 0; j < mcol; ++j)
                dfs(i, j, 1, map[i][j]);
        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}

bool canMove(int row, int col) {
    return 0 <= row && row < mrow && 0 <= col && col < mcol;
}

void dfs(int row, int col, int count, int sum) {
    if (count == 7) {
        if (!check[sum]) {
            check[sum] = true;
            ++answer;
        }
    }
    else if (count < 7)
        for (int i = 0; i < 4; ++i) {
            int nrow = row + movement[i][0], ncol = col + movement[i][1];
            if (canMove(nrow, ncol))
                dfs(nrow, ncol, count + 1, sum * 10 + map[nrow][ncol]);
        }
}