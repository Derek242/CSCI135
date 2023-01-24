#include <iostream>
using namespace std;

int main(){
    float annual;
    float monthly;
    cout << "Input your annual budget: ";
    cin >> annual;
    cout << "Input your month expense: ";
    cin >> monthly;
    float inflation;
    inflation = monthly * 0.15 + monthly;
    cout << "month	expense	remaining balance of budget\n";
    for (int i = 1; i <= 12; i++){
        if (i<=6){
            cout << i << "             " << monthly << "               " << annual-monthly * i << endl;
    
        }
        else if (i>6){
            cout << i << "              " << inflation << "             " << annual-inflation * i << endl;
            
        }
        if (i==12 && annual-inflation*i >= 0){
            cout << "You're on track";
        }
        else if (i==12 && annual-inflation*i < 0){
            cout << "You need a higher budget";
        }
            
        
    }
    cout << endl;
}