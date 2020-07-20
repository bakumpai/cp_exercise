//
// Created by Muhammad Fajar Pamungkas on 2020-02-13.
//

#include <iostream>

using namespace std;

int arr[8]={-1};
bool ch[8] = {false};
int cnt = 0;
bool check(int j){
    for(int i = 0 ;i < j ; i++) {
        if ((j - i) == abs(arr[j] - arr[i])) return false;
    }

    return true;
}
void solve(int n){
    if(n == 8){
//        for (int i : arr) {
//            cout<< i <<" ";
//        }
        cnt++;
    } else {
        for(int i = 0 ;i < 8 ;i++){
            if(!ch[i]) {
                ch[i] = true;
                arr[n] = i;
                if (check(n)) {
                    solve(n + 1);
                }
                ch[i] = false;
                arr[n] = -1;
            }
        }
    }
}

int main()
{
    solve(0);
    cout<<cnt<<endl;
}
