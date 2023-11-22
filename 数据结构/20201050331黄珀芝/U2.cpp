#include<iostream>
using namespace std;
#define MAXLEN 20				        //最大长度
typedef char DATA;				        //定义元素类型
struct 	CBTType			                       //定义二叉树结点类型
{
	DATA data;					//元素数据
	CBTType * left;					//左子树结点指针
	CBTType * right;				//右子树结点指针
};
/*********************初始化二叉树***********************/
CBTType * InitTree()
{
	CBTType * node;
	if(node = new CBTType)		                 //申请内存
	{
		cout<<"请先输入一个根节点数据："<<endl;
		cin>>node->data;
		node->left=NULL;
		node->right=NULL;
		if(node!=NULL)			         //如果二叉树结点不为空
		{
			return node;
		} else
		{
			return NULL;
		}
	}
	return NULL;
}
/***********************查找结点*************************/
CBTType *TreeFindNode(CBTType *treeNode,DATA data)
{
	CBTType *ptr;
	if(treeNode==NULL)
	{
		return NULL;
	}else
	{
		if(treeNode->data==data)
		{
			return treeNode;
		}
		else								//分别向左右子树查找
		{
			if(ptr=TreeFindNode(treeNode->left,data))		//左子树递归查找
			{
				return ptr;
			}
			else if(ptr=TreeFindNode(treeNode->right,data))	        //右子树递归查找
			{
				return ptr;
			}
			else
			{
				return NULL;
			}
		}
	}
}
/**********************添加结点*************************/
void AddTreeNode(CBTType *treeNode)
{
	CBTType *pnode,*parent;
	DATA data;
	char menusel;
	if(pnode=new CBTType)					         //分配内存
	{
		cout<<"输入二叉树结点数据："<<endl;
		cin>>pnode->data;
		pnode->left=NULL;					//设置左子树为空
		pnode->right=NULL;					//设置左子树为空
		cout<<"输入该结点的父结点数据"<<endl;
		cin>>data;
		parent=TreeFindNode(treeNode,data);                     //查找父结点，获得结点指针
		if(!parent)
		{
			cout<<"没有找到父结点"<<endl;
			delete pnode;
			return ;
		}
		cout<<"1.添加该结点到左子树；2.添加该结点到右子树。请输入操作对应的数字。"<<endl;
		do
		{
			cin>>menusel;
			if(menusel=='1'||menusel=='2')
			{
				switch(menusel)
				{
					case '1':					//添加结点到左子树
						if(parent->left)	                //左子树不为空
						{
							cout<<"左子树结点不为空"<<endl;
						}
						else
						{
							parent->left=pnode;
							cout<<"数据添加成功！"<<endl;
						}
						break;
					case '2':					//添加结点到右子树
						if(parent->right)	                //右子树不为空
						{
							cout<<"右子树结点不为空"<<endl;
						}
						else
						{
							parent->right=pnode;
							cout<<"数据添加成功！"<<endl;
						}
						break;
					default:
						cout<<"子节点选择error!"<<endl;
						break;
				}
			}
		}while(menusel!='1'&&menusel!='2');
	}
}
/***********************计算二叉树的深度********************************/
int TreeDepth(CBTType *treeNode)
{
	int depleft,depright;
	if(treeNode==NULL)
	{
		return 0;					//结点为空的时候，深度为0
	}
	else
	{
		depleft=TreeDepth(treeNode->left);		//左子树深度（递归调用）
		depright=TreeDepth(treeNode->right);	       //右子树深度（递归调用）
		if(depleft)
		{
			return ++depleft;
		}
		else
		{
			return ++depright;
		}
	}
}
/*************************显示结点数据*********************************/
void ShowNodeData(CBTType *treeNode)
{
	cout<<treeNode->data<<"\t";					//直接输出结点数据
}
/***********************清空二叉树************************************/
void ClearTree(CBTType *treeNode)
{
	if(treeNode)							//判断当前树不为空
	{
		ClearTree(treeNode->left);				//清空左子树
		ClearTree(treeNode->right);				//清空右子树
		delete treeNode;					//释放当前结点所占用的内存
	}
}
/**************************按层遍历算法*********************************/
void LevelTree(CBTType *treeNode)
{
	CBTType *p;
	CBTType *q[MAXLEN];						//定义一个队列
	int head=0,tail=0;
	if(treeNode)							//如果队首指针不为空
	{
		tail=(tail+1)%MAXLEN;					//计算循环队列队尾序号
		q[tail]=treeNode;					//二叉树根指针进入队列
		while(head!=tail)
		{
			head=(head+1)%MAXLEN;				//计算循环队列的队首序号
			p=q[head];					//获取队首元素
			ShowNodeData(p);				//输出队首元素
			if(p->left!=NULL)				//如果存在左子树
			{
				tail=(tail+1)%MAXLEN;			//计算队列的队尾序号
				q[tail]=p->left;			//左子树入队
			}
			if(p->right!=NULL)				//如果存在右子树
			{
				tail=(tail+1)%MAXLEN;			//计算队列的队尾序号
				q[tail]=p->right;			//右子树入队
			}
		}
	}
}
/*************************先序遍历算法**********************************/
void DLRTree(CBTType *treeNode)
{
	if(treeNode)
	{
		ShowNodeData(treeNode);					//显示结点内容
		DLRTree(treeNode->left);				//显示左子树内容
		DLRTree(treeNode->right);				//显示右子树内容
	}
}
/***********************中序遍历算法************************************/
void LDRTree(CBTType *treeNode)
{
	if(treeNode)
	{

		LDRTree(treeNode->left);				//显示左子树内容
		ShowNodeData(treeNode);					//显示结点内容
		DLRTree(treeNode->right);				//显示右子树内容
	}
}
/***********************后序遍历算法************************************/
void LRDTree(CBTType *treeNode)
{
	if(treeNode)
	{
		LRDTree(treeNode->left);				//显示左子树内容
		DLRTree(treeNode->right);				//显示右子树内容
		ShowNodeData(treeNode);					//显示结点内容
	}
}
/*************************主函数部分************************************/
int main()
{
	CBTType *root=NULL;						//root为指向二叉树根结点的指针
	char menusel;
	//设置根结点
	root=InitTree();
	//添加结点
	do
	{
		cout<<"请选择菜单添加二叉树的结点："<<endl;
		cout<<"0.退出;1.添加二叉树的结点。"<<endl;
		cin>>menusel;
		switch(menusel)
		{
			case '1':
				AddTreeNode(root);
				break;
			case '0':
				break;
			default:
				cout<<"添加结点error"<<endl;
				break;
		}
	}while(menusel!='0');
	//输出树的深度
	cout<<"depth:"<<TreeDepth(root)<<endl;
	//输出结点内容
	do
	{
		cout<<"请选择菜单遍历二叉树，输入0表示退出："<<endl;
		cout<<"1.按层遍历"<<endl;
		cout<<"2.先序遍历DLR"<<endl;
		cout<<"3.中序遍历LDR"<<endl;
		cout<<"4.后序遍历LRD"<<endl;
		cin>>menusel;
		switch(menusel)
		{
			case '0':break;
		 	case '1':
		 		cout<<"按层遍历的结果："<<endl;
		 		LevelTree(root);
			    cout<<endl;
				break;
			case '2':
				cout<<"先序遍历的结果："<<endl;
				DLRTree(root);
				cout<<endl;
				break;
			case '3':
				cout<<"中序遍历的结果："<<endl;
				LDRTree(root);
				cout<<endl;
				break;
			case '4':
				cout<<"后序遍历的结果："<<endl;
				LRDTree(root);
				cout<<endl;
				break;
			default:
				cout<<"遍历方式选择出错！"<<endl;
				break;
		}
	}while(menusel!='0');
	//清空二叉树
	ClearTree(root);
	return 0;
}


