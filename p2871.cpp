#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int w[3410], d[3410], dp[12900];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
            cin >> w[i];
            cin >> d[i];
    }

    for(int i = m; i >= 0; --i){
        if(w[1] <= i){
            dp[i] = d[1];
        }
    }// Initialization

    for(int i = 2; i <= n; ++i){
        for(int j = m; j >= 0; --j){
            if(w[i] > j){
                ;//dp[j] = dp[j], namely nothing to do
            }else{
                dp[j] = max(dp[j], dp[j-w[i]] + d[i]);
            }
        }
    }

    cout << dp[m];

    return 0;
}
