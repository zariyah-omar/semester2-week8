
#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint( float x, float y ) {
    Point new;
    // implementation
        new.x = x;
        new.y = y;
    return new;
}

Line makeLine( Point p1, Point p2 ) {
    Line new;
        new.p[0] = p1;
        new.p[1] = p2;
    return new;
}

Triangle makeTriangle( Point p1, Point p2, Point p3 ) {
    Triangle new;
        new.p[0] = p1;
        new.p[1] = p2;
        new.p[2] = p3;
    return new;
}

float lineLength( Line l ) {
    float length;
        float dx = l.p[1].x - l.p[0].x;
        float dy = l.p[1].y - l.p[0].y;
        length = sqrt(dx*dx + dy*dy);
    return length;
}

// calculate the area of a triangle using Heron's formula
float triangleArea( Triangle t ) {
    float area;

    Line l1 = makeLine(t.p[0], t.p[1]);
    Line l2 = makeLine(t.p[1], t.p[2]);
    Line l3 = makeLine(t.p[2], t.p[0]);

    float a = lineLength(l1);
    float b = lineLength(l2);
    float c = lineLength(l3);

    float s = (a + b + c) / 2; // semi-perimeter    
    area = sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    return area;
}

// return true only if the point is the same location
bool samePoint( Point p1, Point p2 ) {
    Line l = makeLine(p1, p2);
    return lineLength(l) < 1.0e-6; 
}   

bool pointInLine( Point p, Line l) {
    return samePoint(p, l.p[0]) || samePoint(p, l.p[1]);
}

bool pointInTriangle( Point p, Triangle t ) {
    return samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2]);
}

// complete other functions below
// - start with stubs as above
// - compile regularly to test syntax
// - test functions by calling them from main()
