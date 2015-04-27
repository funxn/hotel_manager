#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"const.h"
#include"type.h"
//#include"global.h"
#include"proto.h"

extern int itemNum1;
extern int itemNum2;

int decide(char *A,char *B);

int check_out(char *id){ // ��CURRENT_CUSTOMER��id�봫�������id��ͬ�ļ�¼ɾ��

	printf("%d %d\n", itemNum1, itemNum2);
	FILE *fp1,*fp2;
	CUSTOMER temp;
	int i,j=0;
	int sam_size=0;

	if((fp1=fopen("files/CURRENT_CUSTOMER.txt","r"))==NULL){
		printf("CHECKOUT.txt OPEN ERROR!");
		return 0;
	}// ��CHECKOU.txt�ļ�

	if((fp2=fopen("files/TEMP_FILE.txt","wt+"))==NULL){
		printf("TEMP_FILE.txt build ERROR!");
		return 0;
	}// ����ʱ�ļ�

	for(j=0;j<itemNum2;j++){
		fscanf(fp1,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp1," %d",&temp.roomDate[i]);
		fscanf(fp1," %s %s %s",temp.id,temp.company,temp.city);
		for(i=0;i<FEES_SIZE;i++){
			fscanf(fp1," %d %f",&temp.fees[i].feeType,&temp.fees[i].feeValue);
		}// ��ʽ������һ����¼
		
		if(decide(temp.id,id) == 0){
				fprintf(fp2,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		        for(i=0;i<6;i++)
			         fprintf(fp2," %d",temp.roomDate[i]);
				fprintf(fp2," %s %s %s",temp.id,temp.company,temp.city);
				for(i=0;i<FEES_SIZE;i++){
			            fprintf(fp1," %d %f",temp.fees[i].feeType,temp.fees[i].feeValue);
						if(i == FEES_SIZE-1)
							fprintf(fp2,"\n");
				}
		}
		else
		    sam_size++;
	}// ��id��ͬ��ʱ�򽫼�¼��ʽ��д����ʱ�ļ�
    
    itemNum2=itemNum2-sam_size;
    
	fclose(fp1);
	if((fp1=fopen("files/CURRENT_CUSTOMER.txt","w"))==NULL){
		printf("CURRENT_CUSTOMER.txt CLEAR��FAIL!");
		return 0;
	}// ���CHECKOUT.txt�е�����

	for(j=0;j<itemNum2;j++){
		fscanf(fp2,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp2," %d",&temp.roomDate[i]);
		fscanf(fp2," %s %s %s",temp.id,temp.company,temp.city);
		for(i=0;i<FEES_SIZE;i++)
			fscanf(fp2," %d %f",&temp.fees[i].feeType,&temp.fees[i].feeValue);
		// ������ʱ�ļ��е�һ����¼
         
		fprintf(fp1,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		for(i=0;i<6;i++)
			fprintf(fp1," %d",temp.roomDate[i]);
		fprintf(fp1," %s %s %s",temp.id,temp.company,temp.city);
		
		for(i=0;i<FEES_SIZE;i++){
			fprintf(fp1," %d %f",temp.fees[i].feeType,temp.fees[i].feeValue);
			if(i == FEES_SIZE-1)
					fprintf(fp1,"\n");
		}
		//����ʱ�ļ��е����ݿ�����CURRENT_CUSTOMER�� 
	}

	fclose(fp1);
	fclose(fp2); //�ر��ļ�
	return 1;
}

/*
int changRoom(char *name,int roomNumber){
	FILE *fp1,*fp2;
	CUSTOMER temp;
	int i,j=0;
	int sam_size=0;

	if((fp1=fopen("files/CURRENT_CUSTOMER.txt","r"))==NULL){
		printf("CHECKOUT.txt OPEN ERROR!");
		return 0;
	}// ��CHECKOU.txt�ļ�

	if((fp2=fopen("files/TEMP_FILE.txt","wt+"))==NULL){
		printf("TEMP_FILE.txt build ERROR!");
		return 0;
	}// ����ʱ�ļ�

	for(j=0;j<itemNum2;j++){
		fscanf(fp1,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp1," %d",&temp.roomDate[i]);
		fscanf(fp1," %s %s %s",temp.id,temp.company,temp.city);
		for(i=0;i<FEES_SIZE;i++){
			fscanf(fp1," %d %f",&temp.fees[i].feeType,&temp.fees[i].feeValue);
		}// ��ʽ������һ����¼
		
          if(decide(temp.name,name) == 1)
				fprintf(fp2,"%s %d %d %d",temp.name,temp.sex,temp.age,roomNumber);
		  else
                fprintf(fp2,"%s %d %d %d",temp.name,temp.sex,temp.age,roomNumber);
          for(i=0;i<6;i++)
     			    fprintf(fp2," %d",temp.roomDate[i]);
				fprintf(fp2," %s %s %s",temp.id,temp.company,temp.city);
		  for(i=0;i<FEES_SIZE;i++){
			            fprintf(fp1," %d %f",temp.fees[i].feeType,temp.fees[i].feeValue);
                  if(i == FEES_SIZE-1)
                        fprintf(fp2,"\n");
							
		}
		
	}// ��������ͬ��ʱ��roomNumber�ı� 
    
    
	fclose(fp1);
	if((fp1=fopen("files/CURRENT_CUSTOMER.txt","w"))==NULL){
		printf("CURRENT_CUSTOMER.txt CLEAR��FAIL!");
		return 0;
	}// ���CHECKOUT.txt�е�����

	for(j=0;j<itemNum2;j++){
		fscanf(fp2,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp2," %d",&temp.roomDate[i]);
		fscanf(fp2," %s %s %s",temp.id,temp.company,temp.city);
		for(i=0;i<FEES_SIZE;i++)
			fscanf(fp2," %d %f",&temp.fees[i].feeType,&temp.fees[i].feeValue);
		// ������ʱ�ļ��е�һ����¼
         
		fprintf(fp1,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		for(i=0;i<6;i++)
			fprintf(fp1," %d",temp.roomDate[i]);
		fprintf(fp1," %s %s %s",temp.id,temp.company,temp.city);
		
		for(i=0;i<FEES_SIZE;i++){
			fprintf(fp1," %d %f",temp.fees[i].feeType,temp.fees[i].feeValue);
			if(i == FEES_SIZE-1)
					fprintf(fp1,"\n");
		}
		//����ʱ�ļ��е����ݿ�����CURRENT_CUSTOMER�� 
	}

	fclose(fp1);
	fclose(fp2); //�ر��ļ�
	return 1;
}
*/
int decide(char *A,char *B){
    int i;
    for(i=0;i<ID_SIZE;i++)
         if(A[i]!=B[i])
               return 0;
    return 1;
}

