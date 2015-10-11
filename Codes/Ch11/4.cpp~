#include"bits/stdc++.h"

using namespace std;


int reorder(int*arr,int N,int pos);
int disp_array(int *arr,int N);
int disp_array(int *arr,int N){
    puts("array:");
    for(int i=0;i<N;i++){
        printf("%d ,",arr[i]);
    }
    puts("");
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int reorder(int*arr,int N,int pos){
    int K=N-1-pos;
    if(K%N==0)return 0;
    int g=gcd(K,N);
    for(int i=0;i<g;i++){
        int cur(i+K);
        cur%=N;
        int val_bk(arr[i]);
        while(1){
            int rem=arr[cur];
            arr[cur]=val_bk;
            val_bk=rem;
            if(cur==i)break;
            cur=(cur+K)%N;
        }
    } 
    return 0;
}
bool found_plain(int *arr,int N,int fv){
    for(int i=0;i<N;i++)if(arr[i]==fv)return true;
    return false;
}
bool found(int *arr,int N,int fv,int L,int R){
    while(L<=R){
        int mid=L+(R-L)/2;
        if(arr[mid]==fv)return true;
        else if(arr[mid]<arr[R]&&arr[mid]>arr[L]){
            if(arr[mid]<fv)L=mid+1;
            else R=mid-1;
        }else if(arr[mid]<arr[R]){
            if(arr[mid]<fv){
                if(found(arr,N,fv,mid+1,R))return true;
            }
            if(arr[mid]<arr[L]){
                return found(arr,N,fv,L,mid-1);
            }
            return false;
        }else if(arr[mid]>arr[R]){
            if(arr[mid]>arr[L]&&arr[mid]>fv){
                if(found(arr,N,fv,L,mid-1))return true;
            }
            return found(arr,N,fv,mid+1,R);
        }else{
            if(arr[mid]>arr[L]&&arr[mid]>fv){
                if(found(arr,N,fv,L,mid-1))return true;
                return false;
            }else if(arr[mid]<arr[L]){return found(arr,N,fv,L,mid-1);}
            else {
                return found(arr,N,fv,L,mid-1)||found(arr,N,fv,mid+1,R);
            }
            return false;
        }
    }
    
    return false;
}
bool found(int *arr,int N,int fv){
    int L(0);
    int R(N-1);
    return found(arr,N,fv,L,R);
}
int main(){

    srand(time(NULL));

    int N;
    while(cin>>N){
        int *arr=new int[N]();
        for(int i=0;i<N;i++)arr[i]=rand()%100;
        //input
        sort(arr,arr+N);
        reorder(arr,N,rand()%N); 
        disp_array(arr,N);

        printf("Please Input fv:");

        int fv;
        scanf("%d",&fv);
        printf("find:%d\n",fv);
        if(found(arr,N,fv)){
            puts("Found.");
        }else puts("Not Found.");
    }


return 0;}
