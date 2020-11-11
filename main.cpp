#include <iostream>

#include "libraries/lee_algorithm.h"
#include "libraries/Deque.h"

using std::cout;

int main() {
    /*
7 7
0 -1  0  0  0  0  0
0  0  0  0  0  0  0
0 -1  0  0  0  0  0
0  0  0  0  0  0  0
0 -1 -1 -1 -1  0  0
0 -1  0  0 -1  0 -1
0  0  0 -1  0  0  0
 */

    unsigned int rows, cols;
    std::cin >> rows >> cols;
    rows += 2;
    cols += 2;

    int **arr = new int *[rows];
    arr[0] = new int[cols];
    for (int i = 0; i < cols; ++i) {
        arr[0][i] = -1;
    }
    for (int i = 1; i < rows - 1; ++i) {
        arr[i] = new int[cols];
        arr[i][0] = -1;
        for (int j = 1; j < cols - 1; ++j) {
            std::cin >> arr[i][j];
        }
        arr[i][cols - 1] = -1;
    }
    arr[rows - 1] = new int[cols];
    for (int i = 0; i < cols; ++i) {
        arr[rows - 1][i] = -1;
    }
    std::cout << "\n";

    wave(arr, 1, 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] >= 0 && arr[i][j] <= 9) {
                std::cout << " ";
            }
            if (arr[i][j] == -1) {
                std::cout << "\033[0;31m-1\033[0m" << " ";
            } else {
                std::cout << "\033[0;32m" << arr[i][j] << "\033[0m" << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    auto res = restoration(arr, 7, 7);

    while (!res->IsEmpty()) {
        std::cout << res->Top().x << " " << res->Top().y << "\n";
        res->PopFront();
    }
    return 0;
}
