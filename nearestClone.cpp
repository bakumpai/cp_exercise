//
// Created by Muhammad Fajar Pamungkas on 2020-02-24.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph = vector<vector<int>>();
vector<int> labels = vector<int>();
bool visited[100007] = {0};
bool fnd = false;
int dist = 0;
int cntFound = 0;
int mn = 2000000000;

void dfs(int j, int clone){
    if(!visited[j]){
        visited[j] = 1;
        dist++;
        if(labels[j] == clone){
            cntFound++;
        }

        if(cntFound > 1){
            fnd = true;
            if(mn > dist) mn = dist;
            dist = 0;
        }

        int sze = graph[j].size();
        for (int i = 0; i < sze; i++) {
            dfs(graph[j][i], clone);
        }
    } else {
        dist--;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i =0 ;i < n ;i++){
        graph.push_back(vector<int>());
    }

    for(int i =0 ;i < m ; i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 0 ;i < n ; i++){
        labels.emplace_back();
    }

    for(int i = 0 ;i < n ;i++){
        int x;
        cin>>x;
        labels[i] = x;
    }

    int clone;
    int start;
    cin>>clone;

    for(int i =0 ; i < n ; i++){
        if(labels[i] == clone) {
            start = i;
            break;
        }
    }

    for(int i = start ; i < n ;i++){
        int sz = graph[i].size();
        for(int j = 0; j < sz ; j++){
            dfs(graph[i][j], clone);
            dist = 0;
        }
    }

    if(fnd)
        cout<<mn+1;
    else
        cout<<-1;

    return 0;

}

