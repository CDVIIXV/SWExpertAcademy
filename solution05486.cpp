#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

const char blank = '_', my_car = 'z';
const int mrow = 6, mcol = 6, goal_position[] = { 2, 5 }, movement[] = { -mcol, -1, mcol, 1 };

unordered_set<string> record;

bool canMove(int cIndex, int nIndex) {
    return 0 <= nIndex && nIndex < mrow * mcol && abs(cIndex % mcol - nIndex % mcol) <= 1;
}

bool isGoal(string map) {
    return map.at(goal_position[0] * mcol + goal_position[1]) == my_car;
}

string move(string map, int cIndex, int direction, char car) {
    string nmap = map;
    int nIndex = cIndex + movement[direction];
    while (canMove(cIndex, nIndex) && nmap.at(nIndex) == car) {
        nmap[cIndex] = car;
        nmap[nIndex] = blank;
        cIndex = nIndex;
        nIndex += movement[direction];
    }
    return nmap;
}

int getBFSCount(string startMap) {
    if (isGoal(startMap)) return 0;
    record.clear();
    queue<string> maps;
    record.insert(startMap);
    maps.push(startMap);
    int qSize, moveCount = 0;
    while (!maps.empty()) {
        qSize = maps.size();
        for (int i = 0; i < qSize; ++i) {
            string currMap = maps.front();
            maps.pop();
            for (int j = 0; j < mrow * mcol; ++j)
                if (currMap.at(j) == blank)
                    for (int k = 0; k < 4; ++k) {
                        int nIndex = j + movement[k];
                        if (canMove(j, nIndex) && currMap.at(nIndex) != blank) {
                            char ncar = currMap.at(nIndex);
                            if ((k % 2 == 1) == (ncar >= 'a' && ncar <= 'z')) {
                                string nextMap = move(currMap, j, k, ncar);
                                if (isGoal(nextMap)) return moveCount + 1;
                                if (record.find(nextMap) == record.end()) {
                                    record.insert(nextMap);
                                    maps.push(nextMap);
                                }
                            }
                        }
                    }
        }
        ++moveCount;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    cout.tie(NULL);
    int t, tc;
    cin >> tc;
    for (t = 1; t <= tc; ++t) {
        string startMap = "", line;
        for (int i = 0; i < mrow; ++i) {
            cin >> line;
            startMap += line;
        }
        cout << "#" << t << " " << getBFSCount(startMap) << "\n";
    }
    return 0;
}