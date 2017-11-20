#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
using namespace std;

//学生名单
struct  studentname
{

	char tname[20];
	studentname *next;

};
//学生选课课程
class course 
{
public:
	char cname[20];
	char cno[10];
	course *next;
};
//学生类
class student
{
private:
	char sname[20];
	int coursenum;
	course *root;
public:
	student()
	{
		root=NULL;
		coursenum=0;
	}
	void readname(char name[]);
	void getname(char name[]);
	void addcourse(char no[]);
	int findcourse(char no[]);
	int recoursenum()
	{return coursenum;}
	course *reroot()
	{return root;}
	void clrroot()
	{	root=NULL;
		coursenum=0;
	}

};
void student::readname (char name[])
{strcpy(sname,name);}
void student::getname (char name[])
{strcpy(name,sname);}

//学生链表
class  stunode
{
public:
	student stu;
	stunode *next;
};

//课程类
class subject
{
private:
	char subNO[10];
	char subName[10];
	int credit;
	studentname *first; //学生名单
	int stunum;//选课学生数

public:
	subject()
	{
		first=NULL;
	};

	void setname(char*name)
	{strcpy(subName,name);}
	void setno(char*no)
	{strcpy(subNO,no);}
	void setcre(int n)
	{credit=n;}
	void getname(char*name)
	{strcpy(name,subName);}
	void getno(char*no)
	{strcpy(no,subNO);}
	int  getcre()//得到课程的学分
	{
	return credit;
	}
	int  restunum()
	{
	return stunum;}//返回学生数

	studentname *refirst()
	{return first;}//返回根节点
	void findstudent(stunode *p);//根据课程查找选择这门课程的学生

	
	
	void clrstudentnum()//从文件读出后将学生数清零
	{stunum=0;}

};

//链表
struct subnode
{
	subject sub;
	subnode *next;
};


//学生端函数
//查找是否已有所选课程
int student::findcourse (char no[])
{
	course *p=root;
	if(root==NULL)
		return 0;
	p=p->next ;
	while(p)
	{
		if(strcmp(p->cno ,no)==0)
			return 1;
		p=p->next ;
	}
	return 0;
}
//学生增选一门课程
void student::addcourse(char no[])
{
	course *s=new course;
	s->next =NULL;
	if(root==NULL)
		root=s;
	course *p=root;
	course *newcourse=new course;
	newcourse->next =p->next ;
	p->next =newcourse;

	strcpy(newcourse->cno,no);
	coursenum++;
}
//学生选课
int menu11(stunode *p,subnode *x)
{	
	system("cls");
	cout<<"学生选课操作."<<endl;
	stunode *q=p->next;
	int i;
	char N[20],M[20];
	if(q!=NULL)
		cout<<"所有学生名单如下:\n"<<endl;
	else
	{	cerr<<"对不起,暂无学生名单,请先创建。"<<endl;
		return 1; 
	}
	while(q)//输出全部学生名单
	{	q->stu.getname(N);
		cout<<N;
		cout<<endl;
		q = q->next ; 
	}
	q = p->next;
	if(q==NULL)
		return 1;
	cout<<" 请输入学生姓名:";
	cin>>N;
	i=0;
	q=p->next;
	while(q)
	{	q->stu.getname(M);
		if(strcmp(N,M)==0)
			i++;
		q = q->next;
	}
	int j=0,k=1;
	if(i==0)
	{	cout<<"没有这个学生。"<<endl;
		return 1; 
	}

	else if(i>1)//处理重名的学生
	{	cout<<"共找到"<<i<<"个姓名为"<<N<<"的学生"<<endl;
		cout<<"选择第几个:";
		cin>>k; 
	}
	if(k>i||k<=0)
	{	cerr<<"输入有误。"<<endl;
		return 1; 
	}





	q = p->next;
	j=0;
	while(q)
	{	q->stu.getname(M);
		if(strcmp(N,M)==0)
			j++;
		if(j==k)
		{	
			if(1)
			{
				subnode *t=x->next;
				char N1[20];
  				char O1[20];
				int c1=0;
				system("cls");;
				if(t!=NULL)
				{	cout<<"所有课程如下:"<<endl;
					cout<<"课程名称\t\t 课程编号\t\t学分"<<endl; 
				}
				else
				{	cout<<"对不起,暂时没有课程。"<<endl;
					return 1; 
				}
				while(t)
				{	t->sub.getname(N1);
					t->sub.getno(O1);
				
					
					cout<<N1<<setw(26-strlen(N1))<<O1<<"\t\t"<<t->sub .getcre ()<<endl;
					t = t->next ; 
				}
				char N2[20];
				cout<<"输入你所要选的课程编号: ";
				cin>>N2;
				t = x->next;
				while(t)
				{	t->sub.getno(N1);
					if(strcmp(N1,N2)==0)
					{	if(q->stu.findcourse(N2)==1)
						{	cout<<"此课程你已选过了,不能再选."<<endl;
							return 1; 
						}
						t=x->next;
						char NA[20];
						while(t)
						{	t->sub.getno(NA);
							if(strcmp(NA,N2)==0)
							{	if(t->sub.restunum()>=100)//100个学生为上限
								{	cout<<"此课程已选满,不能选.按任意键继续"<<endl;
									return 1; 
								}
							}
							t = t->next; 
						}
						
						q->stu.addcourse(N2);
						cout<<"选课成功。"<<endl;
						return 1; 
					}
					t = t->next; 
				}
				cout<<"\n\t\t没有此课程!按任意键继续"<<endl;
			}
			return 1; 
		}
		q = q->next; 
	}
	return 1; 
}



//已选课程

int menu12(subnode *p)
{
	subnode *q=p->next;
	char a[20],b[20];
	
	system("cls");
	if (q!=NULL)
	{
		cout<<"所有选课情况："<<endl;
		cout<<"课程名称\t\t\t选课人数\n"<<endl;
	}
	else 
	{
		cout<<"错误！"<<endl;
		return 1;
	}
	while (q)
	{
		q->sub.getname(a);

		cout<<a<<setw(24-strlen(a))<<q->sub .restunum ()<<endl;
		q=q->next ;
	}
	q=p->next;
	cout<<"请输入课程名称：";
	cin>>b;
	while(q)
	{
		q->sub.getname(a);
		studentname *k=q->sub.refirst ();///////////////////////////////////////
		if(k!=NULL)
			k=k->next ;
		if(strcmp(a,b)==0)
		{
			system("cls");;
			if(k==NULL)
			{
				cout<<"无任何选课信息。"<<endl;
				return 1;
			}
			cout<<"选修课程情况如下："<<endl;
			while(k)
			{
				cout<<k->tname <<setw(20-strlen(k->tname ))<<endl;
				k=k->next ;
			}
				cout<<"press anykey to continue."<<endl;
				return 1;
		}
			q=q->next ;
	}

	cout<<"无此课程。press any key to continue."<<endl;

	return 1;
}




//保存数据
int save(stunode *y,subnode *p)
{
	stunode *z=y->next;
	subnode *x=p->next;
	fstream file("subject.txt",ios::out);
	while(x)
	{
		file.write ((char*)&(x->sub),sizeof(x->sub ));
		x=x->next ;
	}
	file.close ();
	fstream file1("student.txt",ios::out);
	fstream file2("course.txt",ios::out);
	while(z)
	{
		file1.write((char*)&(z->stu ),sizeof(z->stu ));
		int time=z->stu .recoursenum ();
		course *co=z->stu .reroot (),*co1;
		if(co!=NULL)
			co1=co->next ;
		while(time)
		{
			file2.write((char*)(co1),sizeof(*co1));
			co1=co1->next ;
			time=time-1;
		}
		z=z->next ;
	}
	file1.close();
	file2.close();
	cout<<"数据已保存."<<endl;
	return 1;
}
int quit()
{
	cout<<"感谢使用本系统。再见。"<<endl;

	exit(-1);
}

//学生端退出
int quitstu(stunode *x,subnode *p)
{
	save(x,p);
	quit();
	return 0;
}

//课程函数
//寻找选某课程的学生
void subject::findstudent (stunode *p)
{
	studentname *newnode=new studentname;
	newnode->next =NULL;
	first=newnode;
	studentname *t=first;
	stunode *k=p->next;
	while(k)
	{
	
		course *y=k->stu .reroot ();
		if(y==NULL)
		{
			k=k->next ;
			continue;
		}
		if(y!=NULL)
			y=y->next ;
		while(y)
		{
			if(strcmp(y->cname ,subName)==0)
			{
				studentname *acode=new studentname;
				char name[20];
				k->stu .getname (name);
				strcpy(acode->tname ,name);
				acode->next =t->next ;
				t->next =acode;
				stunum = stunum + 1;
				break;
			}
			y=y->next ;
		}
		k=k->next ;
	}
	return ;
}



//管理员端函数


//添加课程
int menu22(subnode *p)
{	char name[10],no[10],no2[10];
	int m;
	system("cls");;
	cout<<"添加课程操作。"<<endl;
	cout<<"输入课程编号:"<<endl;
	cin>>no;
	cout<<endl;
	subnode *q=p->next ;
	while(q)
	{
		q->sub .getno (no2);
		if(strcmp(no,no2)==0)
		{
			cout<<"此课程已存在。press anykey to continue."<<endl;
		
		return 1;
		}
		q=q->next ;
	}

	cout<<"输入课程名称："<<endl;
	cin>>name;

	cout<<"输入课程学分:"<<endl;
	cin>>m;
	
	subnode *newnode=new subnode;
	newnode->next=p->next;
	newnode->sub.setname(name);
	newnode->sub.setno(no);
	newnode->sub.setcre(m);
	p->next=newnode;
	cout<<name<<"课程已添加。"<<endl;
	return 1;
}
//增加学生

int menu21(stunode *p)
{
	char a[20];
	system("cls");;
	cout<<"add a student."<<endl;
	cout<<"input the name:";
	cin>>a;
	cout<<endl<<"已添加。"<<endl;
	stunode *newnode=new stunode;
	newnode->next =p->next ;
	newnode->stu .readname (a);
	p->next =newnode;

	return 1;
}


//删除&查找按照编号
int  menu24(subnode*p)
{	
	subnode *q=p->next;
	char no[10];
	char name[20];
	system("cls");;
	cout<<"删除课程。"<<endl;
	if(q!=NULL)
		cout<<"所有课程："<<endl;
	else
	{
		cout<<"没有课程。press anykey to continue."<<endl;
		getch();
		return 1;
	}
	while(q)//输出全部课程信息
	{
		q->sub.getno(no);
		
		q->sub .getname(name);
		cout<<no<<"\t\t\t"<<name<<endl;
		q=q->next;
	}
	q=p->next;
	subnode *r=p;
	if(q==NULL)
		return 1;
	char no2[10];
	
	cout<<"输入要删除课程的编号:"<<endl;
	cin>>no2;
	while(q)
	{
		q->sub.getno(no);
		if(strcmp(no,no2)==0)
		{
			r->next=q->next;
			delete(q);
			cout<<"已删除。press anykey to continue."<<endl;
			getch();
			return 1;
		}
		q=q->next;
		r=r->next;
	}
	cout<<"找不到要删除的课程。"<<endl;
	return 1;
}
//显示所有学生

//选课情况

//菜单
char menu()
{
	int k=0;
	char a[3],c,i;
	system("cls");
	cout<<endl<<endl;
	cout<<"                                         \n"
		<<"              学生选修课系统             \n"
		<<"                                         \n"
		<<"                                         \n"
		<<"     操作方式:                           \n"
		<<"               1.学生                    \n"
		<<"               2.管理员                  \n"
		<<"                                         \n"
		<<"                                         \n"<<endl;


	while(1)
	{
		cout<<"选择操作方式："<<endl;
		cin>>a;
		if(strlen(a)==1)
		{	for(i='1';i<='2';i++)
			{	c=i;
				if(c==a[0])
					return c; 
			}
		}
		cerr<<"输入有误!\n"<<endl;
	
		
	}
}
char menustu()
{	
	char a[10];char b;char i;int k = 0;
	system("cls");;
	cout<<"\n\n\n"
	
		<<"            选修课系统学生端             \n"
		<<"                                         \n"
		<<"                 操作方式:.              \n"
		<<"                1、 学生选课             \n"
		<<"                2、 已选课程             \n"
		<<"                3、 保存退出             \n"
		<<"                                         \n"
		<<"注：必须保存后结果才可更新。"<<endl;

	while(1)
	{	cout<<"请选择操作方式: ";
		cin>>a;
		if(strlen(a)==1)
		{	for(i='1';i<='3';i++)
			{	b=i;
				if(b==a[0]) return b; 
			}
		}
		cerr<<"输入有误!\n"<<endl;
	
	}
}
char menuadmin()
{	char a[10];char b;char i;int k = 0;system("cls");;
	cout<<"\n\n\n"
	
		<<"                                              \n"
		<<"                 选修课系统管理端             \n"
		<<"                                              \n"
		<<"    操作方式:                                 \n"
		<<"            1.增加学生     2.增加课程         \n"
		<<"            3.保存退出     4.删除课程         \n"
		<<"                                              \n"
		<<"                                              \n"
		<<"                                              \n"<<endl;

	while(1)
	{	cout<<" 请选择操作方式: ";
		cin>>a;
		if(strlen(a)==1)
		{	for(i='0';i<='7';i++)
			{	b=i;
				if(b==a[0])
					return b; }
		}
		cerr<<"输入有误!\n"<<endl;;
	
	}
}
  
//void password()?????






int quitadmin(stunode *x,subnode*p)
{
	save(x,p);
	quit();
	return 0;
}







int main()
{
	
	subnode *p=new subnode,*q=p;
	p->next=NULL;
	subject m;
	fstream file("subject.txt",ios::in);
	while(1)
	{
		file.read ((char*)&m,sizeof(m));
		if(!file) break;
		q->next=new subnode;
		q->next->next=NULL;
		q->next->sub=m;
		q=q->next;
	}
	file.close();
	stunode *y=new stunode,*x=y;
	y->next =NULL;
	student n;
	course o;
	fstream file1("student.txt",ios::in);
	fstream file2("course.txt",ios::in);
	while(1)
	{
		file1.read((char*)&n,sizeof(n));
		if (!file1) break;
		y->next =new stunode;
		y->next ->next=NULL;
		y->next ->stu =n;
		int time=n.recoursenum ();
		y->next ->stu .clrroot ();
		while(time)
		{
			file2.read((char*)&o,sizeof(course));
			if(!file2) break;
			y->next ->stu .addcourse (o.cno );
			time--;
		}
		y=y->next ;
	}
	file2.close();
	file1.close();
	q=p->next;
	while(q)
	{
		q->sub .clrstudentnum ();
		q->sub .findstudent (x);
		q=q->next ;
	}
	char c; char b;
	int br=1;b=menu();
	if (b=='1')
	{
		while(1)
		{
			c=menustu();
			switch(c)
			{
			case'1':br=menu11(x,p);getch();break;
			case'2':br=menu12(p);getch();break;
			case'3':br=quitstu(x,p);break;
			}
		if(br==0) break;
		}
	}
	if(b=='2')
	{
		while(1)
		{
			c=menuadmin();
			switch(c)
			{
			 case '1':br = menu21(x);getch();break;  
			 case '2':br = menu22(p);getch();break;  
			 case '3':br = quitadmin(x,p);getch();  break; 
			 case '4':br = menu24(p);        break;

			}
			if(br==0) break;
		}
		
	}
	return 0;
}
	











