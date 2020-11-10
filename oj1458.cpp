#include <iostream>
#include <algorithm>

using namespace std;

int ps[100005];
int c;
int n;

bool IsExcced(int, int);
int BinarySearch(int, int);

bool IsExcced(int d, int cow){
    int p = ps[0];
    int index = 0;
    cow--;
    while(cow > 0){
        p = p + d;
        while(p > ps[index]){
            index++;
            if(index >= n)
                return true;
        }
        p = ps[index];
        cow--;
    }
    return false;
}

int BinarySearch(int a, int b){
    // cout << a << b << endl;
    if(a>=b){
        if(IsExcced(a, c))
            return a-1;
        else
            return a;
    }
    int mid = a + (b-a)/2;
    if(IsExcced(mid, c))
        return BinarySearch(a, mid-1);
    else
        return BinarySearch(mid+1, b);
}

int main(){
    int d;
    cin >> n >> c;

    for(int i = 0; i < n; i++)
        cin >> ps[i];

    sort(ps, ps+n-1);

    d = ps[n-1] / (c-1);

    cout << BinarySearch(1, d);
    return 0;
}
