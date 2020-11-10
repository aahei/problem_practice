#include <iostream>

using namespace std;

string map[100];
int n, m;

int dfs(int r, int c){
    // cout << r << ' ' << c << endl;
    if(map[r][c] != 'W')
        return 0;
    map[r][c] = '.';

    for(int i = -1; i <= 1; ++i)
        for(int j = -1; j <= 1; ++j){
            int nr = r + i, nc = c + j;
            if(nr >= 0 && nc >= 0 && nr < n && nc < m)
                dfs(nr, nc);
        }

    return 1;
}

int main(){
    int count = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> map[i];
    }
    
//    for(int i = 0; i < n; ++i)
//        cout << map[i] << endl;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
           count += dfs(i, j); 
        }
    }

    cout << count << endl;

    return 0;
}
