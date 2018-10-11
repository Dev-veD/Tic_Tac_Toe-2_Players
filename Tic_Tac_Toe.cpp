#include <iostream>
#include<cstdlib>
using namespace std;
int x=20,y=20,arr[9]={0},m=0,rtic[3][3]={0},posx,posy;
string tictoe[20][20];
int init(){
for(int i=0;i<y;i++){
    for(int j=0;j<x;j++)
    {
    if(j==x/3||j==2*x/3)\
        tictoe[j][i]="|";
    else if(i==y/3||i==2*y/3)
        tictoe[j][i]="--";
    else
        tictoe[j][i]="  ";
    }
}return 0;
}
int draw(int c){
string d;
if(m%2==0)
    d="0 ";
else
    d="X ";
m++;

               switch (c){

        case 1:
            {
            int midx=x/6,midy=5*y/6;
            tictoe[midx][midy]=d;
                break;
            }
        case 2:
            {

            int midx=x/2,midy=5*y/6;
            tictoe[midx][midy]=d;
            break;
            }
        case 3:
            {
            int midx=5*x/6,midy=5*y/6;
            tictoe[midx][midy]=d;   break;
            }
        case 4:
            {
            int midx=x/6,midy=y/2;
            tictoe[midx][midy]=d;    break;
            }
        case 5:
            {
            int midx=x/2,midy=y/2;
            tictoe[midx][midy]=d;    break;
            }
        case 6:
            {
            int midx=5*x/6,midy=y/2;
            tictoe[midx][midy]=d;break;
            }
        case 7:
            {
            int midx=x/6,midy=y/6;
            tictoe[midx][midy]=d;    break;
            }
        case 8:
            {
            int midx=x/2,midy=y/6;
           tictoe[midx][midy]=d;    break;
            }
        case 9:
            {
            int midx=5*x/6,midy=y/6;
           tictoe[midx][midy]=d;    break;
            }
        default:
            break;
        }
        for(int j=0;j<y;j++){
            for(int i=0;i<x;i++){
                cout<<tictoe[i][j];
            }
            if(j==0){
                    if(d=="X ")
                    d="0";
                    else
                    d="X";
            cout<<"\t\t\tPlayer "<<d<<"'s Turn";}
            cout<<endl;
        }
        return 0;
    }
int n_pos(int c){
switch(c){
case 1:
    posx=0;
    posy=2;
    break;
case 2:
    posx=1;
    posy=2;
    break;
case 3:
    posx=2;
    posy=2;
    break;
case 4:
    posx=0;
    posy=1;
    break;
case 5:
    posx=1;
    posy=1;
    break;
case 6:
    posx=2;
    posy=1;
    break;
case 7:
    posx=0;
    posy=0;
    break;
case 8:
    posx=1;
    posy=0;
    break;
case 9:
    posx=2;
    posy=0;
    break;
}
return 0;
}
bool has_move(){
for(int i=0;i<3;i++)
    {for(int j=0;j<3;j++)
    {
        if(rtic[i][j]==0)
        return true;
    }
    }
return false;
}
int is_over(){
for(int i=0;i<3;i++)
    if(rtic[i][1]==rtic[i][2]&&rtic[i][0]==rtic[i][1])
    {
        int j=rtic[i][1];
        return j;
    }
for(int j=0;j<3;j++){
    if(rtic[1][j]==rtic[2][j]&&rtic[0][j]==rtic[1][j])
    {
        int k=rtic[1][j];
        return k;
    }
}

    if(rtic[0][0]==rtic[1][1]&&rtic[1][1]==rtic[2][2]){
            int a=rtic[0][0];
            return a;
            }
    if(rtic[0][2]==rtic[1][1]&&rtic[1][1]==rtic[2][0]){
        int b=rtic[0][2];
        return b;
    }
return 0;
}
int logic(int val){
    if(has_move()){
        n_pos(val);
        int d;
        if(m%2==1)
            d=-1;
        else
            d=1;
        rtic[posx][posy]=d;
        int b=is_over();

        if(b==1)
            {cout<<"X WON!!"<<endl;
            exit(0);}
        else if(b==-1)
            {cout<<"0 WON!!"<<endl;
            exit(0);}

    }
    else{
        int b=is_over();
        if(b==1)
            cout<<"X WON!!"<<endl;
        else if(b==-1)
            cout<<"0 WON!!"<<endl;
        else
            cout<<"GAME WAS DRAW\n";
        exit(0);
    }
return 0;
}
int info(){
system("cls");
cout<<"\t\t\t\t\tTIC-TAC-TOE \n\n\n\t\t\t\t\tTwo_Players";
cout<<"\n\n\n\t\t\t\t*WARNING DO NOT TRY THIS AT HOME*\n\n";
cout<<"\t\t\t- Your Num-pad Is Your Remote For Playing The Game \n";
cout<<"\t\t\t- Since Num-pad Is Arranged In Same Order As An Tic-Tac-Toe Grid\n\n\n\n\n\n\n\n";
system("pause");
system("cls");
return 0;
}
int main(){
    int y;
    init();
    info();
    draw(0);
    do{
    cin>>y;
    if(has_move())
    if(arr[y]==1)
    {
        cout<<"Invalid Move ";
        continue;
    }
    arr[y]=1;
    system("cls");
    draw(y);
    logic(y);
    }while(y!=-1);
    return 0;
}
