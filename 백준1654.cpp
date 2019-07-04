#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int k = 0;
    int n = 0;
    cin >> k >> n;

    int line[10001] = {0};

    for(int i = 0; i < k; i++){
        cin >> line[i];
    }
    
    sort(line, line + k);

    int min = 1;
    int max = line[k-1];
    int result = 0;
    
    while(min <= max){
        int temp = 0;
        int mid = (min + max)/2;
        for(int i = k-1; i >=0; i--){
            temp += line[i] / mid;
        }
        if(temp == n){
            result = mid;
            min = mid + 1;
        }else{
            max = mid - 1;
        }
    }
    cout << result;
    return 0;
}