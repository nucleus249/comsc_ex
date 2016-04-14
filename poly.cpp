#include <iostream>
#include <cmath>
using namespace std;

const unsigned short N = 30;  // max size of polynomials

// degree of polynomial 
int degree(double a[]) {
    for(int i=N-1; i; --i)
        if (a[i])
            return i;
    return 0;
}

// prints polynomials nicely
void print(double poly[]) {
    bool first = true;  // true for first non-zero coefficient
    for (int i=N-1; i>=0; i--) {
        if (!poly[i]) 
            continue;
        // print coefficient 
        if (i && poly[i] == 1)   // special case for 1
            cout << (first ? "" : " +");
        else if (i && poly[i] == -1) // special case for -1
            cout << (first ? "-" : " -");  
        else 
            cout << ' ' << (first ? noshowpos : showpos) << poly[i];
        cout << noshowpos;
        // print variable
        if (i>0)   
            cout << "x"; 
        // print power
        if (i>1) 
            cout << '^' << i;  
        first = false;
    }
    if(first)  // print 0 if all zeros
        cout << 0;
}

double evaluate(double a[], double x){
   double sum = 0;
   for(int i=0; i<N; i++)
      sum += a[i] * pow(x,i);
   return sum;
}

void add(double a[], double b[], double result[]){
   for(int i=0; i<N; i++)
      result[i] = a[i] + b[i];
}

void subtract(double a[], double b[], double result[]){
   for(int i=0; i<N; i++)
      result[i] = a[i] - b[i];
}

//The purpose of the function is to take in two arrays of size N that
//represent two polynomials, multiply them together, and place
//the result in a third array.
void multiply(double a[], double b[], double result[]){
   result[N] = {};
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         int k = i + j;
         result[k] += a[i] * b[j];
      }
   }
}

void differentiate(double a[], double result[]){
   result[N] = {};
   for(int i=0; i<N-1; i++)
      result[i] = (i+1) * a[i+1];
}


int main() {
   double a[N] = {12, 1, 0, -32.5, 0, 1};  //first polynomial
   
   cout <<"\nEvaluation:\n";
   double x=-7.3;
   cout << "If x = " << x << ", then ";
   print (a);
   cout << " = " << evaluate(a, x) << endl;

   double b[N] = {1, 1, -1};   //Second polynomial
   double c[N];   //Result polynomial

   cout << "\nAddition:\n";
   add(a,b,c);
   cout << '(';
   print(a);
   cout << ") + (";
   print(b);
   cout << ") = ";
   print(c);
   cout << endl;

   cout << "\nSubtraction:\n";
   subtract(a,b,c);
   cout << '(';
   print(a);
   cout << ") - (";
   print(b);
   cout << ") = ";
   print(c);
   cout << endl;
   
   cout << "\nMultiplication:\n";
   multiply(a,b,c);
   cout << '(';
   print(a);
   cout << ") * (";
   print(b);
   cout << ") = ";
   print(c);
   cout << endl;
   
   cout << "\nDifferentiation:\n";
   cout << "The derivative of (";
   print(a);
   cout << ") is (";
   differentiate(a,c);
   print(c);
   cout << ')' << endl;
   cout << "It's second derivative is (";
   differentiate(c,c);
   print(c);
   cout << ')' << endl;
   cout << endl;
}
