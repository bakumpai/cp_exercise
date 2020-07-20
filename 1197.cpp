//
// Created by Muhammad Fajar Pamungkas on 2019-08-09.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> p,r;

int find(int i){
    return (p[i] == i) ? i : find(p[i]);
}

bool isSameSet(int i, int j){
    return find(i) == find(j);
}

void join(int i, int j){
    if(!isSameSet(i,j)){
        int x = find(i), y = find(j);
        if(r[x] > r[y]) p[y] = x;
        else{
            p[x] = y;
            if(r[x] == r[y]) r[y]++;
        }
    }
}

int main(){
    int m,n,j,k,l;

    while(scanf("%d %d", &n,&m) && (m != 0 || n != 0)) {
        p.assign(n,0);
        r.assign(n,0);
        iota(p.begin(),p.end(),0);
        while(m--){
            scanf("%d", &j);
            vector<int> y;
            while(j--){
                scanf("%d",&k);
                y.push_back(k);
            }

            for(int i =0 ; i < y.size() - 1 ;i++){
                join(y[i],y[i+1]);
            }
        }

        int sus = 0;

        for(int i = 0 ; i < p.size(); i++){
             if (isSameSet(0,i)) sus++;
        }

        cout<<sus<<endl;
    }

}
