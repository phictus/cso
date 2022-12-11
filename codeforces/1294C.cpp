#include <iostream>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);

    uint32_t t;
    cin >> t;
    while (t > 0)
    {
        uint64_t n;
        cin >> n;

        for (uint64_t i = 2; i * i <= n; i++)
        {
            if (!(n % i))
            {
                uint64_t x = n / i;
                for (uint64_t j = i + 1; j * j < x; j++)
                {
                    if (!(x % j))
                    {
                        cout << "YES" << '\n' << i << ' ' << j << ' ' << x / j << '\n';
                        goto LABEL_0;
                    }
                }
            }
        }

        cout << "NO" << '\n';

        LABEL_0:
        t--;
    }

    return 0;
}
