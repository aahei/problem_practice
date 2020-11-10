#include <iostream>
#include <string.h>

using namespace std;

char mp[21][21] = {};
long long steps[21][21] = {};
int cnt = 0;
int b1, b2, m1, m2;
int x = 0, y = 0;
int dp(){
    //test
    // mp[x][y] = 'o';
    // for(int i = 0; i < 21; i++){
    //     for(int j = 0; j < 21; j++)
    //         cout << mp[i][j];
    //     cout << endl;
    // }
    // cout << x << " " << y << " " << steps[x][y] << endl;
    //test
    if(steps[x][y] == -1)
        steps[x][y] = 0;
    else
        return steps[x][y];
    // if(x == b1 && y == b2){
    //     cnt++;
    //     return 1;
    // }
    if(x < b1 && mp[x+1][y] != 'x'){
        x++;
        steps[x-1][y] += dp();
        x--;
    }
    if(y < b2 && mp[x][y+1] != 'x'){
        y++;
        steps[x][y-1] += dp();
        y--;
    }
    return steps[x][y];
}

void gen_pos_of_horse(){
    mp[m1][m2] = 'x';
    if(m1 > 0){ //when m1 = 0, Ma can not move left
        if(m2 > 1)
            mp[m1-1][m2-2] = 'x';
        if(m2 < 19)
            mp[m1-1][m2+2] = 'x';
        if(m1 > 1){
            if(m2 > 0)
                mp[m1-2][m2-1] = 'x';
            if(m2 < 20)
                mp[m1-2][m2+1] = 'x';
        }
    }
    if(m1 < 20){ //when m1 = 20, Ma can not move right
        if(m2 > 1)
            mp[m1+1][m2-2] = 'x';
        if(m2 < 19)
            mp[m1+1][m2+2] = 'x';
        if(m1 < 19){
            if(m2 > 0)
                mp[m1+2][m2-1] = 'x';
            if(m2 < 20)
                mp[m1+2][m2+1] = 'x';
        }
    }
}

int main(){

    // test
    // memset(mp, ' ', sizeof(char)*21*21);
    // test
    memset(steps, -1, sizeof(steps));
    cin >> b1 >> b2 >> m1 >> m2;
    gen_pos_of_horse();
    steps[b1][b2] = 1;
    //test - output of map
    // for(int i = 0; i < 21; i++){
    //     for(int j = 0; j < 21; j++)
    //         cout << mp[i][j];
    //     cout << endl;
    // }
    //end test - output of map

    dp();

    cout << steps[0][0];

    return 0;
}
