#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int n, sum = 0, answer = 0;
        cin >> n;
        int *numbers = new int[n]();
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
            sum += numbers[i];
        }
        bool *dp = new bool[sum + 1]();
        dp[0] = true;
        for (int i = 0; i < n; ++i)
            for (int j = sum; j >= 0; --j)
                if (dp[j])
                    dp[j + numbers[i]] = true;
        for (int i = 0; i <= sum; ++i)
            if (dp[i])
                ++answer;
        delete[] numbers;
        delete[] dp;
        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}