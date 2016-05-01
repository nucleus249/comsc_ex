/*  
    Computer Science 1450 - Spring 2016
    Author: Nicholas Vaughan 
    Date: 2016-04-21
*/ 

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     // exit
#include <cmath>

using namespace std;

const int N=247;   // number of countries 

struct Country {
    string name;   // name in English
    string continent;   
    unsigned int population;
    float area;    // sq. km
    float coastline;  // km
    string government;
    string currency;
    string currency_code;  // a 3-letter abbreviation
    float birth_rate;  // annual per 100 persons
    float death_rate;  // annual per 100 persons
    float life_expectancy;
};


Country countries[N];
string continents[20];
int m = 0;


void load_countries(const char filename[]) {

    ifstream input;
    string line;
    char delimiter=';';
    size_t prev=0, pos; 

    input.open(filename);
    if(!input.is_open()) {
        cerr << "Cannot open file " << filename << endl;
        exit(0);
    }
    getline(input, line); // ignore the first line
    
    for(int i=0; i<N; i++) {
        getline(input, line);
        prev = 0;
        pos = line.find(delimiter, prev); 
        countries[i].name = line.substr(prev+1, pos-prev-2); 
        prev = pos+1;
        prev = line.find(delimiter,prev)+1; // skip Gername name
        prev = line.find(delimiter,prev)+1; // skip native name
        prev = line.find(delimiter,prev)+1; // skip country code
        pos = line.find(delimiter,prev);
        countries[i].continent = line.substr(prev+1, pos-prev-2);
        prev = pos+1;
        prev = line.find(delimiter,prev)+1;  // skip capital
        pos = line.find(delimiter,prev);
        countries[i].population = stoi(line.substr(prev, pos-prev));
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].area = stof(line.substr(prev, pos-prev));
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].coastline = stof(line.substr(prev, pos-prev));
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].government = line.substr(prev+1, pos-prev-2); 
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].currency = line.substr(prev+1, pos-prev-2);
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].currency_code = line.substr(prev+1, pos-prev-2); 
        prev = pos+1;
        prev = line.find(delimiter,prev)+1; // skip dialing prefix
        pos = line.find(delimiter,prev);
        countries[i].birth_rate = stof(line.substr(prev, pos-prev));
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].death_rate = stof(line.substr(prev, pos-prev));
        prev = pos+1;
        pos = line.find(delimiter,prev);
        countries[i].life_expectancy = stof(line.substr(prev, pos-prev));
    }
    input.close();
}

void print_country(int i) {

    cout << "COUNTRY: " << countries[i].name << " (" << countries[i].continent << ") " << endl;
    cout << "  Population: " << countries[i].population << endl;
    cout << "  Area:       " << countries[i].area << " (km^2)" << endl;
    cout << "  Population density: " << countries[i].population/countries[i].area << " (persons per km^2)" << endl;
    cout << "  Coastline:  " << countries[i].coastline << " (km)" << endl;
    cout << "  Currency:   " << countries[i].currency << " (" << countries[i].currency_code << ")" << endl;
    cout << endl;
}
    

//Finds unique continents in countries and adds them to
//the array continents
void find_continents(){
   
   bool found;
   int j;
   for(int i=0; i<N; i++){
      found = false;
      for(j=0; j<m; j++)
            if(continents[j] == countries[i].continent){
               found = true;
               break;
            }
   
      if(!found)
         continents[m++] = countries[i].continent;
   }

}


void print_continent_stats(const string& continent){

   int country = 0;
   int population = 0;
   double area = 0;
   double coastlength = 0;

   for(int i=0; i<N; i++)
      if(countries[i].continent == continent){
         country++;
         population += countries[i].population;
         area += countries[i].area;
         coastlength += countries[i].coastline;
      }
    cout << "CONTINENT: " << continent  << endl;
    cout << "  Population: " << population << endl;
    cout << "  Area:       " << area << " (km^2)" << endl;
    cout << "  Coastline:  " << coastlength << " (km)" << endl;
    cout << "  Number of countries: " << country << endl;
    cout << endl;

}


// Assignment 8 problem 1
int rank_by_population_density(const string& country){
   for(int i=0; i<N; i++)
      for(int j=i+1; j<N; j++){
         float idensity = countries[i].population/countries[i].area;
         float jdensity = countries[j].population/countries[j].area;
         if(jdensity > idensity){
            Country temp = countries[i];
            countries[i] = countries[j];
            countries[j] = temp;
         }
      }
   for(int i=0; i<N; i++)
      if(countries[i].name == country)
         return i+1;

return 0;

}

// Problem 3
void top_landlocked(int n){
   for(int i=0; i<n; i++)
      for(int j=i+1; j<N; j++){
         if(countries[j].area > countries[i].area && countries[j].coastline == 0){
            Country temp = countries[i];
            countries[i] = countries[j];
            countries[j] = temp;
         } 
      }
   for(int i=n-1; i>=0; i--){
      cout << "In rank " << (abs(i-(n-1)) + 1) << " is "; 
      cout << countries[i].name << endl << endl;
  }
}


//Problem 2
void sort_by_population_growth(const string& continent){
   for(int i=0; i<N; i++)
      for(int j=i+1; j<N; j++){
         float igrowth = countries[i].birth_rate - countries[i].death_rate;
         float jgrowth = countries[j].birth_rate - countries[j].death_rate;
         if(continent == countries[j].continent && jgrowth > igrowth){
            Country temp = countries[i];
            countries[i] = countries[j];
            countries[j] = temp;
         }
      }
   for(int i=0; i<N; i++)
     if ( countries[i].continent == continent )
        cout << countries[i].name << endl;
}

//Problem 4
void top_beaches(int n){
   for(int i=0; i<N; i++)
      for(int j=i+1; j<n; j++){
            float ibeach = countries[i].coastline / countries[i].population;
            float jbeach = countries[j].coastline / countries[j].population;
            if(jbeach > ibeach)
               swap(countries[i], countries[j]);
      }
   for(int i=0; i<n; i++)
      cout << countries[i].name << endl;
}

//Problem 5
void long_live_eu(){
   for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
         if(countries[i].life_expectancy < countries[j].life_expectancy)
            swap(countries[i], countries[j]);
   for(int i=0; i<N; i++)
      if(countries[i].currency_code == "EUR")
         cout << countries[i].name << endl;
}




int main() {

    load_countries("countries.csv");
    find_continents();

    for(int i=0; i<m; i++)
       print_continent_stats(continents[i]);
    
    top_landlocked(10);

    sort_by_population_growth("Europe");

    top_beaches(10);

    long_live_eu();
   
   return 0;

}
