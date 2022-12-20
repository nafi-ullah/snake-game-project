#include<iostream>
#include<graphics.h>
#include <dos.h>
#include <conio.h>

using namespace std;


int main()
{
	int height,width;
	height=width=500;

  	initwindow(height,width,"Snake");

  	int key = 80,before;
  	bool menu = true,game=false;

  	while(menu)
  	{
		switch(key)
		{
			case 80:
			  	rectangle((height/2)-100,(width/2)-100,350,200);
			  	rectangle((height/2)-100,(width/2),350,300);
			  	rectangle(0,(width/2)+100,460,450);
			   	outtextxy((height/2)-80, 170, "Press Enter to START");
			   	outtextxy(3, 370, "Submitted by: Nafi Ullah Shafin (Reg:2020831004)");
			   	outtextxy(3, 420, "Submitted To: Mohammed Raihan Ullah (Lecturer,IICT)");
				outtextxy((height/2)-25, 270, "EXIT");
				setlinestyle(1, 0, 2);
				setcolor(RED);
				rectangle((height/2)-100,(width/2)-100,350,200);
				setcolor(GREEN);
				rectangle(0,(width/2)+100,460,450);
				break;
			case 72:
			  	rectangle((height/2)-100,(width/2)-100,350,200);
			  	rectangle((height/2)-100,(width/2),350,300);
			   	outtextxy((height/2)-80, 170, "Press enter to START");
				outtextxy((height/2)-25, 270, "EXIT");
			    setlinestyle(1, 0, 2);
				setcolor(RED);
				rectangle((height/2)-100,(width/2),350,300);
				break;
			case 13:
				if(before==80)
				{
					menu=false;
					game=true;
				}
				else
				{
					menu=false;
					closegraph();
				}
				break;
		}
		before=key;
		getch();
		key = getch();
		cout<<key;
		setcolor(WHITE);
		cleardevice();
	}

  	int w,x,y,z,t,i=0,coun=0;

	x=100;	y=200;
	w=100;	z=100;

	int arrx[100] ;
	int arry[100];
	arrx[i]=x;
	arry[i]=y;

	int lastx,lasty;

	while(game)
	{
	      setfillstyle(XHATCH_FILL,BLUE);
        bar(0,0,500,500);
        setfillstyle(1,RED);
        bar(0,0,500,20);
        bar(0,0,20,500);
        bar(0,500,500,480);
        bar(480,20,500,500);
//coun=0;
		if(i==-1)
		{
		    setcolor(RED);
			outtextxy((height/2)-25, 270, "GAME OVER");
			//outtextxy((height/2)-25, 370, coun);
			//cout<<coun<<endl;
			char appk[5];
//				settextjustify(CENTER_TEXT, CENTER_TEXT);
//                settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

                sprintf(appk, "Score: %d", coun);
                outtextxy((height/2)-20, 300, appk);
			//coun=0;
			getch();
			if(getch()==13)
			{
				i=0;
				arrx[i]=x;
				arry[i]=y;
			}

		}
		else
		{

			if(arrx[0]==w&&arry[0]==z)
			{
				w=(30+rand()%440);
				z=(30+rand()%440);
				i++;
				coun++;
				cout<<endl<<"Alhumdulillah"<<endl;

				arrx[i]=lastx;
				arry[i]=lasty;
			}
			w=w/20;
			w=w*20;
			z=z/20;
			z=z*20;
			bar(w,z,w+20,z+20);

			for(int j=i;j>0;j--)
			{
			    //cout<<endl<<"I am hungry"<<endl;
				arrx[j]=arrx[j-1];
				arry[j]=arry[j-1];
				//coun++;
			}

			lastx=arrx[i];
			lasty=arry[i];

			if(GetAsyncKeyState(VK_UP)&&t!=1)
			{
				t=0;
			}
			else if(GetAsyncKeyState(VK_DOWN)&&t!=0)
			{
				t=1;
			}
			else if(GetAsyncKeyState(VK_RIGHT)&&t!=3)
			{
				t=2;
			}
			else if(GetAsyncKeyState(VK_LEFT)&&t!=2)
			{
				t=3;
			}

			switch(t)
			{
				case 0:arry[0]-=20;break;
				case 1:arry[0]+=20;break;
				case 2:arrx[0]+=20;break;
				case 3:arrx[0]-=20;break;
				default:break;
			}


			for(int j=0;j<=i;j++)
			{
				rectangle(arrx[j],arry[j],arrx[j]+20,arry[j]+20);
				//cout<<endl<<"I am hungry"<<endl;
				if(arrx[0]==arrx[j]&&arry[0]==arry[j]&&j!=0 || arrx[0]>470 || arrx[0]<20  || arry[0]>470 || arry[0]<20)
				{

			        i=-1;

				}
			}


			delay(100);
			cleardevice();
		}
	}
	getch();
}

