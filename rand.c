#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
   srand(time(0));
   printf("%d", 171*rand());
   return 0;
}