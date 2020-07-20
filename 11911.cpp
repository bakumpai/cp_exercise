//
// Created by Muhammad Fajar Pamungkas on 2019-08-09.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int m,n;

    while(scanf("%d %d", &m, &n) != EOF) {
        map<int, vector<int> > lst;
        int i = 0;
        int x;
        while (m--) {
            i++;
            scanf("%d", &x);
            lst[x].push_back(i);
        }

        int k;

        while (n--) {
            int x, y;
            scanf("%d %d", &x, &y);
            k = lst[y].size();
            (x-1 < k)? cout<<lst[y][x-1] : cout<<0;
            cout<<endl;
        }
    }
}