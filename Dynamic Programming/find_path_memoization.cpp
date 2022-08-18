// Given a grid of n x n, with some blocked cells,
// starting at position (0, 0) and having the possibility
// to move to the right or to down, how many path there is
// from starting position to end position (n - 1 x n - 1)
// Solved using recursion and memoization
// Estimated complexity: O(n^2)
#include <iostream>

using namespace std;

bool valid_cell(bool grid[6][6], int row, int col, int n) {
    if (row >= n || col >= n) return false;
    if (!grid[row][col]) return false;
    return true;
}

int count_paths(bool grid[6][6], int memo[6][6], int row, int col, int n) {
    if (!valid_cell(grid, row, col, n)) return 0;
    if (row == n - 1 && col == n - 1) return 1;
    if (memo[row][col] == 0) {
        memo[row][col] = count_paths(grid, memo, row + 1, col, n) +
            count_paths(grid, memo, row, col + 1, n);
    }
    return memo[row][col];
}

int main() {
    const int n = 6;
    bool grid[n][n] = {
        {1, 1, 1, 1, 1, 1}, 
        {0, 0, 1, 1, 0, 1}, 
        {1, 1, 1, 1, 1, 1}, 
        {1, 0, 0, 0, 0, 1}, 
        {1, 1, 1, 0, 0, 1}, 
        {1, 1, 1, 1, 1, 1}
    };

    int memo[n][n];

    int ans = count_paths(grid, memo, 0, 0, n);

    cout << ans << endl;

    return 0;
}

