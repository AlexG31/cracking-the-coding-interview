#include"bits/stdc++.h"

using namespace std;


int rotate_mat(int **mat,int x,int y,int N){
    if(N<=1)return 0;
    int val(0),rem(0);
    for(int i=0;i<N-1;i++){
        //for rotate outer line

        val=mat[x][y+i];
        rem=mat[x+i][y+N-1];
        mat[x+i][y+N-1]=val;
        val=rem;
        rem=mat[x+N-1][y+N-1-i];
        mat[x+N-1][y+N-1-i]=val;
        val=rem;
        rem=mat[x+N-1-i][y];
        mat[x+N-1-i][y]=val;
        val=rem;
        mat[x][y+i]=val;
    }
    rotate_mat(mat,x+1,y+1,N-2);
    return 0;
}
int rotate_mat(int **mat,int N){
    //inputs:matrix & size N

    rotate_mat(mat,0,0,N);

    return 0;
}
int disp(int **mat,int N){
    puts("Mat:");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d , ",mat[i][j]);
        }
        puts("");
    }
    puts("");

    return 0;
}
bool random_test(){

    int **mat,**cp_mat;

    bool ret(true);
    int N=rand()%99;
    N++;
    //alloc matrix
    //
    mat=new int*[N];
    cp_mat=new int*[N];
    for(int i=0;i<N;i++){
        mat[i]=new int[N]();
        cp_mat[i]=new int[N]();
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mat[i][j]=rand()%1000;
            cp_mat[i][j]=mat[i][j];
        }
    }

    for(int i=0;i<4;i++){
        rotate_mat(mat,N);
    }
    //check
    for(int i=0;i<N&&ret;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j]!=cp_mat[i][j]){
                ret=false;
                break;
            }
        }
    }
    
    //free memory
    for(int i=0;i<N;i++){
        delete []mat[i];
        delete []cp_mat[i];
    }
    delete []mat;
    delete []cp_mat;
    return ret;
}
int main(){

    freopen("RotateMat.in","r",stdin);


    //Random Test
    for(int i=0;i<1000;i++){
        if(random_test()==false){
            puts("error!");
        }
    }

    const int MaxN=100;

    int **mat;
    mat=new int*[MaxN];
    for(int i=0;i<MaxN;i++){mat[i]=new int[MaxN]();}
    int N=0;
    while(cin>>N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        disp(mat,N);
        rotate_mat(mat,N);
        puts("After Rotation:");
        disp(mat,N);
    }
    
    //free memory
    for(int i=0;i<MaxN;i++){delete []mat[i];}
    delete []mat;


return 0;}
