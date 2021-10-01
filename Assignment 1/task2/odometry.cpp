#include<math.h>
#include<iostream>
#include<fstream>

#define PI 3.14159265
int wheelbase=30, delta_t=1;
const int SIZE=200;
double vl=10, vr=8;
double rob_x[SIZE]={30}, rob_y[SIZE]={30}, rob_theta[SIZE]={PI/4};

int robot_kinematics(double left_vel, double right_vel)
{
	int i;
	for(i=0; i<SIZE;i++)
	{	//left wheel velocity computation
		rob_x[i+1]=rob_x[i]+(right_vel+left_vel)/2*cos(rob_theta[i])*delta_t;
		//right wheel velocity computation
		rob_y[i+1]=rob_y[i]+(right_vel+left_vel)/2*sin(rob_theta[i])*delta_t;
		//heading direction computation - right wheel subtract left wheel divide by base * time
		rob_theta[i+1]=rob_theta[i]+(right_vel-left_vel)/wheelbase*delta_t;
	}
	return 0;
}

FILE *fp;
int main(int argc, char **argv)
{
	int i;
	fp = fopen("odometry_data2","w");
	robot_kinematics(vl,vr);
	fprintf(fp, "%d, %d \n", 30,30);
	for(i = 1; i<SIZE;i++){
		fprintf(fp, "%f,%f \n", rob_x[i], rob_y[i]);	
	}
	fclose(fp);
	return 0;
}
