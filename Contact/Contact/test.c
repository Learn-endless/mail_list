#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//通讯录面板
void menu()
{
	printf("************************************\n");
	printf("******    0.exit     1.add    ******\n");
	printf("******    2.del      3.search ******\n");
	printf("******    4.modify   5.dis    ******\n");
	printf("******    6.cls      7.sort   ******\n");
	printf("************************************\n");
}

//用来存放对通讯录的操作
enum board
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	DIS,
	CLS,
	SORT
};

int main()
{
	int input = 0;      //接收选项
	//创建一个通讯录
	struct Contact con = { 0 };
	//初始化通讯录
	InitContact(&con);
	do
	{
		//打印个面板
		menu();
		printf("请输入选项》");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			SveContact(&con);   //写入联系人的信息到文件中去
			FreeContact(&con);  //释放空间
			printf("退出通讯录！\n");
			break;
		case ADD:               //添加联系人
			AddPeople(&con);
			break;
		case DEL:               //删除联系人
			DelPeople(&con);
			break;
		case SEARCH:            //查询联系人
			SearchPeople(&con);
			break;
		case MODIFY:            //修改联系人
			ModPeople(&con);
			break;
		case DIS:               //显示通讯录
			Display(&con);
			break;
		case CLS:               //清空联系人
			ClsContact(&con);
			break;
		case SORT:              //给联系人按名字排升序
			NameSort(&con);
			break;
		default:
			printf("选项错误，重新选择！\n");
			break;
		}
	} while (input);

	return 0;
}
