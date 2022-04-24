#include <iostream>
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

bool comp_by_rows(pair<int, int> first_cell, pair<int, int> second_cell) {
    if (first_cell.first != second_cell.first) return first_cell.first < second_cell.first;
    return first_cell.second < second_cell.second;
}

bool comp_by_columns(pair<int, int> first_cell, pair<int, int> second_cell) {
    if (first_cell.second != second_cell.second) return first_cell.second < second_cell.second;
    return first_cell.first < second_cell.first;
}


int main() {
    int m, n, p;
    int result = 0;
    cin >> n >> m >> p;
    vector<pair<int, int>> cells;
    set<pair<int, int>> duplicates;
    for (int i = 0; i < p; ++i) {
        int x, y;
        cin >> x >> y;
        cells.emplace_back(x, y);
    }

    for (int i = 1; i <= m; i++) {
        cells.emplace_back(0, i);
        cells.emplace_back(n + 1, i);
    }
    for (int i = 1; i <= n; i++) {
        cells.emplace_back(i, 0);
        cells.emplace_back(i, m + 1);
    }

    sort(cells.begin(), cells.end(), comp_by_rows);
    for (int i = 0; i < cells.size() - 1; i++) {
        int diff = cells[i + 1].second - cells[i].second;
        if (cells[i].first == cells[i + 1].first && diff >= 2) {
            if (diff == 2) {
                pair<int, int> tmp = make_pair(cells[i].first,cells[i].second + 1);
                duplicates.insert(tmp);
            }
            else {
                result++;
            }
        }
    }

    sort(cells.begin(), cells.end(), comp_by_columns);
    for (int i = 0; i < cells.size() - 1; i++) {
        int diff = cells[i + 1].first - cells[i].first;
        if (cells[i].second == cells[i + 1].second && diff >= 2) {
            if (diff == 2) {
                pair<int, int> tmp = make_pair(cells[i].first + 1,cells[i].second);
                if (duplicates.find(tmp) != duplicates.end()) {
                    result++;
                }
            }
            else {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}
