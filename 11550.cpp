//
// Created by Muhammad Fajar Pamungkas on 2019-08-08.
//

#include <iostream>


using namespace std;


int main(){

//    freopen("in.txt","r", stdin);
//    freopen("out.txt","w", stdout);
    int n;
    scanf("%d", &n);
    while(n--){
        int u,v;

        scanf("%d %d", &u, &v);
        bool arr[8][28] = {false};
        for(int i = 0 ;i < u ; i++){
            for(int j = 0 ;j < v; j++){
                scanf("%d", &arr[i][j]);
            }
        }


        bool arr2[8][28] = {false};
        bool an = true;
        int count = 0;
        for(int i = 0 ; i < v ; i++){
            count = 0; int x,y;
            for(int j = 0 ; j < u ; j++){
                if(arr[j][i]){
                    !count ?  x = j : y = j;
                    count++;
                }

            }

            if(count != 2){
                an = false;
                break;
            }
            else if(count == 2){
                (arr2[x][y]) ? an = false : arr2[x][y] = arr2[y][x] = 1;
            }

        }



        an ? printf("Yes\n") : printf("No\n");
    }
}