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
/*
Don't just show a result. Show the result in the context of the formula being used.
Loop until E or e input.
Add color to enhance the program. i.e. of the output results.
Add option “clear” that enables Dr_T to clear the screen on-demand #include<stdtlib> system(“cls”);
*/

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
  cout << "\nyou entered:" << s1;
  cout << "\nWhat's the displacement?:";
  d = validateDouble(d);
  cout << "\nyou entered:" << d;
  cout << "\nEnter your measurement unit for time:";
  cout << "\nyou entered:" << s2;
  validateString(s2);
  cout << "\nWhats the amount of time?:";
  t = validateDouble(t);
  cout << "\nyou entered:" << t;
  answer = d/t; 
  cout << "\nYour V="<< setprecision(4)<< fixed << answer << " " << s1 << "/" << s2;
  cout << "\noperation "<<"\nV =" << d<< "/"<< t;
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
  cout << "\nyou entered:" << s1;
  cout <<"\nEnter your inital velocity:";
  validateDouble(iv);
  cout << "\nyou entered:" << iv;
  cout <<"\nEnter your final velocity:";
  validateDouble(fv);
  cout << "\nyou entered:" << fv;
  cout << "\nEnter your measurement unit for time:";
  validateString(s2);
  cout << "\nyou entered:" << s2;
  cout <<"\nEnter your time:";
  cout << "\nyou entered:" << t;
  validateDouble(t);
  
  answer = (fv-iv)/t;
  cout << "\na =:"<<setprecision(4)<< fixed << answer<<" "<<s1<<"/"<< s2;
  cout << "\noperation "<<"\na =" <<"("<< fv<< "-"<< iv <<")" <<"/"<<t;
}

void calc_ns2ndlaw()
{ 
  // newtons law F= M*A
  double m, a,answer;
  string s1, s2;
  cout << "\n Newtons Second Law";
  cout << "\nEnter your measurement unit for mass:";
  validateString(s1);
  cout << "\nyou entered:" << s1;
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nyou entered:" << m;
  cout << "\nEnter your measurement unit for acceleration:";
  validateString(s2);
  cout << "\nyou entered:" << s2;
  cout <<"\nEnter your acceleration:";
  validateDouble(a);
  cout << "\nyou entered:" << a;
  
  answer =m*a;
  cout << " f=" << setprecision(4)<< fixed << answer << s1 << "/" << s2;

  cout << "\noperation "<<"\nf =" << m<< "*"<< a;
}

void calc_weight()
{
   double m,answer;
   const double g = 9.8;//this is the gravitational constant of earth
  cout << "\nthis program assumes you are calculating weight on earth";
  string s1;
  cout << "\nEnter your measurement output:";
  validateString(s1);
  cout << "\nyou entered:" << s1;
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nyou entered:" << m;
  answer =m*g;
  cout << "w=" << setprecision(4)<< fixed << answer << " "<< s1; 
  cout << "\noperation "<<"\nw =" << m << "*" << g;
}
void calc_momentum()
{
  //p=m*v momentum calculkation
  double m, v,answer;
  string s1, s2;
  cout << "\n Momentum";
  cout << "\nEnter your measurement unit for mass:";
  validateString(s1);
  cout << "\nyou entered:" << s1;
  cout <<"\nEnter your mass:";
  validateDouble(m);
  cout << "\nyou entered:" << m;
  cout << "\nEnter your measurement unit for velocity:";
  validateString(s2);
  cout << "\nyou entered:" << s2;
  cout <<"\nEnter your acceleration:";
  validateDouble(v);
  cout << "\nyou entered:" << v;
  
  answer =m*v;
  cout << "p=" << setprecision(4)<< fixed << answer << s1 << "/" << s2;
  cout << "\noperation "<<"\np =" << m << "*" << v;
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
void calc_motion_1()
{ 
  // s = 1/2 (v+u) * t
  cout << "\nMotion Method 1 Executed";
  double answer=0, u=0, v=0, t=0, vau= 0;
  string s1, s2;
  cout << "\nEnter your Velocity Data Type E.G Meters:";
  validateString(s1);
  cout << "\nyou entered:" << s1;
  cout << "\nEnter initial velocity:";
  validateDouble(u);
  cout << "\nyou entered:" << u;
  cout << "\nEnter final velocity:";
  validateDouble(v);
  cout << "\nyou entered:" << v;
  cout << "\nEnter your Time Data Type E.G seconds:";
  validateString(s2); 
  cout << "\nyou entered:" << s2;
  cout << "\nEnter time:";
  cout << "\nyou entered:" << t;
  validateDouble(t);
  vau =v + u;
  answer = 1.0/2.0*vau*t;
  // had to break this apart and store v and u in a seperate variable and it fixed this always returning 0 original reference below
  //s = 1/2 (v+u) * t
  //displacement = 1/2 * (final velocity+ inital velocity) * time

  cout << "\ns=" << setprecision(4)<< fixed << answer <<" "<< s1<<"/"<<s2;

  cout << "\noperation "<<"\ns =" << "1.0/2.0*(" << v << "+"<< 
  u << ")*"<< t;
}
void calc_motion_2()
{
  //v = u + a * t
  cout << "\nMotion Method 2 Executed";
  double answer, u, v ,a, s, t;
  string s1, s2;
  cout << "\nEnter your Velocity Data Type E.G Meters:";
  validateString(s1);
  cout << "\nyou entered:" << s1;
  cout << "\nEnter initial velocity:";
  validateDouble(u);
  cout << "\nyou entered:" << u;
  cout << "\nEnter acceleration:";
  validateDouble(a);
  cout << "\nyou entered:" << a;
  cout << "\nEnter your Time Data Type E.G seconds:";
  validateString(s2); 
  cout << "\nyou entered:" << s2;
  cout << "\nEnter time:";
  validateDouble(t);
  cout << "\nyou entered:" << t;
  answer = u + a * t;
  cout << "\nv=" << setprecision(4)<< fixed << answer <<" "<< s1<<"/"<<s2;

  cout << "\noperation "<<"\nv ="<<u<<"+"<<a<<"*"<< t;

}
void calc_motion_3()
{ 
  //v2 = v02 + 2a(displacement − inital displacment?)
  //final velocity^2 = inital_velocity^2 + 2*acceleration*(displacement − inital displacement)
  // input menu code
  cout << "\nMotion Method 3 Executed";
  double answer, u, a, s;
  cout << "\nEnter the displacement:";
  validateDouble(s);
  cout << "\nyou entered:" << s;
  cout << "\nEnter initial velocity:";
  validateDouble(u);
  cout << "\nyou entered:" << u;
  cout << "\nEnter the acceleration:";
  validateDouble(a);
  cout << "\nyou entered:" << a;

  u = 2.0 * a * s;
  answer = sqrt(u);//square root was my issue for this.
  cout << "\nv^2=" << answer; //<< "^2";
  cout << "\noperation "<<"\nv^2= all of this gets squared --->u^2="<<"\n2.0 *"<<a<<"*"<<s;

}
void calc_motion_4()
{ 
  //s = s0 + v0t + ½at2   
  cout << "\nMotion Method 4 Executed";
  double answer, s, u, v, a, t;
  cout << "\nEnter initial velocity:";
  validateDouble(u);
  cout << "\nyou entered:" << u;
  cout << "Enter the acceleration:";
  validateDouble(a);
  cout << "\nyou entered:" << a;
  cout << "\nEnter the time:";
  validateDouble(t);
  cout << "\nyou entered:" << t;

  v =u + a * t;
  s=1.0/2.0*(v+u)*t;
  answer = s;
  cout << "\ns=" << setprecision(4)<< fixed << answer;

  cout << "\noperation "<<"\nv ="<<u<<"+"<<a<<"*"<< t;
  cout << "\noperation "<<"\ns ="<<1.0<<"/"<<2.0<<"*("<< v << "+" << u <<")*" << t;
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