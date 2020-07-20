//
// Created by Muhammad Fajar Pamungkas on 2019-08-06.
//
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
//
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int a,b,c,n;


    while(scanf("%d",&n)!=EOF){
        stack<int> st;
        queue<int> que;
        priority_queue<int> pq;
        bool q = true,w = true,r = true;
        while(n--){
            int x,t;
            scanf("%d %d", &t, &x);
            if(t == 1) {
                st.push(x);que.push(x);pq.push(x);
            }
            else{
               if(q) {
                   if (st.empty() || st.top() != x) q = false;
                   if (q) st.pop();
               }

               if(w) {
                   if (que.empty() || que.front() != x) w = false;
                   if (w) que.pop();
               }

               if(r) {
                   if (pq.empty() || pq.top() != x) r = false;
                   if (r) pq.pop();
               }
            }


        }

        if(!q && !w && !r){
            printf("impossible\n");
        } else if (r && !q && !w){
            printf("priority queue\n");
        } else if (w && !r && !q){
            printf("queue\n");
        } else if(q && !w && !r){
            printf("stack\n");
        } else {
            printf("not sure\n");
        }
    }

    return 0;

}