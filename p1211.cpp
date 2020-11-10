#include <iostream>
#include <cmath>

using namespace std;


/*
     abc
x     ed
----------
     ***
    ***
----------
    ****
*/

bool busket[10] = {};// all false

bool isValid(int n){
    int digit = int(log10(n));
    // cout << n << endl;
    for(int i = 0; i <= digit; ++i){
        // cout << n << " " << n/int(pow(10,i)) << endl;
        // cout << n%10 << " ";
        if(!busket[n%10])
            return false;
        // cout << n << " ";
        n /= 10;
    }
    // cout << endl;
    return true;
}

int makeNum(int g, int s, int b = 0){ // Bai Shi Ge
    return b*100+s*10+g;
}

int main(){
    int n;
    cin >> n;
    int nums[9];

    int temp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums[i] = temp;
        busket[temp] = true;
    }
    int cnt = 0;
    for(int c = 0; c < n; ++c){
        for(int b = 0; b < n; ++b){
            for(int a = 0; a < n; ++a){
                for(int d = 0; d < n; ++d){
                    if(isValid(makeNum(nums[c],nums[b],nums[a]) * nums[d]) && makeNum(nums[c],nums[b],nums[a]) * nums[d] < 1000){
                        for(int e = 0; e < n; ++e){
                            if(isValid(makeNum(nums[c],nums[b],nums[a]) * nums[e]) && makeNum(nums[c],nums[b],nums[a]) * nums[e] < 1000){
                                if(
                                    isValid(makeNum(nums[c],nums[b],nums[a]) * makeNum(nums[d],nums[e])) &&
                                    makeNum(nums[c],nums[b],nums[a]) * makeNum(nums[d],nums[e]) < 10000){
                                    ++cnt;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // cout << endl;

    cout << cnt << endl;

    return 0;
}
