#include "stdafx.h"
#include "iostream"
#include "fstream"  //��������ļ�
#include "string"    
#include "iomanip" //�����ʽ����
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
//---------------------------------ѧ�����Ϲ���-----------------------------��
//---------------------------------ѧ�����ϱ���-----------------------------
void set_inb()
{
	char a;
	cout<<"�Ƿ���Ҫ���棺\t y/n"<<endl;
	cin>>a;
	if(a=='y'||a=='Y')
	{
		char filename[20];
		cout<<"�������ļ�����"<<endl;
	K:
		cin>>filename;
		ofstream outfile;
		outfile.open(filename);
		if(!outfile)
		{
			cout<<"����ʧ�ܣ�"<<endl;
			cout<<endl;
			cout<<"�����������ļ�����"<<endl;
			goto K;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				outfile<<"ѧ��:"<<stu[i].num<<"\t";
				outfile<<"����:"<<stu[i].name<<"\t";
				outfile<<"�Ա�:"<<stu[i].sex<<"\t    ";
				outfile<<"�༶:"<<stu[i].clas<<"\t   ";
				outfile<<"C++�ɼ�:"<<stu[i].Cja<<"\t";
				outfile<<"��ѧ�ɼ�:"<<stu[i].Math<<"\t";
				outfile<<"Ӣ��ɼ�:"<<stu[i].English<<"\t";
				outfile<<"�ܷ�:"<<stu[i].sum<<"\t";
				outfile<<"ƽ����:"<<stu[i].avg<<endl;
			}
			cout<<"����ɹ�����"<<endl;
		}
		outfile.close();
	}
	else
		cout<<"����δ���棡"<<endl;
}
//*********************************¼��ѧ������************************
void set_in1()
{
	cout<<"�붨��¼��ѧ��������"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"��ѧ����ѧ��:"<<endl;
		cin>>stu[i].num;
		cout<<"�������"<<i+1<<"��ѧ��������:"<<endl;
		cin>>stu[i].name;
		cout<<"�������"<<i+1<<"��ѧ�����Ա�:"<<endl;
		cin>>stu[i].sex;
		cout<<"�������"<<i+1<<"��ѧ���İ༶:"<<endl;
		cin>>stu[i].clas;
		cout<<"�������"<<i+1<<"��ѧ����C++�ɼ�:"<<endl;
		cin>>stu[i].Cja;
		cout<<"�������"<<i+1<<"��ѧ������ѧ�ɼ�:"<<endl;
		cin>>stu[i].Math;
		cout<<"�������"<<i+1<<"��ѧ����Ӣ��ɼ�:"<<endl;
		cin>>stu[i].English;
		stu[i].sum=stu[i].Cja+stu[i].Math+stu[i].English;
		stu[i].avg=stu[i].sum/3;
	}
	set_inb();
}
//*********************************ɾ��ѧ������************************
void set_in2()
{
	char q;
	do{
		string xm;
		int c;
		cout<<"������Ҫɾ����ѧ�����֣�"<<endl;
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
				cout<<"ɾ���ɹ���"<<endl;
				break;
			}
		}
		n=n-1;
		set_inb();
		cout<<"�Ƿ���Ҫ����ɾ����\t y/n"<<endl;
		cin>>q;
	}while(q=='y'||q=='Y');
}

//*********************************���ѧ������************************
void set_in3()
{
	char a;
	int f=0;
	do
	{
		cout<<"������Ҫ���ѧ��������"<<endl;
		cin>>people;
		int d=n;
		n=n+people;
		for(int i=d;i<n;i++)
		{
			cout<<"�������"<<f+i<<"��ѧ����ѧ��:"<<endl;
			cin>>stu[i].num;
			cout<<"�������"<<f+i<<"��ѧ��������:"<<endl;
			cin>>stu[i].name;
			cout<<"�������"<<f+i<<"��ѧ�����Ա�:"<<endl;
			cin>>stu[i].sex;
			cout<<"�������"<<f+i<<"��ѧ���İ༶:"<<endl;
			cin>>stu[i].clas;
			cout<<"�������"<<f+i<<"��ѧ����C++�ɼ�:"<<endl;
			cin>>stu[i].Cja;
			cout<<"�������"<<f+i<<"��ѧ������ѧ�ɼ�:"<<endl;
			cin>>stu[i].Math;
			cout<<"�������"<<i+i<<"��ѧ����Ӣ��ɼ�:"<<endl;
			cin>>stu[i].English;
			stu[i].sum=stu[i].Cja+stu[i].Math+stu[i].English;
			stu[i].avg=stu[i].sum/3;
		}
		set_inb();
		cout<<"�����Ƿ���Ҫ������ӣ�\t y/n"<<endl;
		cin>>a;
	}while(a=='y'||a=='Y');
}

//*********************************�޸�ѧ������************************
void set_in4()
{
	char a;
	do
	{
		int c,m,v=1;
	M:
		cout<<"��������Ҫ�޸�ѧ����ѧ�ţ�"<<endl;
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
					cout<<"���������ѧ�Ų�����,������ѡ��"<<endl;
					goto M;
				}
		}	
			for(int j=0;j<1;j++)
			{
				stu[c].num=m;
				cout<<"��������Ҫ�޸�ѧ��������:"<<endl;string na;
				cin>>na;
				stu[c].name=na;
				cout<<"��������Ҫ�޸�ѧ�����Ա�:"<<endl;string e;
				cin>>e;
				stu[c].sex=e;
				cout<<"��������Ҫ�޸�ѧ���İ༶:"<<endl;string cl;
				cin>>cl;
				stu[c].clas=cl;
				cout<<"��������Ҫ�޸�ѧ����C++�ɼ�:"<<endl;float s;
				cin>>s;
				stu[c].Cja=s;
				cout<<"��������Ҫ�޸�ѧ������ѧ�ɼ�:"<<endl;float M;
				cin>>M;
				stu[c].Math=M;
				cout<<"��������Ҫ�޸�ѧ����Ӣ��ɼ�:"<<endl;float E;
				cin>>E;
				stu[c].English=E;
				float SUM=0,AVG=0;
				SUM=stu[c].Cja+stu[c].Math+stu[c].English;
				stu[c].sum=SUM;
				AVG=stu[c].sum/3;
				stu[c].avg=AVG;
			}
		cout<<"�޸ĳɹ���"<<endl;
		set_inb();
		cout<<"�����Ƿ���Ҫ�����޸ģ�\t y/n"<<endl;
		cin>>a;
	}while(a=='y'||a=='Y');
}

//*********************************��ȡѧ������************************
void set_in5()
{
	char filename[20];
	string d;
	cin>>filename;
	ifstream infile(filename);
	if(!infile)
	{
		cout<<"�򿪴���!"<<endl;
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







//-------------------------------ѧ���ɼ�ͳ��-------------------------��
//*********************************���ܷ�����****************************
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
	cout<<"ѧ��"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"�༶"<<"\t        ";
	cout<<"�ܷ�"<<"\t"<<" ����"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<stu[i].num<<"\t"<<stu[i].name<<"\t"<<stu[i].sex<<"\t";
		cout<<stu[i].clas<<"\t"<<stu[i].sum<<"\t   "<<i+1<<endl;
	}
}

//*******************************����ѧ��ģ�ɼ�����**************************
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
	cout<<"ѧ��"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"�༶"<<"\t        ";
	cout<<"��ѧ��ģ "<<"      "<<"����"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].Math<<"\t   ";
		cout<<"��"<<j+1<<"��"<<endl;
	}
}

//*********************************��Ӣ��ɼ�����**************************
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
	cout<<"ѧ��"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"�༶"<<"\t         ";
	cout<<"Ӣ��  "<<"\t"<<"����"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].English<<"\t";
		cout<<"��"<<j+1<<"��"<<endl;
	}
}

//*********************************��C++�ɼ�����**************************
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
	cout<<"ѧ��"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"�༶"<<"\t         ";
	cout<<"C++  "<<"\t"<<"����"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].Cja<<"\t";
		cout<<"��"<<j+1<<"��"<<endl;
	}
}

//********************************����ܷ�***************************
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
	cout<<"����ܷ��ǣ�"<<stu[c].name<<" "<<max<<"��"<<endl;
}

//********************************����ܷ�***************************
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
	cout<<"����ܷ��ǣ�"<<stu[c].name<<" "<<stu[c].sum<<"��"<<endl;
}

//*********************************��ƽ��������**************************
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
	cout<<"ѧ��"<<"\t"<<"����"<<"\t"<<"�Ա�"<<"\t"<<"�༶"<<"\t         ";
	cout<<"ƽ����  "<<"\t"<<"����"<<endl;
	for(int j=0;j<n;j++)
	{
		cout<<stu[j].num<<"\t"<<stu[j].name<<"\t"<<stu[j].sex<<"\t"<<stu[j].clas<<"\t"<<stu[j].avg<<"\t";
		cout<<"��"<<j+1<<"��"<<endl;
	}
}



//--------------------------------ѧ����ѯ-----------------------------------
//********************************��ѧ�Ų�ѯ******************************//�д����
void sort_in1()
{
	int xh,c;
	cout<<"����������Ҫ��ѯѧ����ѧ�ţ�"<<endl;
	cin>>xh;
	for(int i=0;i<n;i++)
	{
		if(stu[i].num==xh)
		c=i;
	}
	cout<<"ѧ��:"<<stu[c].num<<"\t";
	cout<<"����:"<<stu[c].name<<"\t";
	cout<<"�Ա�:"<<stu[c].sex<<"\t";
	cout<<"�༶:"<<stu[c].clas<<"\t";
	cout<<"C++�ɼ�:"<<stu[c].Cja<<"\t";
	cout<<"��ѧ�ɼ�:"<<stu[c].Math<<"\t";
	cout<<"Ӣ��ɼ�:"<<stu[c].English<<"\t";
	cout<<"�ܷ�:"<<stu[c].sum<<"\t";
	cout<<"ƽ����:"<<stu[c].avg<<endl;
}

//********************************��������ѯ***************************//�д����
void sort_in2()
{
	string xm;
	int c;
	cout<<"����������Ҫ��ѯѧ����������"<<endl;
	cin>>xm;
	for(int i=0;i<n;i++)
	{
		if(stu[i].name==xm)
		c=i;
	}
	cout<<"ѧ��:"<<stu[c].num<<"\t";
	cout<<"����:"<<stu[c].name<<"\t";
	cout<<"�Ա�:"<<stu[c].sex<<"\t";
	cout<<"�༶:"<<stu[c].clas<<"\t";
	cout<<"C++�ɼ�:"<<stu[c].Cja<<"\t";
	cout<<"��ѧ�ɼ�:"<<stu[c].Math<<"\t";
	cout<<"Ӣ��ɼ�:"<<stu[c].English<<"\t";
	cout<<"�ܷ�:"<<stu[c].sum<<"\t";
	cout<<"ƽ����:"<<stu[c].avg<<endl;
}

//********************************���༶��ѯ***************************//�д����
void sort_in3()
{
	string bj;
	int c;
	cout<<"����������Ҫ��ѯѧ���İ༶��"<<endl;
	cin>>bj;
	for(int i=0;i<n;i++)
	{
		if(stu[i].clas==bj)
		{
			c=i;
			for(int j=0;j<1;j++)
			{
				cout<<"ѧ��:"<<stu[c].num<<"\t";
				cout<<"����:"<<stu[c].name<<"\t";
				cout<<"�Ա�:"<<stu[c].sex<<"\t";
				cout<<"�༶:"<<stu[c].clas<<"\t";
				cout<<"C++�ɼ�:"<<stu[c].Cja<<"\t";
				cout<<"��ѧ�ɼ�:"<<stu[c].Math<<"\t";
				cout<<"Ӣ��ɼ�:"<<stu[c].English<<"\t";
				cout<<"�ܷ�:"<<stu[c].sum<<"\t";
				cout<<"ƽ����:"<<stu[c].avg<<endl;
			}
		}
	}
	
}




//����������������������������������ѧ�����Ϲ�����桪������������������������
void Fire()
{
	while(choose!=0)
	{ 
		cout<<endl;
		cout<<"\t\t\t*************************************"<<endl;
		cout<<"\t\t\t*************************************"<<endl;
		cout<<"\t\t\t*           ѧ�����Ϲ���            *"<<endl;
		cout<<"\t\t\t*                                   *"<<endl; 
		cout<<"\t\t\t*          1.¼��ѧ������           *"<<endl; 
		cout<<"\t\t\t*          2.ɾ��ѧ������           *"<<endl; 
		cout<<"\t\t\t*          3.���ѧ������           *"<<endl; 
		cout<<"\t\t\t*          4.�޸�ѧ������           *"<<endl; 
		cout<<"\t\t\t*          5.��ȡѧ������           *"<<endl;
		cout<<"\t\t\t*          0.����                   *"<<endl;
		cout<<"\t\t\t*                                   *"<<endl; 
		cout<<"\t\t\t*          ��Enter����              *"<<endl; 
		cout<<"\t\t\t*************************************"<<endl;
		
		cout<<"\t\t\t*************************************"<<endl;
		cout<<"\t\t        ������0-5֮�������һ����:"<<' ';
		cin>>choose;
		switch(choose) //����switch���֧ѡ�����
		{
		case 1:set_in1();break;
		case 2:set_in2();break;
		case 3:set_in3();break;
		case 4:set_in4();break;
		case 5:set_in5();break;
		default:cout<<"\t\t        �������򷵻�������"<<'\n';break;
		}
	}
}
//����������������������������������ѧ���ɼ�ͳ�ƹ�����桪��������������������
void statistics()
{
	while(choose!=0){ 
	 cout<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t\t*          ѧ���ɼ�ͳ�ƹ���         *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
     cout<<"\t\t\t*          1.���ܷ�����             *"<<endl; 
     cout<<"\t\t\t*          2.����ѧ��ģ��������     *"<<endl; 
     cout<<"\t\t\t*          3.��Ӣ���������         *"<<endl;
     cout<<"\t\t\t*          4.��C++��������          *"<<endl;
     cout<<"\t\t\t*          5.����ܷ�               *"<<endl; 
     cout<<"\t\t\t*          6.����ܷ�               *"<<endl; 
     cout<<"\t\t\t*          7.��ƽ��������           *"<<endl; 
	 cout<<"\t\t\t*          8.������                 *"<<endl; 
	 cout<<"\t\t\t*          0.����                   *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
	 cout<<"\t\t\t*          ��Enter����              *"<<endl; 
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t          ������0-8֮�������һ����:"<<' ';
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
			default:cout<<"\t\t        �������򷵻�������"<<'\n';break;
		 }
	}
}
 //����������������������������������ѧ����ѯ������桪������������������������
void inquiry()
{
	while(choose!=0){ 
	 cout<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t\t*          ѧ����ѯ����             *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
     cout<<"\t\t\t*          1.��ѧ�Ų�ѯ             *"<<endl; 
     cout<<"\t\t\t*          2.��������ѯ             *"<<endl; 
     cout<<"\t\t\t*          3.�����ڰ༶��ѯ         *"<<endl;
	 cout<<"\t\t\t*          0.����                   *"<<endl;
     cout<<"\t\t\t*                                   *"<<endl; 
	 cout<<"\t\t\t*          ��Enter����              *"<<endl; 
	 cout<<"\t\t\t*************************************"<<endl;
	 cout<<"\t\t\t*************************************"<<endl;
     cout<<"\t\t         ������0-3֮�������һ����:"<<' ';
	 cin>>choose;
     switch(choose)
	 {
	 case 1:sort_in1();break;
	 case 2:sort_in2();break;
	 case 3:sort_in3();break;
	 default:cout<<"\t\t        �������򷵻�������"<<'\n';break;
	 }
	}
}
 //��������������������������������������ϵͳ���桪����������������������������
void about()
{
	while(choose!=0)
	{      
		cout<<endl;
		cout<<"\t\t******************************************************"<<endl;
        cout<<"\t\t                     ����ϵͳ                         "<<endl;
        cout<<"                                                        "<<endl; 
        cout<<"\t\tϵͳ����ߣ� ����     �༶           ѧ��             "<<endl;
		cout<<"                                                         "<<endl;
        cout<<"\t\t            ̷�ٽ�  Java1403          32             "<<endl;
        cout<<"                                                         "<<endl;
        cout<<"\t\t                                                     "<<endl;   
        cout<<"                                                         "<<endl;
		cout<<"\t\tϵͳ�������:  2009.10.29��2009.11.28                 "<<endl;
        cout<<"                                                         "<<endl;
		cout<<"\t\t         ϵͳ������಻��֮�����������               "<<endl; 
        cout<<"                                                         "<<endl;
        cout<<"\t\t          �緢�ִ�������ϵQQ26839802               "<<endl;
        cout<<"                                                         "<<endl;
        cout<<"\t\t                    ��0����:                          "<<endl;
        cout<<"\t\t******************************************************"<<endl;
		cin>>choose;
		switch(choose)
		{
		case 0:break;
		default:break;
		}
	}
}
 //�����������������������������������˳�������桪����������������������������  
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
 //����������������������������������ѧ���ɼ�����ϵͳ�����桪������������������
int main()
{
	while(choose!='0')
	{
		cout<<endl;
	    cout<<"\t\t  *********************************************** "<<endl;
        cout<<"\t\t ************************************************* "<<endl;
        cout<<"\t\t**********                               **********"<<endl; 
        cout<<"\t\t**********           ��ӭʹ��            **********"<<endl; 
        cout<<"\t\t**********                               **********"<<endl;
        cout<<"\t\t**********         ������ϢѧԺ          **********"<<endl;   
        cout<<"\t\t**********                               **********"<<endl;
		cout<<"\t\t**********       ѧ���ɼ�����ϵͳ        **********"<<endl;
		cout<<"\t\t**********                               **********"<<endl; 
        cout<<"\t\t***************************************************"<<endl;
        cout<<"\t\t***************************************************"<<endl;
        cout<<"\t\t*                   �����˵�                      *"<<endl;
		cout<<"\t\t*                                                 *"<<endl; 
        cout<<"\t\t*                1.ѧ�����Ϲ���                   *"<<endl;
        cout<<"\t\t*                2.ѧ���ɼ�ͳ�ƹ���               *"<<endl;   
        cout<<"\t\t*                3.ѧ����ѯ����                   *"<<endl;
        cout<<"\t\t*                4.����ϵͳ                       *"<<endl;
        cout<<"\t\t*                0.�˳�ϵͳ                       *"<<endl;
		cout<<"\t\t*                                                 *"<<endl; 
        cout<<"\t\t*                  ��Enter����                    *"<<endl;
		cout<<"\t\t*                                                 *"<<endl; 
		cout<<"\t\t***************************************************"<<endl;
        cout<<"\t\t***************************************************"<<endl;   
        cout<<"\t\t             ������0-4֮�������һ����:"<<' ';   
		cin>>choose;
		switch(choose)
		{
			case 1: Fire();break;
			case 2: statistics();break;
			case 3: inquiry();break;
			case 4: about();break;
			case 0: thanks();exit(0);break;
			default:cout<<"\t\t\t        �������,����"<<endl;break;
		}
	}
	return 0;
}