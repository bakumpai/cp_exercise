//
// Created by Muhammad Fajar Pamungkas on 2019-08-23.
//
#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> p,r,s;

int find(int j){
    return j == p[j] ? j : find(p[j]);
}

bool isSameSet(int i, int j){
    return find(i) == find(j);
}

void join(int i, int j){
    if(!isSameSet(i,j)){
        int x = find(i), y = find(j);
        if(r[x] > r[y]) {
            p[y] = x;
            s[x] += s[y];
        }
        else {
            p[x] = y;
            if(r[y] == r[x]) r[y]++;
            s[y]+=s[x];
        }
    }
}

int main(){
    int tc,n,m;

    scanf("%d", &tc);

    while(tc--){
        scanf("%d %d", &n, &m);
        p = vector<int>(n);
        r = p;
        s = p;

        iota(p.begin(), p.end(), 0);
        fill(r.begin(), r.end(), 0);
        fill(s.begin(), s.end(), 1);

        while(m--){
            int i,j;
            scanf("%d %d", &i, &j);
            join(i-1,j-1);
        }

        int max = *max_element(s.begin(), s.end());
        cout<<max<<endl;
    }
}