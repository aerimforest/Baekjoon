// [15657] N과 M (8)
// https://www.acmicpc.net/problem/15657
// 백트래킹

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
bool visited[10];
vector <int> num;

// cnt = 현재까지 선택한 숫자의 개수
void dfs(int cnt)
{
    // m개를 모두 선택했다면
    if(cnt == m) {
        for(int i = 0 ; i < m ; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        if(arr[cnt - 1] <= num[i]) { // 직전에 선택한 수보다 크거나 같다면
            arr[cnt] = num[i]; // 선택한 숫자 저장
            dfs(cnt + 1);
        }
    }
}

int main(void)
{
    int tmp;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    dfs(0);
}