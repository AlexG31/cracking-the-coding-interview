#include"bits/stdc++.h"

using namespace std;

int getKth(int k){
    if(k<2)return 1;
    const int MaxN=100000;
    int arr[MaxN];
    int p3(0),p5(0),p7(0);
    int top(0);
    arr[top++]=1;
    while(top<k){
        int v3=3*arr[p3];
        int v5=5*arr[p5];
        int v7=7*arr[p7];
        int mv=min(v3,min(v5,v7));
       if(mv==v3){
         p3++;
       }
       if(mv==v5){
        p5++;
       }
       else {
        p7++;
       } 
       arr[top++]=mv;
    }

    return arr[top-1];
}
int main(){

    int k;
    while(cin>>k){
        int Kth=getKth(k);
        printf("K=%d,number is %d\n",k,Kth);
    }


return 0;}
