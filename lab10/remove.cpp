#include <iostream>
#include <vector>

void solve();

int main() {
    int t;
    std::cin >> t;

    while(t--) { solve(); }
    
    return 0;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    } 

    int remove_length = 0;
    std::vector<int> check(n+1,0);

    for(int i = n-1; i > -1; i--)
    {
        if (check[a[i]] > 0) {
            remove_length = i+1;
            break;
        }

        check[a[i]]++;
    }

    std::cout << remove_length << std::endl;
}
