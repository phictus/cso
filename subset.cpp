#include <iostream>
#include <vector>

using namespace std;

vector<uint32_t> set;

void print_subsets(vector<uint32_t>::iterator element)
{
    static vector<uint32_t> subset = {};

    for (uint32_t e : subset)
        cout << e << ' ';
    cout << '\n';

    for (auto e = element; e != set.end(); e++)
    {
        subset.push_back(*e);
        print_subsets(e + 1);
        subset.pop_back();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    while (true)
    {
        uint32_t input;
        cin >> input;
        if (input == 0)
            break;
        else
            set.push_back(input);
    }

    print_subsets(set.begin());

    return 0;
}
