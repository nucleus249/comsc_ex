//Program name: stateCity.cpp
//Author name: Nicholas Vaughan
//Date:3/11/16
//COMSC 1341-A

#include <iostream>
#include <fstream>
using namespace std;

//Determines the Northernmost city
string maxLat(double l, string north) {
   static double max = l;
   static string mostN;
   if (l>=max) {
      max = l;
      mostN = north;
      
   }
   return mostN;
}

//Determines Southernmost city
string minLat(double l, string south) {
   static double min = l;
   static string mostS;
   if (l<=min) {
      min = l;
      mostS = south;
   }
   return mostS;
}

//Determines Easternmost city
string maxLong(double l, string east) {
   static double max = l;
   static string mostE;
   if (l>=max) {
      max = l;
      mostE = east;
   }
   return mostE;
}

//Determines Westernmost city
string minLong (double l, string west) {
   static double min = l;
   static string mostW;
   if (l<=min) {
      min = l;
      mostW = west;
   }
   return mostW;
}

int main() {
   
   ifstream input("./statecity.csv");
   ofstream output("stateCityOutput.txt");
  
   if(!input.is_open()) {
      cerr << "Cannot open file\n";
      abort();
   }
   string STATE, state, city, north, south, east, west;
   double latitude, longitude;
   int city_count=0;
   cout << "Input the two letter state code(e.g.'CO'):\n";
   cin  >> STATE;

   input.ignore(200, '\n');  //skip first line

   while(input.good()) {
      getline(input, state, ',');
      input.ignore(100, ',');  //skip FIPS city code
      getline(input,city, ',');
      input.ignore(100, ',');  //skip FIPS city code
      input.ignore(100, ',');  //skip GNIS city code
      input.ignore(100, ',');  //skip city type
      input >> latitude;
      input.ignore(8,',');
      input >> longitude;
      input.ignore(8,'\n');
      
      if (state==STATE) {
         ++city_count;
         north = maxLat(latitude, city);
         south =minLat(latitude, city);
         east = maxLong(longitude, city);
         west = minLong(longitude, city);
      }
   }

   output << "Programming Assignment #4.\n";
   output << "Nicholas Vaughan\n";
   output << "March 10, 2016\n" << endl;
   output << "The state of " << STATE << " has " << city_count << " cities.\n" << endl;
   output << north << " is the Northernmost city.\n";
   output << south << " is the Southernmost city.\n";
   output << east << " is the Easternmost city.\n";
   output << west << " is the Westernmost city.\n";

   return 0;
   
}

