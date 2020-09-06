/*学生成绩管理系统*/
/*基础功能:根据学号录入学生信息，可按学生学号、数学成绩、物理成绩由升序排序、中途插入学生信息，中途删除学生信息*/

#include<stdio.h>
#include<stdlib.h>

#define LEN sizeof(struct Student)

//定义结构体
struct Student
{
	long num;
	float score[3];
	struct Student *next;
};

int n;
float sum;

//菜单
void meun()
{
	printf("\n\n");
	printf("|---------------------功能菜单----------------------|\n");
	printf("|------------------1:输入学生信息.------------------|\n");
	printf("|------------------2:输出学生信息.------------------|\n");
	printf("|------------------3:按学号升序排序.----------------|\n");
	printf("|------------------4:按数学成绩升序排序.------------|\n");
	printf("|------------------5:按物理成绩升序排序.------------|\n");
	printf("|------------------6:按总分升序排序.----------------|\n");
	printf("|------------------7:插入学生信息.------------------|\n");
	printf("|------------------8:删除学生信息.------------------|\n");
	printf("|------------------0:退出管理系统.------------------|\n");
}

//建立链表
struct Student *creat(void)
{
	struct Student *head;
	struct Student *p1,*p2;
	n=0;
	sum=0;
	p1=p2=(struct Student *)malloc(LEN);
	printf("学号:\n数学成绩:\n物理成绩:\n");
	scanf("%ld\n%f\n%f",&p1->num,&p1->score[0],&p1->score[1]);
	p1->score[2]=(p1->score[0] + p1->score[1]);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Student *)malloc(LEN);
	    printf("学号:\n数学成绩:\n物理成绩:\n");
		scanf("%ld\n%f\n%f",&p1->num,&p1->score[0],&p1->score[1]);
		p1->score[2]=(p1->score[0] + p1->score[1]);
	}
	p2->next=NULL;
	return(head);
}

//输出函数
void print(struct Student *head)
{
	struct Student *p;
	printf("\n他们的成绩是:\n");
    if(head!=NULL);
	p=head;
    do
	{
	    printf("学号:%5ld数学成绩:%7.1f物理成绩:%7.1f总分:%7.1f\n",p->num,p->score[0],p->score[1],p->score[2]);
	    p=p->next;
	}while(p!=NULL);
}

//按学号排序
void choice_num(struct Student *head)
{
	struct Student *p,*min,*now;
	int minnum;
	float score[3];
	p=head;
	while(p != NULL)
	{
		now = p;
		min = p;
		min->num = p->num;
		while(now != NULL)
		{
			if(now->num < min->num)
			{
				min = now;
			}
			now = now->next;
		}

		minnum = min->num;
		min->num = p->num;
		p->num = minnum;
		printf("学号:%5d",p->num);

		score[0] = min->score[0];
		min->score[0] = p->score[0];
		p->score[0] = score[0];
		printf("数学:%7.1f",p->score[0]);

		score[1] = min->score[1];
		min->score[1] = p->score[1];
		p->score[1] = score[1];
		printf("物理:%7.1f",p->score[1]);

		score[2] = min->score[2];
		min->score[2] = p->score[2];
		p->score[2] = score[2];
		printf("总分:%7.1f\n",p->score[2]);
		
		p=p->next;
	}
}

//按数学成绩排序
void choice_math(struct Student *head)
{
	struct Student *p,*min,*now;
	int minnum;
	float score[3];
	p=head;
	while(p != NULL)
	{
		now = p;
		min = p;
		min->score[0] = p->score[0];
		while(now != NULL)
		{
			if(now->score[0] < min->score[0])
			{
				min = now;
			}
			now = now->next;
		}
		
		minnum = min->num;
		min->num = p->num;
		p->num = minnum;
		printf("学号:%5d",p->num);

		score[0] = min->score[0];
		min->score[0] = p->score[0];
		p->score[0] = score[0];
		printf("数学:%7.1f",p->score[0]);

		score[1] = min->score[1];
		min->score[1] = p->score[1];
		p->score[1] = score[1];
		printf("物理:%7.1f",p->score[1]);

		score[2] = min->score[2];
		min->score[2] = p->score[2];
		p->score[2] = score[2];
		printf("总分:%7.1f\n",p->score[2]);

		p=p->next;
	}
}

//按总分成绩排序
void choice_sum(struct Student *head)
{
	struct Student *p,*min,*now;
	int minnum;
	float score[3];
	p=head;
	while(p != NULL)
	{
		now = p;
		min = p;
		min->score[2] = p->score[2];
		while(now != NULL)
		{
			if(now->score[2] < min->score[2])
			{
				min = now;
			}
			now = now->next;
		}
		
		minnum = min->num;
		min->num = p->num;
		p->num = minnum;
		printf("学号:%5d",p->num);

		score[0] = min->score[0];
		min->score[0] = p->score[0];
		p->score[0] = score[0];
		printf("数学:%7.1f",p->score[0]);

		score[1] = min->score[1];
		min->score[1] = p->score[1];
		p->score[1] = score[1];
		printf("物理:%7.1f",p->score[1]);

		score[2] = min->score[2];
		min->score[2] = p->score[2];
		p->score[2] = score[2];
		printf("总分:%7.1f\n",p->score[2]);

		p=p->next;
	}
}

//按物理成绩排序
void choice_physics(struct Student *head)
{
	struct Student *p,*min,*now;
	int minnum;
	float score[3];
	p=head;
	while(p != NULL)
	{
		now = p;
		min = p;
		min->score[1] = p->score[1];
		while(now != NULL)
		{
			if(now->score[1] < min->score[1])
			{
				min = now;
			}
			now = now->next;
		}
		
		minnum = min->num;
		min->num = p->num;
		p->num = minnum;
		printf("学号:%5d",p->num);

		score[0] = min->score[0];
		min->score[0] = p->score[0];
		p->score[0] = score[0];
		printf("数学:%7.1f",p->score[0]);

		score[1] = min->score[1];
		min->score[1] = p->score[1];
		p->score[1] = score[1];
		printf("物理:%7.1f",p->score[1]);

		score[2] = min->score[2];
		min->score[2] = p->score[2];
		p->score[2] = score[2];
		printf("总分:%7.1f\n",p->score[2]);

		p=p->next;
	}
}

//插入学生信息函数
void add(struct Student *head)
{
	struct Student *p1,*p2;         //p1 p2 为临时操作指针
	int i;
	n=0;

	p2=head;
	p1=(struct Student *)malloc(LEN);

	printf("学号:\n数学成绩:\n物理成绩:\n");
	scanf("%ld\n%f\n%f",&p1->num,&p1->score[0],&p1->score[1]);
	p1->score[2]=(p1->score[0] + p1->score[1]);

   	printf("请输入需要插入的位置:\n");
    scanf("%d",&i);

   	if(i > 0)
	{
	    while(i > 1)
		{
	    	p2 = p2->next;
	        i--;
		}
	       	p1->next = p2->next;
	    	p2->next = p1;
	}
	else if(i == 0)
	{
	    head = p1;
	    p1->next = p2;
	}
}

//删除学生信息函数
void reduce(struct Student *head)
{
	struct Student *p;
	struct Student *p1;
	int i;

	p=head;
	printf("请输入你要删除的学生的节点:\n");
	scanf("%d",&i);

	if(i > 0)
	{
		while(i > 1)
		{
			p = p->next;
			i--;
		}
		p1 = p->next;
		if(p1->next != NULL)
		{
			p->next = p1->next;
		}
		else
		{
			printf("不存在这个学生!\n");
			printf("请重新输入:\n");
		}
	}
	else if(i == 0)
	{
		p = p->next;
	}
}

int main(struct Student *head)
{
	struct Student *pt;
	int i;
	do
	{
		meun();
	    scanf("%d",&i);
		switch(i)
		{
		case 0:break;
		case 1:system("CLS");pt=creat();break;
		case 2:system("CLS");print(pt);break;
		case 3:system("CLS");choice_num(pt);break;
		case 4:system("CLS");choice_math(pt);break;
		case 5:system("CLS");choice_physics(pt);break;
		case 6:system("CLS");choice_sum(pt);break;
		case 7:system("CLS");add(pt);break;
		case 8:system("CLS");reduce(pt);break;
		default :printf("输入错误!请重新输入!\n");
		}
	}while(i != 0);
	printf("按任意键退出.\n");
}





