#include <iostream>

#include "coord3d.h"
#include "funcs.h"

int main (){
  Coord3D a = {10,20,30};
  Coord3D b = {15,3,11};
  
  //Task A
  std::cout << "For the coordinate, A, where\n   x=10, y=20, z=30:\nThe distance from the coordinate to the origin is " << length(&a) << std::endl;

  //Task B
  std::cout << "\nCompared to the coordinate, B, where\n   x=15, y=3, z=11\n";
  if (fartherFromOrigin(&a,&b) == &a){
    std::cout << "Coordinate A is farther away from the origin\n";
  }
  else {
    std::cout << "Coordinate B is farther away from the origin\n";
  }

  //Task C
  move(&a,&b,10);
    std::cout << "\nAfter 10 seconds of moving coordinate A by:\n   15 in the x direction\n   3 in the y direction\n   11 in the z direction\nThe current coordinate for A is\n   x=" << a.x << " y=" << a.y << " z=" << a.z << std::endl;

  //Task E
  Coord3D *ppos = createCoord3D(5.5,-1.47,7.77);
  move(&a,ppos,10);
  std::cout << "\nAfter another 10 second of moving corrdinate by:\n   5.5 in the x direction\n   -1.47 in the y direction\n   7.77 in the z direction\nThe Coordinate for A is now\n   x=" << a.x << " y=" << a.y << " z=" << a.z << std::endl; 
  deleteCoord3D(ppos);

  return 0;
}
