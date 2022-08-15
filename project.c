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
#include<time.h>
struct scrabble                           
{                                         
	char arr[100];                        
}s1,s2,s2_1,s4,s5,s6,s7,s8,s9;            /* s1 is for letters of the bag AND s2 is letters of the word*/
int score(int,struct scrabble,struct scrabble);
int bag();
int not_space();
void get_word();
int milestone_2(int);
void check(int);
int search(int);
int print_words();
int search_dic();
void final_score(int,int);
void milestone_3(int,int,int);
int select_size_pool(int);
void pool(int); 
int best_score(int);
int create_new_wordfile();
	int l=0,s,start=0,end=0;                             
	FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5;                            
int main()                               
{
	char choice,choice_1;
	int i,j,a=0,c=0,k,made=0,e=0,h=0,t=0,ans,r,words;
	r=bag();  // r is no of asterisks in the bag
	get_word();
	clock_t time1,time2,time3;
	double time;
	time1=clock();
	strcpy(s2_1.arr,s2.arr);
		for(i=0;i<strlen(s1.arr);i++)
		{	
			if(s1.arr[i]!=42)
			{
			   for(j=0;j<strlen(s2.arr);j++)
			        {
		        	    if(s1.arr[i]==s2.arr[j])                     /*for word check*/
			         	    {
			         	    	s2.arr[j]=32;
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
l=search_dic();         // to search for the word in the dictionary provided
     		if(l!=1)
     			{
     				printf("\nWord not Found in Dictionary");
     				printf("\nWord is not valid");
     			}
      ans=score(r,s2_1,s2_1);        /* Calculating the score of the given word*/
      printf("\nThe score of the word  is %d",ans);
/*DATE OF SUBMISSION-18/03/2020
Details of Milestone 2: In this milestone all the words possible from the given bag of letters will be displayed on the screen */
words=milestone_2(r);      //the variable words is the number of words in the ansfile.txt
time1=clock()-time1;
printf("\n\t\t\t\t\t\t\t\t\t\t\tDo u want to continue with milestone 2?");
scanf("%c",&choice);
time2=clock();
if(choice=='y')
	made=print_words();	   // diplays the words that can be made from the given bag of letters and are present in the dictionary
                           //made =1 implies now word possible
/* DATE OF SUBMISSION-19/04/2020
Details of Milestone 3: In this milestone the word with the best score according to the programmer will be displayed on the screen*/
// NOTE: The time taken to take the input has been deducted from the overall time to find the time the program took to find the result
time2=clock()-time2;
printf("\n\t\t\t\t\t\t\t\t\t\t\tDo u want to continue with milestone 3?\t");
scanf("\t%c",&choice_1);
time3=clock();
if(choice_1=='y')
    { 
		milestone_3(r,words,made);
		time3=clock()-time3;
		time=((double)(time1+time2+time3))/CLOCKS_PER_SEC;
		printf("\n\n\t\t\t\t\t\t\tTime taken to do the overall process of finding the word with the best score is: %f seconds",time);
	}
printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t    THE END");
}
int bag()                   //function to take bag of letters as input
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
void get_word()                                     // function to take word as input from the user
{
	int n=0;
printf("Enter word : ");
	gets(s2.arr);
	while(s2.arr[n]!='\0')
	{
		s2.arr[n]=toupper(s2.arr[n]);                 /* for uppercase of letters of word*/
		n++;
	}
}
void check(int made)           // function to check whether the word can be made from the given letters or not
{
 if(made==0)
     	{
     		printf("\nCannot made from the given bag of letters");
     		printf("\nWord is not valid");
     	}
}
int search_dic()           // function to search the dictionary for the word
{
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
     		return l;
}
int score(int b,struct scrabble s5,struct scrabble s2_1)              /* Calculating the score of the given word*/
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
    	{
    		count+=s5.arr[i]-'0';
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
int milestone_2(int r)
{
 remove("subfile.txt");    //for deleting previous saved file
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
remove("subsubfile.txt");                    //for deleting previous saved file
fp1=fopen("subfile.txt","r");   
fp2=fopen("subsubfile.txt","a");             //a subset of subfile.txt with words starting with the letters in the bag
while(!feof(fp1))
{
	fscanf(fp1,"%s",s6.arr);
    for(i=0;i<strlen(s1.arr);i++)
    {
    	if(s1.arr[i]==42)
    	{
    		if(s6.arr[0]=='A' || s6.arr[0]=='E' || s6.arr[0]=='I' || s6.arr[0]=='O' || s6.arr[0]=='U')
    		{
    			fprintf(fp2,"%s\n",s6.arr);
    			break;
    		}
    	}
    	else if(s6.arr[0]==s1.arr[i])
    		{
    			fprintf(fp2,"%s\n",s6.arr);
    			break;
    		}
    }
}
fclose(fp1);
fclose(fp2);
return search(r);           // this is returning the number of words in the file ansfile.txt

}
int not_space()            // function to calculate no of non-space characters(this includes all asterisks and alphabets)
{
	int not_s=0,n;
	for(n=0;n<strlen(s1.arr);n++)
    	{
    		if(s1.arr[n]!=32)
    		not_s=not_s +1;
        }
    return not_s;
}
int search(int a)          //function which creates the final text file which will contain words that can be made from the given bag of letters
{
	int i,c,j,k=0,length,len,num=0;
 remove("ansfile.txt");
 fp2=fopen("subsubfile.txt","r");
 fp3=fopen("ansfile.txt","a");
 while(!feof(fp2))
 {
 	c=0;
 	k=0;
 	strcpy(s5.arr,s1.arr);          //s5.arr conatins the bag of letters
 	fscanf(fp2,"%s",s6.arr);       //s6.arr contains word from the subsubfile.txt
 	strcpy(s4.arr,s6.arr);
 	length=strlen(s6.arr);
 	len=strlen(s5.arr);
 	 	for(i=0;i<length;i++)
 		   {
 		   	for(j=0;j<len;j++)
 			{
 				if(s6.arr[i]==s5.arr[j])
 					{
 					  s5.arr[j]=32;
 					  s6.arr[i]=32;      //assigning a space at the checked position
 					  c=c+1;             // c is number of letters matched
 					  if(c==length)      //all letters matched
 					    {
 					    	num=num+1;
 					    	if(num==1)
 					    		fprintf(fp3,"%s",s4.arr);          // this condition is added because in text file an extra line was adding at the last creating a print of the last word two times
 					    	else
 					    		fprintf(fp3,"\n%s",s4.arr);
 						    i=length;    //for getting totally out of the loops
 						    break;
 					    }
 					    break;	
 					}
 		    }
 		}
 	for(i=0;i<length;i++)
 	      if(s6.arr[i]=='A' || s6.arr[i]=='E' || s6.arr[i]=='I' || s6.arr[i]=='O' || s6.arr[i]=='U')
 	      	k=k+1;  // k is number of vowels left after previous check
 	if(k<=a && (k+c)==length && k!=0)
 		{
 			num=num+1;
 			if(num==1)
 				fprintf(fp3,"%s",s4.arr);
 		    else
 		    	fprintf(fp3,"\n%s",s4.arr);
 		}
 }
 fclose(fp2);
 fclose(fp3);
 return num;                   //num is the number of words in the file ansfile.txt
}
int print_words()            // a function of milestone 2 to print all the words from the final text file of words possible to make from the given bag of letters
{
	int c=1;
	fp3=fopen("ansfile.txt","r");
			while(!feof(fp3))
			{
		        fscanf(fp3,"%s",s7.arr);
		        if(s7.arr[0]==0)
		          	printf("\nNo word can be made from the given bag of letters");
		        else
		        	{
		        		c=c+1;
		        		if(c==2)
		        			printf("\nThe words possible from the given bag of letters are:\n");
		        		printf("\t%d) %s\n",c-1,s7.arr);
		        	}
			}
	fclose(fp3);
	return c;    // this value of c is just to tell whether the word has been made or not for milestone 3
}
void milestone_3(int b,int words,int made)
{
	int s;
	int word,size,line=0;
	if(made==1)
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tNo word can be made");
	else
	{
		size=select_size_pool(words);
		pool(size);
		s=best_score(b);
		words=create_new_wordfile();
		if(words!=0)
			final_score(b,s);
	}
}
int select_size_pool(int words)  // this function is made to select a random size for the pool to be made
{
	int word,length,line=0;
	word=1+(rand()%words);     // variable word is the number of the word randomly selected
	fp3=fopen("ansfile.txt","r");
	while(!feof(fp3))
	{
		fscanf(fp3,"%s",s7.arr);
		line=line+1;
		if(line==word)
		   	{
		   		length=strlen(s7.arr);
	     		break;
	     	}
	}
	fclose(fp3);
	return length;
}
void pool(int size)                                   // function to create a pool of words from the final text file(ansfile.txt) of a fixed length
{
	int num=0,a=0;
	remove("pool.txt");
	fp3=fopen("ansfile.txt","r");
	fp4=fopen("pool.txt","w");
	while(!feof(fp3))
	{
		fscanf(fp3,"%s",s4.arr);
		if(strlen(s4.arr)==size)
			{
				num=num+1;
				if(a==0)
					fprintf(fp4,"%s",s4.arr);
				else
					fprintf(fp4,"\n%s",s4.arr);
				a=a+1;
			}
		else if(strlen(s4.arr)<size)
		    {
			    if(num==0)
				start=start+1;    // after this position the word starts for the pool
		    }
		else
			break;
	}
	fclose(fp3);
	fclose(fp4);
	end=start+num;   //this is the last word for the pool
	start=start+1;   //now start is the first word of the pool
}
void final_score(int b,int s)
{
	int a;
	fp3=fopen("new_wordfile.txt","r");
	while(!feof(fp3))
	{
		fscanf(fp3,"%s",s8.arr);
		a=score(b,s8,s8);
		if(a>s)
			{
				s=a;
				strcpy(s9.arr,s8.arr);
			}
	}
	fclose(fp3);
	printf("\n\n\t\t\t\t\t\t  \t\t\t\t\tThe best score word is: %s with a score of: %d",s9.arr,s);
}
int create_new_wordfile()
{
	int b=0,a=0;   // to tell the text file that it is the first word(to rectify an error occuring due to an extra empty line with \n)
	remove("new_wordfile.txt");
	fp2=fopen("new_wordfile.txt","w");
	fp3=fopen("ansfile.txt","r");
	while(!feof(fp3))
	{
		fscanf(fp3,"%s",s7.arr);
		a=a+1;
		if(a==1 && start==1)
			b=0;
		else if(start!=1)
			{
				if(a==1)
					{
						fprintf(fp2,"%s",s7.arr);
					}
				else
					fprintf(fp2,"\n%s",s7.arr);
				start=start-1;
				b=b+1;
			}
		else if(a>end)
		{
			if(b==0)
				fprintf(fp2,"%s",s7.arr);
			else
			    fprintf(fp2,"\n%s",s7.arr);
			b=b+1;			
		}
	}
	fclose(fp2);
	fclose(fp3);
	return b;     // a return of number of words in the new word file
}
int best_score(int b)               // a function for milestone 3 which finds the best score word from the file pool.txt
{
	int s=-9999,a;
	fp4=fopen("pool.txt","r");
	while(!feof(fp4))
	{
		fscanf(fp4,"%s",s8.arr);
		 		a=score(b,s8,s8);
		 		if(a>=s)
		 			{
		 				s=a;
		 				strcpy(s9.arr,s8.arr);
		 			}		
	}
	if(s9.arr[0]==0)
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tNo word can be made");
	else 
		printf("\n\n\t\t\t\t\t\t      \t\t\t\t\tThe word is: %s with a score of: %d",s9.arr,s);
	return s;
}
