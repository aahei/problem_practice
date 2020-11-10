#include <iostream>

using namespace std;

int ns[100000];
int nss[500000];
long long sum = 0;

void merge(int l, int r){
    if(l == r){
        nss[l] = ns[l];
        return;
    }

    int mid = l + (r - l) / 2; //p2 is mid

    merge(l, mid);
    merge(mid + 1, r);

    int p1 = l, p2 = mid + 1;
    int p = l;
    while(p1 <= mid || p2 <= r){
        while((ns[p1]<=ns[p2] || p2 > r) && p1 <= mid){
            nss[p] = ns[p1];
            p1++;
            p++;
        }
        // if(ns[p1] > ns[p2] && p2 <= r && p1 <= mid){
        //     sum += r - p2 + 1;
        // }
        while((ns[p2]<=ns[p1] || p1 > mid) && p2 <= r){
            if(ns[p2]<ns[p1]){
                sum += mid - p1 + 1;
            }
            nss[p] = ns[p2];
            p2++;
            p++;
        }
    }

    for(int i = l; i <= r; i++){
        ns[i] = nss[i];
        // cout << ns[i];
    }
    // cout << " " << sum << endl;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ns[i];
    }
    merge(0, n - 1);

    cout << sum;
    return 0;
}
