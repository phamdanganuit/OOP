#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        long long x = sqrt(k);
        if (x * x < k)
            x++;
        long long y = k / x;
        if (k % x != 0)
            y++;
        if (x > y)
            swap(x, y);
        if (k >= x * y || x >= y || k <= 0)
            cout << "-1 -1\n";
        else
            cout << x << " " << y << "\n";
    }
    return 0;
}
