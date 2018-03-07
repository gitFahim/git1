#include<iostream>

using namespace std;
int **a,mr,mc,r,s,row=0,col=0;

void allocateSpace(int r, int c){

    a = new int*[r];
    for(int i=0; i<r; i++){
      a[i] = new int[c];
    }
}

int northWest(int col,int row,int r,int c,int temp,int sum){

int flag=0,supply=0,demand=0,count=0, min=0;
do
 {
    count=0;
    flag=0;
    int i,j;
    for(i=0;i<(r-1);i++)
    {
        for(j=0;j<(c-1);j++)
        {
        if((a[i][c-1]!=0)&&(a[r-1][j]!=0)&&flag==0)
        {
            min=a[i][j];
            row=i;
            col=j;
            flag=1;
            count++;
        }

        }
    }
    supply=a[row][c-1];
    demand=a[r-1][col];
    if(supply>=demand)
    {
    temp=supply-demand;
    a[row][col]=a[row][col]*demand;
    sum=sum+a[row][col];
    a[row][c-1]=temp;
    a[r-1][col]=0;
 }
    if(supply<demand)
    {
    temp=demand-supply;
    a[row][col]=a[row][col]*supply;
    sum=sum+a[row][col];
    a[row][c-1]=0;
    a[r-1][col]=temp;
    }
 }while(count!=0);

    return sum;
}

void addSupplyDemand(int mr, int mc){
    cout<<"Enter Supply"<<endl;
    for(int i=0; i<mr; i++){
        cin>>a[i][mc];
    }
    cout<<"Enter Demand"<<endl;
    for(int j=0; j<mc; j++){
        cin>>a[mr][j];
    }
    cout<<"\n";
}
/*
bool checkSupplyDemand(int mc, int mr){
    int p,q;
    a[mr][mc]=0;
    for(int i=0; i<mr; i++)
    {
       a[mr][mc]+=a[i][mc];
    }
    p = a[mr][mc];

     a[mr][mc]=0;
    for(int j=0; j<mc; j++)
    {
       a[mr][mc]+=a[mr][j];
    }
    q = a[mr][mc];
    if(p==q){
        cout<<"working"<<endl;
    }
}*/
void completeTheMatrix(int mr, int mc, int r, int c){

     a[mr][mc]=0;
    for(int i=0; i<mr; i++)
    {
       a[mr][mc]+=a[i][mc];
    }

    cout<<"*****The Matrix is: *****"<<endl;
    cout<<"\n"<<endl;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void createMatrix(int mc, int mr, int r, int c){
    for(int i=0; i<mc; i++){
        for(int j=0; j<mr; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<mc; i++){
        for(int j=0; j<mr; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

}
void printCost(int sum){
    cout<<"\nTotal Cost is :\n"<<sum<<endl;
}
int main(){
    int i=0,j=0,c=0,t,min=0,temp=0, sum=0;

    cout<<"\n***North-West Corner***\n";
    cout<<"\nEnter the order of the matrix:\n";

    cin>>mr;
    cout<<'X'<<endl;
    cin>>mc;
    cout<<"\n";

    r=mr+1;
    c=mc+1;

    allocateSpace(r,c);

    createMatrix(mc,mr,r,c);

    addSupplyDemand(mr,mc);

    completeTheMatrix(mc,mr,r,c);

    sum=northWest(col,row,r,c,temp,sum);

    printCost(sum);

 return 0;
}
