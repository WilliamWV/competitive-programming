#include "../include/geometry.h"

#define TOLERANCE 0.00001


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
    double new_x = p1->x * cos(angle) - p1->y * sin(angle);
    double new_y = p1->x * sin(angle) + p1->y * cos(angle);
    p1->x = new_x;
    p1->y = new_y;
}

Point* infinite_lines_intersection(Line_equation* l1, Line_equation* l2){
    
    double cross_x = (l2->b - l1->b) / (l1->a - l2->a);
    double cross_y = l1->a * cross_x + l1->b;

    return (create_point(cross_x, cross_y));
}

bool intersect(Line* l1, Line* l2){
    Line_equation* l1_eq = get_equation(l1);
    Line_equation* l2_eq = get_equation(l2);

    if (l1_eq->a == l2_eq->a){
        if(l1_eq->b == l2_eq->b){
            if (l1->finite && l2->finite){
                double max_x_l1 = l1->a->x;
                double min_x_l1 = l1->b->x;

                double max_x_l2 = l2->a->x;
                double min_x_l2 = l2->b->x;

                if (l1->a->x < l1->b->x){
                    max_x_l1 = l1->b->x;
                    min_x_l1 = l1->a->x;
                } 

                if (l2->a->x < l2->b->x){
                    max_x_l2 = l2->b->x;
                    min_x_l2 = l2->a->x;
                } 

                if ((max_x_l2 >= min_x_l1 && min_x_l1 >= min_x_l2) || (max_x_l1 >= min_x_l2 && min_x_l2 >= min_x_l1)){ // both segments intersect 
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return true;
            }
        }
        else{
            return false; // parallel line
        }
    }


    // point where the lines would intersect if they are infinite lines;
    Point* virtual_cross_point = infinite_lines_intersection(l1_eq, l2_eq);
    
    return (contains_point(l1, virtual_cross_point) && contains_point(l2, virtual_cross_point));

}

Point* intersection(Line* l1, Line* l2){
    Line_equation* l1_eq = get_equation(l1);
    Line_equation* l2_eq = get_equation(l2);
    
    if (l1_eq->a == l2_eq->a){
        if (l1_eq->b == l2_eq->b){ 
            if (!l1->finite && ! l2->finite){
                return l1->a; //any point of the lines would be valid since they are two infinite lines with the same equation
            }
            if (!l1->finite && l2->finite){
                return l2->a; // any point of l2 would be valid since it is a segment of l1
            }
            if (l1->finite && !l2->finite){
                return l1->a; // any point of l2 would be valid since it is a segment of l1
            }
            else{
                double max_x_l1 = l1->a->x;
                double min_x_l1 = l1->b->x;

                double max_x_l2 = l2->a->x;
                double min_x_l2 = l2->b->x;

                if (l1->a->x < l1->b->x){
                    max_x_l1 = l1->b->x;
                    min_x_l1 = l1->a->x;
                } 

                if (l2->a->x < l2->b->x){
                    max_x_l2 = l2->b->x;
                    min_x_l2 = l2->a->x;
                } 

                if ((max_x_l2 >= min_x_l1 && min_x_l1 >= min_x_l2) || (max_x_l1 >= min_x_l2 && min_x_l2 >= min_x_l1)){ // both segments intersect 
                    if ((max_x_l2 >= min_x_l1 && min_x_l1 >= min_x_l2)){
                        if (l1->a->x < l1->b->x) return l1->a;
                        else return l1->b;
                    }
                    else{
                        if(l2->a->x < l2->b->x) return l2->a;
                        else return l2->b;
                    }
                }
                else{
                    return NULL;
                }
            }

        }
        else{
            return NULL;
        }
    }

    Point* virtual_cross_point = infinite_lines_intersection(l1_eq, l2_eq);

    if ((contains_point(l1, virtual_cross_point) && contains_point(l2, virtual_cross_point))){
        return virtual_cross_point;
    }
    return NULL;
    
}

bool contains_point(Line* l, Point* p){
    Line_equation* eq = get_equation(l);

    if (abs((eq->a * p->x + eq->b) - p->y) > TOLERANCE){
        return false;
    }
    else if (l->finite == false)
        return true;
    else {
        return (
            p->x <= max(l->a->x, l->b->x) && p->x >= min(l->a->x, l->b->x) && 
            p->y <= max(l->a->y, l->b->y) && p->y >= min(l->a->y, l->b->y)
        );
    }
}

double line_point_distance(Line* l, Point* p){
    Line_equation* eq = get_equation(l);
    
    double a = eq->a;
    double b = -1;
    double c = eq->b;

    double infinite_line_dist = abs(a * p->x + b * p->y + c)/sqrt(a * a + b * b);

    if (!l->finite) return infinite_line_dist;
    else{
        Point* mini = l->a;
        Point* maxi = l->b;
        if (l->a->x > l->b->x){
            mini = l->b;
            maxi = l->a;
        }
        double delta = 0.01;

        Point* delta_mini = create_point(mini->x - delta, (mini->x - delta) * eq->a + eq->b);
        Point* delta_maxi = create_point(maxi->x + delta, (maxi->x + delta) * eq->a + eq->b);

        double distance_mini = distance(mini, p);
        double distance_maxi = distance(maxi, p);

        double dmini = (distance_mini - distance(delta_mini, p))/ delta;
        double dmaxi = (distance_maxi - distance(delta_maxi, p))/ delta;

        if (dmini < 0 && dmaxi < 0){ // the minimum distance is inside this line segment
            return infinite_line_dist;
        }
        else return min(distance_maxi, distance_mini);

    }
}

void swap(vector<Point*> &arr, int i, int j){
    Point* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

Point* pivot;

double angle_to_pivot(Point* p){
    return atan2(p->y - pivot->y, p->x - pivot->x);
}

bool angle_cmp(Point* p1, Point* p2){
    double p1_angle = angle_to_pivot(p1);
    double p2_angle = angle_to_pivot(p2);

    if (p1_angle != p2_angle)
        return p1_angle < p2_angle;
    else
        return distance(p1, pivot) < distance(p2, pivot);
}


#define CLOCKWISE 1
#define COLINEAR 0
#define COUNTERCLOCKWISE -1

// find orientation of the ordered triplet, this will determines
// if it does a curve to the right (clockwise) or to the left (counterclockwise)
// 1 -> clockwise
// 0 -> colinear points
// -1 -> counterclockwise (convex polygon)
int orientation(Point* p1, Point* p2, Point* p3){
    double value = (p2->y - p1->y) * (p3->x - p2->x) - 
                (p2->x - p1->x) * (p3->y - p2->y);
    
    if (abs(value) < TOLERANCE) return COLINEAR;
    return (value > 0)? CLOCKWISE : COUNTERCLOCKWISE;
}

vector<Point*> convex_hull(vector<Point*> points){
    if (points.size() <= 3){
        return points;
    }

    int pivot_index = 0;
    for (int i = 0; i < points.size(); i++){
        if (
            points[i]->y < points[pivot_index]->y || 
            (points[pivot_index]->y == points[i]->y && points[i]->x < points[pivot_index]->x)
            )
            pivot_index = i;
    }

    swap(points, 0, pivot_index);

    pivot = points[0];

    sort(++points.begin(), points.end(), angle_cmp); // the pivot (points[0]) is not sorted
    // check for multiple angles and keep the farthest

    vector<Point*> single_angles;
    single_angles.push_back(points[0]);

    for(int i = 2; i < points.size(); i++){ // starts at 2 to not consider the pivot itself
        if (angle_to_pivot(points[i]) != angle_to_pivot(points[i-1])){
            single_angles.push_back(points[i-1]);
        }
    }
    single_angles.push_back(points[points.size() - 1]);

    if (single_angles.size() < 3) return single_angles;

    vector<Point*> ch;
    ch.push_back(single_angles[0]);
    ch.push_back(single_angles[1]);
    ch.push_back(single_angles[2]);

    int ch_points = 3;
    for (int i = 3; i < single_angles.size(); i++){
        while (orientation(ch[ch_points-2], ch[ch_points-1], single_angles[i]) == CLOCKWISE){
            ch.pop_back();
            ch_points--;
        }
        ch.push_back(single_angles[i]);
        ch_points++;
    }
    
    return ch;
    
}


void print_point(Point* p){
    cout<<"x: "<<p->x<<"\ty: "<<p->y<<endl;
}

void print_line(Line* l){
    if (l->finite){
        cout<<"Line segment between points:"<<endl;
        print_point(l->a);
        print_point(l->b);
    }
    else{
        cout<<"Infinite line of equation:"<<endl;
        Line_equation* eq = get_equation(l);
        cout<<eq->a<<"x + "<<eq->b<<" = y"<<endl;
    }
}

bool points_equal(Point* p1, Point* p2){
    return abs(p1->x - p2->x) < TOLERANCE && abs(p1->y - p2->y) < TOLERANCE;
}