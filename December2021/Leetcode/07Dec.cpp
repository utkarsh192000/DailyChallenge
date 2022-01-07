#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(){
        this->val=0;
        this->next=NULL;
    }

    Node(int val){
        this->val=val;
        this->next=NULL;
    }

};




int convertBinToDec(Node *head){
    if(head==NULL){
        return 0;
    }
    int ans=0;
    Node *temp=head;
    while(temp!=NULL){
        ans=ans*2;
        ans+=temp->val;
        temp=temp->next;
    }
    return ans;
}








void printList(Node *head){
    Node *p=head;
    while(p!=NULL){
        cout<<p->val<<"->";
        p=p->next;
    }
}

int main(){

    Node *head=new Node(1);
    head->next=new Node(1);
    head->next->next=new Node(0);
    head->next->next->next=new Node(1);

    printList(head);
    cout<<endl;
    // cout<<convertBinToDec(head)<<endl;
    int ans=convertBinToDec(head);
    cout<<ans<<endl;
    


    return 0;
}