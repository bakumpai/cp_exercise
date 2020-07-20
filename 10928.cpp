//
// Created by Muhammad Fajar Pamungkas on 2019-08-09.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main(){
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt","w",stdout);
    int n;
    int x;
    scanf("%d",&n);



    while(n--){

        scanf("%d",&x);
        map<int, vector<int> > ok;
        int min = 10000000000000;
        getchar();
        for(int i =0 ; i < x ;i++){
            string s;
            int count = 0;
            getline(cin, s);
            istringstream iss(s);
            for(string sss; iss >> s;){
                count++;
            }
            min = count < min ? count : min;
            ok[count].push_back(i);
        }

        for(int i =0 ; i < ok[min].size(); i++){
            cout<<ok[min][i]+1;
            if(i != ok[min].size()-1) cout<<" ";
        }

        cout<<endl;
    }
}