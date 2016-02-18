#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
 

   double a, b, c;
   double amean, gmean, hmean;

   // Set the input and output files.
   ofstream out("meanCalcOutput.txt");
   ifstream in("meanCalcInput.txt");
   
   // Take numbers from input file and
   // store in variables.
   in >> a;
   in.ignore(100, ',');
   in >> b;
   in.ignore(100, ',');
   in >> c;
   in.ignore(100, ',');


   // Calculate the different means.
   amean = (a + b + c) / 3;
   gmean = pow ((a * b * c), (1/3.0));
   hmean = 3 / (1.0/a + 1.0/b + 1.0/c);

   // Put calculated output into output file.
   out << setprecision(4) << setw(10) << amean << ", ";//
   out << setprecision(4) << setw(10) << gmean << ", ";// First line
   out << setprecision(4) << setw(10) << hmean << ",\n";//
   
   out << setprecision(6) << setw(10) << amean << ", ";//
   out << setprecision(6) << setw(10) << gmean << ", ";// Second line
   out << setprecision(6) << setw(10) << hmean << ",\n";//
   
   out << scientific <<  setprecision(2) << setw(10) << amean << ", ";//
   out << setprecision(2) << setw(10) << gmean << ", ";//  Third line
   out << setprecision(2) << setw(10) << hmean << ", ";//
   
   return 0;
}

