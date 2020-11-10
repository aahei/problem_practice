#include <iostream>

using namespace std;

int djset[10005];

int parent(int n)
{
    if(djset[n] == 0)
        return n;
    else
        return parent(n);
}

void join(int u, int v)
{
    if(parent(u) == parent(v))
        return;

    if(parent(u) > parent(v))
        djset[parent(v)] = parent(u);
    else
        djset[parent(u)] = parent(v);

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }

    for(int i = 1; i < n+1; ++i)
        cout << parent(i) << " ";
    cout << endl;

    return 0;
}

