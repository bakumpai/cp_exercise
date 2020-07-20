//
// Created by Muhammad Fajar Pamungkas on 2019-08-07.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m,n;
    while(scanf("%d %d", &m,&n)!=EOF){
        vector<int> adj[n],adj2[n];
        int p = 0;
        for(int i = 0 ; i < m ; i++){
            int k;
            scanf("%d",&k);
            vector<int> l;
            for(int j = 0 ; j < k ; j++){
                int x;
                scanf("%d", &x);
                l.push_back(x);
            }
            for(int jj =0 ; jj < l.size() ; jj++){
                int x;
                scanf("%d", &x);
                adj[l[jj]-1].push_back(x);
                adj2[l[jj]-1].push_back(i+1);
            }
            p++;
        }
        cout<<n<<" "<<m<<endl;
        for(int jj = 0 ; jj < n ; jj++){
            cout<<adj2[jj].size();
            if(adj2[jj].size()!=0) cout<<" ";
            for(auto  x = adj2[jj].begin(); x!= adj2[jj].end(); x++){
                cout<<*x;
                if(x!=adj2[jj].end()-1) cout<<" ";
            }
            cout<<endl;
            for(auto  x = adj[jj].begin(); x!= adj[jj].end(); x++){
                cout<<*x;
                if(x!=adj[jj].end()-1) {cout<<" ";}
            }
            cout<<endl;
        }
    }
}