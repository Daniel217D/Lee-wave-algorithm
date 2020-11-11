#pragma once
#include "Deque.h"

struct Point {
    unsigned int x;
    unsigned int y;
    unsigned int step;
};

void wave(int **arr, unsigned int x, unsigned int y);
Deque<Point> *restoration(int **arr, unsigned int x, unsigned int y);