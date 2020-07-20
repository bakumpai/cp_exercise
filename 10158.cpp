#include <iostream>
#include <vector>
#include <numeric>
#define m 21000
using namespace std;

vector<int> p(m),r(m);
int n;

int find(int x){
    return (x == p[x]) ? x : find(p[x]);
}

bool isSameSet(int x, int y){

    return find(x) == find(y);
}

void join(int x, int y){
    if(!isSameSet(x,y)){
        int xx = find(x), yy = find(y);
        if(r[xx] > r[yy]) p[yy] = xx;
        else{
            p[xx] = yy;
            if(r[xx] == r[yy]) r[yy]++;
        }
    }
}

int enemyIndex(int x){
    return x+n;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    iota(p.begin(),p.end(), 0);
    fill(r.begin(),r.end(), 0);
    int x,y,z;
    scanf("%d", &n);

        while (scanf("%d %d %d",&z, &x, &y) && (x != 0 || y!= 0 || z != 0)) {
            if(z == 1){
                if(isSameSet(x,enemyIndex(y)) || isSameSet(y,enemyIndex(x))){
                    printf("-1\n");
                } else {
                    join(x,y);
                    join(enemyIndex(x),enemyIndex(y));
                }
            } else if (z == 2)
            {
                if(isSameSet(x,y) || isSameSet(enemyIndex(x),enemyIndex(y))){
                    printf("-1\n");
                } else {
                    join(x,enemyIndex(y));
                    join(y,enemyIndex(x));
                }
            } else if (z == 3){
                (isSameSet(x,y) || isSameSet(enemyIndex(x), enemyIndex(y))) ? printf("1\n") : printf("0\n");
            } else {
                (isSameSet(x,enemyIndex(y)) || isSameSet(y,enemyIndex(x))) ? printf("1\n") : printf("0\n");
            }
        }

    return 0;
}