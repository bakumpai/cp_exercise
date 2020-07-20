#include <iostream>
#include <string.h>

using namespace std;


bool tr[32][32];
int cnt;
void build(char s, int k, int v, int l){
    cin >> s;
    if(s == 'p'){
        build(s, k, v, l/2);
        build(s, k+l/2, v, l/2);
        build(s, k, v+l/2, l/2);
        build(s,k+l/2, v+l/2, l/2);
    } else if(s == 'f') {
        for(int i = k ; i < (k+l) ; i++){
            for(int j = v ; j < v+l ; j++){
                if(!tr[i][j]){
                    tr[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
}

int main(){
        string s;

        int n;
        char c = '\0';
        cin>>n;

        while(n--){
            memset(tr, 0, sizeof(tr));
            cnt = 0;
            build(c,0,0,32);
            build(c,0,0,32);
            printf("There are %d black pixels.\n", cnt);
        }
}
