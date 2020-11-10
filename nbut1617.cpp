#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        set<int> s;
        while(m--){
            int a;
            cin >> a;
            if(a > 0 && a <= n)
                s.insert(a);
        }
        cout << n - s.size() << endl;
    }
    return 0;
}

//map做法

// #include <iostream>
// #include <map>
//
// using namespace std;
//
// int main(){
//     int n, m;
//     ios::sync_with_stdio(false);
//     while(cin >> n >> m){
//         map<int, bool> s;
//         while(m--){
//             int a;
//             cin >> a;
//             if(a > 0 && a <= n && s.find(a) == s.end())
//                 s.insert(make_pair(a, true));
//         }
//         cout << n - s.size() << endl;
//     }
//     return 0;
// }
