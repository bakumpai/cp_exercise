//
// Created by Muhammad Fajar Pamungkas on 2019-08-23.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

map<string, string> p;
map<string, int> r,s;

string find(string i){
  return i == p[i] ? i : find(p[i]);
}

bool isSameSet(string i, string j){
    return find(i) == find(j);
}

void join(string i, string j){
    if(!isSameSet(i,j)){
        string x = find(i), y = find(j);
        if(r[x] > r[y]) {
            p[y] = x;
            s[x] += s[y];
        }
        else {
            p[x] = y;
            s[y] += s[x];
            if(r[x] == r[y]) r[y]++;
        }
    }
}

int main()
{

    int m,n;
    while(scanf("%d %d", &n,&m)){
        p.clear();
        s.clear();
        r.clear();
        if(!n && !m)
            break;

        while(n--){
            string ss;
            cin>>ss;
            p.insert(pair<string,string>(ss,ss));
            s.insert(pair<string,int>(ss,1));
            r.insert(pair<string,int>(ss,0));
        }

        while(m--){
            string s1,s2;
            cin>>s1>>s2;
            join(s1,s2);
        }

        auto max = max_element(s.begin(), s.end(), [](const pair<string,int>& p1,
                const pair<string,int>& p2){
                return p1.second < p2.second;
        });

        printf("%d\n",max->second);
    }



}