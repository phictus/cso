#include <iostream>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    uint64_t b[n];
    for (size_t i = 0; i < n; i++)
        cin >> b[i];

    int64_t sum = 0;
    for (size_t i = 0; i < n; i++) {
        int64_t x = b[i] * (i + 1) - sum;
        sum += x;
        cout << x << ' ';
    }

    return 0;
}
