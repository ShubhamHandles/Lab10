//Q.3.Create a class for rectangle that stores data of length and breadth and has two functions : area() and perimeter(). Write a program that uses this class to create two rectangles (rectangle objects) of user input length and breadth. Compare the areas and perimeter of the those rectangles.


#include<iostream>
using namespace std;

class rectangle {
	public:	
	double length;	
	double breadth;
	
	//member functions
	double getArea();
	double getPerimeter();
	void setLength(double len);
	void setBreadth(double bre); 
};

//member function definitions
double rectangle::getArea(){
	return length*breadth;
}
double rectangle::getPerimeter(){
	return 2*(length+breadth);
}
void rectangle::setLength(double len){
	length=len;
} 
void rectangle::setBreadth(double bre){
	breadth=bre;
}

int main(){
	
	//input
	double l1,l2,b1,b2;
	cout << "Enter the length for first rectangle :" << endl;
	cin >> l1;
	cout << "Enter the breadth for first rectangle :" << endl;
	cin >> b1;
	cout << "Enter the length for second rectangle :" << endl;
	cin >> l2;
	cout << "Enter the breadth for second rectangle :" << endl;
	cin >> b2;

	//create rectangles
	rectangle r1,r2;

	//rectangle1
	r1.setLength(l1);
	r1.setBreadth(b1);
	double area1 = r1.getArea();
	cout << "Area of rectangle1 = " << area1 << endl;
	double perimeter1 = r1.getPerimeter();
	cout << "Perimeter of rectangle1 = " << perimeter1 << endl;
	
	//rectangle2
	r2.setLength(l2);
	r2.setBreadth(b2);
	double area2 = r2.getArea();
	cout << "Area of rectangle2 = " << area2 << endl;
	double perimeter2 = r2.getPerimeter();
	cout << "Perimeter of rectangle2 = " << perimeter2 << endl;

	if (area1>area2)
	cout << "Area of rectangle1 is bigger!" << endl;
	else if (area1<area2) 
	cout << "Area of rectangle2 is bigger!" << endl;
	else 
	cout << "Areas of both rectangles are equal!" << endl;

	if (perimeter1>perimeter2)
	cout << "Perimeter of rectangle1 is bigger!" << endl;
	else if (perimeter1<perimeter2)
	cout << "Perimeter of rectangle2 is bigger!" << endl;
	else 
	cout << "Perimeters of both rectangles are equal!" << endl;
	

	return 0;
}

















