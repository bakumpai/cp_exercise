//
// Created by Muhammad Fajar Pamungkas on 2019-08-07.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>

using namespace std;
bitset<26> a,b;
vector<int> k[26];
bool matrix[26][26];
int o = 0;

void dfs(int n){
    a[n].flip();
    o++;
    for(int i = 0 ; i < 26 ; i++){
        if(!a[i] && matrix[n][i]) {
            dfs(i);
        }
    }
}

int main(){

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    string str,str2;
    scanf("%d", &n);
    int trees, acorns;
    while(n--){
        memset(matrix, 0, sizeof(matrix));
        a.reset();
        b.reset();
        bool aa = true;
        while(cin>>str){
            if(str[0] == '*'){
                break;

            }

            matrix[str[1]-'A'][str[3]-'A'] = 1;
            matrix[str[3]-'A'][str[1]-'A'] = 1;
        }

        cin>>str2;
        for(int i =0 ; i < str2.length(); i+=2)
        {
            b[str2[i]-'A'].flip();
        }

        trees = 0;
        acorns = 0;

        for(int i = 0 ;i < 26 ; i++){
            if(!a[i] && b[i]){
                o = 0;
                dfs(i);

                if(o > 1) trees++;

                if(o == 1) acorns++;
            }
        }

       printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }
}
