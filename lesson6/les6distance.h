class ComputeDistance;
class Point{
public:
	Point();
	Point(Point &other);
	Point(double ,double );
	double PointDistance(Point &B);
	void displayXY();
private:
	friend class ComputeDistance;
	friend double FucDistance(Point &Pa,Point &Pb);
	double x;
	double y;	
};
class ComputeDistance{
public:
	ComputeDistance(Point &,Point &);
	double Distance();
private:
	double xa;
	double ya;
	double xb;
	double yb;
	double xsquare;
	double ysquare;
};