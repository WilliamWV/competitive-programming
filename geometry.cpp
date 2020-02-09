#include "geometry.h"

using namespace std;

Point* create_point(double x, double y){
    Point* new_point = (Point*) allocate(sizeof(Point));
    new_point->x = x;
    new_point->y = y;
    return new_point;
}

Line* create_line(Point* p1, Point* p2, bool finite){
    Line* new_line = (Line*) allocate(sizeof(Line));
    new_line->a = p1;
    new_line->b = p2;
    new_line->finite = finite;
    return new_line;
}

Line_equation* get_equation(Line* l){
    Line_equation* eq = (Line_equation*) allocate(sizeof(Line_equation));
    eq->a = (l->a->y - l->b->y) / (l->a->x - l->b->x);
    eq->b = l->a->y - eq->a*l->a->x;
    return eq;
}

double distance(Point* p1, Point* p2){
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
}

void rotate_point(Point* p1, double angle){
    int new_x = p1->x * cos(angle) - p1->y * sin(angle);
    int new_y = p1->x * sin(angle) + p1->y * cos(angle);
    p1->x = new_x;
    p1->y = new_y;
}

bool intersect(Line* l1, Line* l2){

}

Point* intersection(Line* l1, Line* l2){

}

bool contains_point(Line* l, Point* p);

double line_point_distance(Line* l, Point* p)

void convex_hull(vector<Point*> points);

