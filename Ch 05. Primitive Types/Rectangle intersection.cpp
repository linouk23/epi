#include "bits/stdc++.h"

using namespace std;

struct Rectangle {
    int x, y, width, height;
    
    bool is_intersect(const Rectangle& op) const {
        return (!(x + width < op.x)) && (!(op.x + op.width < x))
        && (!(y + height < op.y)) && (!(op.y + op.height < y));
    }
};

class Solution {
public:
    Rectangle insersect_rect(const Rectangle& r1, const Rectangle& r2) {
        if (r1.is_intersect(r2)) {
            return {-1, -1, -1, -1};
        }
        return {max(r1.x, r2.x), max(r1.y, r2.y),
            min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x),
            min(r1.y + r1.height, r2.y + r2.height) - max(r1.y, r2.y)};
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
