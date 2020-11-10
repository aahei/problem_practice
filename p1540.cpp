#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    int m, n, cnt = 0;
    deque<int> mem;
    cin >> m >> n;
    
    int word;
    for(int i = 0; i < n; ++i)
    {
        cin >> word;
        if(find(mem.begin(), mem.end(), word) == mem.end())
        {
            ++cnt;
            if(mem.size() < m)
            {
                mem.push_back(word);
            }
            else
            {
                mem.pop_front();
                mem.push_back(word);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

