#include <iostream>
using namespace std;

#define EMPTY 0
#define N 9

// function which finds empty location
bool find_empty(int grid[N][N], int& row, int& column) {
    for (row = 0; row < N; row++) {
        for (column = 0; column < N; column++) {
            if (grid[row][column] == EMPTY) {
                return true;
            }
        }
    }
    return false;
}

// function which checks if number placed is ok(row)
bool check_row(int grid[N][N], int row, int x) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == x) {
            return true;
        }
    }
    return false;
}

// function which checks if number placed is ok(column)
bool check_column(int grid[N][N], int column, int x) {
    for (int i = 0; i < N; i++) {
        if (grid[i][column] == x) {
            return true;
        }
    }
    return false;
}

// function check the box
bool check_box(int grid[N][N], int row, int column, int x) {
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (grid[i + row][j+ column] == x) {
                return true;
            }
        }
    }
    return false;
}

// wrapper function
bool check_ok(int grid[N][N], int row, int column, int x) {
    return !check_row(grid, row, x) &&
         !check_column(grid, column, x) &&
         !check_box(grid, row - row % 3, column - column % 3, x) &&
         grid[row][column] == EMPTY;
}

// recursive function for backtracking
bool Solve(int grid[N][N]) {
    int row, col;
    if (!find_empty(grid, row, col)) {
        return true;
    }
    for (int i = 1; i <= 9; i++) {
        if (check_ok(grid, row, col, i)) {
            grid[row][col] = i;
            if (Solve(grid))  {
                return true;
            }
            else {
                grid[row][col] = EMPTY;
            }
        }
    }
    return false;
}

void print_grid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
            cout << endl;
    }
}

int main() {
    int grid[N][N];
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    cout << endl;
    if (Solve(grid) == true) {
      print_grid(grid);
   }
    return 0;
}


