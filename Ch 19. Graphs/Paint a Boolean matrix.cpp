#include <bits/stdc++.h>

using namespace std;

struct Cell {
    int row, column;
    Cell() {}
    Cell(int row, int column) : row(row), column(column) {}
    
    bool operator <(const Cell& op) const {
        if (row != op.row)
            return row < op.row;
        return column < op.column;
    }

    bool operator ==(const Cell& op) const {
        return (row == op.row) && (column == op.column);
    }

    bool operator !=(const Cell& op) const {
        return !((row == op.row) && (column == op.column));
    }
};

class Solution {
private:
    int n, m;
    const int num_of_steps = 4;
    map<Cell, int> distance;
    vector<vector<int>> matrix;
    set<Cell> visited;
    vector<int> dx = {0,  0, 1, -1};
    vector<int> dy = {1, -1, 0,  0};
public:
    void read() {
        cin >> n >> m;
        matrix.resize(n, vector<int> (m));
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                cin >> matrix[row][column];
            }
        }
    }

    bool is_in_board(const Cell &op) {
        return (op.row >= 0 && op.row < n &&
               op.column >= 0 && op.column < m);
    }

    void solve() {
        Cell start(0, 0);
        queue<Cell> q;
        visited.insert(start);
        distance[start] = 0;
        q.push(start);
        while(!q.empty()) {
            Cell cell = q.front(); q.pop();
            if (matrix[cell.row][cell.column] == 2) {
                cout << distance[cell];
                return;
            }
            for (int step = 0; step < num_of_steps; ++step) {
                Cell neighbour(cell.row + dy[step], cell.column + dx[step]);
                if (!is_in_board(neighbour) || matrix[neighbour.row][neighbour.column] == 1) { continue; }
                Cell next_neighbour(neighbour.row + dy[step], neighbour.column + dx[step]);
                while(is_in_board(neighbour) &&
                      matrix[neighbour.row][neighbour.column] == 0 &&
                      is_in_board(next_neighbour) &&
                      matrix[next_neighbour.row][next_neighbour.column] != 1) {
                    neighbour = Cell(neighbour.row + dy[step], neighbour.column + dx[step]);
                    next_neighbour = Cell(next_neighbour.row + dy[step], next_neighbour.column + dx[step]);
                }
                if (is_in_board(neighbour) && !visited.count(neighbour)) {
                    visited.insert(neighbour);
                    distance[neighbour] = distance[cell] + 1;
                    q.push(neighbour);
                }
            }
        }
        cout << -1;
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    Solution solution;
    solution.read();
    solution.solve();

    return 0;
}