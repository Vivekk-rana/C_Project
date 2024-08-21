#include<stdio.h>
#include<windows.h>
int main()
{
system("cls"); 
   
system("color 0B");
int a = 177,b=219;
printf("\t\t");
for(int i=1;i<=80;i++){
  printf("%c",a);

}
printf("\r");
printf("\t\t");
for(int i=1;i<=80;i++){
    printf("%c",b);
    Sleep(20);
}







return 0;
}