#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//初始化通讯录
void InitContact(struct Contact* pc)
{
	pc->sz = 0;  //归零，表示通讯录里没有人
	pc->Data = (struct PeoInfo*)malloc(CONTACT_MAX * sizeof(struct PeoInfo));
	pc->ContactMax = CONTACT_MAX;  //最开始的最大容量
}

//添加联系人信息
void AddPeople(struct Contact* pc)
{
	struct PeoInfo temp = { 0 };     //用来临时存放单个人的信息

	if (pc->sz == pc->ContactMax)
	{
		//增容
		struct PeoInfo* ret = realloc(pc->Data,             //内存增容函数
			(pc->ContactMax + 2) * sizeof(struct PeoInfo));
		if (ret == NULL)
		{
			printf("增容失败！\n");
			return;
		}
		else
		{
			pc->Data = ret;          //将开辟的内存的地址真正存放到Data指针中去
			pc->ContactMax += 2;     //更改下容量
			printf("增容成功！\n");
		}
	}
	printf("请输入姓名：");
	scanf("%s", temp.name);
	printf("请输入性别：");
	scanf("%s", temp.sex);
	printf("请输入年龄：");
	scanf("%d", &temp.age);
	printf("请输入电话号码：");
	scanf("%s", temp.number);
	printf("请输入地址：");
	scanf("%s", temp.address);

	pc->Data[pc->sz] = temp;      //把这个人的信息真正存放到通讯录中
	pc->sz++;                     //总人数加1
	printf("添加成功!\n");
}

//删除联系人信息
void DelPeople(struct Contact* pc)
{
	if (pc->sz == 0)           //判断通讯录是否为空
	{
		printf("通讯录为空，删除失败！\n");
	}
	else
	{
		char name[NAME_MAX] = { 0 };      //临时存放要删除的联系人名字

		printf("请输入要删除联系人的名字：");
		scanf("%s", name);
		//查找该联系人
		int ret = FindPeople(pc, name);   //自定义查找联系人函数，找到返回下标，否则返回 -1
		if (ret == -1)
		{
			printf("该联系人不存在！\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < pc->sz - 1; j++)    //从查找的联系人开始，把后面的联系人整体向前移动一位
			{
				pc->Data[j] = pc->Data[j + 1];    //把该联系人的信息给覆盖掉
			}
			pc->sz--;                             //当前联系人数量减一
			printf("删除成功！\n");
		}
	}
}

//查找联系人
int FindPeople(struct Contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
		//当前通讯录有多少联系人就遍历多少次，直到找到所需要的那个
	{
		if (strcmp(pc->Data[i].name, name) == 0)
			//用字符串比较函数，在判断是不是我想查找的那个联系人
		{
			return i;     //找到了，返回下标
		}
	}
	return -1;     //没找到，返回 -1
}

//显示通信录里的联系人
void Display(struct Contact* pc)
{
	printf("%10s\t%2s\t%4s\t%8s\t%10s\n\n",
		"name", "sex", "age", "number", "address");
	int i = 0;
	for (i = 0; i < pc->sz; i++) //当前有多少联系人，就循环多少次
	{
		printf("%10s\t%2s\t%4d\t%8s\t%10s\n",
			pc->Data[i].name, pc->Data[i].sex, pc->Data[i].age,
			pc->Data[i].number, pc->Data[i].address);
	}
}

//查找联系人并打印其信息
void SearchPeople(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };     //临时存放需要查询的联系人的名字
	if (pc->sz == 0)        //判断通讯录是否为空
	{
		printf("通讯录为空，查询失败！\n");
	}
	else
	{
		printf("请输入联系人的名字：");
		scanf("%s", name);
		int ret = FindPeople(pc, name);  //查找该联系人
		if (ret == -1)
		{
			printf("该联系人不存在！\n");
		}
		else
		{
			//打印该联系人的具体信息
			printf("%10s\t%2s\t%4s\t%8s\t%10s\n\n",
				"name", "sex", "age", "number", "address");
			printf("%10s\t%2s\t%4d\t%8s\t%10s\n",
				pc->Data[ret].name, pc->Data[ret].sex, pc->Data[ret].age,
				pc->Data[ret].number, pc->Data[ret].address);
		}
	}
}

//修改指定联系人信息
void ModPeople(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)      //先判断是不是空的通讯录
	{
		printf("通讯录为空，修改失败！\n");
	}
	else
	{
		printf("请输入需要修改的联系人名字：");
		scanf("%s", name);
		int ret = FindPeople(pc, name);    //查找该联系人，并返回其下标
		if (ret == -1)
		{
			printf("该联系人不存在！\n");
		}
		else
		{
			//和添加联系人信息一样，创建一个临时变量，用来存放我要输入的信息
			struct PeoInfo temp = { 0 };

			//逐条输入
			printf("请输入新的名字：");
			scanf("%s", temp.name);
			printf("请输入新的性别：");
			scanf("%s", temp.sex);
			printf("请输入新的年龄：");
			scanf("%d", &temp.age);
			printf("请输入新的电话：");
			scanf("%s", temp.number);
			printf("请输入新的地址：");
			scanf("%s", temp.address);

			//覆盖掉原来联系人的信息
			pc->Data[ret] = temp;

			//提示一下
			printf("修改成功！\n");
		}
	}
}

//按名字升序排通讯录
int name_sort(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

//以名字排序通讯录 - 升序
void NameSort(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，排序失败！\n");
	}
	else
	{
		//使用qsort快速排序
		qsort(pc->Data, pc->sz, sizeof(struct PeoInfo), name_sort);
		printf("排序成功！(升序)！\n");
	}
}

//清空所有联系人
void ClsContact(struct Contact* pc)
{
	if (pc->sz == 0)   //判断通讯录里有没有联系人
	{
		printf("没有联系人，清除失败！\n");
	}
	else
	{
		//直接初始化通讯录
		InitContact(pc);
		printf("清除成功！\n");
	}
}

//销毁通讯录
void FreeContact(struct Contact* pc)
{
	free(pc->Data);
	pc->Data = NULL;   //释放之后，要置为空指针
	pc->ContactMax = 0;
	pc->sz = 0;
}