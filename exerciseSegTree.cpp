#include <iostream>
#include <vector>
using namespace std;
vector<int> st,A,B;
int n;

int left(int i){
    return i << 1;
}

int right(int i){
    return (i << 1) + 1;
}

void build(int p, int l, int r)
{
    if(l == r)
    {
        st[p] = A[l];
    } else {
        build(left(p), l, (l+r)/2);
        build(right(p), (l+r)/2+1, r);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = p1 + p2;
    }
}

int RSQ(int p, int l, int r, int i, int j)
{
    if(l > j || r < i)
        return -1;

    if(l >= i && r <= j){
        return st[p];
    }

    int p1 = RSQ(left(p), l, (l+r)/2,i,j);
    int p2 = RSQ(right(p), (l+r)/2+1, r, i, j);

    if(p1 == -1) return p2;
    if(p2 == -1) return p1;

    return p1+p2;
}

int rsq(int i, int j){
    return RSQ(1,0,n-1,i,j);
}

int main()
{
    int arr[] = {10,2,47,3,7,9,1,98,21};
    A = vector<int>(arr, arr+9);
    n = A.size();
    st.assign(n*4,0);
    build(1,0,n-1);
    printf("RSQ(3,8) = %d\n", rsq(3,8));
    printf("RSQ(1,7) = %d\n", rsq(1,7));
    return 0;

}

