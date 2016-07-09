/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
 // the libraries to use in this programme
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include <stdint.h>
 FILE*jpeGout;
 
int main(int argc, char* argv[])
{
   
    //check if there is no  command argument  (it is restricted)
    if(argc!=1)
    {
        printf("USAGE: ./recover\n");
        return 1;
    }
    //makeing variables
    int opened=0;
    int jpeGcounter=0;
   
//open the memory card file
FILE* cf=fopen("card.raw","r");
if(cf==NULL)
{
    printf("there is an error of openning the cord.raw ");
}
unsigned char data[512];                                                                        
                                                                                                                                   
//read 512 bytes at a time from record file                                                                                        

while(fread(&data,512,1,cf)>0)
{ // i am still in the file
    if(data[0]==0xff && data[1]==0xd8 && data[2]==0xff && (data[3]==0xe0||data[3]==0xe1)) //is that is jpeG
    {
         char imgname[8];
            sprintf(imgname,"%03d.jpg",jpeGcounter);
        if(opened==0)
        {
           
             jpeGout=fopen(imgname,"w");
             if(jpeGout==NULL)
             {
                 printf("can't open the file of the image");
             }
        fwrite(data,512,1,jpeGout);
        opened=1;
       }
    if(opened==1)
    {
       
        fclose(jpeGout);
       
            jpeGout=fopen(imgname,"w");
        fwrite(data,512,1,jpeGout);
        jpeGcounter++;
       
    }
   
  }
  else
  {
 
     
        if(opened==1){
         fwrite(data,512,1,jpeGout);
     }
  }
 
}


fclose(cf);
fclose(jpeGout);
 

 
 return 0;
 
}