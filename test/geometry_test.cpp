#include "../include/geometry.h"

using namespace std;

int test_geometry(){
    Point* p1 = create_point(0,0);
    Point* p2 = create_point(1,1);
    Point* p3 = create_point(2,2);
    Point* p4 = create_point(1,2);
    Point* p5 = create_point(0,5);
    Point* p6 = create_point(1,6);
    Point* p7 = create_point(7,2);
    Point* p8 = create_point(-1,2);
    Point* p9 = create_point(4,-3);
    Point* p10 = create_point(-2,-1);
    Point* p11 = create_point(0,-4);
    

    Line* l1 = create_line(p4, p9, false);
    Line* l2 = create_line(p2, p5, true);
    Line* l3 = create_line(p1, p3, false);

    cout<<"Distance between points"<<endl;
    print_point(p1);
    print_point(p4);
    cout<<"Equal to: "<<distance(p1, p4)<<endl;
    
    cout<<"Distance between points"<<endl;
    print_point(p3);
    print_point(p7); 
    cout<<"Equal to: "<<distance(p3, p7)<<endl;
    
    cout<<"Distance between points"<<endl;
    print_point(p6);
    print_point(p9);
    
    cout<<"Equal to: "<<distance(p6, p9)<<endl;
    
    Point* pr = create_point(1, 0);
    cout<<"Rotating point: "<<endl;
    print_point(pr);
    cout<<"By 90 degrees"<<endl;
    rotate_point(pr, M_PI_2);
    cout<<"Result is:"<<endl;
    print_point(pr);

    cout<<endl<<"Checking intersection between lines "<<endl;
    print_line(l1);
    print_line(l2);

    if(intersect(l1, l2)){ 
        cout<< "Intersect at"<<endl; 
        print_point(intersection(l1, l2)); 
    }
    else{
        cout<< "Does not intersect";
    }

    cout<<endl<<"Checking intersection between lines "<<endl;
    print_line(l1);
    print_line(l3);

    if(intersect(l1, l3)){
        cout<< "Intersect at"<<endl; 
        print_point(intersection(l1, l3));
    }
    else{
        cout<< "Does not intersect";
    }

    cout<<endl<<"Checking intersection between lines "<<endl;
    print_line(l2);
    print_line(l3);

    if (intersect(l2, l3)) {
        cout<< "Intersect at"<<endl; 
        print_point(intersection(l2, l3)); 
    }
    else {
        cout<<"Does not intersect"<<endl;
    }

    cout<<endl<<"Checking if line contains point "<<endl;
    print_line(l3);

    if (contains_point(l3, p2)){ 
        cout<<"Contains"<<endl;
        print_point(p2);
    }
    else{
        cout<<"Does not contains"<<endl;
        print_point(p2);
    }

    cout<<endl<<"Checking if line contains point "<<endl;
    print_line(l2);
    
    Point* po = create_point(-1,9);
    
    if (contains_point(l2, po)){ 
        cout<<"Contains"<<endl;
        print_point(po);
    } else{
        cout<<"Does not contains"<<endl;
        print_point(po);
    }

    cout<<"Distance between point: "<<endl;
    print_point(p5);
    cout<<"And:"<<endl;
    print_line(l1);
    cout<<"Equals to: "<<line_point_distance(l1, p5)<<endl;

    
    vector<Point*> points = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11};
    
    vector<Point*> ch = convex_hull(points);
    cout<<"Convex hull of points:"<<endl;
    for (int i = 0; i< points.size(); i++){
        print_point(points[i]);
    }

    cout<<endl<<"Is:"<<endl;
    for (int i = 0; i< ch.size(); i++){
        print_point(ch[i]);
    }

    return 0;
    
}