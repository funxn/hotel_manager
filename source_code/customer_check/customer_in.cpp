#include<stdio.h>
#include<stdlib.h>
#include"const.h"
#include"type.h"
#include"global.h"
#include"proto.h"

extern int itemNum1;
extern int itemNum2;

int check_in(CUSTOMER temp){
	FILE *fp1,*fp2;
	int j;

	printf("%d %d\n", itemNum1, itemNum2);

	if((fp1=fopen("files/ALL_CUSTOMER.txt","at")) == NULL){
		printf("ALL_CUSTOMER.txt OPEN ERROE!");
		return 0;
	}// 打开CHECKIN.txt文件

	if((fp2=fopen("files/CURRENT_CUSTOMER.txt","at")) == NULL){
		printf("CURRENT_CUSTOMER.txt OPEN ERROR!");
		return 0;
	}// 打开CHECKOUT.txt文件
    
	fprintf(fp1,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
	for(j=0;j<6;j++){
		fprintf(fp1," %d",temp.roomDate[j]);
    }
	fprintf(fp1," %s %s %s",temp.id,temp.company,temp.city);

 	fprintf(fp2,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
	for(j=0;j<6;j++)
		fprintf(fp2," %d",temp.roomDate[j]);
	fprintf(fp2," %s %s %s",temp.id,temp.company,temp.city);

	for(j=0;j<FEES_SIZE;j++){
		fprintf(fp1," %d %f",temp.fees[j].feeType,temp.fees[j].feeValue);
		fprintf(fp2," %d %f",temp.fees[j].feeType,temp.fees[j].feeValue);
		if(j==FEES_SIZE-1){
		   fprintf(fp1,"\n");
		   fprintf(fp2,"\n");
        }
	}
    
	itemNum1++;
	itemNum2++;
	
    fclose(fp1);
	fclose(fp2);
	return 1;

}
