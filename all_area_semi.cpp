/*
Author: Isabel Tait
Date: 09-20-2018
Class: COP3014
Assignment: Assignment 4
Professor: Dr. Lofton Bullard

Description: The program will compute the semiperimeter and area of the sides of a triangle. It will
invalidate any numbers that do not make up the sides of a triangle.

*/
#include <iostream>
#include<string>

using namespace std;

void Input(double & a, double & b, double & c);
void Compute(double a, double b, double c, double & area, double & semiperimeter);

void Input(double & a, double & b, double & c)
{
	
		cout << "Please input side length a." << endl;
		cin >> a;

		cout << "Please input side length b." << endl;
		cin >> b;

		cout << "Please input side length c." << endl;
		cin >> c;

}


void Compute(double a, double b, double c, double & area, double & semiperimeter)
{

	cout << "We will now computer the semiperimeter." << endl;
	semiperimeter = (a + b + c) / 2;
	cout << "The semiperimeter is " <<semiperimeter<<endl;

	cout << "We will now compute the area." << endl;
	area = sqrt(semiperimeter*(semiperimeter - a)*(semiperimeter - b)*(semiperimeter - c));
	cout << "The area is " << area << endl;
}


int main()
{
	double a, b, c;
    double semiperimeter, area;
	string response = "y";

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while(response=="Y"||response=="y")
	{
		Input(a, b, c);
		if (a + b > c && a + c > b && b + c > a)
		{
			cout << "Your side lengths are" << a << " ," << b << ", " << c << ", " << endl;
		}
		else
		{
			cout << "These are not valid side lengths. The sum of any two lengths must be greater than the third side" << endl;
			//exit(0);
			cout << "Would you like to calculate another area and semiperimeter?" << endl;
			cin >> response;
			if (response == "Y" || response == "y")
			{
				Input(a, b, c);

				Compute(a, b, c, area, semiperimeter);
			}
		}

		
		
		Compute(a, b, c, area, semiperimeter);

		cout << "Would you like to calculate the measurements of another triangle?" << endl;
		cin >> response;
	}
	
	cout << "Goodbye." << endl;
	
	return 0;
}


