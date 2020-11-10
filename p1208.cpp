#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int p, a;
}lst[5000];

bool cmp(const node& a, const node& b){
    return a.p < b.p;
}

int main(){
    int m, n;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> lst[i].p >> lst[i].a;
    }

    sort(lst, lst+m, cmp);

    int pos = 0;
    int total = 0;

    while(n > 0){
        if(n >= lst[pos].a){
            n -= lst[pos].a;
            total += lst[pos].p * lst[pos].a;
        }else{
            total += lst[pos].p * n;
            n = 0;
        }
        ++pos;
    }

    cout << total << endl;

    return 0;
}
