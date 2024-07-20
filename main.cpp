#include <iostream>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool isSafe(int grid[N][N], int row, int col, int num);


bool findUnassignedLocation(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    return isSafeInRow(grid, row, num) &&
           isSafeInCol(grid, col, num) &&
           isSafeInBox(grid, row - row % 3, col - col % 3, num);
}


bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findUnassignedLocation(grid, row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

// Print the grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {5, 3, UNASSIGNED, UNASSIGNED, 7, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED},
        {6, UNASSIGNED, UNASSIGNED, 1, 9, 5, UNASSIGNED, UNASSIGNED, UNASSIGNED},
        {UNASSIGNED, 9, 8, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6, UNASSIGNED},
        {8, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6, UNASSIGNED, UNASSIGNED, UNASSIGNED, 3},
        {4, UNASSIGNED, UNASSIGNED, 8, UNASSIGNED, 3, UNASSIGNED, UNASSIGNED, 1},
        {7, UNASSIGNED, UNASSIGNED, UNASSIGNED, 2, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6},
        {UNASSIGNED, 6, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 2, 8, UNASSIGNED},
        {UNASSIGNED, UNASSIGNED, UNASSIGNED, 4, 1, 9, UNASSIGNED, UNASSIGNED, 5},
        {UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 8, UNASSIGNED, UNASSIGNED, 7, 9}
    };

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists";
    }

    return 0;
}
