#include <stdlib.h>
#include "glut.h"

float fRotate    = 0.0f; //旋转因子（茶壶和桌子）
float fScale     = 1.0f; //缩放因子

float tRotate = 0.0f; //旋转因子（茶壶）

bool bPersp = false; //是否为透视投影 （vs 正投影）
bool bAnim = false; // 茶壶和桌子是否旋转
bool bWire = false; // 绘制模式是否为线形 （vs 填充）
bool isRotate = false; //茶壶是否旋转

int wHeight = 0;
int wWidth = 0;

int min(int x, int y)
{
	return x < y ? x : y;
}

//绘制腿部
void Draw_Leg() 
{
	glScalef(1, 1, 3);
	glutSolidCube(1.0);
}

void Draw_Scene(float place[])
{
	//画茶壶
	glPushMatrix();
	glTranslatef(place[0], place[1], place[2]);//控制平移
	glRotatef(90, 1, 0, 0);
	glRotatef(tRotate, 0, 1, 0);//控制旋转
	glutSolidTeapot(1);
	glPopMatrix();


        //画地板
	glm::vec4 v1(-3, 0,-3, 1), v2(-3, 0, 3, 1), v3( 3, 0, 3, 1), v4( 3, 0,-3, 1);//四个顶点
        glm::mat4 m = glm::translate(glm::vec3(0.5f,0.5f,0.5f))
        * glm::scale(glm::vec3(0.5f,0.5f,0.5f)); // 需要将裁剪坐标的[-1,+1]缩放到[0,1]
        glm::vec4 t;
        glBegin(GL_POLYGON);
    　　glNormal3f(0, 1, 0);
    　　t = m*shadow_mat_p*shadow_mat_v*v1; // 按和生成纹理相同的变换计算纹理坐标
    　　glTexCoord4fv(&t[0]); glVertex3fv(&v1[0]);
    　　t = m*shadow_mat_p*shadow_mat_v*v2;
    　　glTexCoord4fv(&t[0]); glVertex3fv(&v2[0]);
    　　t = m*shadow_mat_p*shadow_mat_v*v3;
    　　glTexCoord4fv(&t[0]); glVertex3fv(&v3[0]);
    　　t = m*shadow_mat_p*shadow_mat_v*v4;
    　　glTexCoord4fv(&t[0]); glVertex3fv(&v4[0]);
    glEnd();
}

void updateView(int width, int height)
{
	glViewport(0,0,width,height);//设置视窗大小

	glMatrixMode(GL_PROJECTION);//设置矩阵模式为投影
	glLoadIdentity();	 //初始化矩阵为单位矩阵  

	float whRatio = (GLfloat)width/(GLfloat)height;//设置显示比例

	if (bPersp){
		gluPerspective(45, whRatio, 1, 100); //透视投影
		//参数：

		//GLdouble fovy 视角
		//GLdouble aspect 宽高比
		//GLdouble zNear 近处
		//GLdouble zFar 远处
	}
	else
		glOrtho(-3 ,3, -3, 3,-100,100); //正投影
	    //参数

		//GLdouble left,
		//GLdouble right,
		//GLdouble bottom,
		//GLdouble top,
		//GLdouble near,
		//GLdouble far

	glMatrixMode(GL_MODELVIEW);	//设置矩阵模式为模型
}

void reshape(int width, int height)
{
	if (height==0)	//如果高度为0
	{
		height=1;	//让高度为1（避免出现分母为0的现象）
	}

	height = width = min(height, width);
	wHeight = height;
	wWidth = width;
	
	updateView(wHeight, wWidth); //更新视角
}

void idle() 
{
	glutPostRedisplay();//调用当前绘制函数 
}

float eye[] = {0, 0, 8};
float center[] = {0, 0, 0};
float place[] = {0, 0, 5};



void redraw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除颜色缓存和深度缓存
	glLoadIdentity(); //初始化矩阵为单位矩阵

	gluLookAt(eye[0], eye[1], eye[2],
		center[0], center[1], center[2],
		0, 1, 0);			

	//  观察位置(eye[0],eye[1],eye[2]
	//	物体位置(center[0],center[1],center[2]
	//	观察方向(x, y, z) 

	if (bWire) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //设置多边形绘制模式：正反面，线型  
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //设置多边形绘制模式：正反面，填充  
	}

	glEnable(GL_DEPTH_TEST);  //开启深度测试
	glEnable(GL_LIGHTING); //开启光照模式
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 }; // 定义颜色
	GLfloat light_pos[] = {5,5,5,1};  //定义光源位置

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos); //设置第0号光源的光照位置
	glLightfv(GL_LIGHT0, GL_AMBIENT, white); //设置第0号光源多次反射后的光照颜色（环境光颜色）
	glEnable(GL_LIGHT0); //开启第0号光源
	Draw_Scene(place); //场景绘制
	
	

	glutSwapBuffers(); //交换缓冲区  
}

int main (int argc,  char *argv[])
{
	glutInit(&argc, argv);//对glut的初始化 
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);//初始化显示模式:RGB颜色模型，深度测试，双缓冲   
	glutInitWindowSize(480,480);//设置窗口大小  
	int windowHandle = glutCreateWindow("Ex 3");//设置窗口标题   

	glutDisplayFunc(redraw);//注册绘制回调函数  
	glutReshapeFunc(reshape);//注册重绘回调函数 
	glutKeyboardFunc(key);//注册按键回调函数
	glutIdleFunc(idle);//注册全局回调函数：空闲时调用  

	glutMainLoop();// glut事件处理循环
	return 0;
}


