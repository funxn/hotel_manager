#include"const.h"
#include"type.h"
#include"global.h"
#include"proto.h"
#include<stdio.h>
#include<malloc.h>

#define TimeFactor

CUSTOMER getCustomerFromUI();						// 来自于QT构造的窗口环境里面的传回来的结构体

void addNode(LNode head){						// 考虑将addNode()函数交给QTGui按下按钮时调用
	LNode p = malloc(sizeof(Node));
	p->customer=getCustomerFromUI();
	p->next = head->next;
	head->next = p;

	checkIn();							// 在此处调用checkIn()对客户进行注册
}

int main(){
	LNode head = malloc(sizeof(Node));




	check_out("22222");

	return 0;
}


void getMouseLoc(){}
void getScanCode(){}
int* getTime(){}
