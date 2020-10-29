#include <iostream>
#include <cmath>

#include "coord3d.h"
#include "funcs.h"

//Task A
double length(Coord3D *p){
  Coord3D temp = *p;
  return sqrt((temp.x)*(temp.x)+(temp.y)*(temp.y)+(temp.z)*(temp.z));
}

//Task B
Coord3D *fartherFromOrigin(Coord3D *one, Coord3D *two){
  if (length(one) > length(two)){
    return one;
  }
  else {
    return two;
  }
}

//Task C
void move(Coord3D *ppos, Coord3D *pvel, double dt){
  ppos->x += (pvel->x)*dt;
  ppos->y += (pvel->y)*dt;
  ppos->z += (pvel->z)*dt;
}

//Task E
Coord3D* createCoord3D(double x, double y, double z){
  Coord3D *p = new Coord3D;
  *p = {x,y,z};
  return p;
}

void deleteCoord3D(Coord3D* p){
  p->x = 0;
  p->y = 0;
  p->z = 0;
  delete p;
}


double roundto (double a){
  return round(a*10000)/10000;
}
