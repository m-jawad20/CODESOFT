#include"List.h" // User Define header file Containing the List class 
#include<thread>
#include<chrono>
int main()
{
    List l1; // creating list object
    int choice;
    do{
        l1.menu();
        cout<<"Enter Your Choice = "; 
        cin>>choice;
        switch (choice) // Applying User's choice
        {
        case 1:
            l1.Add_Task();
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            break;
        case 2:
            l1.Update_Task_Status();
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            break;
        case 3:
            l1.View_Tasks();
            break;
        case 4:
            l1.Delete_Task();
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            break;
        case 0:
            cout<<"Tnahks!";
            break;
        default:
            cout<<"Wrong Choice Please ReEnter Your Choice(0-4) : ";
            break;
        }
    } while (choice!=0);
    
    return 0;
}