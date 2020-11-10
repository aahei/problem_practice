#include <iostream>

using namespace std;

struct node{
    int face;
    string name;
}people[100000];

int main(){
    int n, m, pos = 0, a, s;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> people[i].face >> people[i].name;
    }
    // cout << endl;
    for(int i = 0; i < m; ++i){
        cin >> a >> s;
        // cout << a << " " << people[pos].face << " " << (a ^ people[pos].face) << endl;
        if(a ^ people[pos].face){// 逆时针，即正
            pos = (pos + s) % n;
        }else{
            pos = (pos - (s%n) + n) % n;
        }
    }
    cout << people[pos].name << endl;
    return 0;
}
