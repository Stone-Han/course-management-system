#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
using namespace std;

//ѧ������
struct  studentname
{

	char tname[20];
	studentname *next;

};
//ѧ��ѡ�ογ�
class course 
{
public:
	char cname[20];
	char cno[10];
	course *next;
};
//ѧ����
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

//ѧ������
class  stunode
{
public:
	student stu;
	stunode *next;
};

//�γ���
class subject
{
private:
	char subNO[10];
	char subName[10];
	int credit;
	studentname *first; //ѧ������
	int stunum;//ѡ��ѧ����

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
	int  getcre()//�õ��γ̵�ѧ��
	{
	return credit;
	}
	int  restunum()
	{
	return stunum;}//����ѧ����

	studentname *refirst()
	{return first;}//���ظ��ڵ�
	void findstudent(stunode *p);//���ݿγ̲���ѡ�����ſγ̵�ѧ��

	
	
	void clrstudentnum()//���ļ�������ѧ��������
	{stunum=0;}

};

//����
struct subnode
{
	subject sub;
	subnode *next;
};


//ѧ���˺���
//�����Ƿ�������ѡ�γ�
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
//ѧ����ѡһ�ſγ�
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
//ѧ��ѡ��
int menu11(stunode *p,subnode *x)
{	
	system("cls");
	cout<<"ѧ��ѡ�β���."<<endl;
	stunode *q=p->next;
	int i;
	char N[20],M[20];
	if(q!=NULL)
		cout<<"����ѧ����������:\n"<<endl;
	else
	{	cerr<<"�Բ���,����ѧ������,���ȴ�����"<<endl;
		return 1; 
	}
	while(q)//���ȫ��ѧ������
	{	q->stu.getname(N);
		cout<<N;
		cout<<endl;
		q = q->next ; 
	}
	q = p->next;
	if(q==NULL)
		return 1;
	cout<<" ������ѧ������:";
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
	{	cout<<"û�����ѧ����"<<endl;
		return 1; 
	}

	else if(i>1)//����������ѧ��
	{	cout<<"���ҵ�"<<i<<"������Ϊ"<<N<<"��ѧ��"<<endl;
		cout<<"ѡ��ڼ���:";
		cin>>k; 
	}
	if(k>i||k<=0)
	{	cerr<<"��������"<<endl;
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
				{	cout<<"���пγ�����:"<<endl;
					cout<<"�γ�����\t\t �γ̱��\t\tѧ��"<<endl; 
				}
				else
				{	cout<<"�Բ���,��ʱû�пγ̡�"<<endl;
					return 1; 
				}
				while(t)
				{	t->sub.getname(N1);
					t->sub.getno(O1);
				
					
					cout<<N1<<setw(26-strlen(N1))<<O1<<"\t\t"<<t->sub .getcre ()<<endl;
					t = t->next ; 
				}
				char N2[20];
				cout<<"��������Ҫѡ�Ŀγ̱��: ";
				cin>>N2;
				t = x->next;
				while(t)
				{	t->sub.getno(N1);
					if(strcmp(N1,N2)==0)
					{	if(q->stu.findcourse(N2)==1)
						{	cout<<"�˿γ�����ѡ����,������ѡ."<<endl;
							return 1; 
						}
						t=x->next;
						char NA[20];
						while(t)
						{	t->sub.getno(NA);
							if(strcmp(NA,N2)==0)
							{	if(t->sub.restunum()>=100)//100��ѧ��Ϊ����
								{	cout<<"�˿γ���ѡ��,����ѡ.�����������"<<endl;
									return 1; 
								}
							}
							t = t->next; 
						}
						
						q->stu.addcourse(N2);
						cout<<"ѡ�γɹ���"<<endl;
						return 1; 
					}
					t = t->next; 
				}
				cout<<"\n\t\tû�д˿γ�!�����������"<<endl;
			}
			return 1; 
		}
		q = q->next; 
	}
	return 1; 
}



//��ѡ�γ�

int menu12(subnode *p)
{
	subnode *q=p->next;
	char a[20],b[20];
	
	system("cls");
	if (q!=NULL)
	{
		cout<<"����ѡ�������"<<endl;
		cout<<"�γ�����\t\t\tѡ������\n"<<endl;
	}
	else 
	{
		cout<<"����"<<endl;
		return 1;
	}
	while (q)
	{
		q->sub.getname(a);

		cout<<a<<setw(24-strlen(a))<<q->sub .restunum ()<<endl;
		q=q->next ;
	}
	q=p->next;
	cout<<"������γ����ƣ�";
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
				cout<<"���κ�ѡ����Ϣ��"<<endl;
				return 1;
			}
			cout<<"ѡ�޿γ�������£�"<<endl;
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

	cout<<"�޴˿γ̡�press any key to continue."<<endl;

	return 1;
}




//��������
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
	cout<<"�����ѱ���."<<endl;
	return 1;
}
int quit()
{
	cout<<"��лʹ�ñ�ϵͳ���ټ���"<<endl;

	exit(-1);
}

//ѧ�����˳�
int quitstu(stunode *x,subnode *p)
{
	save(x,p);
	quit();
	return 0;
}

//�γ̺���
//Ѱ��ѡĳ�γ̵�ѧ��
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



//����Ա�˺���


//��ӿγ�
int menu22(subnode *p)
{	char name[10],no[10],no2[10];
	int m;
	system("cls");;
	cout<<"��ӿγ̲�����"<<endl;
	cout<<"����γ̱��:"<<endl;
	cin>>no;
	cout<<endl;
	subnode *q=p->next ;
	while(q)
	{
		q->sub .getno (no2);
		if(strcmp(no,no2)==0)
		{
			cout<<"�˿γ��Ѵ��ڡ�press anykey to continue."<<endl;
		
		return 1;
		}
		q=q->next ;
	}

	cout<<"����γ����ƣ�"<<endl;
	cin>>name;

	cout<<"����γ�ѧ��:"<<endl;
	cin>>m;
	
	subnode *newnode=new subnode;
	newnode->next=p->next;
	newnode->sub.setname(name);
	newnode->sub.setno(no);
	newnode->sub.setcre(m);
	p->next=newnode;
	cout<<name<<"�γ�����ӡ�"<<endl;
	return 1;
}
//����ѧ��

int menu21(stunode *p)
{
	char a[20];
	system("cls");;
	cout<<"add a student."<<endl;
	cout<<"input the name:";
	cin>>a;
	cout<<endl<<"����ӡ�"<<endl;
	stunode *newnode=new stunode;
	newnode->next =p->next ;
	newnode->stu .readname (a);
	p->next =newnode;

	return 1;
}


//ɾ��&���Ұ��ձ��
int  menu24(subnode*p)
{	
	subnode *q=p->next;
	char no[10];
	char name[20];
	system("cls");;
	cout<<"ɾ���γ̡�"<<endl;
	if(q!=NULL)
		cout<<"���пγ̣�"<<endl;
	else
	{
		cout<<"û�пγ̡�press anykey to continue."<<endl;
		getch();
		return 1;
	}
	while(q)//���ȫ���γ���Ϣ
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
	
	cout<<"����Ҫɾ���γ̵ı��:"<<endl;
	cin>>no2;
	while(q)
	{
		q->sub.getno(no);
		if(strcmp(no,no2)==0)
		{
			r->next=q->next;
			delete(q);
			cout<<"��ɾ����press anykey to continue."<<endl;
			getch();
			return 1;
		}
		q=q->next;
		r=r->next;
	}
	cout<<"�Ҳ���Ҫɾ���Ŀγ̡�"<<endl;
	return 1;
}
//��ʾ����ѧ��

//ѡ�����

//�˵�
char menu()
{
	int k=0;
	char a[3],c,i;
	system("cls");
	cout<<endl<<endl;
	cout<<"                                         \n"
		<<"              ѧ��ѡ�޿�ϵͳ             \n"
		<<"                                         \n"
		<<"                                         \n"
		<<"     ������ʽ:                           \n"
		<<"               1.ѧ��                    \n"
		<<"               2.����Ա                  \n"
		<<"                                         \n"
		<<"                                         \n"<<endl;


	while(1)
	{
		cout<<"ѡ�������ʽ��"<<endl;
		cin>>a;
		if(strlen(a)==1)
		{	for(i='1';i<='2';i++)
			{	c=i;
				if(c==a[0])
					return c; 
			}
		}
		cerr<<"��������!\n"<<endl;
	
		
	}
}
char menustu()
{	
	char a[10];char b;char i;int k = 0;
	system("cls");;
	cout<<"\n\n\n"
	
		<<"            ѡ�޿�ϵͳѧ����             \n"
		<<"                                         \n"
		<<"                 ������ʽ:.              \n"
		<<"                1�� ѧ��ѡ��             \n"
		<<"                2�� ��ѡ�γ�             \n"
		<<"                3�� �����˳�             \n"
		<<"                                         \n"
		<<"ע�����뱣������ſɸ��¡�"<<endl;

	while(1)
	{	cout<<"��ѡ�������ʽ: ";
		cin>>a;
		if(strlen(a)==1)
		{	for(i='1';i<='3';i++)
			{	b=i;
				if(b==a[0]) return b; 
			}
		}
		cerr<<"��������!\n"<<endl;
	
	}
}
char menuadmin()
{	char a[10];char b;char i;int k = 0;system("cls");;
	cout<<"\n\n\n"
	
		<<"                                              \n"
		<<"                 ѡ�޿�ϵͳ�����             \n"
		<<"                                              \n"
		<<"    ������ʽ:                                 \n"
		<<"            1.����ѧ��     2.���ӿγ�         \n"
		<<"            3.�����˳�     4.ɾ���γ�         \n"
		<<"                                              \n"
		<<"                                              \n"
		<<"                                              \n"<<endl;

	while(1)
	{	cout<<" ��ѡ�������ʽ: ";
		cin>>a;
		if(strlen(a)==1)
		{	for(i='0';i<='7';i++)
			{	b=i;
				if(b==a[0])
					return b; }
		}
		cerr<<"��������!\n"<<endl;;
	
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
	











