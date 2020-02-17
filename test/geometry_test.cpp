#include "../include/geometry.h"
#include <gtest/gtest.h>

using namespace std;

Point* p0_0 = create_point(0, 0);
Point* p0_1 = create_point(0, 1);
Point* p1_0 = create_point(1, 0);
Point* p1_1 = create_point(1, 1);
Point* p0_m1 = create_point(0, -1);
Point* pm1_0 = create_point(-1, 0);
Point* pm1_m1 = create_point(-1, -1);
Point* p2_3 = create_point(2, 3);
Point* pm2_3 = create_point(-2, 3);
Point* p7_m1 = create_point(7, -1);
Point* pm9_2 = create_point(-9, 2);
Point* p4_0 = create_point(4, 0);
Point* p3_6 = create_point(3, 6);
Point* p4_m7 = create_point(4, -7);
Point* pm3_m4 = create_point(-3, -4);
Point* p2_2 = create_point(2, 2);
Point* pm1_m8 = create_point(-1, -8);
Point* pm9_5 = create_point(-9, 5);
Point* pm3_3 = create_point(-3, 3);
Point* p9_2 = create_point(9, 2);
Point* pm7_8 = create_point(-7, 8);

Line* l1 = create_line(p0_0, p1_1);
Line* l2 = create_line(p1_1, p2_2, true);
Line* l3 = create_line(pm1_m1, p0_0, true);
Line* l4 = create_line(pm1_m8, p3_6);

TEST(GetEquationTest, GetEquationTest){
    Line_equation* l1_eq = get_equation(l1);
    Line_equation* l2_eq = get_equation(l2);
    Line_equation* l3_eq = get_equation(l3);
    Line_equation* l4_eq = get_equation(l4);
    
    ASSERT_DOUBLE_EQ(1, l1_eq->a);
    ASSERT_DOUBLE_EQ(0, l1_eq->b);

    ASSERT_DOUBLE_EQ(1, l2_eq->a);
    ASSERT_DOUBLE_EQ(0, l2_eq->b);

    ASSERT_DOUBLE_EQ(1, l3_eq->a);
    ASSERT_DOUBLE_EQ(0, l3_eq->b);

    ASSERT_DOUBLE_EQ(7.0/2.0, l4_eq->a);
    ASSERT_DOUBLE_EQ(-4.5, l4_eq->b);
}

TEST(PointDistanceTest, PointDistanceTest){
    ASSERT_DOUBLE_EQ(1, distance(p0_0, p0_1));
    ASSERT_DOUBLE_EQ(sqrt(10), distance(p1_1, p4_0));
    ASSERT_DOUBLE_EQ(sqrt(52), distance(p0_m1, p4_m7));
    ASSERT_DOUBLE_EQ(sqrt(17), distance(p3_6, p2_2));
    ASSERT_DOUBLE_EQ(sqrt(37), distance(p1_0, p7_m1));
    ASSERT_DOUBLE_EQ(sqrt(292), distance(pm7_8, p9_2));
    ASSERT_DOUBLE_EQ(sqrt(125), distance(pm1_m8, pm3_3));
    ASSERT_DOUBLE_EQ(sqrt(333), distance(pm9_5, p9_2));
    
}

//void rotate_point(Point* p1, double angle);

//bool intersect(Line* l1, Line* l2);

//Point* intersection(Line* l1, Line* l2);

//bool contains_point(Line* l, Point* p);

//double line_point_distance(Line* l, Point* p);

//std::vector<Point*> convex_hull(std::vector<Point*> points);
