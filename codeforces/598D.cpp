#include <iostream>

using namespace std;

constexpr uint32_t maxn = 1000;
constexpr uint32_t maxm = 1000;
constexpr int32_t g[] = { 1, -1, 0, 0 };
constexpr int32_t h[] = { 0, 0, 1, -1 };
uint32_t n, m, k;
bool grid[maxn][maxm];
int64_t mark[maxn][maxm];

void dfs(uint32_t x, uint32_t y, int64_t& result, size_t index)
{
    if (!grid[x][y])
        return;

    mark[x][y] = index;

    for (size_t i = 0; i < 4; i++) {
        int32_t nx = x + g[i];
        int32_t ny = y + h[i];
        if (nx < 0 || ny < 0 || x >= n || y >= m)
            continue;
        if (mark[nx][ny] == -1)
            dfs(nx, ny, result, index);

        if (!grid[nx][ny])
            result++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) {
            mark[i][j] = -1;
            char in;
            cin >> in;
            if (in == '.')
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }

    uint64_t results[k];
    for (size_t i = 0; i < k; i++) {
        size_t x, y;
        cin >> x >> y;

        int64_t result = mark[x - 1][y - 1];
        if (result == -1) {
            result = 0;
            dfs(x - 1, y - 1, result, i);
            results[i] = result;
        } else
            result = results[result];

        cout << result << '\n';
    }

    return 0;
}
