#include <iostream>
#include <conio.h>
using namespace std;

class Cylinder
{
	double radius, height, volume;
	public:
		Cylinder();
		Cylinder(double, double);
		~Cylinder();
		void print_val();
		friend Cylinder frnd(Cylinder ob1, Cylinder ob2);
		void setRadius(double);
		void setHeight(double);
		void setVolume(double);
};

Cylinder::Cylinder()
{
	this->radius = 0;
	this->height = 0;
	this->volume = 0;
}

Cylinder::Cylinder(double radius, double height)
{
	this->radius = radius;
	this->height = height;
	this->volume = 3.14 * radius * radius * height;
}

void Cylinder::print_val()
{
	cout << " R = " << radius << " H = " << height << " V = " << volume << endl;
}

Cylinder::~Cylinder(){}

void Cylinder::setRadius(double a)
{
	this->radius = a;
}

void Cylinder::setHeight(double a)
{
	this->height = a;
}

void Cylinder::setVolume(double a)
{
	this->volume = a;
}

Cylinder frnd(Cylinder ob1, Cylinder ob2)
{
	Cylinder result;
	result.setVolume(ob1.volume + ob2.volume);
	if (ob1.radius > ob2.radius)
		result.setRadius(ob1.radius);
	else
		result.setRadius(ob2.radius);
	return result;
}

int main()
{
	Cylinder a(2, 3);
	Cylinder b(3, 4);
	Cylinder c = frnd(a, b);
	Cylinder d = frnd(a, b);
	a.print_val();
	c.print_val();
}