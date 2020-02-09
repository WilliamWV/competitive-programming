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

Point* infinite_lines_intersection(Line_equation* l1, Line_equation* l2){
    int cross_x = (l2->b - l1->b) / (l1->a - l2->a);
    int cross_y = l1->a * cross_x + l1->b;

    return (create_point(cross_x, cross_y));
}

bool intersect(Line* l1, Line* l2){
    Line_equation* l1_eq = get_equation(l1);
    Line_equation* l2_eq = get_equation(l2);
    
    if (l1_eq->a == l2_eq->a && l1_eq->b != l2_eq->b){ //parallell line
        return false;
    }

    // point where the lines would intersect if they are infinite lines;
    Point* virtual_cross_point = infinite_lines_intersection(l1_eq, l2_eq);
    
    return (contains_point(l1, virtual_cross_point) && contains_point(l2, virtual_cross_point));

}

Point* intersection(Line* l1, Line* l2){
    Line_equation* l1_eq = get_equation(l1);
    Line_equation* l2_eq = get_equation(l2);
    
    if (l1_eq->a == l2_eq->a && l1_eq->b != l2_eq->b){ 
        return NULL;
    }

    Point* virtual_cross_point = infinite_lines_intersection(l1_eq, l2_eq);
    if ((contains_point(l1, virtual_cross_point) && contains_point(l2, virtual_cross_point))){
        return virtual_cross_point;
    }
    return NULL;
    
}

bool contains_point(Line* l, Point* p){
    Line_equation* eq = get_equation(l);

    if (eq->a * p->x + eq->b != p->y)
        return false;
    else if (l->finite == false)
        return true;
    else return (
        p->x <= max(l->a->x, l->b->x) && p->x >= min(l->a->x, l->b->x) && 
        p->y <= max(l->a->y, l->b->y) && p->y >= min(l->a->y, l->b->y)
    );
}

double line_point_distance(Line* l, Point* p);

void convex_hull(vector<Point*> points);

