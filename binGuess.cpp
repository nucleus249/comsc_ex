
//Nicholas Vaughan
//Programming assignment 2
//Name: BinGuess.cpp
//Date: 3/1/16
//COMSC-1450-A
//
//This program uses a binary algorithm to guess a number that the user
//is thinking of between 0 and 100.
//
#include<iostream>
#include<string>
#include<random>

using namespace std;

int main()
{
   string answer;
   int size = 101;
   int guess;
   int max = size;
   int min = 0;

   //Prompts user with first guess.
   cout << "Pick a number between 1 and 100\n";
   guess = rand() % size;
   cout << "Is your number " << guess << "?\t\tyes/higher/lower\n";

   //Loops until answer is yes.  Includes user error message.
      do
      {
         cin >> answer;

         if (answer == "higher")
         {
            min = guess;
            guess = (max + min)/2;
            cout << "Is your number " << guess << "?\t\tyes/higher/lower\n";
         }
         else if (answer == "lower")
         {
            max = guess;
            guess = (max + min)/2;
            cout << "Is your number " << guess << "?\t\tyes/higher/lower\n";

         }
         else if (answer == "yes")
         {
            cout << "yay! I got it!\n";
            break;
         }
         else
             cout << " you must say higher or lower or yes.\n";
      }
      while (answer == "higher" || answer == "lower" || answer != "yes");
   
      return 0;
}

