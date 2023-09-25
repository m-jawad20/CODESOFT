#include<string> 
#include<iostream>
using namespace std;
struct Node{ // Node Struct With Three Attributes
    string Task; // Task Name
    int Status; // Task Status
    Node *next; // Address to the next Node 
};