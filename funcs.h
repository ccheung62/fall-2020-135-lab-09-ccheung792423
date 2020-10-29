#pragma once
double roundto(double a);
double length(Coord3D *p);
Coord3D *fartherFromOrigin(Coord3D *one, Coord3D *two);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D* p);
