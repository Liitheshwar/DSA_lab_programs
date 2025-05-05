#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
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

    vector<vector<string>> words(3,vector<string>(n));
    map<string,int> word_count;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> words[i][j];
            word_count[words[i][j]]++;
        }
    }

    vector<int> points(3,0);

    for (int i = 0; i < 3; i++)
    {
        for (string w : words[i])
        {
            if (word_count[w] == 1) {
                points[i] += 3;
            }
            else if (word_count[w] == 2) {
                points[i] += 1;
            }
        }
    }

    cout << points[0] << " " << points[1] << " " << points[2] << endl;

}