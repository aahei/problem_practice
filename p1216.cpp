#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int r;
    int tri[1000][1000];
    cin >> r;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j <= i; ++j){
            cin >> tri[i][j];
        }
    }

    // for(int i = 0; i < r; ++i){
    //     for(int j = 0; j < i; ++j){
    //         cout << tri[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = r - 2; i >= 0; --i){
        for(int j = 0; j < i+1; ++j){
            tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
            // cout << max(tri[i+1][j], tri[i+1][j+1]) << endl;
        }
    }
    cout << tri[0][0];
    return 0;
}
