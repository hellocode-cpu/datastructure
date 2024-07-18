#include <bits/stdc++.h>
#include<vector>
using namespace std;
struct link
{
    int data;
    struct link* next;
    
};
void display(struct  link* first)
{
    while(first!=NULL)
    {
        cout<<first->data;
        first=first->next;
    }
    cout<<"\n";
}


struct link* reverse(struct  link* head)
{
    struct link *temp=NULL;
    struct link *first=head;
    
    while(first!=NULL)
    {
        struct link * p=first->next;
        first->next=temp;
        temp=first;
        first=p;
    }
    return temp;

}
void middle(struct  link* head)
{
    vector<int> v;
    while(head!=NULL)
    {
        
        v.push_back(head->data);
        head=head->next;
    }
    int n=v.size()/2;
    cout<< v[n]<<"\n";
}


struct link* remove_occurence(struct  link* head,int key)
{
    struct  link* temp;
    struct  link* first=head;
    temp=(link*)malloc(sizeof(link));
    temp->data=0;
    temp->next=first;
    first=temp;
    
    while(first!=NULL && first->next!=NULL)
    {
        if(first->next->data==key)
        {
            first->next=first->next->next;
        }
        else
        {
        first=first->next;
        }
    }
    head=temp->next;
    
    return head;

}

struct link* input()
{
    struct  link* first,*list,*pre;
    int n=0,ch;
    do
    {
        list=(link*) malloc(sizeof(link*));
      
        if(n==0)
        {
            cout<<"Enter data:";
            cin>>list->data;
            list->next=NULL;
            first=list;
            pre=list;
            n++;
          
        }
        else{
             cout<<"Enter data:";
            cin>>list->data;
            list->next=NULL;
            pre->next=list;
            pre=list;

        }
        cout<<"Enter 1 for more input and 0 to exit:";
        cin>>ch;
    } while (ch!=0);
    return first;
}

int main()
{
    int n;
    struct  link* first;
    
  
    while(n!=0)
    {
        cout<<"enter your choice:\n"
            <<"0.exit\n"
            <<"1.create\n"
            <<"2.show\n"
            <<"3.reverse:\n"
            <<"4.find middle:\n"
            <<"5.remove_occurence:";
    cin>>n;
    if(n==1)
    {
        first=input();

    }
    else if(n==2)
    {
        display(first);
    }
    else if(n==3)
    {
        first=reverse(first);
    }
    else if(n==4)
    {
        middle(first);
    }
    else if(n==5)
    {
        int key;
        cout<<"Enter a key:";
        cin>>key;
        first=remove_occurence(first,key);
    }
    }


}
