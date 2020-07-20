//
// Created by Muhammad Fajar Pamungkas on 2019-08-14.
//


#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <bitset>

using namespace std;



bitset<26> isAlive;


int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        isAlive.reset();
        int m;
        cin>>m;
        string s;
        cin>>s;
        set<int> aa;

        for(int i = 0; i < s.size() ; i++){
            isAlive.set(s[i]-'A');
        }


        vector< vector<int> > b(26);
        while(m--){
            cin >> s;
            b[s[0] - 'A'].push_back(s[1] - 'A');
            aa.insert(s[0]-'A');
            aa.insert(s[1]-'A');
            b[s[1] - 'A'].push_back(s[0] - 'A');
        }

        int years = 0;

        while(isAlive.count() < n){
            vector<int> aaaa;
            bool check = false;
            for (set<int>::iterator it = aa.begin(); it != aa.end(); it++) {
                int count = 0;
                if (!isAlive[*it]) {
                    for (int ii = 0; ii < b[*it].size(); ii++) {
                        isAlive[b[*it][ii]] ? count++ : count;
                        if (count >= 3) {
                            aaaa.push_back(*it);
                            check = true;
                            break;
                        }
                    }
                }
            }

            if(check) {
                for(int i: aaaa) isAlive.set(i);
                years++;
            }
            else {
                break;
            }

        }

        (isAlive.count() >= n) ? printf("WAKE UP IN, %d, YEARS\n",years) : printf("THIS BRAIN NEVER WAKES UP\n");
    }

    return 0;

}
