#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{typedef struct {
     char name[40];
     int salary;
     int pf;
}emply;
     emply e1;
     FILE *fp,*fp1;
     fp = fopen("bankrecord.txt","w");
      char ch = 'y';
      while(ch=='y'){

     printf("Enter the name of employer: ");
     scanf("%s",e1.name);
     printf("Enter the salary and pf: ");
     scanf("%d %d",&e1.salary,&e1.pf);
     fprintf(fp,"%s  %d   %d\n",e1.name,e1.salary,e1.pf);
     fflush(stdin);
      printf("Enter your another record: ");
      ch = getchar();

      }
    fclose(fp);
    char name1[40];
   fp = fopen("bankrecord.txt","r");
   fp1 = fopen("temp.txt","w");
      printf("Enter the name of canidates which you want to upate: ");
      scanf("%s",name1); 
while(fscanf(fp,"%s %d %d",e1.name,&e1.salary,&e1.pf)!=EOF){
            if(strcmp(e1.name,name1)==0){
                printf("Enter the new name: ");
                scanf("%s",e1.name);
                 printf("Enter the new salary and pf: ");
                 scanf("%d %d",&e1.salary,&e1.pf);
           


            }
   fprintf(fp1,"%s   %d   %d\n",e1.name,e1.salary,e1.pf);
}
fclose(fp);
fclose(fp1);
fp = fopen("bankrecord.txt","w");
fp1 = fopen("temp.txt","r");
while(fscanf(fp1,"%s %d %d",e1.name,&e1.salary,&e1.pf)!=EOF){
         fprintf(fp,"%s   %d   %d\n",e1.name,e1.salary,e1.pf);
         printf("%s   %d   %d\n",e1.name,e1.salary,e1.pf);
}
fclose(fp);
fclose(fp1);
int found=0;
fp = fopen("bankrecord.txt","r");
   fp1 = fopen("temp.txt","w");
      printf("Enter the name of canidates which you want to delet: ");
      scanf("%s",name1); 
while(fscanf(fp,"%s %d %d",e1.name,&e1.salary,&e1.pf)!=EOF){
            if(strcmp(e1.name,name1)==0){
               found = 1;                  
               
            }
      if(found==0){      
   fprintf(fp1,"%s   %d   %d\n",e1.name,e1.salary,e1.pf);
      }
      found=0;
}
fclose(fp);
fclose(fp1);
fp = fopen("bankrecord.txt","w");
fp1 = fopen("temp.txt","r");
while(fscanf(fp1,"%s %d %d",e1.name,&e1.salary,&e1.pf)!=EOF){
         fprintf(fp,"%s   %d   %d\n",e1.name,e1.salary,e1.pf);
         printf("%s   %d   %d\n",e1.name,e1.salary,e1.pf);
}
fclose(fp);
fclose(fp1);




       












return 0;
}