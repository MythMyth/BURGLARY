#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> w;
set<int> res;
int n;
long long d;

void find(int currIndex, long long currVal, int currCount) {
    if(currVal + w[currIndex] == d) {
        res.insert(currCount + 1);
    }
    if(currIndex == n - 1) return;
    find(currIndex + 1, currVal + w[currIndex], currCount + 1);
    find(currIndex + 1, currVal , currCount);
}

int main() {
    int t; cin >> t;
    int rt = t;
    while( rt-- > 0) {
        cin >> n >> d;
        w.resize(n);
        res.clear();
        for(int i = 0; i < n; i++) {
            cin >> w[i];
        }
        find(0, 0, 0);
        if(res.size() == 0) {
            cout << "Case #" << t - rt << ": IMPOSSIBLE\n";
        } else if(res.size() == 1) {
            cout << "Case #" << t - rt << ": " << *(res.begin()) << "\n";
        } else {
            cout << "Case #" << t - rt << ": AMBIGIOUS\n";
        }
    }
    return 0;
}
