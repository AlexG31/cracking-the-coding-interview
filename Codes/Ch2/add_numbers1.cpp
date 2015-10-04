#include"bits/stdc++.h"

using namespace std;

class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int v):val(v),next(NULL){

    }
    
};

void disp(ListNode*a){
   if(a==NULL)puts("NULL");
   while(a!=NULL){
       printf("%d->",a->val);
       a=a->next;

   }
   puts("");
}

ListNode* add_lists(ListNode*a,ListNode*b){
    //
    if(a==NULL&&b==NULL)return NULL;

    int rr(0);
    ListNode*ca(a),*cb(b);
    ListNode*res=new ListNode(0);
    ListNode*cr(res);

    while(ca!=NULL||cb!=NULL){
       int va(0);
       if(ca!=NULL)va=ca->val;
       int vb(0);
       if(cb!=NULL)vb=cb->val;

       int v=rr+va+vb;

       cr->val=v%10;
       rr=v/10;
       if(ca!=NULL)
       ca=ca->next;
       if(cb!=NULL)
       cb=cb->next;
       if(ca!=NULL||cb!=NULL){
          cr->next=new ListNode(0);
          cr=cr->next;
       }
    }
    if(rr>0){
       cr->next=new ListNode(rr);  
    }
    return res;
}

void input_lists(ListNode*&a){
     //0-9
    puts("Please input list :");
    int v;
    ListNode*cur(NULL);
    while(cin>>v){
       if(v<0||v>=10)break;
       if(cur==NULL)cur=new ListNode(v),a=cur;
       else{
          cur->next=new ListNode(v);
          cur=cur->next;
       }
    }
}
int main(){

    
    ListNode*a(NULL),*b(NULL);

    input_lists(a);
    input_lists(b);
    disp(a);
    disp(b);
    
    ListNode*c=add_lists(a,b);
    disp(c);

    return 0;
}
