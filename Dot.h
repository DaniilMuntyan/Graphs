#ifndef DOT_H
#define DOT_H
using namespace System::Drawing;
using namespace std;
class Dot
{
private:
	Point point;
	int id;
public:
	Dot();
	Dot(Point p);
	Dot(int x, int y);
	Dot(const Dot& dot);
	~Dot();

	Point getPoint();
	void setPoint(Point *p);

	bool inRegion(Point p, int width, int height, int radius);
	void drawPoint(Graphics ^gr, SolidBrush ^brush, int width, int height, int number);
	void drawEllipse(Graphics ^gr, Pen ^pen, int radius);
	void drawTo(Graphics ^gr, Pen ^pen, Dot dot);
	double length(Point p1, Point p2);

	friend bool operator> (const Dot &d1, const Dot &d2);
	friend bool operator<= (const Dot &d1, const Dot &d2);

	friend bool operator< (const Dot &d1, const Dot &d2);
	friend bool operator>= (const Dot &d1, const Dot &d2);

	friend bool operator== (const Dot &d1, const Dot &d2);
};

#endif