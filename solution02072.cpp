#include <iostream>

using namespace std;

const int numberCount = 10;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int sum = 0, number;
        for (int i = 0; i < numberCount; ++i) {
            cin >> number;
            if (number & 1)
                sum += number;
        }
        cout << "#" << t << " " << sum << "\n";
    }

    return 0;
}