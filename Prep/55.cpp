#include <iostream>
using namespace std;

int main(){
    cout << "Enter the degree in Celcius: ";
    int celsius;
    cin >> celsius;
    int farenheit;
    farenheit = 9/5 * celsius + 32;
    cout << "The degree in Farenheit will be :" << farenheit << ".\n";
    return 0;


}