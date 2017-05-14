#include "bits/stdc++.h"

using namespace std;

struct Player {
    bool operator<(const Player& that) const { return height < that.height; }
    
    int height;
};

class Team {
public:
    explicit Team(const vector<int>& height) {
        for (int h : height) {
            players_.emplace_back(Player{h});
        }
    }
    
    // Checks if A can be placed in front of B.
    static bool valid_placement_exists(const Team& A, const Team& B) {
        vector<Player> A_sorted(A.SortPlayersByHeight());
        vector<Player> B_sorted(B.SortPlayersByHeight());
        for (int i = 0; i < A_sorted.size() && i < B_sorted.size(); ++i) {
            if (!(A_sorted[i] < B_sorted[i])) {
                // A_sorted[i] cannot be placed behind B_sorted[i].
                return false;
            }
        }
        return true;
    }
    
private:
    vector<Player> SortPlayersByHeight() const {
        vector<Player> sorted_players(players_);
        sort(sorted_players.begin(), sorted_players.end());
        return sorted_players;
    }
    
    vector<Player> players_;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
