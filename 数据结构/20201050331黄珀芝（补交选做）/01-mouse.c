#include <stdio.h>
#include <stdlib.h>
#define EAST  MAZE[x][y+1]  /*���嶫�������λ��*/
#define WEST  MAZE[x][y-1]  /*�������������λ��*/
#define SOUTH MAZE[x+1][y]	/*�����Ϸ������λ��*/
#define NORTH MAZE[x-1][y]	/*���山�������λ��*/
#define ExitX 8			/*������ڵ�X�����ڵ�8��*/
#define ExitY 10			/*������ڵ�Y�����ڵ�10��*/
struct list
{
	int x,y;//·������x��y
	struct list* next;//ָ����һ���
};
typedef struct list node;
typedef node* link;
 //�ö�ά�����ʾ�Թ�����+1ʱ��ʾ�þ��������Ͷ�ά�����Ӧ������������[0][*]��[*][0]������Ԫ�أ���+2ʱ������Ϊ������Թ���Χ��Χǽ
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
				rate =new Random().nextInt(10)+1; //�������1-10������
				if(rate<=3)//30%���������ϰ�
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
 
	//���֤��ںͳ�������
	maze[1][1]=2
maze[rowSize][colSize]= 3��
}

link push(link stack,int x,int y)
{
	link newnode;//�½��ָ��
	newnode = (link)malloc(sizeof(node));//�������ڴ�
	if(!newnode)
	{
		printf("Error!�ڴ����ʧ��!\n");
		return NULL;
	}
	newnode->x=x;//����·������x
	newnode->y=y;//����·������y
	newnode->next=stack;//�½��ָ��ԭ��ʼ
	stack=newnode;//�½���Ϊջ��ʼ
    return stack;
}
link pop(link stack,int* x,int* y)//ջ���ݵ�ȡ��
{
	link top;//ָ��ջ����
	if(stack!=NULL)
	{
		top=stack;
		stack=stack->next;//ջָ��ָ���½��
		*x=top->x;//ȡ��·������x
		*y=top->y;//ȡ��·������y
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
	x=1;		/*��ڵ�X����*/
	y=1;    /*��ڵ�Y����*/
	printf("[�Թ��ĵ�ģ��ͼ(1��ʾǽ,2��ʾ���,3��ʾ����]\n"); /*��ӡ���Թ���·��ͼ*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	while(x<=ExitX&&y<=ExitY)//�Ƿ����Թ�����
	{
		MAZE[x][y]=6;//��ʾ�߹���·
		if(NORTH==0)//������
		{
			x -= 1;
			path=push(path,x,y);//����·��
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
		else if(chkExit(x,y,ExitX,ExitY)==1) /*����Ƿ��ߵ�������*/
			break;
		else
		{
			MAZE[x][y]=2;
			path=pop(path,&x,&y);
		}
	}
	printf("---------------------------\n");
	printf("[6��ʾ�����߹���·��]\n"); /*��ӡ�����������Թ����·��ͼ*/
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
