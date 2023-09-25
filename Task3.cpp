#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;
bool check(char grid[3][3]) { // Function to Check if Any Player wins or not :
    for (int row = 0; row < 3; row++) { // check rows
        if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2] && grid[row][0] != '_') {
            return true; }
    }
    for (int col = 0; col < 3; col++) { // check columns
        if (grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col] && grid[0][col] != '_') {
            return true; }
    }
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '_') || // check Dignals
        (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '_')) {
        return true;}
    return false;
}
void display(char grid[3][3]) // function to display the Game Board
{
    cout<<"\n\x1B[4m*************** Welcome to Tic-Tak-Toe Game ***************\x1B[0m\n";
    string x="\x1B[4m" + string(1, 'X') + "\x1B[0m",o="\x1B[4m" + string(1, 'O') + "\x1B[0m";
    cout<<" _ _ _\n";
    for (int i = 0; i < 3; i++) {
          cout<<"|";
        for (int j = 0; j < 3; j++) {
            if(grid[i][j]=='X'){
                cout <<x << "|";
            }
            else if(grid[i][j]=='O'){
                cout <<o << "|";
            }
            else{
                cout <<grid[i][j] << "|";
            }
        }
        cout << endl;
    }
}
void Grid(char grid[3][3]) // Making the 3*3 Board for the Game
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] ='_';
        }
    }
}
bool done(char position,char grid[3][3]) // Check if the game is over or not
{
    bool flag;
    switch (position) {
        case '1':
                if(grid[0][0]=='X'||grid[0][0]=='O'){
                    flag=true;
                }
            break;
        case '2':
                if(grid[0][1]=='X'||grid[0][1]=='O'){
                    flag=true;
                }
                break;
        case '3':
                if(grid[0][2]=='X'||grid[0][2]=='O'){
                    flag=true;
                }
                break;
         case '4':
                if(grid[1][0]=='X'||grid[1][0]=='O'){
                    flag=true;
                }
                break;
        case '5':
                if(grid[1][1]=='X'||grid[1][1]=='O'){
                    flag=true;
                }
                break;
        case '6':
                if(grid[1][2]=='X'||grid[1][2]=='O'){
                    flag=true;
                }
                break;
         case '7':
                if(grid[2][0]=='X'||grid[2][0]=='O'){
                    flag=true;
                }
                break;
        case '8':
                if(grid[2][1]=='X'||grid[2][1]=='O'){
                    flag=true;
                }
                break;
        case '9':
                if(grid[2][2]=='X'||grid[2][2]=='O'){
                    flag=true;
                }
                break;
        default:
                break;
        }
    return flag;
}
int main(){ // Main
    string Again="no";
do{
    char grid[3][3]; 
    char p1='X',p2='O',position=0,move=0;
    int start=1;
    bool chk=false;
    Grid(grid);
    display(grid);
    do{
        cout<<"Note: Enter Your Position From 1 to 9\n";
        bool flag=false;
        if ((start+1)%2==0){
            cout<<"\nEnter Your Move player 1 = ";
            move=p1;
        }
        else{
            cout<<"\nEnter Your Move player 2 = ";
            move=p2;
        }
        do{
            cin>>position;
            flag=done(position,grid);
            if(flag){
            cout<<"This place is already fill Please try another position = "; // check if the position is already filld ?
            }
            if(flag==false){
                break;
            }
        } while (1);
        switch (position){ // Add the symbol of the current Player at the given position of the Grid  
        case '1':
                grid[0][0]=move;
                start++;
            break;
        case '2':
                grid[0][1]=move;
                start++;
            break;
        case '3':
                grid[0][2]=move;
                start++;
            break;
         case '4':
                grid[1][0]=move;
                start++;
            break;
        case '5':
                grid[1][1]=move;
                start++;
            break;
        case '6':
                grid[1][2]=move;
                start++;
            break;
         case '7':
                grid[2][0]=move;
                start++;
            break;
        case '8':
                grid[2][1]=move;
                start++;
            break;
        case '9':
                grid[2][2]=move;
                start++;
            break;
        default:
                cout<<"You enter Wrong Position please Try Again:\n";
            break;
        }
        system("cls");
        display(grid);
        if(start>4){
        chk=check(grid);
        if(chk) // Check is the Game over or not ?
        {
            if(move=='X'){
            cout<<"Player 1 Wins\nCongrats!\n";
            break;
            }
            else{
            cout<<"Player 2 Wins\nCongrats!\n";
            break;
            }
        }
        else if(!chk&& start<10){
            cout<<"Ongoing!\n";
        }    
        }
    } while (start!=10);
    if(start>9&&chk==false){
    cout<<"Match is Draw\n"; }
    cout<<"Do You want to Play Again yes/no : ";
    cin>>Again;
    if(Again=="yes"){
       system("cls");
    }
}while(Again =="yes"); // Loop untill user type Yes 
    cout<<"Thank You for Playing !\n";
    return 0;
} // End