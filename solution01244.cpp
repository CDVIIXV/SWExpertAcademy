#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    int t, tc;
    cin >> tc;
    for (t = 1; t <= tc; ++t) {
        string number;
        int change;
        cin >> number >> change;
        vector<int> digit;
        for (int i = 0; i < number.size(); ++i)
            digit.push_back(number[i] - '0');
        vector<vector<int>> record(10);

        for (int i = 0; i < digit.size() - 1 && change > 0; ++i) {
            int maxIndex = i;
            for (int j = digit.size() - 1; j > i; --j)
                if (digit[maxIndex] < digit[j])
                    maxIndex = j;
            if (maxIndex > i) {
                record[digit[maxIndex]].push_back(maxIndex);	// 뒷자리가 맨 앞에 저장되어있음.
                --change;
                swap(digit[maxIndex], digit[i]);
            }
        }

        // 큰 숫자 부분이 처리되지 않았을 때 처리
        int set = 9;
        while (set >= 0) {
            if (record[set].size() > 1)
                for (int j = record[set].size() - 1; j >= 0; --j) {	// 뒷자리 수 부터 저장되어있다. 그래서 거꾸로 탐색
                    int maxIndex2 = j;
                    for (int k = j - 1; k >= 0; --k)
                        if (digit[record[set][maxIndex2]] < digit[record[set][k]])
                            maxIndex2 = k;
                    if (maxIndex2 != j)
                        swap(digit[record[set][maxIndex2]], digit[record[set][j]]);
                }
            --set;
        }

        // 바꾸는 횟수가 남았을 때,
        if (change > 0) {
            bool same = false;
            for (int i = 0; i < digit.size() && !same; ++i)
                for (int j = i + 1; j < digit.size() && !same; ++j)
                    if (digit[i] == digit[j])
                        same = true;
            if (!same)
                if (change % 2 == 1)
                    swap(digit[digit.size() - 2], digit[digit.size() - 1]);
        }

        number.clear();
        for (int i = 0; i < digit.size(); ++i)
            number += digit[i] + '0';
        cout << "#" << t << " " << number << "\n";
    }
    return 0;
}