//
// Created by Muhammad Fajar Pamungkas on 2019-08-24.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> p,r,s;
int total;

int find(int i){
    return i == p[i] ? i : find(p[i]);
}

bool isSameSet(int i, int j){
    return find(i) == find(j);
}

void join(int i, int j){
    if(!isSameSet(i,j)){
        int x = find(i), y = find(j);
        if(r[x] > r[y]){
            s[x] += s[y];
            s[y] -= s[y];
            p[y] = x;
        } else {
            s[y] += s[x];
            s[x] -= s[x];
            p[x] = y;
            if(r[x] == r[y]) r[y]++;
        }
    }
}

int main()
{
    int n,m;
    scanf("%d", &n);

    while(n--){
        int j,k;
        total = 0;
        scanf("%d %d", &j, &k);

        p = vector<int>(j);
        r = p;
        iota(p.begin(), p.end(), 0);
        fill(r.begin(), r.end(), 0);
        s = r;


        for(int i = 0 ;i < j ; i++){
            int amo;
            scanf("%d", &amo);
            s[i] = amo;
        }

        while(k--){
            int o,oo;
            scanf("%d %d", &o,&oo);
            join(o,oo);
        }

        bool c = true;
        for(int i =0 ;i < s.size() ;i++){
            if(s[i] != 0){
                c = false;
                break;
            }
        }
        c ? cout<<"POSSIBLE\n" : cout<<"IMPOSSIBLE\n";
    }

    return 0;
}