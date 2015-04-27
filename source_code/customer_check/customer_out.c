#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"const.h"
#include"type.h"

int check_out(char *id){
	FILE *fp1,*fp2;
	CUSTOMER temp;
	int i;

	if((fp1=fopen("files/CHECKOUT.txt","r"))==NULL){
		printf("CHECKOUT.txt OPEN ERROR!");
		return false;
	}

	if((fp2=fopen("files/TEMP_FILE.txt","wt+"))==NULL){
		printf("TEMP_FILE.txt build ERROR!");
		return false;
	}

	while(feof(fp1)!=1){
		fscanf(fp1,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp1," %d", &temp.roomDate[i]);
		fscanf(fp1," %s %s %s %d %f %d %f %d %f %d %f %d %f",temp.id,temp.company,temp.city,&temp.fees[0].feeType,&temp.fees[0].feeValue,&temp.fees[1].feeType,&temp.fees[1].feeValue,&temp.fees[2].feeType,&temp.fees[2].feeValue,&temp.fees[3].feeType,&temp.fees[3].feeValue,&temp.fees[4].feeType,&temp.fees[4].feeValue);
		
		if(strcmp(temp.id,id)!=0){
				fprintf(fp2,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		        for(i=0;i<6;i++)
			         fprintf(fp2," %d",temp.roomDate[i]);
		        fprintf(fp2," %s %s %s %d %f %d %f %d %f %d %f %d %f",temp.id,temp.company,temp.city,temp.fees[0].feeType,temp.fees[0].feeValue,temp.fees[1].feeType,temp.fees[1].feeValue,temp.fees[2].feeType,temp.fees[2].feeValue,temp.fees[3].feeType,temp.fees[3].feeValue,temp.fees[4].feeType,temp.fees[4].feeValue);
		}
	}

	fclose(fp1);
	if((fp1=fopen("files/CHECKOUT.txt","w"))==NULL){
		printf("CHECKOUT.txt CLEAR¡¡FAIL!");
		return false;
	}

	while(feof(fp2)!=1){
		fscanf(fp2,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp2," %d",&temp.roomDate[i]);
		fscanf(fp2," %s %s %s %d %f %d %f %d %f %d %f %d %f",temp.id,temp.company,temp.city,&temp.fees[0].feeType,&temp.fees[0].feeValue,&temp.fees[1].feeType,&temp.fees[1].feeValue,&temp.fees[2].feeType,&temp.fees[2].feeValue,&temp.fees[3].feeType,&temp.fees[3].feeValue,&temp.fees[4].feeType,&temp.fees[4].feeValue);
		
		fprintf(fp1,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		for(i=0;i<6;i++)
			fprintf(fp1," %d",temp.roomDate[i]);
		fprintf(fp1," %s %s %s %d %f %d %f %d %f %d %f %d %f\n",temp.id,temp.company,temp.city,temp.fees[0].feeType,temp.fees[0].feeValue,temp.fees[1].feeType,temp.fees[1].feeValue,temp.fees[2].feeType,temp.fees[2].feeValue,temp.fees[3].feeType,temp.fees[3].feeValue,temp.fees[4].feeType,temp.fees[4].feeValue);	
	}

	fclose(fp1);
	fclose(fp2); 
	return true;
}

int changeRoom(char * id,int ChangeNum){
	FILE *fp1,*fp2;
	CUSTOMER temp;
	int i;

	if((fp1=fopen("files/CHECKOUT.txt","r"))==NULL){
		printf("CHECKOUT.txt OPEN ERROR!");
		return false;
	}

	if((fp2=fopen("files/TEMP_FILE.txt","wt+"))==NULL){
		printf("TEMP_FILE.txt build ERROR!");
		return false;
	}

	while(feof(fp1)!=1){
		fscanf(fp1,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp1," %d",&temp.roomDate[i]);
		fscanf(fp1," %s %s %s %d %f %d %f %d %f %d %f %d %f",temp.id,temp.company,temp.city,&temp.fees[0].feeType,&temp.fees[0].feeValue,&temp.fees[1].feeType,&temp.fees[1].feeValue,&temp.fees[2].feeType,&temp.fees[2].feeValue,&temp.fees[3].feeType,&temp.fees[3].feeValue,&temp.fees[4].feeType,&temp.fees[4].feeValue);
		
		if(strcmp(temp.id,id)==0){
			temp.roomNumber=ChangeNum;
		}

		fprintf(fp2,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		for(i=0;i<6;i++)
			  fprintf(fp2," %d",temp.roomDate[i]);
		fprintf(fp2," %s %s %s %d %f %d %f %d %f %d %f %d %f",temp.id,temp.company,temp.city,temp.fees[0].feeType,temp.fees[0].feeValue,temp.fees[1].feeType,temp.fees[1].feeValue,temp.fees[2].feeType,temp.fees[2].feeValue,temp.fees[3].feeType,temp.fees[3].feeValue,temp.fees[4].feeType,temp.fees[4].feeValue);
	}

	fclose(fp1);
	if((fp1=fopen("files/CHECKOUT.txt","w"))==NULL){
		printf("CHECKOUT.txt CLEAR¡¡FAIL!");
		return false;
	}

	while(feof(fp2)!=1){
		fscanf(fp1,"%s %d %d %d",temp.name,&temp.sex,&temp.age,&temp.roomNumber);
		for(i=0;i<6;i++)
			fscanf(fp2," %d",&temp.roomDate[i]);
		fscanf(fp2," %s %s %s %d %f %d %f %d %f %d %f %d %f",temp.id,temp.company,temp.city,&temp.fees[0].feeType,&temp.fees[0].feeValue,&temp.fees[1].feeType,&temp.fees[1].feeValue,&temp.fees[2].feeType,&temp.fees[2].feeValue,&temp.fees[3].feeType,&temp.fees[3].feeValue,&temp.fees[4].feeType,&temp.fees[4].feeValue);
		
		fprintf(fp1,"%s %d %d %d",temp.name,temp.sex,temp.age,temp.roomNumber);
		for(i=0;i<6;i++)
			fprintf(fp1," %d",temp.roomDate[i]);
		fprintf(fp1," %s %s %s %d %f %d %f %d %f %d %f %d %f\n",temp.id,temp.company,temp.city,temp.fees[0].feeType,temp.fees[0].feeValue,temp.fees[1].feeType,temp.fees[1].feeValue,temp.fees[2].feeType,temp.fees[2].feeValue,temp.fees[3].feeType,temp.fees[3].feeValue,temp.fees[4].feeType,temp.fees[4].feeValue);	
	}

	fclose(fp1);
	fclose(fp2); 
	return true;
}
