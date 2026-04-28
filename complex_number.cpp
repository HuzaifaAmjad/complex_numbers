#include <iostream>
#include <cmath>
using namespace std;

class complex 
{
private:
 double real;
 double imag;
public:
//default constructor
 complex() 
 {
  real=0;
  imag=0;
 }
//parameterized constructor
 complex(double r,double i) 
 {
  real=r;
  imag=i;
 }
//setters
 void setReal(double r) 
 {
  real=r;
 }
 void setImag(double i) 
 {
 imag=i;
 }
//getters
 double getReal() 
 {
  return real;
 }
 double getImag() 
 {
 return imag;
 }
//magnitude
 double magnitude() 
 {
  return sqrt(real*real+imag*imag);
 }
//angle in degrees
 double angle() 
 {
 return atan2(imag,real)*180/3.142;
 }
//conjugate
 complex conjugate() 
 {
  return complex(real,-imag);
 }
//display rectangular form
 void displayRect() 
 {
  cout<<real<<" + j"<<imag<<endl;
 }
//display polar form
 void displayPolar() 
 {
  cout<<magnitude()<<" at "<<angle()<<" degrees"<<endl;
 }
//operator Overloading
 complex operator+(complex c) 
 {
  return complex(real+c.real,imag+c.imag);
 }
 complex operator-(complex c) 
 {
  return complex(real-c.real,imag-c.imag);
 }
 complex operator*(complex c) 
 {
  return complex
  (
   real*c.real-imag*c.imag,
   real*c.imag+imag*c.real
  );
 }
 complex operator/(complex c) 
 {
  double den=c.real*c.real+c.imag*c.imag;
  return complex
  (
   (real*c.real+imag*c.imag)/den,
   (imag*c.real-real*c.imag)/den
  );
 }
};
//main 
int main() 
{
 complex a(3,4);
 complex b(1,2);
 cout<<"Number A: ";
 a.displayRect();
 cout<<"Number B: ";
 b.displayRect();
 cout<<"\nMagnitude of A: "<<a.magnitude()<<endl;
 cout<<"Angle of A: "<<a.angle()<<endl;
 cout<<"Conjugate of A: ";
 b.conjugate().displayRect();
 cout<<"Magnitude of B: "<<b.magnitude()<<endl;
 cout<<"Angle of B: "<<b.angle()<<endl;
 cout<<"Conjugate of B: ";
 b.conjugate().displayRect();
 cout<<"\nA+B=";
 (a+b).displayRect();
 cout<<"A-B=";
 (a-b).displayRect();
 cout << "A*B=";
 (a*b).displayRect();
 cout<<"A/B=";
 (a/b).displayRect();
 cout<<"\nPolar form of A: ";
 a.displayPolar();
 cout<<"Polar form of B: ";
 b.displayPolar();
 return 0;
}