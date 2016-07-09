#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
int main(int argc,string argv[])
{
// check if the input from user is correct
//*****************************************************************************************************************************************************
if(argc!=2){
printf("enter the right command arguments !,please\n");
return 1;}
 else if (argv[1])
    {
        int l = strlen(argv[1]);
        for (int i = 0; i < l; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: /pset2/vigenere <key> \n");
                return 1;
            }
        }  
        }
//**********************************************************************************************************************************************************

string p=argv[1];
                    // get the plaintext from the user 
string s =GetString();

                    // get the length of the plaintext 
 
 int length=strlen(s);
                      // get the length of the key 
 int length_key=strlen(p);
 
 // access to each characther character in the plaintext 
 int j,i;
 j=0;
 
 for( i=0;i<length;i++)
 {
 
 
 if(isalpha(s[i])){
 
 
if(isupper(s[i]))
{
if(isupper(p[j%length_key]))
{
int replace=(s[i]- 65+(p[j%length_key]-65))%26 ;
replace=replace +65;
printf("%c",replace);}
else if(islower (p[j%length_key]))
{
int replace=(s[i]- 65+(p[j%length_key]-97))%26 ;
replace=replace +65;
printf("%c",replace);
}
}

// plaintext is lower 
if(islower(s[i]))
{
if(islower(p[j%length_key]))
{
int replace=(s[i]-97 +(p[j%length_key]-97))%26 ;
replace=replace +97;
printf("%c",replace);}
else if(isupper( p[j%length_key]))
{
int replace=(s[i]- 97+(p[j%length_key]-65))%26 ;
replace=replace +97;
printf("%c",replace);
}
} j++; } 

else
{
printf("%c",s[i]);
}
}
printf("\n"); }