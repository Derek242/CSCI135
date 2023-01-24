#include <iostream>
using namespace std;

int main(){
    int start;
    int end;
    cout << "Type in the starting number: ";
    cin >> start;
    cout << "Type in the ending number: ";
    cin >> end;
    for (int i = start; i < end; i++){
        if (i%2 == 0){
            cout << i << "\n";
        }

    }

}