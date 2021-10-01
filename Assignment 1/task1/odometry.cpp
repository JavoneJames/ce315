#include<math.h>
#include<iostream>
#include<fstream>

int wheelbase, delta_t, SIZE;
double rob_x[SIZE], rob_y[SIZE], rob_theta[SIZE];

int robot_kinematics(double left_vel, double right_vel)
{
 int i;

 for(i=0; i<SIZE; i++)
 {
 rob_x[i+1]=rob_x[i]+(right_vel + left_vel)/2*cos(rob_theta[i])*delta_t;
 // Put your code for other two equations here
rob_y[i+1]=rob_y[i]+(right_vel + left_vel)/2*sin(rob_theta[i])*delta_t;
rob_theta[i+1]=rob_theta[i]+(right_vel - left_vel)/wheelbase*delta_t;
 }
 return 0;
}
