#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "coord3d.h"
#include "funcs.h"

Coord3D p1 = {10,20,30};
Coord3D p2 = {15,25,35};
Coord3D *p3;

//Task A
TEST_CASE ("Task A: Regular Cases"){
  CHECK(roundto(length(&p1)) == 37.4166);
  p1 = {22.345, 54.6, 7.00};
  CHECK(roundto(length(&p1)) == 59.4093);
  p1 = {10000,1.83,500.43};
  CHECK(roundto(length(&p1)) == 10012.5138);
}
TEST_CASE ("Task A: Negative Numbers"){
  p1 = {-10,-20,30};
  CHECK(roundto(length(&p1)) == 37.4166);
  p1 = {22.345, -54.6, 7.00};
  CHECK(roundto(length(&p1)) == 59.4093);
  p1 = {10000,-1.83,-500.43};
  CHECK(roundto(length(&p1)) == 10012.5138);
}
TEST_CASE ("Task A: Zero"){
  p1 = {0,0,0};
  CHECK(roundto(length(&p1)) == 0);
}

//Task B
TEST_CASE ("Task B: Regular Cases"){
  CHECK(fartherFromOrigin(&p1,&p2) == &p2);
  p1 = {10000.34,-10033.353,1};
  CHECK(fartherFromOrigin(&p1,&p2) == &p1);
  p1 = {0,0.3,2};
  CHECK(fartherFromOrigin(&p1,&p2) == &p2);
}
TEST_CASE ("Task B: Equal distance"){
  p1 = {10,20,30};
  p2 = {10,20,30};
  CHECK(fartherFromOrigin(&p1,&p2) == &p2);
}

//Task C
TEST_CASE("Task C: Regular Cases"){
  move(&p1,&p2,1);
  CHECK(p1.x == 20);
  CHECK(p1.y == 40);
  CHECK(p1.z == 60);
  p2 = {-20,-40,-60};
  move(&p1,&p2,0.5);
  CHECK(p1.x == 10);
  CHECK(p1.y == 20);
  CHECK(p1.z == 30);
  p2 = {15,3,11};
  move(&p1,&p2,3);
  CHECK(p1.x == 55);
  CHECK(p1.y == 29);
  CHECK(p1.z == 63);
}
TEST_CASE("Task C: Negative Time"){
  p1 = {10,20,30};
  p2 = {10,20,30};
  move(&p1,&p2,-1);
  CHECK(p1.x == 0);
  CHECK(p1.y == 0);
  CHECK(p1.z == 0);
  p2 = {-10,-20,-30};
  move(&p1,&p2,-1);
  CHECK(p1.x == 10);
  CHECK(p1.y == 20);
  CHECK(p1.z == 30);
}
TEST_CASE("Task C: Zero Velocity"){
  p2 = {0,0,0};
  move(&p1,&p2,56.7);
  CHECK(p1.x == 10);
  CHECK(p1.y == 20);
  CHECK(p1.z == 30);
}

//Task E
TEST_CASE("Task E"){
  p3 = createCoord3D(33.3,-6.423,0.2);
  CHECK(p3->x == 33.3);
  CHECK(p3->y == -6.423);
  CHECK(p3->z == 0.2);
  deleteCoord3D(p3);
  p3 = createCoord3D(88,-47.6,0.001);
  CHECK(p3->x == 88);
  CHECK(p3->y == -47.6);
  CHECK(p3->z == 0.001);
  deleteCoord3D(p3);
  p3 = createCoord3D(27.89,349,-0.485);
  CHECK(p3->x == 27.89);
  CHECK(p3->y == 349);
  CHECK(p3->z == -0.485);
  deleteCoord3D(p3);
}
