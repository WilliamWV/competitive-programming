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

Line* l1 = create_line(p0_0, p1_1); // y = x
Line* l2 = create_line(p1_1, p2_2, true);
Line* l3 = create_line(pm1_m1, p0_0, true);
Line* l4 = create_line(pm1_m8, p3_6); // y = 3.5x - 4.5
Line* l5 = create_line(pm9_5, p4_0); // y = -0.38x + 1.54

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

TEST(RotatePointTest, RotatePointTest){
    Point* p1 = create_point(0, 1);

    rotate_point(p1, M_PI);
    ASSERT_TRUE(points_equal(p1, p0_m1));

    rotate_point(p1, -M_PI);
    ASSERT_TRUE(points_equal(p1, p0_1));

    rotate_point(p1, M_PI_2);
    ASSERT_TRUE(points_equal(p1, pm1_0));

    rotate_point(p1, M_PI);
    ASSERT_TRUE(points_equal(p1, p1_0));

    Point* paux = create_point(sqrt(2)/2.0, sqrt(2)/2.0);
    rotate_point(p1, M_PI_4);
    ASSERT_TRUE(points_equal(p1, paux));


}

TEST(IntersectTest, LinesIntersect){
    ASSERT_TRUE(intersect(l1, l4));
    ASSERT_TRUE(intersect(l1, l5));
    ASSERT_TRUE(intersect(l4, l5));
    ASSERT_TRUE(intersect(l4, l1));
    ASSERT_TRUE(intersect(l3, l3));
    ASSERT_TRUE(intersect(l1, l1));
    

    ASSERT_TRUE(intersect(l1, l2));
    ASSERT_TRUE(intersect(l1, l3));
    ASSERT_TRUE(intersect(l4, l2));
    ASSERT_TRUE(intersect(l5, l2));
    
}

TEST(IntersectTest, LinesDoesNotIntersect){
    ASSERT_FALSE(intersect(l4, l3));
    ASSERT_FALSE(intersect(l5, l3));

    ASSERT_FALSE(intersect(l2, l3));
    ASSERT_FALSE(intersect(l3, l5));
    
}

TEST(IntersectionTest, IntersectionTest){

    Point* expected_l1_l4 = create_point(1.8, 1.8);
    ASSERT_TRUE(points_equal(intersection(l1, l4), expected_l1_l4));

    Point* expected_l1_l5 = create_point(10.0/9.0, 10.0/9.0);
    ASSERT_TRUE(points_equal(intersection(l1, l5), expected_l1_l5));

    Point* expected_l4_l5 = create_point(157.0/101.0, 190.0/202.0);
    ASSERT_TRUE(points_equal(intersection(l4, l5), expected_l4_l5));
    ASSERT_TRUE(points_equal(intersection(l4, l1), expected_l1_l4));

    ASSERT_TRUE(points_equal(intersection(l3, l3), l3->a));
    ASSERT_TRUE(points_equal(intersection(l1, l1), l1->a));
    

    ASSERT_TRUE(points_equal(intersection(l1, l2), l2->a));
    ASSERT_TRUE(points_equal(intersection(l1, l3), l3->a));
    ASSERT_TRUE(points_equal(intersection(l4, l2), expected_l1_l4));

    ASSERT_EQ(intersection(l4, l3), nullptr);
    ASSERT_TRUE(points_equal(intersection(l5, l2), expected_l1_l5));
    ASSERT_EQ(intersection(l5, l3), nullptr);

    ASSERT_EQ(intersection(l2, l3), nullptr);
    ASSERT_EQ(intersection(l3, l5), nullptr);
}
//Point* intersection(Line* l1, Line* l2);

//bool contains_point(Line* l, Point* p);

//double line_point_distance(Line* l, Point* p);

//std::vector<Point*> convex_hull(std::vector<Point*> points);
