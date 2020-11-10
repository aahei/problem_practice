#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int circle[105];
    cin >> n >> m;

    for(int i = 0; i < 105; ++i)
        circle[i] = i+1;
    // simulate simple singly linked list
    circle[n] = 1;

    int pre = 1, cur = 1;
    do
    {
        for(int i = 1; i < m; ++i)
        {
            pre = cur;
            cur = circle[cur];
        }
        cout << cur << " ";
        circle[pre] = circle[cur];
        cur = circle[cur];
    }
    while(circle[pre] != pre);
    
    cout << pre << endl;

    return 0;
}

