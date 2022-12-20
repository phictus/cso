#include <iostream>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);

    uint64_t n, q;
    cin >> n;
    int64_t a[n + 1];
    for (size_t i = 1; i <= n; i++)
        cin >> a[i];

    uint64_t x = (n % 2 == 0) ? n / 2 : n / 2 + 1;
    uint64_t y = n / 2;

    int64_t o[x + 1];
    int64_t e[y + 1];

    o[0] = 0;
    for (size_t i = 1; i <= x; i++)
        o[i] = o[i - 1] + a[i * 2 - 1];
    e[0] = 0;
    for (size_t i = 1; i <= y; i++)
        e[i] = e[i - 1] + a[i * 2];

    cin >> q;
    while (q--) {
        uint64_t l, r;
        cin >> l >> r;

        int64_t v, w;
        if (l % 2 == 0) {
            if (r % 2 == 0)
                cout << (e[r / 2] - e[l / 2 - 1]) - (o[r / 2] - o[l / 2]) << endl;
            else
                cout << (e[r / 2] - e[l / 2 - 1]) - (o[r / 2 + 1] - o[l / 2]) << endl;
        } else {
            if (r % 2 == 0)
                cout << (o[r / 2] - o[l / 2]) - (e[r / 2] - e[l / 2]) << endl;
            else
                cout << (o[r / 2 + 1] - o[l / 2]) - (e[r / 2] - e[l / 2]) << endl;
        }
    }

    return 0;
}
