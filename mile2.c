/*DSA PROJECT
GROUP NUMBER- 62
  19UCS009-SHUBHAM AGRAWAL
  19UCS209-AYUSH AGRAWAL
  19UME063-ADITYA ALOK BHARDWAJ
  19UME066-UTKARSH AGRAWAL
  19UME075-RISHABH BINDAL
DATE OF SUBMISSION-15/02/2020
DETAILS OF MILESTONE 1- In this milestone a bag of letters and a word is entered and is checked if the word is made from the bag of letters.Further the word is matched with the words of the dictionary.If matched the word is valid otherwise invalid.
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
struct scrabble                           /* s1 is for letters of the bag*/
{                                         /* s2 is letters of the word*/
	char arr[100];                        /* s2_1 is copy of letters of s2*/
}s1,s2,s2_1,s4,s5,s6;                     /* s4 is word from the Dictionary*/
int score(int,struct scrabble );
int bag();
int not_space();
void get_word();
void milestone_2();
void check(int);
void search();
void print_words();
                          
	int l=0,s;                                    /*s is number of non_spaces in bag of letters*/    
	FILE *fp,*fp1,*fp2,*fp3;                      /*l defined globally is for whether word is made or not*/
int main()                               
{
	int i,j,a=0,c=0,k,made=0,e=0,h=0,t=0,ans,asy,r;
	r=bag();  // r is no of letters in the bag
	get_word();
	strcpy(s2_1.arr,s2.arr);
		for(i=0;i<strlen(s1.arr);i++)
		{	if(s1.arr[i]!=42)
			{
			for(j=0;j<strlen(s2.arr);j++)
			    {
		        	if(s1.arr[i]==s2.arr[j])                     /*for word check*/
			         	{
			         		s2.arr[j]=32;                           /*a is number of spaces*/
			         	    a+=1;
			         	    break;
			         	}
			    }
			}
			    if(a==strlen(s2.arr))
			       {
			       	printf("\nWord made from the given bag of letters");    /* d is 1 when word is made from the given letters*/
			       	k=1;
			       	made=1;
			       	break;
			       }
	    }
	    if(k!=1 && r!=0)
{
	for(i=0;i<strlen(s2.arr);i++)
		{
			if(s2.arr[i]=='A' || s2.arr[i]=='E' || s2.arr[i]=='I' || s2.arr[i]=='O' || s2.arr[i]=='U')
			    {
			    	c=c+1;                                             /* checking for the cases of asterisk as vowels*/
			    	s2.arr[i]=32;
			    }
		}
		for(i=0;i<strlen(s2.arr);i++)
			{
				if(r>=c && s2.arr[i]==32)
                { 
                	e=e+1;
                 	if(e==strlen(s2.arr))
                  {
                  	printf("\nWord made from the given bag of letters");
                    made=1;
                  }
                }
            }
 }
 check(made);            //to check whether word is made or not
fp=fopen("dic.txt","r");               /* Opening of file*/
     	while(!feof(fp))
     		{
     			fscanf(fp,"%s",s4.arr);
     			if(strcmp(s2_1.arr,s4.arr)==0)
     			         {
     			         	printf("\nWord Found in Dictionary");
     			         	printf("\nWord is valid");
     			         	l=1;
     			         	break;
     			         }     		
     		}
     		fclose(fp);
     		if(l!=1)
     			{
     				printf("\nWord not Found in Dictionary");
     				printf("\nWord is not valid");
     				//exit(0);
     			}
ans=score(r,s2_1);        /* Calculating the score of the given word*/
printf("\nThe score of the word  is %d",ans);
milestone_2();                                  /*here starts the milestone 2. this function makes the subfile and the subsubfile*/
search();                                       /*this function makes the final subset of the subsubfile and inspects it for word made*/
print_words();                                  /*this function prints the words fromm the ans file*/
}




void milestone_2()
{
 remove("subfile.txt");    //for deleting previous saved file
 
 remove("subsubfile.txt");  //for deleting previous saved file
	int i;
	s=not_space();
fp1=fopen("subfile.txt","w");               //file containing words with size equal and less than the bag of letters
 fp=fopen("dic.txt","r");             
    while(!feof(fp))
    {
    	fscanf(fp,"%s",s4.arr);
    	if(strlen(s4.arr)<=s)
    	   {
    	   	fprintf(fp1,"%s\n",s4.arr);
    	   }
    	else 
    		break;
    }
fclose(fp);
fclose(fp1);
fp1=fopen("subfile.txt","r");   
fp2=fopen("subsubfile.txt","a");             //a subset of subfile.txt with words starting with the letters in the bag
while(!feof(fp1))
{
	fscanf(fp1,"%s",s6.arr);
    for(i=0;i<strlen(s1.arr);i++)
    {
    	if(s6.arr[0]==s1.arr[i])
    		{
    			fprintf(fp2,"%s\n",s6.arr);
    	break;
    }
    }
}
fclose(fp1);
fclose(fp2);
}
int score(int b,struct scrabble s5)              /* Calculating the score of the given word*/
{
	int i,count=0,n=0,weight,s=0,bad,good,score,mult;
for(i=0;i<strlen(s5.arr);i++)
	{
	if(s5.arr[i]=='D' || s5.arr[i]=='G')
		s5.arr[i]='2';
	if(s5.arr[i]=='B' || s5.arr[i]=='C' || s5.arr[i]=='M' || s5.arr[i]=='P')
		s5.arr[i]='3';
	if(s5.arr[i]=='K')
		s5.arr[i]='5';                                                                              /*for assigning score of the given letter*/
	if(s5.arr[i]=='F' || s5.arr[i]=='H' || s5.arr[i]=='V' || s5.arr[i]=='W' || s5.arr[i]=='Y')
		s5.arr[i]='4';
	if(s5.arr[i]=='J' || s5.arr[i]=='K')
		s5.arr[i]='8';
	if(s5.arr[i]=='Q' || s5.arr[i]=='Z')
		{
			s5.arr[i]='9';
			n=n+1;
		}
	if(s5.arr[i]=='E' || s5.arr[i]=='A' || s5.arr[i]=='I' || s5.arr[i]=='O' || s5.arr[i]=='N' || s5.arr[i]=='R' || s5.arr[i]=='T' || s5.arr[i]=='L' || s5.arr[i]=='S' || s5.arr[i]=='U')
		s5.arr[i]='1';
    }
    for(i=0;i<strlen(s5.arr);i++)
    	{count+=s5.arr[i]-'0';
    	}
    weight=count-b+n;
    s=not_space();
good=(s-1)*strlen(s2_1.arr);
if(3 * (s + 1 - strlen(s2_1.arr))>1)
    bad=3 * (s + 1 - strlen(s2_1.arr));
else
	bad=1;
mult=good-bad;
score=weight*mult; 
return score;    	
}
int not_space()
{
	int not_s=0,n;
	for(n=0;n<strlen(s1.arr);n++)
    	{
    		if(s1.arr[n]!=32)
    		not_s=not_s +1;
        }
    return not_s;
}
int bag()
{
	int i,b=0,h;
	printf("enter bag of letters : ");
	gets(s1.arr);
		for(i=0;i<strlen(s1.arr);i++)
		{
			if(s1.arr[i]>=65 && s1.arr[i]<=90)
			        s1.arr[i]+=0;
	     	else if(s1.arr[i]>=97 && s1.arr[i]<=122)                       /*for upper case of letters and invalid characters*/
			        s1.arr[i]-=32;
	    	else if(s1.arr[i]==42)
	    	{
	    		s1.arr[i]+=0;
	    		b=b+1;                                        /* b is number of asterisks in bag of letters*/
	    	}
	    	else if(s1.arr[i]==32)
	    	      s1.arr[i]+=0;
	    	else
	    		{
	    			printf("Invalid letters");
	    	     h=1;
	    	     assert(h==1);                               /* used assert if the entered bag of letters contain inavlid charcater*/
	    	     exit(0);
	    	    }
	    	}
	    	return b;
}

void get_word()
{
	int n=0;
printf("Enter word : ");
	gets(s2.arr);
	while(s2.arr[n]!='\0')
	{
		s2.arr[n]=toupper(s2.arr[n]);                           /* for uppercase of letters of word*/
		n++;
	}
}
void check(int made)
{
 if(made==0)
     	{
     		printf("\nCannot made from the given bag of letters");
     		printf("\nWord is not valid");
     	}
}
void search()
{
	int i,c,j;
 remove("ansfile.txt");
 fp2=fopen("subsubfile.txt","r");
 fp3=fopen("ansfile.txt","a");
 while(!feof(fp2))
 {
 	c=0;
 	strcpy(s5.arr,s1.arr);          //s5.arr conatins the bag of letters
 	fscanf(fp2,"%s",s6.arr);       //s6.arr contains word from the subsubfile.txt
 	for(i=0;i<strlen(s6.arr);i++)
 		for(j=0;j<strlen(s5.arr);j++)
 			{
 				if(s6.arr[i]==s5.arr[j])
 			{
 				s5.arr[j]=32;
 				c=c+1;
 				if(c==strlen(s6.arr))
 					{
 						i=strlen(s6.arr);
 						fprintf(fp3,"%s\n",s6.arr);
 					}
 					break;
 			}
 		}
 }
 fclose(fp2);
 fclose(fp3);
}
void print_words()
{
	printf("\nThe words possible from the given bag of letters are:\n");
	fp3=fopen("ansfile.txt","r");
	while(!feof(fp3))
	{
		fscanf(fp3,"%s",s6.arr);
		puts(s6.arr);
	}
	fclose(fp3);
}
