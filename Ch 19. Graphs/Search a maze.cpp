#include <bits/stdc++.h>

using namespace std;

enum Direction { L, U, R, D };

struct Cell {
    int row, column;
    Direction last_dir;

    Cell() {}
    Cell(int row, int column, Direction last_dir) :
         row(row), column(column), last_dir(last_dir) {}

    bool operator <(const Cell& op) const {
        if (row != op.row)
            return row < op.row;
        if (column != op.column)
            return column < op.column;
        return last_dir < op.last_dir;
    }

    bool operator ==(const Cell& op) const {
        return (row == op.row) && (column == op.column) && 
                (last_dir == op.last_dir);
    }

    bool operator !=(const Cell& op) const {
        return (row != op.row) || (column != op.column) ||
                (last_dir != op.last_dir);
    }
};

class Solution {
private:
    Cell start, finish;
    vector<string> matrix;
    map<Direction, vector<Direction>> get_next_direction;
    map<Direction, pair<int, int>> get_next_coordinates;
    int n, m;

    map<Cell, int> distance;
    map<Cell, Cell> prev;
    set<Cell> visited;
    pair<int, int> start_pos;
    pair<int, int> finish_pos;
public:
    void read() {
        cin >> n >> m;
        matrix.resize(n);
        getline(cin, matrix[0]);
        for (int row = 0; row < n; ++row) {
            getline(cin, matrix[row]);
        }

        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (matrix[row][column] == 'S') {
                    start_pos = {row, column};
                } else if (matrix[row][column] == 'F') {
                    finish_pos = {row, column};
                }
            }
        }

        get_next_direction[Direction::L] = {Direction::L, Direction::U};
        get_next_direction[Direction::U] = {Direction::U, Direction::R};
        get_next_direction[Direction::R] = {Direction::R, Direction::D};
        get_next_direction[Direction::D] = {Direction::D, Direction::L};
        get_next_coordinates[Direction::L] = {0, -1};
        get_next_coordinates[Direction::U] = {-1,  0};
        get_next_coordinates[Direction::R] = {0,  1};
        get_next_coordinates[Direction::D] = {1, 0};
    }

    bool is_in_board(int row, int column) {
        return (row >= 0) && (row < n) &&
               (column >= 0) && (column < m);
    }

    void solve() {
        queue<Cell> q;
        vector<Direction> directions = {L, U, R, D};
        Cell fake_cell(-1, -1, Direction::L);
        for (const auto & direction : directions) {
            Cell start(start_pos.first, start_pos.second, direction);
            distance[start] = 0;
            prev[start] = fake_cell;
            q.push(start);
            visited.insert(start);
        }
        while(!q.empty()) {
            Cell cell = q.front(); q.pop();
            auto last_dir = cell.last_dir;
            for (auto direction : get_next_direction[last_dir]) {
                int new_row = cell.row + get_next_coordinates[direction].first;
                int new_column = cell.column + get_next_coordinates[direction].second;
                if (!is_in_board(new_row, new_column) || matrix[new_row][new_column] == 'X') {
                    continue;
                }
                
                Cell neighbour(new_row,
                               new_column,
                               direction);
                if (!visited.count(neighbour)) {
                    visited.insert(neighbour);
                    q.push(neighbour);
                    distance[neighbour] = distance[cell] + 1;
                    prev[neighbour] = cell;
                }
            }
        }
        int answer = INT_MAX;
        for (const auto & direction : directions) {
            Cell finish(finish_pos.first, finish_pos.second, direction);
            if (distance.count(finish)) {
                answer = min(answer, distance[finish]);
            }
        }
        cout << answer << endl;
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