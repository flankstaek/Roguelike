
#ifndef POINT_H
#define POINT_H

#include "map.h"
#include <map>
#include <vector>

class Tile;
class PointComp;
using namespace std;



class Point{
public:
	int xVal;
	int yVal;
	double distance(Point p);
	bool equals(Point p);
	std::vector<Point> path(Tile[MAXHEIGHT][MAXLENGTH], Point, Point);
	std::vector<Point> reconstruct_path(std::map<Point, Point, PointComp>, Point);
	std::vector<Point> getNeighbors(Point);
	Point(int, int);
	Point(){ xVal = 0; yVal = 0; }
};

class PointComp{
public:
	bool operator() (const Point& lhs, const Point& rhs) const{
		return lhs.xVal < rhs.xVal;
	}
};

#endif