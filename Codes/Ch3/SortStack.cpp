#include"bits/stdc++.h"

using namespace std;

class Stack{
    int arr[100];
    int stk_top;
public:Stack():stk_top(0){}
       void push(int v){
        arr[stk_top++]=v;
       }
       void pop(){stk_top--;}
       bool empty()const{
        return stk_top==0;
       }
       int top(){if(stk_top==0)return 0;return arr[stk_top-1];}
};

void stack_input(Stack&stk){
    puts("Please input Stack:(end with -1):");
    int v;
    while(cin>>v){
        if(v==-1)break;
        stk.push(v);
    }
    return ;
}
void disp_stack(Stack stk){
    
    while(stk.empty()==false){
        printf("%d ,",stk.top());
        stk.pop();
    }
    puts("");
}
void sort_stack(Stack&stk){
    Stack rstk;
    int rem(0);
    while(stk.empty()==false){
        rem=stk.top();
        stk.pop();
        //insert to right position of rstk
        int cnt(0);
        while(rstk.empty()==false){
            if(rstk.top()>rem){
                
                cnt++;
                stk.push(rstk.top());
                rstk.pop();

                
            }else{
                break;
            }
        }
        //insert
        rstk.push(rem);
        for(;cnt>0;cnt--){
            rstk.push(stk.top());
            stk.pop();
        }
        
    }
    //insert back
    while(rstk.empty()==false){
        stk.push(rstk.top());
        rstk.pop();

    }

    return ;
}
int main(){


    Stack stk;
    stack_input(stk);

    disp_stack(stk);

    sort_stack(stk);

    disp_stack(stk);



return 0;}
