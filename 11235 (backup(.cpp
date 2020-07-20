#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi st,A;
int n;

int l(int p)
{
  return p << 1;
}

int r(int p)
{
  return p << 1 | 1;
}

int conquer(int a, int b)
{
    if(a == -1) return b;
    if(b == -1) return a;

    return A[a] >= A[b] ? a : b;
}

void build(int p, int L, int R)
{
    if(L == R)
      st[p] = L;
    else {
      int m = (L+R) >> 1;
      build(l(p),L,m);
      build(r(p),m+1,R);
      st[p] = conquer(st[l(p)],st[r(p)]);
    }
}

int RMQ(int p, int L, int R, int i , int j)
{
    if(L > j || R < i)
      return -1;

    if(L >= i && R <= j)
      return st[p];

    int m = (L+R) >> 1;

    return conquer(RMQ(l(p),L,m,i,min(m,j)), RMQ(r(p),m+1,R,max(m+1,i),j));
}

int RMQ(int i, int j)
{
    return RMQ(1,0,n-1,i,j);
}

int main()
{
  //freopen("in.txt", "r",stdin);
  //freopen("out.txt","w",stdout);

  int m,o;

  while(scanf("%d", &m) && m)
  {

    vi pos,in;
    scanf("%d",&o);
    n = m;
    int cur, cnt = 0;
    for(int i = 0 ;i < m ; i++)
    {
       int x;
       scanf("%d", &x);
       in.push_back(x);


       if(cur == x)
       {
          cnt++;
          if( i == m-1)
          {
            for(int j = 0 ; j < cnt; j++)
            {
              A.push_back(cnt);
              pos.push_back(i-cnt+2);
            }
          }
       } else {
          if(i!=0){
            for(int j=0 ; j < cnt; j++)
            {
              A.push_back(cnt);
              pos.push_back(i-cnt+1);
            }
          }

          cnt = 1;
          if( i == m-1)
          {
            for(int j = 0 ; j < cnt; j++)
            {
              A.push_back(cnt);
              pos.push_back(i-cnt+2);
            }
          }

       }




      cur = x;
    }

    st = vi(4*n);
    build(1,0,n-1);
    while(o--)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      x--;
      y--;
      if(in[x] != in[y]){
        int p1 = pos[x] + A[x] - x - 1;
        int p2 = y - pos[y] + 2;
        int x1 = pos[x] + A[x],x2 = pos[y] - 1;
        int index = RMQ(x1-1,x2-2);
        int p3 = index == -1 ? -1 : A[index];
        printf("%d\n", max(p1,(max(p2,p3))));
      } else {
        printf("%d\n", y - x + 1);
      }
    }
    st.clear();
    A.clear();
  }
  return 0;
}
