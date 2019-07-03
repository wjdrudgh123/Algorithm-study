#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n = 0;
int m = 0;
string maze[101];
int result = 0;

void solution(int i, int j){
    maze[i][j] = '0';
    result++;
    if(i - 1 >= 0 && maze[i - 1][j] == '1') solution(i-1,j);
    if(i + 1 < n && maze[i + 1][j] == '1') solution(i+1,j);
    if(j - 1 >= 0 && maze[i][j -1] == '1') solution(i,j-1);
    if(j + 1 < m && maze[i][j + 1] == '1') solution(i,j+1);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> maze[i];
    }
    //미로 완성
    solution(0,0);
    cout << result;
    return 0;
}