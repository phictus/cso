#include <iostream>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);

    uint64_t n, m;
    cin >> n >> m;

    if (m >= n)
    {
        cout << n << '\n';
        return 0;
    }

    uint64_t i = 1, j = 1;
    while (j < n - m)
    {
        i++;
        j += i;
    }

    cout << m + i << '\n';
    return 0;
}
