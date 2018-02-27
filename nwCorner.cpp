#include<iostream>

using namespace std;
int main(){
    int i=0,r=0,j=0,c=0,t,s,min,row=0,col=0,temp=0;
    int **a,flag=0,supply=0,demand=0,sum=0,count=0,mr=0,mc=0;
    cout<<"\nNorth-West Corner\n";
    cout<<"\nEnter the order of the matrix:\n";
    cin>>mr;
    cout<<'X'<<endl;
    cin>>mc;
    cout<<"\n";
    
    r=mr+1;
    c=mc+1;
    a = new int*[r];
    for(i=0; i<r; i++){
      a[i] = new int[c];
    }
    for(i=0; i<mc; i++){
        for(j=0; j<mr; j++){
            cin>>a[i][j];
        }
    }
    for(i=0; i<mc; i++){
        for(j=0; j<mr; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
   
    cout<<"Enter Supply"<<endl;
    for(i=0; i<mr; i++){
        cin>>a[i][mc];
    }    
    cout<<"Enter Demand"<<endl;
    for(j=0; j<mc; j++){
        cin>>a[mr][j];
    }
    cout<<"\n";

    a[mr][mc]=0;
    for(i=0; i<mr; i++)
    {
       a[mr][mc]+=a[i][mc];
    }
       
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

do
 {
  count=0;
  flag=0;

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
 
 cout<<"\nTotal Cost is :\n"<<sum<<endl;
 return 0;
}

