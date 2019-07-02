#include <iostream>
#include <cmath>
using namespace std;

int n, *position;

int backtracking(int index);

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    cout.tie(NULL);
    int t, tc;
    cin >> tc;
    for (t = 1; t <= tc; ++t) {
        cin >> n;
        position = new int[n];
        cout << "#" << t << " " << backtracking(0) << "\n";
        delete[] position;
    }
    return 0;
}

int backtracking(int index) {
    if (index == n)		// index가 n에 다다르면 (퀸이 서로 겹치치않게 n개가 놓여진 상황이다.)
        return 1;		// 현재 놓은 횟수 1을 추가
    int answer = 0, left = n * index, right = n * (index + 1);		// index번째의 퀸이 놓여질 수 있는 가로줄의 맨 왼쪽부터 오른쪽까지 위치
    while (left < right)
    {
        bool conti = true;		// 현재 자리에 퀸을 배치하기 위한 변수
        for (int i = 0; i < index && conti; ++i)
        {
            int mod1 = left % n, mod2 = position[i] % n;
            if (mod1 - mod2 == 0 || abs(mod1 - mod2) == index - i)		// 같은 열이거나 대각선으로 만난다면
                conti = false;		// 현재 자리에 퀸을 배치하지 않는다.
        }
        if (conti)
        {
            position[index] = left;
            answer += backtracking(index + 1);
        }
        ++left;
    }
    return answer;
}