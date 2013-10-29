//Bilgehan Saglik Comp128
//Wentworth Institute of Technology
//Lab08 Pass by Reference
#include <iostream>
#define pi 3.14159265359
using namespace std;

//Prototype Declerations
void evalCircle (double rad, double& area, double& circ);
void evalRectangle (double w, double h, double& area, double& per);
int evalTriangle (double a, double b, double c, double& area, double& per);

void evalCircle (double rad, double& area, double& circ){
	area = pi * rad * rad;
	circ = 2 * pi * rad;
}

void evalRectangle (double w, double h, double& area, double& per){
	area = w * h;
	per = 2 * (w + h);
}

int evalTriangle (double a, double b, double c, double& area, double& per){
	if (a + b < c || a + c < b || b + c < a){
		cout << "Not a valid triangle." << endl;
		return 2;
	}
	else if (a + b == c || a + c == b || b + c == a){
		cout << "All points of this tirangle lays on the same line." << endl;
		return 1;
	}
	else {
		per = a + b + c;
		double s = per / 2;
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		return 0;
	}
}

int main (){
	char option;
	double rad, area, w, h, per, a, b, c;

	do{
		cout << "Select an option." << endl;
		cout << "a) Calculate the size of a circle" << endl;
		cout << "b) Calculate the size of a rectangle" << endl;
		cout << "c) Calculate the size of a triangle" << endl;
		cout << "d) Quit" << endl;
		cin >> option;

		switch (option)
		{
		case 'a':
			cout << "What is the radius of this circle?" << endl;
			cin >> rad;
			evalCircle (rad, area, per);
			cout << "Area is " << area << " and circumference is " << per << endl;
			break;
		case 'b':
			cout << "What is the height of this rectangle?" << endl;
			cin >> h;
			cout << "What is the width of this rectangle?" << endl;
			cin >> w;
			evalRectangle (w, h, area, per);
			cout << "Area is " << area << " and perimeter is " << per << endl;
			break;
		case 'c':
			cout << "What is the 1st side of this triangle?" << endl;
			cin >> a;
			cout << "What is the 2nd side of this triangle?" << endl;
			cin >> b;
			cout << "What is the 3rd side of this triangle?" << endl;
			cin >> c;
			
			if (evalTriangle (a, b, c, area, per) == 0)
				cout << "Area is " << area << " and perimeter is " << per << endl;

			break;
		
		case 'd':
			return 0;
		default:
			cout << "Invalid choice, please try again.";
			break;
		}
		cout << endl;
		system("PAUSE");
		cout << endl;
	} while(true);
	return 0;
}