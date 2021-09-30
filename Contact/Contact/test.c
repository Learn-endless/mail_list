#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//ͨѶ¼���
void menu()
{
	printf("************************************\n");
	printf("******    0.exit     1.add    ******\n");
	printf("******    2.del      3.search ******\n");
	printf("******    4.modify   5.dis    ******\n");
	printf("******    6.cls      7.sort   ******\n");
	printf("************************************\n");
}

//������Ŷ�ͨѶ¼�Ĳ���
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
	int input = 0;      //����ѡ��
	//����һ��ͨѶ¼
	struct Contact con = { 0 };
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		//��ӡ�����
		menu();
		printf("������ѡ�");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			SveContact(&con);   //д����ϵ�˵���Ϣ���ļ���ȥ
			FreeContact(&con);  //�ͷſռ�
			printf("�˳�ͨѶ¼��\n");
			break;
		case ADD:               //�����ϵ��
			AddPeople(&con);
			break;
		case DEL:               //ɾ����ϵ��
			DelPeople(&con);
			break;
		case SEARCH:            //��ѯ��ϵ��
			SearchPeople(&con);
			break;
		case MODIFY:            //�޸���ϵ��
			ModPeople(&con);
			break;
		case DIS:               //��ʾͨѶ¼
			Display(&con);
			break;
		case CLS:               //�����ϵ��
			ClsContact(&con);
			break;
		case SORT:              //����ϵ�˰�����������
			NameSort(&con);
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}
