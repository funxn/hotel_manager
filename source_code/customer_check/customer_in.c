#include<stdio.h>
#include<stdlib.h>
#include"const.h"
#include"type.h"

int check_in(CUSTOMER temp){
	FILE *fp1,*fp2;
	int i,j;

	if((fp1=fopen("files/CHECKIN.txt","at")) == NULL){
		printf("CHECKIN.txt OPEN ERROE!");
		return false;
	}

	if((fp2=fopen("files/CHECKOUT.txt","at")) == NULL){
		printf("CHECKOUT.txt OPEN ERROR!");
		return false;
	}
    
	fprintf(fp1,"\n%s %d %d %d %s",temp.name,temp.sex,temp.age,temp.roomNumber);
	for(j=0;j<6;j++){
		fprintf(fp1," %d",temp.roomDate[j]);
	}
	fprintf(fp1," %s %s %s",temp.id,temp.company,temp.city);

 	fprintf(fp2,"\n%s %d %d %d %s",temp.name,temp.sex,temp.age,temp.roomNumber);
	for(j=0;j<6;j++){
		fprintf(fp2," %d",temp.roomDate[j]);
	}
	fprintf(fp2," %s %s %s",temp.id,temp.company,temp.city);

	for(i=0;i<FEES_SIZE;i++){
		fprintf(fp1," %d %f",temp.fees[i].feeType,temp.fees[i].feeValue);
		fprintf(fp2," %d %f",temp.fees[i].feeType,temp.fees[i].feeValue);
	}

	fclose(fp1);
	fclose(fp2);
	return true;

}
