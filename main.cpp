#include <iostream>
#include <iomanip>
#include <cmath>
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
  //color definitions go here
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
  << "\n"
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
  string s1, s2;
  cout << "\n Velocity";
  cout << "\nEnter your measurement unit for displacment:";
  validateString(s1);
  cout << "\nWhat's the displacement?:";
  d = validateDouble(d);
  cout << "\nEnter your measurement unit for time:";
  validateString(s2);
  cout << "\nWhats the amount of time?:";
  t = validateDouble(t);
  answer = d/t; 
  cout << "\nYour Velocity is:"<< answer << " " << s1 << "/" << s2;
}
void calc_accelleration()
{
  //accelleration= (FINAL_VELOCITY - INITAL_VELOCITY) divided by TIME 
  //CALCULATES acceleration over interval
  double iv, fv, t,answer;
  string s1, s2;
  cout << "\n Acceleration";
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
  cout << "your accelleration is "<<answer<<" "<<s1<<"/"<< s2;
}

void calc_ns2ndlaw()
{ 
  // newtons law F= M*A
  double m, a,answer;
  string s1, s2;
  cout << "\n Newtons Second Law";
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
   double m,answer;
   const double g = 9.8;//this is the gravitational constant of earth
  cout << "\nthis program assumes you are calculating weight on earth";
  string s1;
  cout << "\nEnter your measurement output:";
  validateString(s1);
  cout <<"\nEnter your mass:";
  validateDouble(m);
  answer =m*g;
  cout << "your force is " << answer << " "<< s1; 
}
void calc_momentum()
{
  //p=m*v momentum calculkation
  double m, v,answer;
  string s1, s2;
  cout << "\n Momentum";
  cout << "\nEnter your measurement unit for mass:";
  validateString(s1);
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nEnter your measurement unit for velocity:";
  validateString(s2);
  cout <<"\nEnter your acceleration:";
  validateDouble(v);
  
  answer =m*v;
  cout << "your force is " << answer << s1 << "/" << s2;
}
void motion_submenu()
{ 
  int input;
  bool loop=true;
  //loops the input checking logic until 1-4 is entered then it sets loop to false and makes it go back to the original menu
  do
  {
    cout //u v a s t
    << "\nMomentum Select 1 of 4 Options"
    << "\n* ^ is denotion that the following number is an exponent"
    << "\n1.   s = 1/2 (v+u) * t"
    << "\n2.   v = u + a * t"
    << "\n3. v^2 = u^2 + 2*a*s"
    << "\n4.   s = ut + 1/2 *a*t^2"
    << "\n9. Return to Main Menu."
    ;
    validateInt(input);
    if(input ==1)
    {
      calc_motion_1();
      loop = false;
    }
    else if(input ==2)
    {
      calc_motion_2();
      loop = false;
    }
    else if(input ==3)
    {
      calc_motion_3();
      loop = false;
    }
    else if(input ==4)
    {
      calc_motion_4();   
      loop = false;
    }
    else if(input ==9)
    {
      break;// now i realise i could have just write this vs loop=true and such with bools
    }
    else
    {
      cout << "\n Error Invalid input!";
    }
  }while(loop==true);



}
/*the 4 types of motion to calculate
v = v0 + at
s = s0 + v0t + ½at2
v2 = v02 + 2a(s − s0)
v̅ = ½(v + v0)
            
            Ma = solve for v

            Ms = solve for s

            Mv2 = solve for v^2

            Mv = solve for v_bar
*/
void calc_motion_1()
{ 
  // s = 1/2 (v+u) * t
  // todo fix this and find out why the result is always 0
  cout << "\nMotion Method 1 Executed";
  double answer=0, u=0, v=0, t=0;
  string s1, s2;
  cout << "\n Enter your Velocity Data Type E.G Meters:";
  validateString(s1);
  cout << "\nEnter initial velocity";
  validateDouble(u);
  cout << "\nEnter final velocity";
  validateDouble(v);
  cout << "\n Enter your Time Data Type E.G seconds:";
  validateString(s2); 
  cout << "\nEnter time";
  validateDouble(t);
  cout <<"debug spew"<< answer <<u<< v << t<< s1 << s2;
  answer = 1/2*(v + u)*t;//todo fix this somehow always results in 0

  
  cout << "\nyour displacement is " << p <<" "<< s1<<"/"<<s2;
}
void calc_motion_2()
{
  //v = u + a * t
  cout << "\nMotion Method 2 Executed";
  double answer, u, v ,a, s, t;
  string s1, s2;
  cout << "\n Enter your Velocity Data Type E.G Meters:";
  validateString(s1);
  cout << "\nEnter initial velocity";
  validateDouble(u);
  cout << "\nEnter acceleration";
  validateDouble(a);
  cout << "\n Enter your Time Data Type E.G seconds:";
  validateString(s2); 
  cout << "\nEnter time";
  validateDouble(t);
  answer = u + a * t;
  cout << "\nyour velocity is " << answer <<" "<< s1<<"/"<<s2;

}
void calc_motion_3()
{
  //v^2 = u^2 + 2*a*s
  cout << "\nMotion Method 3 Executed";
  double answer, u, v ,a, s, t;
  string s1, s2;
  cout << "\n Enter your Velocity Data Type E.G Meters:";
  validateString(s1);
  cout << "Enter initial velocity";
  validateDouble(u);
  cout << "Enter final velocity";
  validateDouble(v);
  cout << "\n Enter your Time Data Type E.G seconds:";
  validateString(s2); 
  cout << "Enter time";
  validateDouble(t);


}
void calc_motion_4()
{
  //s = u*t + 1/2 *a*t^2
  cout << "\nMotion Method 4 Executed";
  double answer, u, v ,a, s, t;
  string s1, s2;
  cout << "\n Enter your Velocity Data Type E.G Meters:";
  validateString(s1);
  cout << "Enter initial velocity";
  validateDouble(u);
  cout << "Enter final velocity";
  validateDouble(v);
  cout << "\n Enter your Time Data Type E.G seconds:";
  validateString(s2); 
  cout << "Enter time";
  validateDouble(t);



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