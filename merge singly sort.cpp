//sort merge list
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
struct Node
{
    Node* next;
    int data;
};
class LinkedList
{
   
 public:
  int length;
	Node* head ;
    Node* tail ;
	LinkedList()
	    {
	    head = NULL;
        tail = NULL;
        length = 0;
		}
    void Insert(int input){
        Node* newNode = new Node;
        newNode->data = input;
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
		else{
            tail->next = newNode;//passing adress of next one 
            tail = tail->next;//moving tail itself forwrd
           }
        length++;
    }
	void Merge(LinkedList *one, LinkedList *two, LinkedList *three){
		if(one->head==NULL&&two->head!=NULL)
		{
			selectionSort(two);
			three->head=two->head;
			cout<<"Merged Sorted  =  ";
			return;
		}
		if(one->head!=NULL&&two->head==NULL)
		{
			selectionSort(one);
			three->head=one->head;
			cout<<"Merged Sorted  =  ";
			return;
		}
		if(one->head!=NULL&&two->head!=NULL)
		{
		three->head=one->head;
		Node*temp2=three->head;
		while(temp2->next!=NULL){
			temp2=temp2->next;
		}
		temp2->next=two->head;
		cout<<"Merged unSorted=  ";
	    three->Display(three);
        selectionSort(three);
	    cout<<"Merged Sorted  =  ";
		}
	    else 
	    cout<<"Empty :-0"<<endl;
		
	
	
	 }
  void selectionSort(LinkedList *obj){   
    	int swap;
    	for(Node*temp=obj->head;temp!=NULL;temp=temp->next)
    	{
		   for(Node*temp2=temp->next;temp2!=NULL;temp2=temp2->next)
		 {
		if(temp->data>temp2->data)
		   {
			 swap = temp->data; 
             temp->data = temp2->data; 
             temp2->data = swap;
           }
		 }
	    }
    }
    bool checkEmpitness()
    {
        if (head == NULL)
        {
            cout << "Empty List :-)" << endl;
        return true;
		}
		return false;
    }
 
    
	void Display(LinkedList *obj)
	{ // if(checkEmpitness())
		{	
			Node* temp = obj->head;
			while (temp->next != NULL)
			{
				cout << temp->data <<" ";
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
	}
  
};
int main()
{ LinkedList obj;
    LinkedList *one= new LinkedList();
	LinkedList *two = new LinkedList();	
	LinkedList *three = new LinkedList();
	int info,size1=0;
	cout<<"Enter the total number of elements you want to enter in the list 1 "<<endl;
	cin>>size1;
	for(int i=0;i<size1;i++)
	{cout<<"Enter Data to insert in "<<i+1<<" number = ";cin>>info;
		one->Insert(info);
	}
	cout<<"Enter the total number of elements you want to enter in the list 2 "<<endl;
	cin>>size1;
	for(int i=0;i<size1;i++)
	{cout<<"Enter Data to insert in "<<i+1<<" number = ";cin>>info;
		two->Insert(info);
	}
	three->Merge(one,two,three);
	
	three->Display(three);
return 0;
}

