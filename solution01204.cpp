#include <iostream>

using namespace std;

const int max_value = 100, student_count = 1000;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount, test;
    cin >> testCount;
    while (testCount-- > 0) {
        cin >> test;
        cout << "#" << test << " ";
        int score, count[max_value + 1] = {0, }, answer = 0, max = 0;
        for (int i = 0; i < student_count; ++i) {
            cin >> score;
            ++count[score];
        }
        for (int i = 0; i < max_value; ++i)
            if (max <= count[i]) {
                answer = i;
                max = count[i];
            }
        cout << answer << "\n";
    }
    return 0;
}