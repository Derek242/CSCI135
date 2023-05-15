#include <iostream>
using namespace std;

void swappednums(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 5;
    int y = 7;
    cout << x;
    cout << y;
    swappednums(x,y);
    //references directly to the function so we don't have to save it to a new variable 

    cout << x;
    cout << y;
    
}