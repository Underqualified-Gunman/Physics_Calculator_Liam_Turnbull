#include <iostream>
#include <iomanip>
#include "Input_Validation_Extended.h"
using namespace std;

//prototypes
void display_menu();
void calc_velocity();
void motion_submenu();
void calc_motion_1();
void calc_motion_2();
void calc_motion_3();
void calc_motion_4();
void calc_accelleration();
void calc_ns2ndlaw();
void calc_weight();
void calc_momentum();
bool input_catcher();


int main() 
{ 
  //color definitions would go here
  string blue = "\x1b[34;7m";
  string reset = "\x1b[0m";


  // define top level variables here
  bool loop_ref_set = true;
  bool& loop = loop_ref_set;
  
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
  << "\nWhat would you like to calculate?" 
  << "\n1. Calculate Velocity"
  << "\n2. Calculate Motion"
  << "\n3. Calculate Acceleration"
  << "\n4. Calculate Newton's Second Law"
  << "\n5. Calculate Weight"
  << "\n6. Calculate Momentum"
  << "\n9. Exit Program"

  << "\nTo select an option enter a whole number between 1-6 :";
}
//will ask a user if they want to continue after solving a problem if yes it clears the screen then redisplays the menu.

void calc_velocity()
{
  double d, t,answer;
  string string1, string2;
  cout << "\nEnter your measurement unit for displacment:";
  validateString(string1);
  cout << "\nWhat's the displacement?:";
  d = validateDouble(d);
  cout << "\nEnter your measurement unit for time:";
  validateString(string2);
  cout << "\nWhats the amount of time?:";

  t = validateDouble(t);
  answer = d/t; 
  cout << "\nYour Velocity is:"<< answer << " " << string1 << "/" << string2;
}



void calc_accelleration()
{

  // 
  //accelleration= (FINAL_VELOCITY - INITAL_VELOCITY) divided by TIME 
  //
  //CALCULATES acceleration over interval
  double iv, fv, t,answer;
  string s1, s2;
  cout << "\nEnter your measurement unit for velocity:";
  validateString(s1);
  cout <<"\nEnter your inital velocity:";
  validateDouble(iv);
  cout <<"\nEnter your final velocity:";
  validateDouble(fv);
  cout << "\nEnter your measurement unit for time:";
  validateString(s2);
  cout <<"\nEnter your time:";
  validateDouble(t);
  
  answer = (fv-iv)/t;
  cout << "your accelleration is" << answer << s1 << "/" << s2;
}

void calc_ns2ndlaw()
{ // newtons law F= M*A
  double m, a,answer;
  string s1, s2;
  cout << "\nEnter your measurement unit for mass:";
  validateString(s1);
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nEnter your measurement unit for acceleration:";
  validateString(s2);
  cout <<"\nEnter your acceleration:";
  validateDouble(a);
  
  answer =m*a;
  cout << "your force is " << answer << s1 << "/" << s2;
}

void calc_weight()
{
  
}

void calc_momentum()
{
  
}
void motion_submenu()
{

}
void calc_motion_1()
{
  
}
void calc_motion_2()
{
  
}
void calc_motion_3()
{
  
}
void calc_motion_4()
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
    motion_submenu();
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
  else if(input == 9)
  {
    input = 0;
    cout << "Why?";
    return false;
  }
  else
  { 
    cout << "\nError Incorrect Entry!";
    //cout << "\n input is" << input; debug
  } 
  return true;
}