#include <iostream>

using namespace std;

int n, m, items[3402][2];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> items[i][1] >> items[i][2];
    }

    return 0;
}
