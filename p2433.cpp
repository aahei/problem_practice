#include <iostream>
#include <cmath>

int main()
{
    const double PI = 3.141593
    int n;
    cin >> n;
    switch(n)
    {
    case 1:
        cout << "I love Luogu";
        break;
    case 2:
        cout << 2 + 4 << " " << 10-2-4;
        break;
    case 3:
        cout << 14/4 << " " << 14-14%4 << " " << 14%4;
        break;
    case 4:
        cout << setprecision(6) << 500.0/3;
        break;
    case 5:
        cout << (260+220)/(20+12);
        break;
    case 6:
        cout << sqrt(6*6+9*9);
        break;
    case 7:
        cout << 110 << endl << 90 << endl << 0;
        break;
    case 8:
        cout << 2*PI*5 << endl << 5*5*PI << endl << 4/3 * PI * 5*5*5;
        break;
    case 9:
        cout << 22;
        break;
    case 10:
        
    case 11:
        cout << 100/3;
        break;
    case 12:
        cout << 'M' - 'A' + 1 << endl << (char)'A'+17;
        break;
    case 13:
        cout << cbrt(16*PI+100*PI);
        break;
    case 14:
        cout << 50;
    }
    cout << endl
    return 0;
}

