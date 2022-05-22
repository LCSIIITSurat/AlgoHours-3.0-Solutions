#include <bits/stdc++.h>

using namespace std;

/*

Given x,y,z number of circle, parabola and  straight line respectively.

Print the maximum number of intersection possible.

testCase 1:

3

3 4 2

3 1 9

2 1 1



*/

// Function to find the nCr

long long NcR(int n, int r)

{

    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
    cout << p << endl;
}

void solution()
{

    int x, y, z;
    cin >> x >> y >> z;

    // x,y,z are greater than equal to 2;
    // C P ST

    int ans = 2 * NcR(x, 2) + 4 * NcR(y, 2) + 1 * NcR(z, 2) + 4 * NcR(x, 1) * NcR(y, 1) + 2 * NcR(y, 1) * NcR(z, 1) + 2 * (NcR(z, 1)) * (NcR(x, 1));
    cout << ans << "\n";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout<<"Case #"<<i<<": ";
        solution();
    }
}
