#include <iostream>

using namespace std;

uint32_t table[9][9];

bool safe(uint32_t row, uint32_t col, uint32_t number)
{
    for (uint32_t i = 0; i < 9; i++)
    {
        if (table[i][col] == number)
            return false;
    }

    for (uint32_t i = 0; i < 9; i++)
    {
        if (table[row][i] == number)
            return false;
    }

    uint32_t x = row / 3;
    uint32_t y = col / 3;
    for (uint32_t i = 0; i < 3; i++)
    {
        for (uint32_t j = 0; j < 3; j++)
        {
            if (table[x * 3 + i][y * 3 + j] == number)
                return false;
        }
    }

    return true;
}

bool solve(uint32_t row, uint32_t col)
{
    if (row == 9)
    {
        if (col == 8)
            return true;
        else
        {
            col++;
            row = 0;
        }
    }

    if (table[row][col] == 0)
    {
        for (uint32_t i = 1; i <= 9; i++)
        {
            if (safe(row, col, i))
            {
                table[row][col] = i;
                if (solve(row + 1, col))
                    return true;
            }

            table[row][col] = 0;
        }

        return false;
    }
    else
        return solve(row + 1, col);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    for (uint32_t i = 0; i < 9; i++)
    {
        for (uint32_t j = 0; j < 9; j++)
            cin >> table[i][j];
    }

    if (solve(0, 0))
    {
        for (uint32_t i = 0; i < 9; i++)
        {
            for (uint32_t j = 0; j < 9; j++)
                cout << table[i][j] << ' ';

            cout << '\n';
        }
    }
    else
        cout << "Error!" << '\n';

    return 0;
}
