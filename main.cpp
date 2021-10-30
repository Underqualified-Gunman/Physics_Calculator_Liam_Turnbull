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
  char s1, s2;
  cout << "\n Velocity";
  cout << "\nEnter your measurement unit for displacment:";
  validateChar(s1);
  cout << "\nWhat's the displacement?:";
  d = validateDouble(d);
  cout << "\nEnter your measurement unit for time:";
  validateChar(s2);
  cout << "\nWhats the amount of time?:";
  t = validateDouble(t);
  answer = d/t; 
  cout << "\nYour Velocity is:"<< setprecision(4)<< fixed << answer << " " << s1 << "/" << s2;
}
void calc_accelleration()
{
  //accelleration= (FINAL_VELOCITY - INITAL_VELOCITY) divided by TIME 
  //CALCULATES acceleration over interval
  double iv, fv, t,answer;
  char s1, s2;
  cout << "\n Acceleration";
  cout << "\nEnter your measurement unit for velocity:";
  validateChar(s1);
  cout <<"\nEnter your inital velocity:";
  validateDouble(iv);
  cout <<"\nEnter your final velocity:";
  validateDouble(fv);
  cout << "\nEnter your measurement unit for time:";
  validateChar(s2);
  cout <<"\nEnter your time:";
  validateDouble(t);
  
  answer = (fv-iv)/t;
  cout << "your accelleration is "<<setprecision(4)<< fixed << answer<<" "<<s1<<"/"<< s2;
}

void calc_ns2ndlaw()
{ 
  // newtons law F= M*A
  double m, a,answer;
  char s1, s2;
  cout << "\n Newtons Second Law";
  cout << "\nEnter your measurement unit for mass:";
  validateChar(s1);
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nEnter your measurement unit for acceleration:";
  validateChar(s2);
  cout <<"\nEnter your acceleration:";
  validateDouble(a);
  
  answer =m*a;
  cout << "your force is " << setprecision(4)<< fixed << answer << s1 << "/" << s2;
}

void calc_weight()
{
   double m,answer;
   const double g = 9.8;//this is the gravitational constant of earth
  cout << "\nthis program assumes you are calculating weight on earth";
  char s1;
  cout << "\nEnter your measurement output:";
  validateChar(s1);
  cout <<"\nEnter your mass:";
  validateDouble(m);
  answer =m*g;
  cout << "your force is " << setprecision(4)<< fixed << answer << " "<< s1; 
}
void calc_momentum()
{
  //p=m*v momentum calculkation
  double m, v,answer;
  char s1, s2;
  cout << "\n Momentum";
  cout << "\nEnter your measurement unit for mass:";
  validateChar(s1);
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nEnter your measurement unit for velocity:";
  validateChar(s2);
  cout <<"\nEnter your acceleration:";
  validateDouble(v);
  
  answer =m*v;
  cout << "your force is " << setprecision(4)<< fixed << answer << s1 << "/" << s2;
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
    << "\n3.  v2 = v02 + 2as"
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
v̅ = ½(v + u)
v = u + at
v2 = u2 + 2a(s − s0)
s = s0 + ut + ½ (a*t)^2          
            Ma = solve for v

            Ms = solve for s

            Mv2 = solve for v^2

            Mv = solve for v_bar
s=1/2*(v+u)*t// only useable if v is constant
v = u+at//ka
v^2 = u^2+2as//ka
s = ut + 1/2 at^2//ka
*/
void calc_motion_1()
{ 
  // s = 1/2 (v+u) * t
  cout << "\nMotion Method 1 Executed";
  double answer=0, u=0, v=0, t=0, vau= 0;
  char s1, s2;
  const double one = 1.0, two = 2.0;
  cout << "\nEnter your Velocity Data Type E.G Meters:";
  validateChar(s1);
  cout << "\nEnter initial velocity";
  validateDouble(u);
  cout << "\nEnter final velocity";
  validateDouble(v);
  cout << "\nEnter your Time Data Type E.G seconds:";
  validateChar(s2); 
  cout << "\nEnter time";
  validateDouble(t);
  cout <<"\ndebug spew"<< setprecision(4)<< fixed << answer << u << v << t<< s1 << s2;

  vau =v + u;
  answer = one/two*vau*t;
  // had to break this apart and store v and u in a seperate variable and it fixed this always returning 0 original reference below
  //s = 1/2 (v+u) * t
  //displacement = 1/2 * (final velocity+ inital velocity) * time

  
  cout << "\nyour displacement is " << setprecision(4)<< fixed << answer <<" "<< s1<<"/"<<s2;
}
void calc_motion_2()
{
  //v = u + a * t
  cout << "\nMotion Method 2 Executed";
  double answer, u, v ,a, s, t;
  char s1, s2;
  cout << "\nEnter your Velocity Data Type E.G Meters:";
  validateChar(s1);
  cout << "\nEnter initial velocity";
  validateDouble(u);
  cout << "\nEnter acceleration";
  validateDouble(a);
  cout << "\nEnter your Time Data Type E.G seconds:";
  validateChar(s2); 
  cout << "\nEnter time";
  validateDouble(t);
  answer = u + a * t;
  cout << "\nyour velocity is " << setprecision(4)<< fixed << answer <<" "<< s1<<"/"<<s2;

}
void calc_motion_3()
{ 
  //v2 = v02 + 2a(displacement − inital displacment?)
  //final velocity^2 = inital_velocity^2 + 2*acceleration*(displacement − inital displacement)
  // input menu code
  cout << "\nMotion Method 3 Executed";
  double answer, u, a, s;
  cout << "\nEnter the displacement";
  validateDouble(s);
  cout << "\nEnter initial velocity";
  validateDouble(u);
  cout << "\nEnter the acceleration";
  validateDouble(a);

  u = 2.0 * a * s;
  answer = sqrt(u);//square root was my issue for this.
  cout << "\nthe final velocity is " << answer; //<< "^2";
}
void calc_motion_4()
{ 
  //s = s0 + v0t + ½at2   
  cout << "\nMotion Method 4 Executed";
  double answer, s, u, v, a, t;
  cout << "\nEnter initial velocity";
  validateDouble(u);
  cout << "Enter the acceleration";
  validateDouble(a);
  cout << "\nEnter the time";
  validateDouble(t);

  v =u + a * t;
  s=1.0/2.0*(v+u)*t;
  answer = s;
  cout << "\nthe final displacement is " << setprecision(4)<< fixed << answer;
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