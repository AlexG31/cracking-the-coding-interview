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

int get_listlen(ListNode*a){
    int len(0);
    while(a!=NULL){a=a->next;len++;}
    return len;
}

ListNode* add_lists(ListNode*a,ListNode*b,int la,int lb,int level,int &rr){
    int rn(0);
    int val(0);
    if(la>=level){
        val+=a->val;
        a=a->next;
    }
    if(lb>=level){
        val+=b->val;
        b=b->next;
    }
    ListNode*res_next(NULL);
    if(level>1){
        res_next=add_lists(a,b,la,lb,level-1,rn);
    }
    val+=rn;

    rr=val/10;
    val%=10;
    ListNode*res=new ListNode(val);
    res->next=res_next;

    return res;
}

ListNode* add_lists(ListNode*a,ListNode*b){
    //
    if(a==NULL&&b==NULL)return NULL;

    int la(get_listlen(a));
    int lb(get_listlen(b));
    int rr(0);
    ListNode*res=add_lists(a,b,la,lb,max(la,lb),rr);

    if(rr>0){
        ListNode*head=new ListNode(rr);
        head->next=res;
        res=head;
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
