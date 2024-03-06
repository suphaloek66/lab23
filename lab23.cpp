#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

double ComplexNumber::abs(){
	double sumV = 0;
	sumV = sqrt(pow(real,2) +  pow(imag,2));
	return sumV;
}

double ComplexNumber::angle(){
	double PI = 3.14159265359;
	double sumS = 0;
	sumS = atan2(imag, real) * (180.00/PI);
	return sumS;
}

ComplexNumber operator+ (double a , const ComplexNumber &b){
	return ComplexNumber(a + b.real , b.imag);
}

ComplexNumber operator- (double a, const ComplexNumber &b){
	return ComplexNumber(a - b.real,  - b.imag);
}

ComplexNumber ComplexNumber::operator* ( const ComplexNumber &b){
	return ComplexNumber((real * b.real) - (imag*b.imag) , (real * b.imag) + (b.real * imag));
}
ComplexNumber operator* (double a , const ComplexNumber &b){
	return ComplexNumber((a * b.real) , ( a * b.imag));
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber &b){
	return  ComplexNumber((((real)*(b.real))+((imag)*(b.imag)))/(pow(b.real,2)+pow(b.imag,2)),(((b.real)*(imag))-((real)*(b.imag)))/((pow(b.real,2)+pow(b.imag,2))));
}

ComplexNumber operator/ (double a , const ComplexNumber &b){
	return ComplexNumber((((a)*(b.real))+((0)*(b.imag)))/(pow(b.real,2)+pow(b.imag,2)),(((b.real)*(0))-((a)*(b.imag)))/((pow(b.real,2)+pow(b.imag,2))));
}

bool ComplexNumber::operator==(const ComplexNumber &b){
	if((real == b.real) && (imag == b.imag)) return true;
	else return false;
}

bool operator==(double a , const ComplexNumber &b){
	if((a == b.real) && (a == b.imag)) return true;
	else return false;
}

ostream & operator<<(ostream &os, const ComplexNumber &a){
	if(a.imag > 0){
		if(a.real > 0) return  os << a.real << "+" << a.imag << "i";
		if(a.real == 0) return os << a.imag << "i";
		if (a.real < 0) return os  << a.real << "+" << a.imag << "i";
	}
	
	if(a.imag < 0){
		if(a.real > 0) return os << a.real << a.imag << "i";
		if (a.real == 0) return os << a.imag << "i";
		if (a.real < 0) return os  << a.real << a.imag << "i";
	}
	
	if(a.imag == 0) return os << a.real;
	return os ;
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





