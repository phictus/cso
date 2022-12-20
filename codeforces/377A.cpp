#include <iostream>

using namespace std;

constexpr uint32_t maxn = 500;
constexpr uint32_t maxm = 500;
constexpr int32_t g[] = { 1, -1, 0, 0 };
constexpr int32_t h[] = { 0, 0, 1, -1 };

char a[maxm][maxn];
bool mark[maxm][maxn];
uint32_t n, m, k;

void dfs(uint32_t x, uint32_t y)
{
    if (a[x][y] != '.')
        return;

    mark[x][y] = true;
    for (uint32_t i = 0; i < 4; i++) {
        int32_t nx = x + g[i];
        int32_t ny = y + h[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (!mark[nx][ny])
            dfs(nx, ny);
    }

    if (!k)
        return;
    a[x][y] = 'X';
    k--;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    int32_t startx = -1, starty = -1;

    cin >> n >> m >> k;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) {
            mark[j][i] = false;
            char in;
            cin >> in;
            a[j][i] = in;
            if (in == '.' && startx == -1) {
                startx = j;
                starty = i;
            }
        }

    dfs(startx, starty);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++)
            cout << a[j][i];
        cout << '\n';
    }

    return 0;
}
