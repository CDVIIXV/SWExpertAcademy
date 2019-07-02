#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int n, m, s, e, answer = 0;
        cin >> n >> m;

        bool link[50][50] = {0, };

        for(int i=0; i<m; ++i) {
            cin >> s >> e;
            link[s - 1][e - 1] = true;
            link[e - 1][s - 1] = true;
        }

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (link[i][j])
                    for (int k = j + 1; k < n; ++k)
                        if (link[j][k] && link[k][i])
                            ++answer;

        cout << answer << "\n";
    }
    return 0;
}