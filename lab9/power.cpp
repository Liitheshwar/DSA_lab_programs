#include <iostream>
#include <vector>

void solve();

int main() {
    int t;
    std::cin >> t;

    for (int j = 0; j < t; j++)
    {
        solve();
    }

    return 0;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector <int>pow(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> pow[i];
    }


    int max = pow[0], 
        max2 = pow[1];

    for (int i = 1; i < n; i++)
    {
        if (pow[i] > max) {
            max2 = max;
            max = pow[i];
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (pow[i] == max) {
            std::cout << max - max2 << " ";
        }
        else {
            std::cout << pow[i] - max << " ";
        }
    }
    std::cout << std::endl;
}