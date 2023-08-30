//push_back is adding a value at the end and pop_back is removing the last item for vectors (arrays).

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
/*
1) What does the * operator do: 
    The * operator is called a pointer and creates a pointer variable when initialized. 
    A pointer points to the address of a variable of its same object variant/type.

2) Can a function return a pointer to a dynamic array? Why?
    Yes, a function can return a pointer to a dynamic array since the pointer 
    can point to the first value of the dynamic array and can be used to access the rest of the values

3) Explain the difference between the current size and the capacity of an array:
    The current size of an array is the amount of elements that is stored in the array 
    the capacity is the maximum amount of memory allocated to the array

4) What is the difference between passing by value and passing by reference to a function:
    The difference between passing a value and passing a reference to a function is that passing a value 
    creates a copy of the variable that is being passed through while the reference directly changes the variable

5) Explain the purpose of the :: operators?
    The :: operator is used to refer to and impliment member functions outside of the class
    (refers to the class that the function belongs to)

6) Why is it important to use the "delete" operator on a pointer to a dynamic object, before setting its value to nullptr?
    We need to deallocate it because its the only way to access the pointer and by setting it to nullptr
    it resets the pointer so that memoyr cannot be accessed but still takes space.
    (we used the delete operator to deallocate memory and setting pointer to nullptr frees up memory space and not allowing us to access the deleted memory)

7) What does the -> operator do?
    The arrow is used to access the variabels of a class pointer.

8) What is the public interface of a class?
    What is denoted under public: and can be accessed by functions outside the class (getters, setters, constructors).
    These usually contain methods, constructions, and variables.

9) What is a pointer?
    A pointer is a variable that holds the address of another variable.

10) What does the & operator do?
    The operator is used to access the address of the variable it is placed next to
    returns the memory address of the object/variable.
*/


//Write a recursive function that determines the number of digits in a positive number "n".
//Hint: if n is < 10. It has one digit; otherwise, it has one more digit than (n/10) has.

// int determine_num_of_dig(int n){
//     if (n < 10){ 
//         return 1;
//     }
//     return (determine_num_of_dig(n/10) + 1); 
// }

//Write a function that replaces the value to which p points with x, if x is greater, 
//and always returns the old value to which p was pointing.
// double replace_if_greater(double* p, double x){
//     double old;
//     old = *p;
//     if (x > old){
//         *p = x;
//     }
//     return old;
// }


//Reverse a string with one parameter
// void reverse(string &s){
//     char backwards = ' ';
//     for (int i = 0; i < (s.length())/2; i++){ //Monkey Mon|key -> yek|noM
//         backwards = s[i];
//         s[i] = s[s.length()-i - 1]; //s = "Monkey" *Must minus one because if s[0] is M then s.size() is 6 and then -1 is still 6
//         //However s[6] doesn't exist and we must -1 to find the last character
//         s[s.length()-i - 1] = backwards;
//     }
// }

//Write a func that removes the last string from a non-empty vector of strings, 
//add a new string to the vector, and returns the removed string
std::string replace(std::vector<std::string> &my_vector, std::string new_string){
    std::string deleted = my_vector[my_vector.size()-1];
    my_vector.pop_back();
    my_vector.push_back(new_string);
    // for(int i=0; i<my_vector.size(); i++){
    //     std::cout << my_vector[i];
    // }
    return deleted;
}

class Point{
    //The we-like-to-be-extra way
    // private:
    //     double x;
    //     double y;
    public:
    // double distance(Point a, Point b);
    double x;
    double y;
};

// double Point::distance(Point a, Point b)          part of the extra way
//     double dx = a.x - b.x;
//     double dy = a.y - a.y;
//     return sqrt(pow(dx,2) + pow(dy,2));    
// }

// double distance(Point a, Point b){
//     double dx = a.x - b.x;
//     double dy = a.y - b.y;
//     return sqrt(pow(dx,2) + pow(dy,2));    
// }

// int main(){
//     Point a;
//     Point b;
//     cout << "x and y of the two points: ";
//     cin >> a.x >> a.y >> b.x >> b.y;
//     cout << distance(a,b);
// }

// int factorial(int a){
//     if(a == 1){
//         return 1;
//     }
//     return a*factorial(a-1);
// }

//Write a function that returns a pointer to the first occurence of the string "s" in the dynamic array of strings or nullptr if there is no match.
// string *found (string *my_array_of_string, string s, int size){
//     //string *x;
//     //must find the first occurence of s
//     for (int i = 0; i < size; i++){
//         if (my_array_of_string[i] == s){
//             return &my_array_of_string[i];
//             //return x;
//         }
//     }
//     return nullptr;
// }

string *found (string *my_array_of_string, string s, int size){
    string *x;
    //must find the first occurence of s
    for (int i = 0; i < size; i++){
        if (*(my_array_of_string+i) == s){
            return my_array_of_string+i;
            //return x;
        }
    }
    return nullptr;
}



int main(){
    // string x = "Hello";
    // reverse(x);
    // cout << x << endl;
    // int size; //declares size for a random integer
    // cout << "Size: "; // asking for user input 
    // cin >> size;  // setting user input to size

    // int* myArray = new int[size]; //Creating dynamic array

    // for (int i = 0; i < size; i++){
    //     //loops though every element in the array to store a new value
    //     cout << "Array[" << i << "] ";
    //     cin >> myArray[i]; //referencing the array stores the value to memory where it is pointed
    // }

    // for (int i = 0; i < size; i++){
    //     //prints out the stored array
    //     cout << myArray[i] << " "; //brackets deallocate the pointer, giving us the stored value
    // }

    // delete[]myArray; //this deletes the array
    // myArray = nullptr; //sets the memory to NULL

    // int a[7] = {4,5,6243234,72342342,82352352,93465346,10};
    // int* p = a; // a[0]
    // p = a + 4; // a[0+4] = a[4]
    // cout << *p << endl; //This returns the element of the position of the array a[4] 

    // vector<float>e;
    // float f = 10;
    // float c = 12;
    // e.push_back(f); //{f} = {10}
    // e.push_back(c); //{f,g} == {10,12}
    // cout << e[0] << e[1] << endl; 
    // e.pop_back(); //{10}
    // for (int i = 0; i < e.size(); i++){
    //     cout << e[i] << endl;
    // }
    // int x = 5;
    // cout << factorial(x);
    
    std::string my_array[] = {"apple", "banana", "orange", "kiwi", "mango"};
    int size = sizeof(my_array); // sizeof(my_array[0]);  - we dont need this part
    string *w = found(my_array, "kiwi", size);
    cout << *w << endl;
    //cout << found(my_array, "kiwi", size) << endl;
}


//Create a class for a dog, must be able to change his name and fur color

// class Dog{
//     private:
//         string dog_name;
//         string fur_color;
//     public:
//         Dog();
//         Dog(string dog, string fur);
//         string getName();
//         string getFur();
//         void setName(string n);
//         void setFur(string f);
// };

// Dog::Dog(){
//     dog_name = "UNKNOWN";
//     fur_color = "UNKNOWN";
// }

// Dog::Dog(string dog, string fur){
//     dog_name = dog;
//     fur_color = fur;
// }

// string Dog::getName(){
//     return dog_name;
// }

// string Dog::getFur(){
//     return fur_color;
// }

// void Dog::setName(string n){
//     dog_name = n;
// }

// void Dog::setFur(string f){
//     fur_color = f;
// }

// //Create class breed that inherts dog. We should be able to change breed

// class Breed : public Dog{ //inherentance
//     private:
//         string breed; //variable
    
//     public:
//         Breed(); //Intitalize without variable (Constructor)
//         Breed(string n, string f, string b); //Initalize with variables
//         string getBreed(); //getter
//         void setBreed(string b); //setter
// };

// Breed::Breed(){
//     Dog();
//     breed = "UNKNOWN";
// }

// Breed::Breed(string n, string f, string b){
//     Dog();
//     breed = b;
// }

// string Breed::getBreed(){
//     return breed;
// }

// void Breed::setBreed(string b){
//     breed = b;
// }