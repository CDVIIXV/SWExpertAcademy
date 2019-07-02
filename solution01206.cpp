#include <iostream>
#include <algorithm>

using namespace std;

const int testCount = 10, maxLength = 1000;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    for (int t = 1; t <= testCount; ++t) {
        int count, array[maxLength], answer = 0;
        cin >> count;
        for (int i = 0; i < count; ++i) {
            cin >> array[i];
            if (i - 2 >= 2 && i - 2 < count - 2) {
                int value = array[i-2] - max(max(array[i-4], array[i-3]), max(array[i-1], array[i]));
                answer += value > 0 ? value : 0;
            }
        }
        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}