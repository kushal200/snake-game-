#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,height=25,width=25;
int x,y,fruitX,fruitY,gameOver,score=0,flag;
int tailX[100], tailY[100],countTail=0;
char ch;
int m,k;

//This is the code for coordiates
void setup(){
	gameOver=0;
	x=height/2;
	y=width/2;
	label1:
	fruitX=rand()%20;
	if (fruitX==0)
	{
		goto label1;
	}
	label2: 
	fruitY=rand()%20;
	if (fruitY==0)
	{
		goto label2;
	}
	
	
}

//This is the function for the movement of the snake
//you can move the snake with key awsd
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				flag=1;
				break;
			case 's':
				flag=2;
				break;
			case 'd':
				flag=3;
				break;
			case 'w':
				flag=4;
				break;
			case 'x':
				gameOver=1;	
		}
		
	}
}

//this is the code for the logic of the movement of the snake

void makeLogic()
{
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X, prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	
	for(i=1;i<countTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	
	
	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y++;
			break;
		case 4:
			x--;
			break;
		default:
			break;
	}
	if(x<0||x>height||y<0||y>width)
	{
		gameOver=1;
		for(i=0;i<countTail;i++)
		{
			if(x==tailX[i] && y==tailY[i])
			{
				gameOver=1;
			}
		}
	}
	if(x==fruitX && y==fruitY)
	{
		label3:
	fruitX=rand()%20;
	if (fruitX==0)
	{
		goto label3;
	}
	label4:
	fruitY=rand()%20;
	if (fruitY==0)
	{
		goto label4;
		
	}
 		score+=10;
		countTail++;
	}
}


//This is the code for the shape
void shape()
{
	system("cls");
	for(i=0; i<width; i++)
	{
		for(j=0; j<height; j++)
		{
			if(i==0||i==width-1||j==0||j==height-1)
			{
				printf("*");
			}
			else
			{
				if(i==x && j==y)
				{
					printf("O");
				}
				else if (i==fruitX && j==fruitY)
				{
					printf("F");
				}
				else
				{
					int ch=0;
					for(k=0;k<countTail;k++)
					{
						if(i==tailX[k] && j==tailY[k])
						{
							printf("*");
							ch=1;
						}
					}
					if(ch==0)
					printf(" ");
				}
				
			}
			
		}
			printf("\n");
	}
	printf("SCORE=%d",score);
	printf("\n");
}
int main(){
	label5:
	setup();
	
	while(!gameOver)
	{
		shape();
		input();
		makeLogic();
	}
		printf("GAME OVER!!!");
	while(gameOver)
	{
		printf("\nPress Y or y to continue: ");
		scanf("%c",&ch);
	if(ch=='y' || ch=='Y')
		{
		goto label5;
		}
	}
	for(k=1;k<1000;k++)
	{
	
	}
	for(k=1;k<1000;k++)
	{
	}
	for(k=1;k<1000;k++)
	{
	}
	for(k=1;k<1000;k++)
	{
	}
		
}
