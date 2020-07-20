//
// Created by Muhammad Fajar Pamungkas on 2019-08-05.
//

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int setToMin(int a){
    return (a < 0) ?  0 : a;
}

void printSet(multiset<int, greater <int> > l){
    multiset<int, greater <int> > :: iterator itr;
    for(itr = l.begin(); itr != l.end(); ++itr){
        printf("%d\n", *itr);
    }
}

int minSize(int a, int b){
    return (a > b) ? b : a;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    bool gWin, bWin;
    int n;
    int p;

    scanf("%d", &n);
    while(n){
        multiset<int, greater <int> > l1;
        multiset<int, greater <int> > l2;
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int g;

        while(b--){
            int g;
            scanf("%d", &g);
            l1.insert(g);
        }

        while(c--){
            int g;
            scanf("%d", &g);
            l2.insert(g);
        }

        while(l1.size() && l2.size()){

            int s1 = l1.size(), s2 = l2.size();
            int min = minSize(s1,s2);
            int loop = (minSize(s1,s2) > a ? a : min);
            multiset<int, greater < int > > :: iterator it,it2,itt,itt2;
            multiset<int, greater < int > > ll1,ll2;
            it = l1.begin();
            it2 = l2.begin();

            for(int i = 0 ;i < loop; i++){
                int pow1 = *it;
                int pow2 = *it2;
                int pp = setToMin(pow1 - pow2);
                int pp2 = setToMin(pow2 - pow1);

                if(pp>0) ll1.insert(pp);
                if(pp2>0) ll2.insert(pp2);

                l1.erase(it);
                l2.erase(it2);
                it = l1.begin();
                it2 = l2.begin();
            }

            itt = ll1.begin();
            itt2 = ll2.begin();

            for(itt; itt != ll1.end(); itt++){
                l1.insert(*itt);
            }

            for(itt2; itt2 != ll2.end(); itt2++){
                l2.insert(*itt2);
            }

            ll1.clear();
            ll2.clear();
        }

        if(!l1.size() && !l2.size()){
            printf("green and blue died\n");
        } else if(l1.size()){
            printf("green wins\n");
            printSet(l1);
        } else {
            printf("blue wins\n");
            printSet(l2);
        }

        n--;

        if(n)
            cout<<endl;
    }
}



