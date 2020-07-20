//
// Created by Muhammad Fajar Pamungkas on 2019-08-09.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;
vector<int> p;
vector<int> r;

int findSet(int x)
{
    return p[x] == x ? x : findSet(p[x]);
}


bool isSameNet(int i, int j){
    return findSet(i) == findSet(j);
}


void con(int i, int j){
    if(!isSameNet(i,j)){
        int x = findSet(i), y = findSet(j);
        if(r[x] > r[y]) p[y] = x;
        else{
            p[x] = y;
            if(r[x] == r[y]) r[y]++;
        }
    }
}



int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,m,n,nn;

    scanf("%d",&n);
    nn = n;
    while(n--) {
        if (nn > n + 1) {
            cout<<endl;
        }
        int un = 0,suc = 0;
        scanf("%d",&m);
        p.assign(m, 0);
        r.assign(m, 0);
        iota(p.begin(),p.end(),0);
        char c;
        string s;
        getchar();
        while(getline(cin,s), s!= ""){
            stringstream ss(s);
            ss >> c >> i >> j;
            i--;
            j--;
            if(c == 'q'){
                isSameNet(i,j) ? suc++ : un++;
            } else {
                con(i,j);
            }
        }

        cout<<suc<<","<<un<<endl;
    }


}
