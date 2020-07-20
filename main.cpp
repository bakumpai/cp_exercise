#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;

    scanf("%d", &n);
    string tree;
    getchar();
    getchar();

    while(n--){
        int tot = 0;
        map<string, int> trees;
        while(getline(cin, tree)){
            if(tree.length() == 0)
                break;
            trees[tree]++;
            tot++;
        }

        for(auto x : trees)
        {
            printf("%s %.4f\n", x.first.c_str() , x.second*100.0/tot);
        }

        if(n)
            printf("\n");
    }


   return 0;
}