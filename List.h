#include"Node.h"
class List // List class
{
private: // Private Attributes 
    Node* head;
    Node* tail;
public: // Public Functions
    List();
    ~List();
    void Add_Task() // Function to add a new task 
    {
        string name;
        cout<<"Enter Task Name = ";
        cin>>name;
        Node *node=new Node;
        node->Task=name;
        node->Status=0;
        node->next=nullptr;
        if(head==nullptr){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
        cout<<"Task Added Successfuly!\n";
    }
    void Update_Task_Status() // Function to Update the Task Status
    {
        bool avaieble;
        do{
            avaieble=false;
            Node*temp=head;
            string name;
            cout<<"Enter Task Name to Update it's Status to Complete = ";
            cin>>name;
            while (temp!=nullptr){
                if(temp->Task==name){
                    temp->Status=1;
                    avaieble=true;
                    break;
                }
                temp=temp->next;
            }
            if(!avaieble){
                cout<<"You Enter Wrong Task Name Please Try Again!\n";
            }
            else{
                cout<<"Task "<<temp->Task<<" Updated to Complete Successfuly\n";
            }
        } while (avaieble!=true);
    }
    void View_Tasks(){ //Function to display all the Tasks 
        Node*temp=head;
        cout<<"\n\x1B[4mTask    Status\x1B[0m\n";
        if(head==nullptr){
            cout<<"No Task Avalibel!\n";
        }
        else{
            while (1)
            {
                cout<<temp->Task<<"    ";
                if(temp->Status==1)
                {
                    cout<<"Complete\n";
                }
                else
                {
                    cout<<"Pending\n";
                }
                if(temp->next==nullptr)
                {
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
        }
    }
    void Delete_Task() // Function to delete the task 
    {
        string name;
        cout<<"Enter Task Name = ";
        cin>>name;
        bool flag=false;
        if(head->Task==name){
            Node*tmp=head;
            head=head->next;
            delete tmp;
            tmp=nullptr;
            flag=true;
        }
        else{
            Node*temp=head;
            while (temp!=nullptr)
            {
                if(temp->next->Task==name){
                    Node*del= temp->next;
                    temp->next=del->next;
                    delete del;
                    del=nullptr;
                    flag=true;
                    break;
                }
                else{
                    temp=temp->next;
                }
            }
            if(flag)
            {
                cout<<"Task Deleted Succesfully\n";
            }
        }
    }
    void menu(){
    cout<<"***************Menu****************\n"; // Menu
    cout<<"Press 1 to Add Task\n";
    cout<<"Press 2 to Update Task Status\n";
    cout<<"Press 3 to view Task\n";
    cout<<"Press 4 to Delete Task\n";
    cout<<"Press 0 to Exit\n\n";
    }
};
List::List() // Default Constructor of the class
{
    head=nullptr;
    tail=nullptr;
}
List::~List() // Default Destructor of the class
{
    head=nullptr;
    tail=nullptr;
}