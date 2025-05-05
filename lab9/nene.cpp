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
    int n, m;

    std::cin >> n >> m;

    std::vector <int> pos(n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> pos[i];
    }
    
    std::vector <int> set(m);
    for (int i = 0; i < m; i++) 
    {
        std::cin >> set[i];
    }

    int lpos = pos[0];
    for ( int i = 0; i < m; i++)
    {
        if (lpos > set[i]) {
            std::cout << set[i] << ' ';
        }
        else {
            std::cout << lpos-1 << " ";
        }
    }
    std::cout << std::endl;
}