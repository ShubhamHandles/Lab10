//Q.4.Complete the following exercises: 
   
//Exercise 4.1 
/*
Using the program point.cpp, add a member function print to the class Point so that it prints out coordinates as: 
(2, 3) for a point with coordinates (2, 3). Test it in main(). 
*/

#include<iostream>
using namespace std;


// ********************************************************************
//  Declaration of class Point
// ********************************************************************
// class Point represents a two-dimensional point
class Point {
	
	// private data members x, y represent coordinates of the point:
	private:
  		int X;
  		int Y;

	public:
  	// default class constructor (with no arguments):
  	Point(); 

  	// class constructor that sets the coordinates x, y to the values xval, yval:
  	Point(int xval, int yval);

  	// member function for moving a point by dx, dy:
  	void Move(int dx, int dy);

  	// member functions for getting values of x, y:
  	int Get_X() const;
  	int Get_Y() const;

  	// member functions for setting x, y to xval, yval respectively  
  	void Set_X(int xval);
  	void Set_Y(int yval);

	//exercise 4.1. Add declaration of member function Print here:
	void print();
};

// ********************************************************************
//  Methods for class Point
// ********************************************************************
// class constructor sets X, Y to zero when no values are specified:
Point::Point(){
  	X = 0;
  	Y = 0;
}

// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval){
  	X = xval;
  	Y = yval;
}

// member function Move: increases the x coordinate by dx and the y coordinate by dy.
void Point::Move(int dx, int dy){
  	X += dx;
  	Y += dy;
}

// Get_X returns the value of the X coordinate
int Point::Get_X() const{
  	return X;
}

// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const{
  	return Y;
}

// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval){
  	X = xval;
} 

// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval){
  	Y = yval;
}

//exercise 4.1. Add definition of member function print:
void Point::print(){
	cout << "(" << X << "," << Y << ")";
}


//Exercise 4.2
/*
Write a definition of a class Rectangle using the Point class. 
A rectangle is specified by two corner points (bottom left and top right). The sides of the rectangle are parallel to the coordinate axes. 
The implementation of the class should be as follows: 

The private data members of the class include all 4 corner points of the rectangle. 

There are two constructors: 
one takes two points as arguments and creates a rectangle with the first point as the bottom left corner and the second as the top right corner, the other (default) constructor creates a rectangle with the corners (0,0), (1,0), (0,1), (1,1). 

Hint: use functions Set_X, Set_Y from the class Point to set the values of the corner points. 
The print member function prints all 4 corners of the rectangle, using the member function print of the class Point. 
Test the class Rectangle in main(), demonstrate that all member functions work as specified. 
*/

//Exercise 4.3 
/*
Add two private member functions side1, side2 to the class Rectangle to compute the lengths of the two sides. Using this function, write a public member function to compute the area of the rectangle.
*/

// ********************************************************************
//  Declaration of class Rectangle
// ********************************************************************
//exercise 4.2, 4.3: Add class Rectangle declaration HERE:  
class Rectangle {
	
	private:
	//4 points
	Point tR,tL,bR,bL;

	//side functions
	int side1();
	int side2();

	public:
	//constructors
	Rectangle(Point p1, Point p2);
	Rectangle();
	
	//print 4 points
	void print();

	//area
	int area();

};

// ********************************************************************
//  Methods for class Rectangle
// ********************************************************************
//exercise 4.2, 4.3. Add class Rectangle methods HERE: 
Rectangle::Rectangle(Point p1, Point p2){
	tR.Set_X(p2.Get_X());
	tR.Set_Y(p2.Get_Y());
	tL.Set_X(p1.Get_X());
	tL.Set_Y(p2.Get_Y());
	bR.Set_X(p2.Get_X());
	bR.Set_Y(p1.Get_Y());
	bL.Set_X(p1.Get_X());
	bL.Set_Y(p1.Get_Y());
}

Rectangle::Rectangle(){
	tR.Set_X(1);
	tR.Set_Y(1);
	tL.Set_X(0);
	tL.Set_Y(1);
	bR.Set_X(1);
	bR.Set_Y(0);
	bL.Set_X(0);
	bL.Set_Y(0);
}

void Rectangle::print(){
	cout << "The co-ordinates of 4 points of the rectangle are : ";
	tR.print();
	cout << ",";
	tL.print();
	cout << ",";
	bR.print();
	cout << ",";
	bL.print();
	cout << endl;
}

int Rectangle::side1(){
	int x1,x2;
	x1=bL.Get_X();
	x2=bR.Get_X();
	return x2-x1;
}

int Rectangle::side2(){
	int y1,y2;
	y1=bL.Get_Y();
	y2=tL.Get_Y();
	return y2-y1;
}

int Rectangle::area(){
	int s1,s2;
	s1=side1();
	s2=side2();
	return s1*s2;
}

// ********************************************************************
//  main() function for testing classes Point and Rectangle
// ********************************************************************
// Testing classes Point and Rectangle 
int main(){

	// Declaring a point using default class constructor (x = y = 0):
  	Point p1;
  	cout<< "The x value for p1 is " << p1.Get_X() << endl;
  	cout<< "The y value for p1 is " << p1.Get_Y() << endl;

	// Declaring a point with coordinates X = 2, Y = 3:
  	Point p2(2, 3);
  	cout<< "The x value for p2 is " << p2.Get_X() << endl;
  	cout<< "The y value for p2 is " << p2.Get_Y() << endl;

	// Moving point p2 by (1, -1):
  	p2.Move(1, -1);
  	cout<< "After the move :" << endl;
  	cout<< "The x value for p2 is " << p2.Get_X() << endl;
  	cout<< "The y value for p2 is " << p2.Get_Y() << endl;

	// Exercise 4.1. Test member function print on points p1, p2:
	cout << "Point p1 is : ";
	p1.print();
	cout << endl;
	cout << "Point p2 is : ";
	p2.print();
	cout << endl;

	// Exercises 4.2, 4.3. Testing of the class Rectangle goes here:
	Rectangle r1(p1,p2),r2;
	r1.print();
	cout << "Area of the rectangle is : " << r1.area() << " unit sq. " << endl;
	r2.print();
	cout << "Area of the rectangle is : " << r2.area() << " unit sq. " << endl;  

  	return 0;
}

