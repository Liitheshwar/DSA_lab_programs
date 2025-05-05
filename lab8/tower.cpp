#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> towers(n);
    long long total_blocks = 0;

    for (int i = 0; i < n; i++) {
        cin >> towers[i];
        total_blocks += towers[i];
    }

    sort(towers.begin(), towers.end());

    long long tower1 = towers[0];

    for (int i = 1; i < n; i++) {
        if (towers[i] > tower1) {
            tower1++;
            towers[i]--;
        }
    }

    cout << tower1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
