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

struct Vertex {
    Cell fst_cell, snd_cell;
    Vertex(Cell op1, Cell op2) : fst_cell(op1), snd_cell(op2) {}

    bool operator <(const Vertex& op) const {
        if (fst_cell != op.fst_cell)
            return fst_cell < op.fst_cell;
        return snd_cell < op.snd_cell;
    }

    bool has_same_cells() {
        return fst_cell == snd_cell;
    }
};

class Solution {
private:
    const int n = 8;
    const int m = 8;
    map<Vertex, int> distance;
    set<Vertex> visited;
    string pos_fst, pos_snd;
    vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dy = {1,-1, 2, -2, 2, -2, 1, -1};
public:
    void read() {
        cin >> pos_fst >> pos_snd;
    }

    bool is_in_board(const Cell &op) {
        return (op.row >= 0 && op.row < n &&
               op.column >= 0 && op.column < m);
    }

    bool is_in_board(const Vertex &op) {
        return is_in_board(op.fst_cell) && is_in_board(op.snd_cell);
    }
    
    void solve() {
        Vertex start(Cell(pos_fst[0] - 'a', pos_fst[1] - '0' - 1),
                     Cell(pos_snd[0] - 'a', pos_snd[1] - '0' - 1));
        queue<Vertex> q;
        visited.insert(start);
        distance[start] = 0;
        q.push(start);
        while(!q.empty()) {
            Vertex vertex = q.front(); q.pop(); 
            if (vertex.has_same_cells()) {
                cout << distance[vertex];
                return;
            }
            for (int ind1 = 0; ind1 < n; ++ind1) {
                for (int ind2 = 0; ind2 < n; ++ind2) {
                    Vertex neighbour(Cell(vertex.fst_cell.row + dy[ind1], vertex.fst_cell.column + dx[ind1]),
                                     Cell(vertex.snd_cell.row + dy[ind2], vertex.snd_cell.column + dx[ind2]));
                    if (!visited.count(neighbour) && is_in_board(neighbour)) {
                        visited.insert(neighbour);
                        distance[neighbour] = distance[vertex] + 1;
                        q.push(neighbour);
                    }
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