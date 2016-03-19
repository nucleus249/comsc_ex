//Program name: cityDistance.cpp
//Author name: Nicholas Vaughan
//Date:3/18/16
//COMSC 1341-A


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


//converts degrees into radians
double torad(double d) {
   double r = (d * M_PI)/180.0;
   return r;
}

//calculates distance
double haversine(double lat1, double lat2, double lon1, double lon2) {

   const double EARTH_RADIUS = 6372797.56;  //In units of meters
   double rlat1 = torad(lat1);
   double rlat2 = torad(lat2);
   double rlon1 = torad(lon1);
   double rlon2 = torad(lon2);

   double dlat = rlat2 - rlat1;
   double dlon = rlon2 - rlon1;
   
   double a = pow(sin(dlat/2), 2) + cos(rlat1) *
              cos(rlat2) * pow(sin(dlon/2), 2);
   double b = 2 * asin(sqrt(a));

   return EARTH_RADIUS * b;

}

int main() {
   
   ifstream input("./statecity.csv");
   ofstream output("cityDistanceOutput.txt");
  
   if(!input.is_open()) {
      cerr << "Cannot open file\n";
      abort();
   }

   string STATE1, STATE2, CITY1, CITY2, state, city;
   double latitude, longitude, lat1, lat2, lon1, lon2, dist, midist, kmdist;

   //Prompts for input
   cout << "Input name of first city, then the two letter state code,\n"
           "seperated by comma, no space after comma (e.g. Longmont,CO):\n";
   getline(cin, CITY1, ',');
   getline(cin, STATE1);

   cout << "Input name of second city, then the two letter state code,\n"
           "seperated by comma (e.g. Houston,TX):\n";
   getline(cin, CITY2, ',');
   getline(cin, STATE2);
   
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
      
      if(state == STATE1 && city == CITY1) {
         lat1 = latitude;
         lon1 = longitude;
      }

      if(state == STATE2 && city == CITY2) {
         lat2 = latitude;
         lon2 = longitude;
      }
   }

   dist = haversine(lat1, lat2, lon1, lon2);
   midist = dist/1609.34;
   kmdist = dist/1000.0;

   //Output formatting
   output << "Programming Assignment #5.\n";
   output << "Nicholas Vaughan\n";
   output << "March 18, 2016\n" << endl;
   output << "The distance from "<<CITY1<<", "<<STATE1<<" to "<<CITY2
          <<", "<<STATE2<<" is \n"<<midist<<" miles ("<<kmdist<<" km)";

   return 0;
   
}
