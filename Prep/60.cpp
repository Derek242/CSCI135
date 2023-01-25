#include <iostream>
using namespace std;

int main(){
    int n;
    //recieving our number
    cout << "Give a whole number between -128 and 127: " << endl;
    cin >> n;
    //if num is negative we swap to positive and add -1
    int num = n;
    if (num < 0){
        num = -num-1;
    }
    //giving us our 1s and 0s until there is nothing left
    string result;
    int rem;
    while (num > 0){
        rem = num%2;
        result = to_string(rem) + result; //to_sring makes the int into a string
        num /=2;
    }
    //to make sure we get all 8 digits if the length is less than 8
    int size = 8;
    int len = result.length();
    for (int i=0; i < size-len; i++){
        result = "0" + result;
    }
    //reversal if OG input is negative
    if (n<0){
        for (int i = 0; i < result.length(); i++){
            if (result[i] == '0'){
                result[i] = '1';
            }
            else if (result[i] == '1'){
            result[i] = '0';
            }
        }
    }
    cout << "Binary string: " << result << endl;
}