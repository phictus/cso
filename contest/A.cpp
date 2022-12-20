#include <ios>
#include <iostream>

using namespace std;

uint64_t factor2(uint64_t num)
{
    uint64_t result = 0;

    while (num % 2 == 0) {
        num /= 2;
        result++;
    }

    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    uint64_t t;
    cin >> t;

    while (t--) {
        uint64_t n;
        cin >> n;
        uint64_t a[n];
        uint64_t result = 18446744073709551615ULL;
        uint64_t numberOfOdds = 0;
        for (size_t i = 0; i < n; i++) {
            cin >> a[i];
            uint64_t fac2 = factor2(a[i]);
            if (fac2 == 0) {
                numberOfOdds++;
                if ((a[i] + 3) % 4 == 0)
                    result = 1;
                else {
                    uint64_t x = 0;
                    uint64_t y = a[i];
                    while (y % 2 == 1) {
                        y /= 2;
                        x++;
                    }
                    if (result > x)
                        result = x;
                }
            } else if (result > fac2)
                result = fac2;
        }

        if (numberOfOdds % 2 == 0)
            cout << 0 << '\n';
        else
            cout << result << '\n';
    }
}
