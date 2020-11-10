#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int sum1 = 1, sum2 = 1;
    for(int i = 0; i < a.length(); i++){
        sum1 *= a[i] - 'A' + 1;
    }
    for(int i = 0; i < b.length(); i++){
        sum2 *= b[i] - 'A' + 1;
    }
    // cout << sum1 << sum2;
    if(sum1%47 == sum2%47)
        cout << "GO";
    else
        cout << "STAY";

    return 0;
}
