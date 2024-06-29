/*
 *  lab1exe_A.cpp
 *  ENSF 694 Lab 1, exercise A
 *  Created by Mahmood Moussavi
 *  Completed by: Ryan Baker
 *  Development Date: June 26, 2024
 */

#include <iostream>
#include <cmath>
#include <iomanip> // included for table formatting
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
/* REQUIRES
 *   v (double) the velocity to base the table on
 * PROMISES 
 *   prints a table of angle (0-90 degrees) with corresponding times and distances
 */

double Projectile_travel_time(double a, double v);
/* REQUIRES
 *   0 < a < 90.
 * PROMISES 
 *  return value is projectile travel time when maximum horizontal distance is reached (in seconds).
 */

double Projectile_travel_distance(double a, double v);
/* REQUIRES
 *   0 < a < 90.
 * PROMISES 
 *  return value is maximum projectile distance (in metres).
 */

double degree_to_radian(double d);
/* REQUIRES
 *  Angle in degrees between 0 and 360.
 * PROMISES 
 *  returns value is angle in radians.
 */

int main(void)
{
    double velocity;
    
    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;
    
    
    if(!cin)  // means if cin failed to read
    {
        cout << "Invlid input. Bye...\n";
        exit(1);
    }
    
    while (velocity < 0 )
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if(!cin)
        {
            cout << "Invlid input. Bye...";
            exit(1);
        }
    }

    create_table(velocity);
    
    return 0;
}


void create_table(double v){
    cout << "Angle\t\t\tt\t\t\td\n(deg)\t\t\t(sec)\t\t\t(m)\n";
    cout << std::fixed << std::setprecision(6); // format digits of table
    for(double i = 0; i <= 90; i +=5){
        cout << i << "\t\t" << Projectile_travel_time(i, v) << "\t\t" << Projectile_travel_distance(i, v) << "\n";
    }
}


double degree_to_radian(double d){
    return (d / 180 * PI);
}


double Projectile_travel_time(double a, double v){
    return abs(2 * v * sin(degree_to_radian(a)) / G);
}


double Projectile_travel_distance(double a, double v){
    return abs(v * v * sin(degree_to_radian(2*a)) / G);
}