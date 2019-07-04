#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int solution(string a[], int n, int m, int N, int M){
    queue<pair<int,int>> q;
    q.push(make_pair(n, m));
    a[n][m] = '0';
    int result = 0;
    int goX = 0;
    int goY = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int lastY = q.back().second;
        int temp = 0;
        q.pop();
        cout << x << "," << y << "," << q.size() << endl;
        // if(y < lastY){
        //     continue;
        // }
        result++;
        if(x + 1 >= 0 && a[x+1][y] == '1'){
            q.push(make_pair(x+1, y));
            a[x+1][y] = '0';
            temp++;
            goX++;
        }
        if(y + 1 >= 0 && a[x][y + 1] == '1'){
            q.push(make_pair(x, y + 1));
            a[x][y+1] = '0';
            temp++;
            goY++;
        }
        if(y - 1 >= 0 && a[x][y-1] == '1'){
            q.push(make_pair(x, y-1));
            a[x][y-1] = '0';
            temp++;
        }
        if(x - 1 >= 0 && a[x-1][y] == '1'){
            q.push(make_pair(x-1, y));
            a[x-1][y] = '0';
            temp++;
        }
        if(x == N -1 && y == M - 1){
            break;
        }
        if(temp == 0){
            cout << "back" <<x <<","<< y<< endl;
            result--;
        }
    }
    cout << "out" <<result << ","<< goX << "," <<goY << endl;
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
    return 0;
}