#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include "mm.h"

typedef struct point{
    double x;
    double y;
} Point;

typedef struct line{
    Point* a;
    Point* b;
    bool finite;
} Line;

// Equation of a line as in: ax + b = y 
typedef struct line_eq{
    double a;
    double b;
} Line_equation;


Point* create_point(double x, double y);

Line* create_line(Point* p1, Point* p2, bool finite = false);

Line_equation* get_equation(Line* l);

double distance(Point* p1, Point* p2);

void rotate_point(Point* p1, double angle);

bool intersect(Line* l1, Line* l2);

Point* intersection(Line* l1, Line* l2);

bool contains_point(Line* l, Point* p);

double line_point_distance(Line* l, Point* p)

void convex_hull(std::vector<Point*> points);

