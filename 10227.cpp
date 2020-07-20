//
// Created by Muhammad Fajar Pamungkas on 2019-08-12.
//

#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>
#include <cstring>

using namespace std;

vector<int> tp(100),rtp(100);
vector < set <int> > opinion;
int res;



int find(int x){
    return (x == tp[x]) ? x : find(tp[x]);
}

bool sameSet(int x, int y){
    return find(x) == find(y);
}

void join(int x, int y){
    if(!sameSet(x,y)){
        res--;
        int xx = find(x), yy = find(y);
        if(rtp[xx] > rtp[yy]) tp[yy] = xx;
        else {
            tp[xx] = yy;
            if(rtp[xx] == rtp[yy]) rtp[yy]++;
        }
    }
}


int main(){
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    while(n--){
        iota(tp.begin(), tp.end(), 0);
        fill(rtp.begin(), rtp.end(), 0);
        int p,t,i,j;
        scanf("%d %d", &p, &t);
        opinion.assign(p, set<int>());
        res = p;
        char s[4];
        getchar();
        while(gets(s)){
            if(strlen(s) == 0) break;
            sscanf(s,"%d %d", &i, &j);
            opinion[i-1].insert(j-1);
        };

        for(int i = 0 ; i < p - 1; i++){
            for(int j = i+1; j < p ; j++){
                if(opinion[i] == opinion[j]) join(i,j);
            }
        }

        cout<<res<<endl;
        if(n != 0) cout<<endl;
    }

    return 0;
}
