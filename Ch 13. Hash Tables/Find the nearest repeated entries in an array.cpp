#include "bits/stdc++.h"

using namespace std;

int FindNearestRepetition(const vector<string>& text) {
    unordered_map<string, int> word_to_latest_index;
    int result = INT_MAX;
    for (int i = 0; i < text.size(); ++i) {
        if (word_to_latest_index.count(text[i])) {
            result = min(result, i - word_to_latest_index[text[i]]);
        }
        word_to_latest_index[text[i]] = i;
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    return 0;
}