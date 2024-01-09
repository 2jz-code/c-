#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double radius, weight_object;
    cout << "Radius of one balloon (cm):" << endl;
    cin >> radius;
    cout << "Weight of object being lifted (kg):" << endl;
    cin >> weight_object;

    double balloon_volume;

    balloon_volume = 4.0/3.0 * M_PI * pow(radius, 3);

    cout << "Volume for one balloon (cm^3):\n" << balloon_volume << endl;

    int balloon_needed;
    balloon_needed = 1.0 + weight_object / (balloon_volume * 9.958736e-7);

    cout << "Number of balloons needed:\n" << balloon_needed << endl;

    double total_volume = balloon_needed * balloon_volume;

    cout << "Total Volume (cm^3):\n" << total_volume << endl;
}