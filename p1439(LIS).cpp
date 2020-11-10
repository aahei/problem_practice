#include <iostream>
#include <algorithm>
#include <string.h>
// #include <bits/stdc++.h>

using namespace std;

int s1[100000];
int s2[100000];
int maxLen[2][100001];

int main(){
    int n;
    cin >> n;
    for(int j = 0; j < n; ++j){
        cin >> s1[j];
    }
    for(int j = 0; j < n; ++j){
        cin >> s2[j];
    }

    // cout << 1 << endl;

    memset(maxLen, 0, 100001*sizeof(int));

    // cout << 2 << endl;

    for(int i = 1; i <= n; ++i){
        maxLen[1][0] = 0;
        // cout << 4 << endl;
        for(int j = 1; j <= n; ++j){
            // cout << j << endl;
            if(s1[j-1] == s2[i-1])
                maxLen[1][j] = maxLen[0][j-1] + 1;
            else
                maxLen[1][j] = max(maxLen[1][j-1], maxLen[0][j]);
        }
        // cout << 3 << endl;
        memcpy(&maxLen[0][0], &maxLen[1][0], 100001*sizeof(int));
        //为什么不可以maxLen 和 maxLen+100000???
    }
    // cout << "end" << endl;

    cout << maxLen[0][n];
    return 0;
}
