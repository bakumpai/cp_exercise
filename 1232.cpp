#include <iostream>

using namespace std;

struct Node{
    int mn,mx,flag;
};

Node nodes[1 << 18];
int total = 0;

int left(int p) { return p << 1;}
int right(int p) { return (p << 1) | 1;}

void propagate(int p){
    if(nodes[p].flag){
        nodes[left(p)].mx = nodes[left(p)].mn = nodes[left(p)].flag = nodes[p].flag;
        nodes[right(p)].mx = nodes[right(p)].mn = nodes[right(p)].flag = nodes[p].flag;
        nodes[p].flag = 0;
    }
}

void update(int p, int L, int R, int i, int j, int height){
    if(i > j) return;

    if(L != R) propagate(p);

    if(nodes[p].mn > height) return;

    if(L >= i && R <= j){
        if(nodes[p].mx <= height){
            total += R - L + 1;
            nodes[p].mx = nodes[p].mn = nodes[p].flag = height;
            return;
        }
    }

    int m = (L + R) >> 1;
    update(left(p),L, m, i, min(m,j), height);
    update(right(p), m+1, R, max(i,m+1), j, height);
    nodes[p].mx = max(nodes[left(p)].mx, nodes[right(p)].mx);
    nodes[p].mn = min(nodes[left(p)].mn, nodes[right(p)].mn);
}

int main()
{
    int n,m,x,y,h;

    scanf("%d", &n);

    while(n--)
    {
        total = 0;
        scanf("%d", &m);
        while(m--){
            scanf("%d %d %d", &x, &y, &h);
            update(1,1,100000,x,y-1,h);
        }
    }

    printf("%d", total);
}
