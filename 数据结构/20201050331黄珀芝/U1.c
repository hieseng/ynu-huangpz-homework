#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define  N  100

typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

BiTNode* CreateBiTree(int n,TElemType *pre,TElemType *in )//构造二叉链表表示的二叉树，pre为前序序列，in为中序序列
{
    int i=0,n1=0,n2=0,m1=0,m2=0;
    BiTNode *node=NULL;
    TElemType Lpre[N],Rpre[N],Lin[N],Rin[N];

    if(n==0)
        return NULL;

    node=(BiTNode*)malloc(sizeof(BiTNode));

    if(node==NULL)
        return NULL;

    node->data=pre[0];//先序的第一个元素为根结点
    for(i=0; i<n; i++)
    {

        if((i<=n1)&&(in[i]!=pre[0])) Lin[n1++]=in[i];//根据根结点将中序序列分为左子树和右子树
        else if(in[i]!=pre[0]) Rin[n2++]=in[i];
    }

    for(i=1; i<n; i++)
    {
        if(i<(n1+1)) Lpre[m1++]=pre[i];
        else Rpre[m2++]=pre[i];
    }

    node->lchild=CreateBiTree(n1,Lpre,Lin);
    node->rchild=CreateBiTree(n2,Rpre,Rin);
    return node;
}

void PreOrderTraverse(BiTNode *root)//先序遍历
{
    if (root==NULL) return;
    printf("%c ",root->data);
    PreOrderTraverse(root->lchild);
    PreOrderTraverse(root->rchild);
}


void InOrderTraverse(BiTNode*root)//中序遍历//
{
    if (root==NULL) return;
    InOrderTraverse(root->lchild);
    printf("%c ",root->data);
    InOrderTraverse(root->rchild);
}


void PostOrderTraverse(BiTNode *root)//后序遍历//
{

    if (root==NULL) return;
    PostOrderTraverse(root->lchild);
    PostOrderTraverse(root->rchild);
    printf("%c ",root->data);
}

int LeavesCount(BiTree T)//计算二叉树的叶子数目//
{
    if(NULL==T)//树为空
        return 0;
    if(NULL==T->lchild&&NULL==T->rchild)//根节点
        return 1;
    return LeavesCount(T->lchild)+LeavesCount(T->rchild);
}

int TreeDeep(BiTree T)//计算二叉树的深度//
{
    int deep = 0;
    if(T)
    {
        int Leftdeep=TreeDeep(T->lchild);//左子树深度
        int Rightdeep=TreeDeep(T->rchild);//右子树深度
        if(Leftdeep>Rightdeep)
            deep=Leftdeep+1;
        deep=Rightdeep+1;
    }
    return deep;
}


int main()
{
    TElemType preNode[N],inNode[N];

    int n = 0,m=0,choose;
    char ch;
    BiTNode* root=NULL;
    BiTNode* T=NULL;
    while(1)
    {
        system("cls");
        printf("请输入操作对应的数字进行相应操作，输入错误则根据提示重新选择。\n1、根据前序和中序建立二叉树；\n2、按照前序输出；\n3、按照中序输出;\n4、按照后序输出；\n5、计算树的深度; \n6、计算树的叶子结点数; \n7、退出程序。\n");

        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
        {
            printf("请输入先序序列:\n");
            fflush(stdin);
            while((ch = getchar())&&ch!='\n')
                preNode[n++] = ch;
            printf("请输入中序序列:\n");
            fflush(stdin);
            while((ch = getchar())&&ch!='\n')
                inNode[m++] = ch;

            if(m!=n)
            {
                printf("输入有误，程序结束。\n");
                return 0;


            }
            else
            {
                CreateBiTree(n,preNode,inNode);
                root = CreateBiTree(n,preNode,inNode);
                printf("已成功创建二叉树可继续进行后续操作！");
                system("pause");
                break;
            }
        }

        case 2:
        {
            if(root==NULL)
            {
                printf("尚未成功创建树故无法完成指令。");
                return 0;
            }

            printf("\n先序序列:\n");
            PreOrderTraverse(root);
            system("pause");
            break;
        }

        case 3:
        {

            if(root==NULL)
            {
                printf("尚未成功创建树故无法完成指令。");
                return 0;
            }
            printf("\n中序序列:\n");
            InOrderTraverse(root);
            system("pause");
            break;
        }

        case 4:
        {
            if(root==NULL)
            {
                printf("尚未成功创建树故无法完成指令。");
                return 0;
            }
            printf("\n后序序列:\n");
            PostOrderTraverse(root);
            system("pause");
            break;
        }

         case 5:
        {
            if(T==NULL)
            {
                printf("尚未成功创建树故无法完成指令。");
                return 0;
            }

            printf("树的深度为:%d\n",TreeDeep(T));
            system("pause");
            break;
        }

        case 6:
        {

            if(T==NULL)
            {
                printf("尚未成功创建树故无法完成指令。");
                return 0;
            }
            printf("树的叶子结点个数为:%d\n",LeavesCount(T));
            system("pause");
            break;
        }


        case 7:
        {
            exit(0);
        }

        default:
            system("pause");
        }
    }
    return 0;
}
