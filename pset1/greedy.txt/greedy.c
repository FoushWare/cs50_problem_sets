#include<stdio.h>
#include<cs50.h>
#include<math.h>
 
int main(void)
{
float money;
int counter=0;
int change_owed;
 
do
{
printf("please,enter your money int dollar:");
 money = GetFloat(); 
if( money <=0){
printf("please enter a positive number");}
 
}while(money <=0);
float c= money*100;
 
 change_owed =roundf(c);
 
 
while(change_owed >=25)
 {
 change_owed-=25;
 counter++;
 }
 while(change_owed >= 10)
 {
 change_owed-=10;
 counter++;
  }
  while(change_owed >=5)
   {
 change_owed-=5;
 counter++;
   }
 while(change_owed >=1)
   {
 change_owed-=1;
 counter++;
   }
   printf("%d\n",counter);
 }