#include <iostream>
#include <vector>

using namespace std;

vector<int> values, start,frequent,st;
int sz;

int left(int p){ return p << 1;}
int right(int p){ return (p << 1) | 1;}

int conquer(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;

    return (frequent[a] >= frequent[b]) ? a : b;
}

void build(int p, int l, int r){
    if(l == r){
        st[p] = l;
    }
    else {
        int m = (l+r) >> 1;
        build(left(p), l, m);
        build(right(p), m+1,r);
        st[p] = conquer(st[left(p)], st[right(p)]);
    }
}

int RMQ(int p, int L, int R, int i, int j){
    if(i > j) return -1;

    if(L >= i && R <= j)
        return st[p];

    int m = (L+R) >> 1;
    return conquer(
                RMQ(left(p), L, m, i, min(m,j)),
                RMQ(right(p), m+1, R, max(i,m+1), j));

}

int RMQ(int i, int j){
    return RMQ(1,1,sz, i,j);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt","w",stdout);

    int n,q;

    while(scanf("%d %d", &n, &q) && n) {
        values.push_back(-1);
        start.push_back(-1);
        frequent.push_back(-1);
        sz = n;
        int count = 0, temp;
        int full = n;
        while (n--) {
            int val;
            scanf("%d", &val);
            if (n == full - 1) temp = val;
            values.push_back(val);
            if (val != temp) {
                temp = val;
                int startS = start.size();
                for (int i = 0; i < count; i++) {
                    frequent.push_back(count);
                    start.push_back(startS + 1);
                }
                count = 1;
                if(n == 0){
                    int startS = start.size();
                    for(int i =0 ; i < count; i++){
                        frequent.push_back(count);
                        start.push_back(startS+1);
                    }
                }
            } else {
                count++;
                if(n == 0){
                    int startS = start.size();
                    for(int i =0 ; i < count; i++){
                        frequent.push_back(count);
                        start.push_back(startS+1);
                    }
                }
            }
        }

        st = vector<int>(4 * sz+1);
        build(1, 1, sz);

        int p1, p2, p3,x,y;
        int t = q;
        while (q--) {
            scanf("%d %d", &x, &y);
            if(values[x] != values[y]) {
                p1 = start[x] + frequent[x] - x - 1;
                int idx = RMQ(start[x] + frequent[x]-1, start[y] - 3);
                p2 = (idx == -1) ? idx : frequent[idx];
                p3 = y - start[y] + 2;
                printf("%d\n", max(max(p1, p2), p3));
            } else {
                printf("%d\n", y-x+1);
            }
        }
        frequent.clear();
        start.clear();
        st.clear();
        values.clear();
    }
}