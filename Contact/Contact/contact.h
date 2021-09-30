#pragma once

#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#define CONTACT_MAX 3    //�ʼͨѶ¼������

#define NAME_MAX  20     //������ֵĳ���
#define SEX_MAX   5      //�Ա���󳤶�
#define NUMBER_MAX 20    //�绰��󳤶�
#define ADDRESS_MAX 20   //��ַ��󳤶�

//���ÿһ���˵ľ�����Ϣ
struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char number[NUMBER_MAX];
	char address[ADDRESS_MAX];
};

//ͨѶ¼
struct Contact
{
	struct PeoInfo* Data;     //����ָ��̬���ٵ��ǿ��ڴ�ռ�
	int sz;    //��¼��ǰͨѶ¼�ﻹ�ж�����
	int ContactMax;  //ͨѶ¼��ǰ�������
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//�����ϵ����Ϣ
void AddPeople(struct Contact* pc);

//ɾ����ϵ����Ϣ
void DelPeople(struct Contact* pc);

//��ʾͨѶ¼
void Display(struct Contact* pc);

//������ϵ��
int FindPeople(struct Contact* pc, char* name);

//������ϵ�˲���ӡ����Ϣ
void SearchPeople(struct Contact* pc);

//�޸�ָ����ϵ����Ϣ
void ModPeople(struct Contact* pc);

//����������ͨѶ¼ - ����
void NameSort(struct Contact* pc);

//���������ϵ��
void ClsContact(struct Contact* pc);

//����ͨѶ¼
void FreeContact(struct Contact* pc);

//д����ϵ�˵���Ϣ���ļ���ȥ
void SveContact(struct Contact* pc);  

//����ͨѶ¼��Ϣ
void LoadContact(struct Contact* pc);

//���ݺ���
void CapacityContact(struct Contact* pc);