#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int d[100005];

bool fajo(int day, int faj, int maxi){
    int sum = 0;
    if(faj <= 0)
        return false;
    // cout << faj << endl;
    if(faj >= n - day){
        return true;
    }
    for(int i = day; i < n; i++){
        sum += d[i];
        if(sum > maxi){
            return fajo(i, faj-1, maxi);
        }
        if(sum == maxi){
            return fajo(i + 1, faj - 1, maxi);
        }
        // cout << "sum:" << sum << "day:" << i << endl;
    }
    return true;
}

int main(){
    int total = 0;
    int mini = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        cin >> d[i];
        total += d[i];
        mini = max(d[i], mini);
    }
    int l = mini;
    int r = total;
    int mid = l + (r - l) / 2;
    while(l < r){
        mid = l + (r - l) / 2;
        if(fajo(0, m, mid))
            r = mid;
        else{
            l = mid + 1;
            // cout << "false" << endl;
        }
        // cout << "l: " << l << "r:" << r << endl;
    }
    cout << l;
    return 0;
}
