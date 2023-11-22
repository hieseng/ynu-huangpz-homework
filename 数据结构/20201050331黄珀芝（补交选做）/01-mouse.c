#include <stdio.h>
#include <stdlib.h>
#define EAST  MAZE[x][y+1]  /*定义东方的相对位置*/
#define WEST  MAZE[x][y-1]  /*定义西方的相对位置*/
#define SOUTH MAZE[x+1][y]	/*定义南方的相对位置*/
#define NORTH MAZE[x-1][y]	/*定义北方的相对位置*/
#define ExitX 8			/*定义出口的X坐标在第8行*/
#define ExitY 10			/*定义出口的Y坐标在第10列*/
struct list
{
	int x,y;//路径坐标x、y
	struct list* next;//指向下一结点
};
typedef struct list node;
typedef node* link;
 //用二维数组表示迷宫，当+1时表示让矩阵索引和二维数组对应，弃用了形如[0][*]和[*][0]的数组元素；当+2时，则是为了添加迷宫外围的围墙
        int[][] maze = new int[rowSize+2][colSize+2];
		
	int i,j,rate;
	
	for(i =0;i<rowSize+2;i++)
	{
		for(j =0;j<colSize+2;j++)
		{   
				 
			if((i==0)||(i==rowSize+1)||(j==0)||(j==colSize+1))
			{
				maze[i][j]= 1;
			}
			else
			{
				rate =new Random().nextInt(10)+1; //随机生成1-10的整数
				if(rate<=3)//30%几率设置障碍
				{
				      maze[i][j] = 1;
				}
				else 
				{
				      maze[i][j]= 0;
				}
			}	
		     }
		}
 
	//最后保证入口和出口能走
	maze[1][1]=2
maze[rowSize][colSize]= 3；
}

link push(link stack,int x,int y)
{
	link newnode;//新结点指针
	newnode = (link)malloc(sizeof(node));//分配结点内存
	if(!newnode)
	{
		printf("Error!内存分配失败!\n");
		return NULL;
	}
	newnode->x=x;//存入路径坐标x
	newnode->y=y;//存入路径坐标y
	newnode->next=stack;//新结点指向原开始
	stack=newnode;//新结点成为栈开始
    return stack;
}
link pop(link stack,int* x,int* y)//栈数据的取出
{
	link top;//指向栈顶端
	if(stack!=NULL)
	{
		top=stack;
		stack=stack->next;//栈指针指向下结点
		*x=top->x;//取出路径坐标x
		*y=top->y;//取出路径坐标y
		free(top);
		return stack;
	}
	else
		*x=-1;
	return stack;
}
int chkExit(int x,int y,int ex,int ey)
{
	if(x==ex&&y==ey)
	{
		if(NORTH==1||SOUTH==1||WEST==1||EAST==2)
			return 1;
		if(NORTH==1||SOUTH==1||WEST==2||EAST==1)
			return 1;
		if(NORTH==1||SOUTH==2||WEST==1||EAST==1)
			return 1;
		if(NORTH==2||SOUTH==1||WEST==1||EAST==1)
			return 1;
    }
	return 0;
}

int main()
{
	int i,j,x,y;
	link path = NULL;
	x=1;		/*入口的X坐标*/
	y=1;    /*入口的Y坐标*/
	printf("[迷宫的地模拟图(1表示墙,2表示入口,3表示出口]\n"); /*打印出迷宫的路径图*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	while(x<=ExitX&&y<=ExitY)//是否是迷宫出口
	{
		MAZE[x][y]=6;//标示走过的路
		if(NORTH==0)//往上走
		{
			x -= 1;
			path=push(path,x,y);//存入路径
		}
		else if(SOUTH==0)
		{
			x+=1;
			path=push(path,x,y);
		}
		else if(SOUTH==0)
		{
			y-=1;
			path=push(path,x,y);
		}
		else if(EAST==0)
		{
			y+=1;
			path=push(path,x,y);
		}
		else if(chkExit(x,y,ExitX,ExitY)==1) /*检查是否走到出口了*/
			break;
		else
		{
			MAZE[x][y]=2;
			path=pop(path,&x,&y);
		}
	}
	printf("---------------------------\n");
	printf("[6表示老鼠走过的路线]\n"); /*打印出老鼠走完迷宫后的路径图*/
	printf("---------------------------\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
