/*****************************************************************************************
         initialization 
                                                                                        ***
                                                                                        ***
**********************************************************************************************/                                                                                          






#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
string s=GetString();
int length =strlen(s);



int c;
 c = toupper(s[0]);
printf("%c",c);

for (int i =1;i<=length;i++)
{

if(s[i]== ' ')
{
i++;
 c =toupper(s[i]);
printf("%c",c);
}


}
printf("\n");









}