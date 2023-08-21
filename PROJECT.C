#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main()
{

 int gdriver=DETECT,gmode;
 int midx,midy,n;
 int radius=100;
 int IMS;

 int codforhrx[]={25,43,50,43,25,0,-25,-43,-50,-43,-25,0};
 int codforhry[]={-43,-25,0,25,43,50,43,25,0,-25,-43,-50};

 int codforminsecx[]={0,7,14,21,28,35,41,46,52,56,60,63,66,68,69,70,69,68,66,63,60,56,52,46,41,35,28,21,14,7,0,-7,-14,-21,-28,-35,-41,-46,-52,-56,-60,-63,-66,-68,-69,-70,-69,-68,-66,-63,-60,-56,-52,-46,-41,-35,-28,-21,-14,-7};
 int codforminsecy[]={-70,-69,-68,-66,-63,-60,-56,-52,-46,-41,-35,-28,-21,-14,-7,0,7,14,21,28,35,41,46,52,56,60,63,66,68,69,70,69,68,66,63,60,56,52,46,41,35,28,21,14,7,0,-7,-14,-21,-28,-35,-41,-46,-52,-56,-60,-63,-66,-68,-69};

 time_t rawTime;
 struct tm* currentTime;
 char a[100];
 initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

 midx=getmaxx()/2;
 midy=getmaxy()/2;
 for(n=0;n<20;n++)
 {
 rawTime=time(NULL);
 currentTime=localtime(&rawTime);

//two circles draw from the centr
 setcolor(BLUE);
 circle(midx,midy,radius);
 circle(midx,midy,radius=2);

 setbkcolor(YELLOW);

 outtextxy(midx+0,  midy-98,  "12");
 outtextxy(midx+48,  midy-84, "1");
 outtextxy(midx+82,  midy-46, "2");
 outtextxy(midx+93,  midy+0,  "3");
 outtextxy(midx+80,  midy+43, "4");
 outtextxy(midx+43,  midy+79, "5");
 outtextxy(midx+0,   midy+90, "6");
 outtextxy(midx-44,  midy+80, "7");
 outtextxy(midx-83,  midy+43, "8");
 outtextxy(midx-94,  midy+0,  "9");
 outtextxy(midx-84,  midy-48, "10");
 outtextxy(midx-48,  midy-84, "11");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy(midx-51,midy-200,"ANALOG CLOCK");

 strftime(a,100,"%I",currentTime);
 sscanf(a,"%d",&IMS);
 setcolor(RED);
 setlinestyle(0,0,3);
 line(midx,midy,midx+codforhrx[IMS-1],midy+codforhry[IMS-1]);

 strftime(a,100,"%M",currentTime);
 sscanf(a,"%d",&IMS);
 setcolor(GREEN);
 line(midx,midy,midx+codforminsecx[IMS+1],midy+codforminsecy[IMS+1]);

 strftime(a,100,"%S",currentTime);
 sscanf(a,"%d",&IMS);
 setcolor(BLUE);
 line(midx,midy,midx+codforminsecx[IMS+1],midy+codforminsecy[IMS+1]);
 delay(1000);
 cleardevice();
 }


 getch();
 closegraph();
 return 0;

}