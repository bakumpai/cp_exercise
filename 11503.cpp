//
// Created by Muhammad Fajar Pamungkas on 2019-08-23.
//
#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

map<string, string> p;
map<string, int> r,l;


string find(string j){
    return j == p[j] ? j : find(p[j]);
}

bool isSameSet(string i, string j){
    return find(i) == find(j);
}

void join(string i, string j){
    if(!isSameSet(i,j)){
        string x = find(i), y = find(j);
        if(r[x] > r[y]){
            p[y] = x;
            l[x] += l[y];
            cout<<l[x]<<endl;
        } else {
            p[x] = y;
            l[y] += l[x];
            cout<<l[y]<<endl;
            if(r[x] == r[y]) r[y]++;
        }
    } else {
        string x = find(i);
        cout<<l[x]<<endl;
    }
}

int main()
{
    int m,n;
    scanf("%d", &n);


    while(n--){
        p.clear();
        r.clear();
        l.clear();
        vector<pair<string,string>> pp;
        set<string> person;
        scanf("%d", &m);
        string s,ss;
        while(m--){
            cin>>s>>ss;
            pp.push_back(pair<string,string>(s,ss));
            person.insert(s);
            person.insert(ss);
        }

        for(set<string> :: iterator it = person.begin(); it != person.end(); it++){
            r.insert(pair<string,int>(*it,0));
            l.insert(pair<string,int>(*it,1));
            p.insert(pair<string,string>(*it,*it));
        }

        for(pair<string,string> i : pp){
            join(i.first,i.second);
        }
    }

    return 0;
}

