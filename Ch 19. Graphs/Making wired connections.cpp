#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123456;

class Solution {
private:
    vector<int> g[MAXN];
    int n, m;
    vector<bool> used;
    vector<int> color, fst_component;
    bool is_ok = true;
public:
    void read() {
        cin >> n >> m;
        used.resize(n, false);
        color.resize(n, 0);
        int a, b;
        for (int edge = 0; edge < m; ++edge) {
            cin >> a >> b;
            --a; --b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }

    void fill() {
        for (int vertex = 0; vertex < n; ++vertex) {
            if (color[vertex] == 0) {
                fst_component.emplace_back(vertex + 1);
            }
        }
    }

    void find_num() {
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!used[vertex]) {
                queue<int> q;
                int start = vertex;
                q.push(start);
                used[start] = true;
                color[start] = 0;
                while(!q.empty()) {
                    int v = q.front(); q.pop();
                    for (int neighbour : g[v]) {
                        if (used[neighbour]) { continue; }
                        used[neighbour] = true;
                        color[neighbour] = 1 - color[v];
                        q.push(neighbour);
                    }
                }
            }
        }
        for (int vertex = 0; vertex < n; ++vertex) {
            for (int neighbour : g[vertex]) {
                if (color[vertex] == color[neighbour]) {
                    is_ok = false;
                    break;
                }
            }
        }
        if (is_ok) {
            cout << "YES" << endl;
            fill();
            for (int guest : fst_component) {
                cout << guest << " ";
            }
        } else {
            cout << "NO";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    solution.find_num();

    return 0;
}