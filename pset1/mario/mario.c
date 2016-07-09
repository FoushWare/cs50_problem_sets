#include<stdio.h>
#include<cs50.h>
 
int main(void)
{ // set a boundary
int h ;
do{

printf("enter the height of the half pyramids in boundary that not exceed 25\n");

h =GetInt();// to get the  height of the pyramid 
}while(h<0 || h>23);
int x=h;

if(h>=0 && h<=23){
for(int j=0;j<x;j++)
  { 
  for(int k=1;k<h;k++) // to print the blanks
  
              printf(" ");
       for(int i=0;i<j+2;i++)// to print the block of # 
       printf("#");
       
       printf("\n");
       h=h-1;
        
          
    }}}