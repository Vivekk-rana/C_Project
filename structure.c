#include<stdio.h>
int main()
{
     struct student
     {
        char *name;
        int age;
        float marks;
        int height;
     };
     
struct student s2;
s2.name = "apurb";
s2.age = 23;
s2.marks = 56.89;
s2.height=175;
printf("%s\n %d \n %f\n %d",s2.name,s2.age,s2.marks,s2.height);



     










return 0;
}