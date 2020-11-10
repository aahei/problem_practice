#include <iostream>

using namespace std;

int len, n, m;
int d[50005];

bool check(int x)
{
    int cur = 0;
    int suivant = 1;
    int m_rest = m;
    while(cur < n && m_rest >= 0)
    {
        if(d[suivant] - d[cur] < x && m_rest >= 0)
        {
            suivant++;
            m_rest--;
        }
        else
        {
            cur = suivant;
            suivant++;
        }
    }
    if(cur == n)
        return true;
    else
        return false;
}

int main()
{
    cin >> len >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> d[i];
    }
    d[n] = len;

    int l = 0, r = len;
    int mid;
    int ans;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        } 
        else
            r = mid - 1;
        /* cout << "l:" << l << "r:" << r << endl; */
    }

    cout << ans << endl;

    return 0;
}

