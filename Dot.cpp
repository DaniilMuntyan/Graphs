#include "Dot.h"
#include <math.h>
using namespace System;
using namespace System::Drawing;

Dot::Dot() {}
Dot::Dot(Point p)
{
	this->point = p;
}
Dot::Dot(int x, int y) 
{
	setPoint(new Point(x, y));
}
Dot::Dot(const Dot &dot)
{
	*this = dot;
}
Dot::~Dot() {}

Point Dot::getPoint()
{
	return this->point;
}

void Dot::setPoint(Point *p)
{
	this->point = *p;
}

bool Dot::inRegion(Point p, int width, int height, int radius)
{
	Point *center = new Point(p.X - (width / 2), p.Y - (height / 2));
	return length(p, this->point) < radius;
}

double Dot::length(Point p1, Point p2)
{
	return sqrt(pow((p1.X - p2.X), 2) + pow((p1.Y - p2.Y), 2));
}

void Dot::drawPoint(Graphics ^gr, SolidBrush ^brush, int width, int height, int number)
{
	StringFormat ^stringFormat = gcnew StringFormat();
	stringFormat->Alignment = StringAlignment::Center;
	stringFormat->LineAlignment = StringAlignment::Center;
	RectangleF rect(this->point.X - (width / 2), this->point.Y - (height / 2), width, height);
	//gr->DrawEllipse(gcnew Pen(Color::Black), rect);
	//gr->FillEllipse(brush, this->point.X - (width / 2), this->point.Y - (height / 2), width, height);
	gr->FillEllipse(brush, rect);
	gr->DrawString(number.ToString(), gcnew Font("Arial", 10), gcnew SolidBrush(Color::White), rect, stringFormat);
}

void Dot::drawEllipse(Graphics ^gr, Pen ^pen, int radius)
{
	gr->DrawEllipse(pen, this->point.X - radius / 2, this->point.Y - radius / 2, radius, radius);
}

void Dot::drawTo(Graphics ^gr, Pen ^pen, Dot dot)
{
	gr->DrawLine(pen, this->getPoint(), dot.getPoint());
}

bool operator> (const Dot &d1, const Dot &d2)
{
	Point p1 = d1.point, p2 = d2.point;
	return ((p1.X > p2.X) && (p1.Y > p2.Y));
	//return d1.point > d2.point;
}

bool operator>= (const Dot &d1, const Dot &d2)
{
	Point p1 = d1.point, p2 = d2.point;
	return ((p1.X >= p2.X) && (p1.Y >= p2.Y));
	//return d1.point >= d2.point;
}

bool operator< (const Dot &d1, const Dot &d2)
{
	Point p1 = d1.point, p2 = d2.point;
	return ((p1.X < p2.X) || (p1.X == p2.X && p1.Y < p2.Y));
	//return d1.point < d2.point;
}

bool operator<= (const Dot &d1, const Dot &d2)
{
	Point p1 = d1.point, p2 = d2.point;
	return ((p1.X <= p2.X) && (p1.Y <= p2.Y));
	//return d1.point <= d2.point;
}

bool operator== (const Dot &d1, const Dot &d2)
{
	Point p1 = d1.point, p2 = d2.point;
	return p1.X == p2.X && p1.Y == p2.Y;
	//return d1.point > d2.point;
}

