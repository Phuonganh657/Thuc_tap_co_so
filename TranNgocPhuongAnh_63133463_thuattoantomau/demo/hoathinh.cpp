#include <graphics.h>
#include <bits/stdc++.h>
int x=439,y=125, x1=440, yy=125, ll;
using namespace std;
void Traitim()
{
int love[22]={x,y,x+22,y-15,x+44,y-27,x+88,y-12,x+102,y,x+117,y+22,x+125,y+44,x+125,y+47,x+120,y+66,x+105,y+88,x,y+220};
int love2[22]={x1,yy,x1-22,yy-15,x1-44,yy-27,x1-88,yy-12,x1-102,yy,x1-117,yy+22,x1-125,yy+44,x1-125,yy+47,x1-120,yy+66,x1-105,yy+88,x1,yy+220};
    setcolor(0); setfillstyle(1,0);
    fillpoly(11,love);
    fillpoly(11,love2);
    if(ll==0){x++; x1--;} else if(ll==1){x--; x1++;}
int ily[22]={x,y,x+22,y-15,x+44,y-27,x+88,y-12,x+102,y,x+117,y+22,x+125,y+44,x+125,y+47,x+120,y+66,x+105,y+88,x,y+220};
int ily2[22]={x1,yy,x1-22,yy-15,x1-44,yy-27,x1-88,yy-12,x1-102,yy,x1-117,yy+22,x1-125,yy+44,x1-125,yy+47,x1-120,yy+66,x1-105,yy+88,x1,yy+220};
    if(x==440)  {   setcolor(15); setfillstyle(1,15);}
    else{setcolor(12); setfillstyle(1,12);}
    fillpoly(11,ily);
    fillpoly(11,ily2);
}
void Floodfill(int x, int y)
{
    int mht=getpixel(x,y);
    if(mht==15)
    {
        putpixel(x,y,12);
        for(int i=0;i<200000;i++);
        Floodfill(x-1, y);
        Floodfill(x+1, y);
        Floodfill(x, y-1);
        Floodfill(x, y+1);
    }
}

int main()
{
    initwindow(890,500);
    setcolor(9); settextstyle(6,0,1); 
    Traitim();
    Floodfill(440,300);
    delay(5000);
    
    
getch();
}

