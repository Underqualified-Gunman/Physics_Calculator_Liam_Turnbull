#include <iostream>
#include "Input_Validation_Extended.h"
using namespace std;

//prototypes
void display_menu();
void calc_velocity();
void calc_motion();
void calc_accelleration();
void calc_ns2ndlaw();
void calc_weight();
void calc_momentum();
bool input_catcher();


int main() 
{ 
  // define top level variables here
  bool loop = true;

  cout<< "Welcome to Liam's Foundational Physics Calculator!";
  do
  {
    display_menu();
    loop = input_catcher();
  }
  while(loop == true);
  return 0;
}

void display_menu()
{
  cout 
  << "\n What would you like to calculate?" 
  << "\n1. Calculate Velocity"
  << "\n2. Calculate Motion"
  << "\n3. Calculate Acceleration"
  << "\n4. Calculate Newton's Second Law"
  << "\n5. Calculate Weight"
  << "\n6. Calculate Momentum"
  << "\n9. Exit Program"
  << "\n To select an option enter a whole number between 1-6 :";
}

void calc_velocity()
{
  double d, t,answer;
  cout << "\nWhat's the displacement?:";
  d = validateDouble(d);
  cout << "\nWhats the amount of time?:";
  t = validateDouble(t);
  answer = d/t; 
  cout << "\nYour Velocity is:"<< answer;
}

void calc_motion()
{
  
}

void calc_accelleration()
{
  
}

void calc_ns2ndlaw()
{
  
}

void calc_weight()
{
  
}

void calc_momentum()
{
  
}
bool input_catcher()
{ 
  int input=0;
  validateInt(input);
  if(input == 1)
  {
    calc_velocity();
  }
  else if(input ==2)
  {
    calc_motion();
  }
  else if(input ==3)
  {
    calc_accelleration();
  }
  else if(input ==4)
  {
    calc_ns2ndlaw();
  }
  else if(input ==5)
  {
    calc_weight();
  }
  else if(input ==6)
  {
    calc_momentum();
  }
  else if(input ==9)
  { 
    cout << "Why?";
    return false;
  }
  else
  {
    cout << "\nError Incorrect Entry!";
  }



  return true;
}


/*
 bool loop = true;
  int input;
  do
  {
    cout << "\nenter a one or two :";
    input = validateInt(input); 
    if(input == 1)
    {
      cout << "\ncase 1";
      loop = false;
    }
    else if(input == 2)
    {
      cout << "\n case 2";
      loop = false;
    }
    else
    {
      cout << "\nerror case";
    }
    
  } 
  while(loop == true);
  return 0;
*/