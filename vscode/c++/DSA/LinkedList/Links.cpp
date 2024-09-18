#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
   
    Node(int val){
        data= val;
        next=nullptr;
    }
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head=nullptr;
    }
    void AddAtTail(int val){
        Node* n = new Node(val);
        if(head == nullptr){
            head= n;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=n;
    }
    void Display(){
        Node* temp= head;
        if (temp == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while(temp->next!=nullptr){
            cout<<temp->data<<endl;
            temp= temp->next;
        }
        if(temp->next==nullptr){
            cout<<temp->data<<endl;
        }
    }
};
int main() {
    LinkedList list;
    int total;
    int data;
    cout<<"enter total number of nodes"<<endl;
    cin>>total;
    cout<<"enter data for node"<<endl;
    for(int i=0;i<total;i++){
        cin>>data;
        list.AddAtTail(data);
    }
    list.Display();
    return 0;
}
