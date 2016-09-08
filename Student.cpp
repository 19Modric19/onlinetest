#include "stdafx.h"
#include "iostream"
#include "fstream"  //输入输出文件
#include "string"    
#include "iomanip" //输出格式控制
using namespace std;  
char press;int choose;int n;int people;int count=0;

class Student
{
public:
	int num;
	string name;
	string sex;
	string clas;
	float Math,English,Cja;
	float sum,avg;
};
Student stu[100];
//---------------------------------学生资料管理-----------------------------：
//---------------------------------学生资料保存-----------------------------
void set_inb()
{
	char a;
	cout<<"是否需要保存：\t y/n"<<endl;
	cin>>a;
	if(a=='y'||a=='Y')
	{
		char filename[20];
		cout<<"请输入文件名："<<endl;
	K:
		cin>>filename;
		ofstream outfile;
		outfile.open(filename);
		if(!outfile)
		{
			cout<<"创建失败！"<<endl;
			cout<<endl;
			cout<<"请重新输入文件名："<<endl;
			goto K;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				outfile<<"学号:"<<stu[i].num<<"\t";
				outfile<<"姓名:"<<stu[i].name<<"\t";
				outfile<<"性别:"<<stu[i].sex<<"\t    ";
				outfile<<"班级:"<<stu[i].clas<<"\t   ";
				outfile<<"C++成绩:"<<stu[i].Cja<<"\t";
				outfile<<"数学成绩:"<<stu[i].Math<<"\t";
				outfile<<"英语成绩:"<<stu[i].English<<"\t";
				outfile<<"总分:"<<stu[i].sum<<"\t";
				outfile<<"平均分:"<<stu[i].avg<<endl;
			}
			cout<<"保存成功！！"<<endl;
		}
		outfile.close();
	}
	else
		cout<<"数据未保存！"<<endl;
}
//*********************************录入学生资料************************
void set_in1()
{
	cout<<"请定义录入学生人数："<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个学生的学号:"<<endl;
		cin>>stu[i].num;
		cout<<"请输入第"<<i+1<<"个学生的姓名:"<<endl;
		cin>>stu[i].name;
		cout<<"请输入第"<<i+1<<"个学生的性别:"<<endl;
		cin>>stu[i].sex;
		cout<<"请输入第"<<i+1<<"个学生的班级:"<<endl;
		cin>>stu[i].clas;
		cout<<"请输入第"<<i+1<<"个学生的C++成绩:"<<endl;
		cin>>stu[i].Cja;
		cout<<"请输入第"<<i+1<<"个学生的数学成绩:"<<endl;
		cin>>stu[i].Math;
		cout<<"请输入第"<<i+1<<"个学生的英语成绩:"<<endl;
		cin>>stu[i].English;
		stu[i].sum=stu[i].Cja+stu[i].Math+stu[i].English;
		stu[i].avg=stu[i].sum/3;
	}
	set_inb();
}
//*********************************删除学生资料************************
void set_in2()
{
	char q;
	do{
		string xm;
		int c;
		cout<<"请输入要删除的学生名字："<<endl;
		cin>>xm;
		for(int i=0;i<n;i++)
		{
			if(xm==stu[i].name)
			{
				c=i;
				for(int i=c;i<n;i++)
				{
					stu[i].num=stu[i+1].num;
					stu[i].name=stu[i+1].name;
					stu[i].sex=stu[i+1].sex;
					stu[i].clas=stu[i+1].clas;
					stu[i].Cja=stu[i+1].Cja;
					stu[i].Math=stu[i+1].Math;
					stu[i].English=stu[i+1].English;
					stu[i].sum=stu[i+1].sum;
					stu[i].avg=stu[i+1].avg;
				}
				cout<<"删除成功！"<<endl;
				break;
			}
		}
		n=n-1;
		set_inb();
		cout<<"是否需要继续删除：\t y/n"<<endl;
		cin>>q;
	}while(q=='y'||q=='Y');
}

//*********************************添加学生资料************************
void set_in3()
{
	char a;
	int f=0;
	do
	{
		cout<<"请输入要添加学生人数："<<endl;
		cin>>people;
		int d=n;
		n=n+people;
		for(int i=d;i<n;i++)
		{
			cout<<"请输入第"<<f+i<<"个学生的学号:"<<endl;
			cin>>stu[i].num;
			cout<<"请输入第"<<f+i<<"个学生的姓名:"<<endl;
			cin>>stu[i].name;
			cout<<"请输入第"<<f+i<<"个学生的性别:"<<endl;
			cin>>stu[i].sex;
			cout<<"请输入第"<<f+i<<"个学生的班级:"<<endl;
			cin>>stu[i].clas;
			cout<<"请输入第"<<f+i<<"个学生的C++成绩:"<<endl;
			cin>>stu[i].Cja;
			cout<<"请输入第"<<f+i<<"个学生的数学成绩:"<<endl;
			cin>>stu[i].Math;
			cout<<"请输入第"<<i+i<<"个学生的英语成绩:"<<endl;
			cin>>stu[i].English;
			stu[i].sum=stu[i].Cja+stu[i].Math+stu[i].English;
			stu[i].avg=stu[i].sum/3;
		}
		set_inb();
		cout<<"请问是否需要继续添加？\t y/n"<<endl;
		cin>>a;
	}while(a=='y'||a=='Y');
}

//*********************************修改学生资料************************
void set_in4()
{
	char a;
	do
	{
		int c,m,v=1;
	M:
		cout<<"请输入需要修改学生的学号："<<endl;
		cin>>m;
		for(int i=0;i<n;i++)
		{
			v++;
			if(stu[i].num==m)
			{
				c=i;
				break;
			}
			else
				if(v>n)
				{
					cout<<"您所输入的学号不存在,请重新选择："<<endl;
					goto M;
				}
		}	
			for(int j=0;j<1;j++)
			{
				stu[c].num=m;
				cout<<"请输入需要修改学生的姓名:"<<endl;string na;
				cin>>na;
				stu[c].name=na;
				cout<<"请输入需要修改学生的性别:"<<endl;string e;
				cin>>e;
				stu[c].sex=e;
				cout<<"请输入需要修改学生的班级:"<<endl;string cl;
				cin>>cl;
				stu[c].clas=cl;
				cout<<"请输入需要修改学生的C++成绩:"<<endl;float s;
				cin>>s;
				stu[c].Cja=s;
				cout<<"请输入需要修改学生的数学成绩:"<<endl;float M;
				cin>>M;
				stu[c].Math=M;
				cout<<"请输入需要修改学生的英语成绩:"<<endl;float E;
				cin>>E;
				stu[c].English=E;
				float SUM=0,AVG=0;
				SUM=stu[c].Cja+stu[c].Math+stu[c].English;
				stu[c].sum=SUM;
				AVG=stu[c].sum/3;
				stu[c].avg=AVG;
			}
		cout<<"修改成功！"<<endl;
		set_inb();
		cout<<"请问是否需要继续修改？\t y/n"<<endl;
		cin>>a;
	}while(a=='y'||a=='Y');
}

//*********************************读取学生资料************************
void set_in5()
{
	char filename[20];
	string d;
	cin>>filename;
	ifstream infile(filename);
	if(!infile)
	{
		cout<<"打开错误!"<<endl;
	}
	for(int i=0;i<n*9;i++)
	{
		infile>>d;
		cout<<d<<"\t";
		if(i%9==0)
			cout<<endl;
	}
	infile.close();
}







//-------------------------------学生成绩统计-------------------------：
//*********************************按总分排名****************************
void get_in1()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[i].sum<stu[j].sum)
			{
				float t=stu[i].sum;			int c=stu[i].num;			string r=stu[i].name;		string x=stu[i].sex;	string s=stu[i].clas;
				stu[i].sum=stu[j].sum;  	stu[i].num=stu[j].num;	    stu[i].name=stu[j].name;	stu[i].sex=stu[j].sex;	stu[i].clas=stu[j].clas;
				stu[j].sum=t;				stu[j].num=c;				stu[j].name=r;			    stu[j].sex=x;			stu[j].clas=s;
			}
		}
	}
	cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"班级"<<"\t        ";
	cout<<"总分"<<"\t"<<" 排名"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<stu[i].num<<"\t"<<stu[i].name<<"\t"<<stu[i].sex<<"\t";
		cout<<stu[i].clas<<"\t"<<stu[i].sum<<"\t   "<<i+1<<endl;
	}
}

//*******************************按数学建模成绩排名**************************
void get_in2()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[i].Math<stu[j].Math)
			{
				float t=stu[i].Math;		int c=stu[i].num;			string r=stu[i].name;		string x=stu[i].sex;	string s=stu[i].clas;
				stu[i].Math=stu[j].Math;  	stu[i].num=stu[j].num;	    stu[i].name=stu[j].name;	stu[i].sex=stu[j].sex;	stu[i].clas=stu[j].clas;
				stu[j].Math=t;				stu[j].num=c;				stu[j].name=r;			    stu[j].sex=x;			stu[j].clas=s;
			}	
		}
	}
	cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"班级"<<"\t        ";
	cout<<"数学建模 "<<"      "<<"排名"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].Math<<"\t   ";
		cout<<"第"<<j+1<<"名"<<endl;
	}
}

//*********************************按英语成绩排名**************************
void get_in3()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[i].English<stu[j].English)
			{
				float t=stu[i].English;				int c=stu[i].num;			string r=stu[i].name;		string x=stu[i].sex;	string s=stu[i].clas;
				stu[i].English=stu[j].English;  	stu[i].num=stu[j].num;	    stu[i].name=stu[j].name;	stu[i].sex=stu[j].sex;	stu[i].clas=stu[j].clas;
				stu[j].English=t;					stu[j].num=c;				stu[j].name=r;			    stu[j].sex=x;			stu[j].clas=s;
			}	
		}
	}
	cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"班级"<<"\t         ";
	cout<<"英语  "<<"\t"<<"排名"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].English<<"\t";
		cout<<"第"<<j+1<<"名"<<endl;
	}
}

//*********************************按C++成绩排名**************************
void get_in4()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[i].Cja<stu[j].Cja)
			{
				float t=stu[i].Cja;			int c=stu[i].num;			string r=stu[i].name;		string x=stu[i].sex;	string s=stu[i].clas;
				stu[i].Cja=stu[j].Cja;  	stu[i].num=stu[j].num;	    stu[i].name=stu[j].name;	stu[i].sex=stu[j].sex;	stu[i].clas=stu[j].clas;
				stu[j].Cja=t;				stu[j].num=c;				stu[j].name=r;			    stu[j].sex=x;			stu[j].clas=s;
			}	
		}
	}
	cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"班级"<<"\t         ";
	cout<<"C++  "<<"\t"<<"排名"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].Cja<<"\t";
		cout<<"第"<<j+1<<"名"<<endl;
	}
}

//********************************最高总分***************************
void get_in5()
{
	float max=0;
	int c;
	for(int i=0;i<n;i++)
	{
		if(max<stu[i].sum)
		{
			max=stu[i].sum;
			c=i;
		}
	}
	cout<<"最高总分是："<<stu[c].name<<" "<<max<<"分"<<endl;
}

//********************************最低总分***************************
void get_in6()
{
	float min=0;
	int c;
	for(int i=0;i<n;i++)
	{
		if(min>stu[i].sum)
		{
			min=stu[i].sum;
			c=i;
		}
	}
	cout<<"最低总分是："<<stu[c].name<<" "<<stu[c].sum<<"分"<<endl;
}

//*********************************按平均分排名**************************
void get_in7()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[i].avg<stu[j].avg)
			{
				float t=stu[i].avg;			int c=stu[i].num;			string r=stu[i].name;		string x=stu[i].sex;	string s=stu[i].clas;
				stu[i].avg=stu[j].avg;  	stu[i].num=stu[j].num;	    stu[i].name=stu[j].name;	stu[i].sex=stu[j].sex;	stu[i].clas=stu[j].clas;
				stu[j].avg=t;				stu[j].num=c;				stu[j].name=r;			    stu[j].sex=x;			stu[j].clas=s;
			}	
		}
	}
	cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"班级"<<"\t         ";
	cout<<"平均分  "<<"\t"<<"排名"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].avg<<"\t";
		cout<<"第"<<j+1<<"名"<<endl;
	}
}



//--------------------------------学生查询-----------------------------------
//********************************按学号查询******************************//有待解决
void sort_in1()
{
	int xh,c;
	cout<<"请输入您所要查询学生的学号："<<endl;
	cin>>xh;
	for(int i=0;i<n;i++)
	{
		if(stu[i].num==xh)
		c=i;
	}
	cout<<"学号:"<<stu[c].num<<"\t";
	cout<<"姓名:"<<stu[c].name<<"\t";
	cout<<"性别:"<<stu[c].sex<<"\t";
	cout<<"班级:"<<stu[c].clas<<"\t";
	cout<<"C++成绩:"<<stu[c].Cja<<"\t";
	cout<<"数学成绩:"<<stu[c].Math<<"\t";
	cout<<"英语成绩:"<<stu[c].English<<"\t";
	cout<<"总分:"<<stu[c].sum<<"\t";
	cout<<"平均分:"<<stu[c].avg<<endl;
}

//********************************按姓名查询***************************//有待解决
void sort_in2()
{
	string xm;
	int c;
	cout<<"请输入您所要查询学生的姓名："<<endl;
	cin>>xm;
	for(int i=0;i<n;i++)
	{
		if(stu[i].name==xm)
		c=i;
	}
	cout<<"学号:"<<stu[c].num<<"\t";
	cout<<"姓名:"<<stu[c].name<<"\t";
	cout<<"性别:"<<stu[c].sex<<"\t";
	cout<<"班级:"<<stu[c].clas<<"\t";
	cout<<"C++成绩:"<<stu[c].Cja<<"\t";
	cout<<"数学成绩:"<<stu[c].Math<<"\t";
	cout<<"英语成绩:"<<stu[c].English<<"\t";
	cout<<"总分:"<<stu[c].sum<<"\t";
	cout<<"平均分:"<<stu[c].avg<<endl;
}

//********************************按班级查询***************************//有待解决
void sort_in3()
{
	string bj;
	int c;
	cout<<"请输入您所要查询学生的班级："<<endl;
	cin>>bj;
	for(int i=0;i<n;i++)
	{
		if(stu[i].clas==bj)
		{
			c=i;
			for(int j=0;j<1;j++)
			{
				cout<<"学号:"<<stu[c].num<<"\t";
				cout<<"姓名:"<<stu[c].name<<"\t";
				cout<<"性别:"<<stu[c].sex<<"\t";
				cout<<"班级:"<<stu[c].clas<<"\t";
				cout<<"C++成绩:"<<stu[c].Cja<<"\t";
				cout<<"数学成绩:"<<stu[c].Math<<"\t";
				cout<<"英语成绩:"<<stu[c].English<<"\t";
				cout<<"总分:"<<stu[c].sum<<"\t";
				cout<<"平均分:"<<stu[c].avg<<endl;
			}
		}
	}
	
}




//—————————————————学生资料管理界面—————————————
void Fire()
{
	while(choose!=0)
	{ 
		cout<<endl;
		cout<<"\t\t\t*************************************"<<endl;
		cout<<"\t\t\t*************************************"<<endl;
		cout<<"\t\t\t*           学生资料管理            *"<<endl;
		cout<<"\t\t\t*                                   *"<<endl; 
		cout<<"\t\t\t*          1.录入学生资料           *"<<endl; 
		cout<<"\t\t\t*          2.删除学生资料           *"<<endl; 
		cout<<"\t\t\t*          3.添加学生资料           *"<<endl; 
		cout<<"\t\t\t*          4.修改学生资料           *"<<endl; 
		cout<<"\t\t\t*          5.读取学生资料           *"<<endl;
		cout<<"\t\t\t*          0.返回                   *"<<endl;
		cout<<"\t\t\t*                                   *"<<endl; 
		cout<<"\t\t\t*          按Enter继续              *"<<endl; 
		cout<<"\t\t\t*************************************"<<endl;
		
		cout<<"\t\t\t*************************************"<<endl;
		cout<<"\t\t        请输入0-5之间的任意一数字:"<<' ';
		cin>>choose;
		switch(choose) //运用switch多分支选择语句
		{
		case 1:set_in1();break;
		case 2:set_in2();break;
		case 3:set_in3();break;
		case 4:set_in4();break;
		case 5:set_in5();break;
		default:cout<<"\t\t        输入错误或返回主界面"<<'\n';break;
		}
	}
}
//—————————————————学生成绩统计管理界面———————————
void statistics()
{
	while(choose!=0){ 
	 cout<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t\t*          学生成绩统计管理         *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
     cout<<"\t\t\t*          1.按总分排名             *"<<endl; 
     cout<<"\t\t\t*          2.按数学建模分数排名     *"<<endl; 
     cout<<"\t\t\t*          3.按英语分数排名         *"<<endl;
     cout<<"\t\t\t*          4.按C++分数排名          *"<<endl;
     cout<<"\t\t\t*          5.最高总分               *"<<endl; 
     cout<<"\t\t\t*          6.最低总分               *"<<endl; 
     cout<<"\t\t\t*          7.按平均分排名           *"<<endl; 
	 cout<<"\t\t\t*          8.及格率                 *"<<endl; 
	 cout<<"\t\t\t*          0.返回                   *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
	 cout<<"\t\t\t*          按Enter继续              *"<<endl; 
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t          请输入0-8之间的任意一数字:"<<' ';
		 cin>>choose;
		 switch(choose)
		 {
			case 1:get_in1();break;
			case 2:get_in2();break;
			case 3:get_in3();break;
			case 4:get_in4();break;
			case 5:get_in5();break;
			case 6:get_in6();break;
			case 7:get_in7();break;
			case 8:;break;
			default:cout<<"\t\t        输入错误或返回主界面"<<'\n';break;
		 }
	}
}
 //—————————————————学生查询管理界面—————————————
void inquiry()
{
	while(choose!=0){ 
	 cout<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t\t*          学生查询管理             *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
     cout<<"\t\t\t*          1.按学号查询             *"<<endl; 
     cout<<"\t\t\t*          2.按姓名查询             *"<<endl; 
     cout<<"\t\t\t*          3.按所在班级查询         *"<<endl;
	 cout<<"\t\t\t*          0.返回                   *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
	 cout<<"\t\t\t*          按Enter继续              *"<<endl; 
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t         请输入0-3之间的任意一数字:"<<' ';
	 cin>>choose;
     switch(choose)
	 {
	 case 1:sort_in1();break;
	 case 2:sort_in2();break;
	 case 3:sort_in3();break;
	 default:cout<<"\t\t        输入错误或返回主界面"<<'\n';break;
	 }
	}
}
 //—————————————————关于系统界面———————————————
void about()
{
	while(choose!=0)
	{      
		cout<<endl;
		cout<<"\t\t******************************************************"<<endl;
        cout<<"\t\t                     关于系统                         "<<endl;
        cout<<"                                                        "<<endl; 
        cout<<"\t\t系统设计者： 姓名     班级           学号             "<<endl;
		cout<<"                                                         "<<endl;
        cout<<"\t\t            谭荣杰  Java1403          32             "<<endl;
        cout<<"                                                         "<<endl;
        cout<<"\t\t                                                     "<<endl;   
        cout<<"                                                         "<<endl;
		cout<<"\t\t系统设计日期:  2009.10.29至2009.11.28                 "<<endl;
        cout<<"                                                         "<<endl;
		cout<<"\t\t         系统仍有许多不足之处，敬请见谅               "<<endl; 
        cout<<"                                                         "<<endl;
        cout<<"\t\t          如发现错误，请联系QQ26839802               "<<endl;
        cout<<"                                                         "<<endl;
        cout<<"\t\t                    按0返回:                          "<<endl;
        cout<<"\t\t******************************************************"<<endl;
		cin>>choose;
		switch(choose)
		{
		case 0:break;
		default:break;
		}
	}
}
 //—————————————————退出程序界面———————————————  
void thanks()
 {     
	   cout<<endl;
	   cout<<"                                                          "<<endl;
       cout<<"                                                          "<<endl;
       cout<<"                                                          "<<endl; 
       cout<<"\t* * * *  *    *      *      **    *   *    *    * * *   "<<endl; 
       cout<<"\t   *     *    *     * *     * *   *   *   *    *     *  "<<endl;
       cout<<"\t   *     * ** *    * * *    *  *  *   *  *        *     "<<endl;   
       cout<<"\t   *     *    *   *     *   *   * *   *   *    *     *  "<<endl;
	   cout<<"\t   *     *    *  *       *  *    **   *    *    * * *   "<<endl;
	   cout<<"\t                                                        "<<endl; 
       cout<<"                                                          "<<endl;
       cout<<"                                                        "<<endl;
}
 //—————————————————学生成绩管理系统主界面——————————
int main()
{
	while(choose!='0')
	{
		cout<<endl;
	    cout<<"\t\t  *********************************************** "<<endl;
        cout<<"\t\t ************************************************* "<<endl;
        cout<<"\t\t**********                               **********"<<endl; 
        cout<<"\t\t**********           欢迎使用            **********"<<endl; 
        cout<<"\t\t**********                               **********"<<endl;
        cout<<"\t\t**********         湖南信息学院          **********"<<endl;   
        cout<<"\t\t**********                               **********"<<endl;
		cout<<"\t\t**********       学生成绩管理系统        **********"<<endl;
		cout<<"\t\t**********                               **********"<<endl; 
        cout<<"\t\t***************************************************"<<endl;
        cout<<"\t\t***************************************************"<<endl;
        cout<<"\t\t*                   操作菜单                      *"<<endl;
		cout<<"\t\t*                                                 *"<<endl; 
        cout<<"\t\t*                1.学生资料管理                   *"<<endl;
        cout<<"\t\t*                2.学生成绩统计管理               *"<<endl;   
        cout<<"\t\t*                3.学生查询管理                   *"<<endl;
        cout<<"\t\t*                4.关于系统                       *"<<endl;
        cout<<"\t\t*                0.退出系统                       *"<<endl;
		cout<<"\t\t*                                                 *"<<endl; 
        cout<<"\t\t*                  按Enter继续                    *"<<endl;
		cout<<"\t\t*                                                 *"<<endl; 
		cout<<"\t\t***************************************************"<<endl;
        cout<<"\t\t***************************************************"<<endl;   
        cout<<"\t\t             请输入0-4之间的任意一数字:"<<' ';   
		cin>>choose;
		switch(choose)
		{
			case 1: Fire();break;
			case 2: statistics();break;
			case 3: inquiry();break;
			case 4: about();break;
			case 0: thanks();exit(0);break;
			default:cout<<"\t\t\t        输入错误,返回"<<endl;break;
		}
	}
	return 0;
}