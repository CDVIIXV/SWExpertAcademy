#include <iostream>
#include <string>
using namespace std;

const int mrow = 16, mcol = 16, path = 0, wall = 1, start_mark = 2, end_mark = 3;
const int movement[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

bool answer;
int map[mrow][mcol], start_row, start_col, end_row, end_col;

bool canMove(int row, int col);
void dfs(int crow, int ccol);

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 10;
    while (tc-- > 0) {
        int t;
        cin >> t;
        for (int i = 0; i < mrow; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < mcol; ++j) {
                map[i][j] = line[j] - '0';
                if (map[i][j] == start_mark) {
                    start_row = i;
                    start_col = j;
                }
                else if (map[i][j] == end_mark) {
                    end_row = i;
                    end_col = j;
                }
            }
        }
        answer = false;
        dfs(start_row, start_col);
        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}

bool canMove(int row, int col) {
    return 0 <= row && row < mrow && 0 <= col && col < mcol;
}

void dfs(int crow, int ccol) {
    if (!answer)
        for (int i = 0; i < 4; ++i) {
            int nrow = crow + movement[i][0], ncol = ccol + movement[i][1];
            if (canMove(nrow, ncol) && (map[nrow][ncol] == path || map[nrow][ncol] == end_mark)) {
                if (map[nrow][ncol] == end_mark) {
                    answer = true;
                    return;
                }
                map[nrow][ncol] = wall;
                dfs(nrow, ncol);
            }
        }
}