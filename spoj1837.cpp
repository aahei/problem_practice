#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int n, f;
double pies[10005];
double pie_size[10005];

bool check(double size){
    int fri = f;
    // cout << size << endl;
    for(int i = n; i > 0; i--){
        fri -= int(pie_size[i-1] / size);
        // cout << "size:" << pie_size[i-1] << "fri:" << fri << endl;
        if(fri <= 0)
            return true;
    }
    return false;
}

int main(){
    double sum = 0;
    double l, r, mid;
    cin >> n >> f;
    f += 1;
    for(int i = 0; i < n; i++){
        cin >> pies[i];
        pie_size[i] = pies[i]*pies[i]*acos(-1);
        sum += pie_size[i];
    }

    // cout << sum << endl;

    double biggest_posible_size = sum / f;
    // double biggest_posible_size = 100000000;

    // l = 0.0001;
    l = 0.0;
    // r = biggest_posible_size;
    r = sum;

    while(l - r < -0.0001){
        mid = l + (r - l) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
        // cout << mid << l << r<< l-r << endl;
    }
    cout << fixed << setprecision(3) << l;
    return 0;
}
