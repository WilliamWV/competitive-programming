#include <iostream>
#include <vector>
#include "mm.h"

typedef struct point{
    int x;
    int y;
} Point;

typedef struct line{
    Point* a;
    Point* b;
    bool finite;
} Line;

Point* create_point(int x, int y);

Line* create_line(int x, int y);

double distance(Point* p1, Point* p2);

void rotate_point(Point* p1, double angle);

bool intersect(Line* l1, Lin2* l2);

bool contains_point(Line* l, Point* p);

double line_point_distance(Line* l, Point* p)

void convex_hull(std::vector<Point*> points);

