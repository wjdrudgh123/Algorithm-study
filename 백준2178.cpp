#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

/* 
result 변수로 했을 때는 큐에 값 들어간 수대로 계속 증가가 됨
그래서 2차원 배열을 따로 설정해 전 좌표를 설정하고 증가 값을 넣음.
분기가 되도 전 배열(좌표)의 값에 더하기 때문에 result처럼 전체 큐 값으로 증가가 안됨을 알 수 있었음. 
*/
int solution(string a[], int n, int m, int N, int M){
    queue<pair<int,int>> q;
    q.push(make_pair(n, m));
    a[n][m] = '0';
    int result[N][M] = {0};
    result[n][m] = 1;
    while(!q.empty()){
        // cout << "큐 사이즈 : " << q.size() << endl;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // cout << "x: " << x << ", y: " << y << endl;
            if(x + 1 < N && a[x+1][y] == '1'){
                result[x+1][y] = result[x][y]+1;
                a[x+1][y] = '0';
                q.push(make_pair(x+1, y));
            }
            if(y + 1 < M && a[x][y + 1] == '1'){
                result[x][y+1] = result[x][y]+1;
                a[x][y+1] = '0';
                q.push(make_pair(x, y + 1));
            }
            if(y - 1 >= 0 && a[x][y-1] == '1'){
                result[x][y-1] = result[x][y]+1;
                a[x][y-1] = '0';
                q.push(make_pair(x, y-1));
            }
            if(x - 1 >= 0 && a[x-1][y] == '1'){
                result[x-1][y] = result[x][y]+1;
                a[x-1][y] = '0';
                q.push(make_pair(x-1, y));
            }
            if(x == N -1 && y == M - 1){
                return result[x][y];
            }
    }
    return 0;
}

int main(){

    int n = 0;
    int m = 0;
    string maze[101];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> maze[i];
    }
    //미로 완성
    int result = solution(maze, 0, 0, n, m);
    cout << result;
    return 0;
}