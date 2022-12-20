#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);

    uint64_t t;
    cin >> t;
    while (t--) {
        uint64_t n;
        cin >> n;
        uint64_t a[n];
        vector<pair<uint64_t, uint64_t>> b;
        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        for (size_t i = 0; i < n; i++) {
            uint64_t x = 1;
            while (a[i] > x)
                x *= 2;

            if (x - a[i] != 0)
                b.push_back(make_pair(i, x - a[i]));
        }

        cout << b.size() << '\n';
        for (const auto& result : b)
            cout << result.first + 1 << ' ' << result.second << '\n';
    }
}
