#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cnt = 0, ce = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            if (cnt < a+b) {
                cout << "Yes\n";
                cnt++;
            } else {
                cout << "No\n";
            }
        } else if (s[i] == 'E') {
            if (cnt < a+b && ce < b) {
                cout << "Yes\n";
                cnt++;
                ce++;
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    }
}
