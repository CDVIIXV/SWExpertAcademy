#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        long number, answer = 0, sqr;
        cin >> number;
        while (number > 2) {
            sqr = (int)ceil(sqrt(number));
            answer += sqr * sqr - number + 1;
            number = sqr;
        }
        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}