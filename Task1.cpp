#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
bool chk(int randomnum,int guess) // Function to check if the Guess is correct or not
{
        if(guess<randomnum){
            cout<<"Your Guess is Low, Try Greater Number:\n";
            return false;
        }
        else if(guess>randomnum){
            cout<<"Your Guess is High, Try Smaller Number:\n";
            return false;
        }
        else{
            cout<<"\nCongrats! Your Guess is Right\n";
            return true;
        }
        // return bool 
}
int main() {
    cout<<"\n\x1B[4m******************************** Welcome To Number Guessing Game ********************************\x1B[0m\n";
    srand (int(time(nullptr))); 
    int randomNumber = rand()%100, num; // Generate Random Number Between 1- 100 
    bool Guess=false;
    do{ // Taking number from user untill the guess is not correct 
        cout<<"Enter Your Guess = ";
        cin>>num;
        Guess=chk(randomNumber,num);
    } while (!Guess); 
    cout<<"Thanks for Playing!\n\n"; // End
    return 0;
}