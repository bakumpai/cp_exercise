//
// Created by Muhammad Fajar Pamungkas on 2020-02-12.
//

#include <iostream>

using namespace std;

int arr[5][5];

int ch[5][5] = {{0}};

int ch1[6][3] = {{-1, -1, 1},
                 {-1, 0,  2},
                 {0,  1,  2},
                 {1,  1,  1},
                 {1,  0,  2},
                 {0,  -1, 2}};
int ch2[6][3] = {{1,  -1, 2},
                 {-1, 0,  1},
                 {-1, 1,  2},
                 {0,  1,  1},
                 {1,  0,  1},
                 {0,  -1, 1}};

bool check(int i, int j, int diagonal) {
    if (diagonal == 1) {
        for (int ii = 0; ii < 6; ii++) {
            int x = i+ch1[ii][0];
            int y = j+ch1[ii][1];

            if (x >= 0 && x < 5 && y >= 0 && y < 5) {
                if (arr[x][y] == ch1[ii][2]) return false;
            }
        }
    } else if (diagonal == 2){
        for (int ii = 0; ii < 6; ii++) {
            int x = i+ch2[ii][0];
            int y = j+ch2[ii][1];
            if (x >= 0 && x < 5 && y >= 0 && y < 5) {
                if (arr[x][y] == ch2[ii][2]) return false;
            }
        }
    }

    return true;
}

void solve(int n, int ii, int jj) {

    if(ii == 3 && n < 10) return;

    if (n == 16) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout<<endl;
    } else {
        int i = ii;
        int j;
        if(jj % 5 == 0 && jj != 0){
            i = ii + 1;
        }

        i = i % 5;
        j = jj % 5;

        for(int k = 0 ;k < 3; k++){
            if(n >= 16) return;
            if (!ch[i][j]) {
                ch[i][j] = 1;
                if(check(i, j, k)){
                    arr[i][j] = k;
                    if(k) n++;
                    solve(n, i, j+1);
                    if(k) n--;
                }
                arr[i][j] = 0;
                ch[i][j] = 0;
            }
        }


    }
}

int main() {
    solve(0,0,0);
}

