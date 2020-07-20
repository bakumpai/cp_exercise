//
// Created by Muhammad Fajar Pamungkas on 2019-08-23.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> p,r;
int out;

int find(int i){
   return p[i] == i ? i : find(p[i]);
}

bool isSameSet(int i, int j){
   return find(i) == find(j);
}

void join(int i, int j){
   if(!isSameSet(i,j)){
      out--;
      int x = find(i), y = find(j);
      if(r[x] > r[y]) p[y] = x;
      else{
         p[x] = y;
         if(r[y] == r[x]) r[y]++;
      }
   }
}

int main()
{
    int n,m;
    int ii = 0;
    while(scanf("%d %d", &n, &m) && (n && m)){
       ii++;
       out = n;
       p = vector<int>(n);
       r = p;
       iota(p.begin(),p.end(), 0);
       fill(r.begin(),r.end(),0);

       int i,j;
       while(m--) {
          scanf("%d %d", &i, &j);
          join(i-1,j-1);
       }

       printf("Case %d: %d\n", ii , out);
    }

    return 0;
}

