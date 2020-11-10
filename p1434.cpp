#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int LIMIT = 100;
// const int INF = ~(1 << 31);

struct Area{
    int h;
    int x;
    int y;
    // Area(int hh):h(hh){}
};

bool operator < (const Area & a, const Area & b){
    if(a.h < b.h)
        return true;
    else
        return false;
}

int length[LIMIT][LIMIT];
Area height[LIMIT*LIMIT];
int h[LIMIT][LIMIT];

int main(){
    int r, c, highest = 1;
    cin >> r >> c;
    int cnt = 0;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j){
            cin >> height[cnt].h;
            height[cnt].x = j;
            height[cnt].y = i;
            length[i][j] = 1;
            h[i][j] = height[cnt].h;
            ++cnt;
        }



    sort(height, height+r*c);

for(int i = 0; i < r*c; ++i)
    cout << height[i].x << " " << height[i].y << " " << height[i].h << endl;


    for(int i = 0; i < r*c; ++i){
        if(height[i].x > 0 && height[i].h < h[height[i].x-1][height[i].y])// set left
            length[height[i].x-1][height[i].y] += length[height[i].x][height[i].y];
        if(height[i].x < c-1 && height[i].h < h[height[i].x+1][height[i].y])// set right
            length[height[i].x+1][height[i].y] += length[height[i].x][height[i].y];
        if(height[i].y < r-1 && height[i].h < h[height[i].x][height[i].y+1])// set down
            length[height[i].x][height[i].y+1] += length[height[i].x][height[i].y];
        if(height[i].y > 0 && height[i].h < h[height[i].x][height[i].y-1])// set up
            length[height[i].x][height[i].y-1] += length[height[i].x][height[i].y];

        cout << length[height[i].x][height[i].y] << endl;

        for(int k = 0; k < r; ++k){
            for(int j = 0; j < c; ++j){
                cout << length[k][j] << " ";
            }
            cout << endl;
        }

        highest = max(highest, length[height[i].x][height[i].y]);
    }

    cout << highest;

    return 0;
}
