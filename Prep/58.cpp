#include <iostream>
using namespace std;

int main(){
    int num;
    char symbol;
    cout << "Enter an int: " << endl;
    cin >> num;
    cout << "Enter a symbol other than space: " << endl;
    cin >> symbol;
    
    for (int i = 0; i < num; i++){
        for (int blank = num - i; blank > 0; blank--)
            cout << " ";
        
        for(int sym = 0; sym < i; sym++){
            cout << symbol;
        }
        cout << endl;
    }
    
}