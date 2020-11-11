#include "lee_algorithm.h"
#include "Deque.h"

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void wave(int **arr, unsigned int x, unsigned int y) {
    auto d = new Deque<Point>;
    d->PushFront({x, y, 1});
    arr[y][x] = -1;
    do {
        Point p = d->PopBack();

        for (int i = 0; i < 4; ++i) {
            if (arr[p.x + dx[i]][p.y + dy[i]] == 0) {
                arr[p.x + dx[i]][p.y + dy[i]] = p.step;
                d->PushFront({p.x + dx[i], p.y + dy[i], p.step + 1});
            }
        }
    } while (!d->IsEmpty());

    arr[y][x] = 0;
}


Deque<Point> *restoration(int **arr, unsigned int x, unsigned int y) {
    Point p;
    auto s = new Deque<Point>;
    s->PushFront({x, y, (unsigned int)arr[y][x]});

    do {
        p = s->Top();

        for (int i = 0; i < 4; ++i) {
            if (arr[p.y + dy[i]][p.x + dx[i]] == p.step - 1) {
                s->PushFront({p.x + dx[i], p.y + dy[i], p.step - 1});
                break;
            }
        }
    } while(s->Top().step != 0);

    return s;
}