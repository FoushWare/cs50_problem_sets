#include<stdio.h>// to print output 
#include<cs50.h> // to use GetString 
#include<ctype.h> // to use isalph / isupper /islower 
#include<string.h> // to use strlen

int main(int argc,string argv[])
{

if(argc!=2){
printf("enter the right arg\n");
return 1;}

int key=atoi(argv[1]);  // handle the key
 

string s=GetString();

int length=strlen(s);
for(int i=0;i<length;i++) // access to each element into the string 
{
if(isalpha(s[i])){

 
// upper case  alphabitic value 
 if(isupper(s[i])){
// ascii value                          // check if the character is here in range of upper (65 to 90) if not find it's position from 0 to 25 then we have
int result=(s[i]+key)%26 ;                 // the the position referenced for the A=65   when we add 65 to the position we get the right position of the shifted character
if(isupper(result)){
   
printf("%c",result); } 

else{
int replace= (s[i]-65+key)%26 ;
replace=replace+65;
if (isupper(replace))
printf("%c",replace);
}}

// lower case  alphabitic value
 if(islower(s[i]))
{
// ascii value 
int result=(s[i]+key)%26 ;
if(islower(result)){
   
printf("%c",result); } 
else{
int replace= (s[i]-97+key)%26 ;
replace=replace+97;
if (islower(replace))
printf("%c",replace);
} }}
// if the input is a special character
else
printf("%c",s[i]);


}
 printf("\n");

}         