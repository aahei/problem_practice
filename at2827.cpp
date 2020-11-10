#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int ns[100000];
int maxLen[100000];
int maxi = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> ns[i];
    }

    // memset(maxLen, 1, n*sizeof(int));
    //!!!memset设置每一个字节

    for(int i = 1; i < n; ++i){
        maxLen[i] = 1;
        for(int j = 0; j < i; ++j){
            if(ns[j] < ns[i]){
                    maxLen[i] = max(maxLen[j], maxLen[i]);
            }
        }
        maxi = max(maxi, maxLen[i]);
    }
    cout << maxi;
    return 0;
}
