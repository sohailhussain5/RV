#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 500
int t[MAX];
void shifttable(char p[]) {
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}
int horspool(char st[],char p[]) {
	int i,j,k,m,n;
	n=strlen(st);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\n Length of pattern=%d",m);
	i=m-1;
	while(i<n) {
		k=0;
		while((k<m)&&(p[m-1-k]==st[i-k]))
		   k++;
		if(k==m)
		   return(i-m+1); else
		   i+=t[st[i]];
	}
	return -1;
}
int main() {
	char st[100],p[100];
	int shift[100];
	int pos;
	struct timeval e,s;
	int time,n,time1;
	FILE *f;
	f=fopen("a.txt","a");
	printf("Enter the text in which pattern is to be searched=\n");
	gets(st);
	n=strlen(st);
	printf("Enter the pattern for best case=\n");
	gets(p);
	gettimeofday(&st,0);
	shifttable(p,shift);
	pos=horspool(st,p,shift);
	gettimeofday(&e,0);
	time=e.tv_usec-s.tv_usec;

	if(pos== -1)
	  printf("\n The pattern was not found in the given text\n");
	else
	  printf("\n found at %d \n",pos+1); 
	printf("Time taken is %d",time);
	
	printf("Enter the pattern for worst case=\n");
	gets(p);
	gettimeofday(&st,0);
	shifttable(p,shift);
	pos=horspool(st,p,shift);
	gettimeofday(&e,0);
	time1=e.tv_usec-s.tv_usec;

	if(pos== -1)
	  printf("\n The pattern was not found in the given text\n");
	else
	  printf("\n found at %d \n",pos+1); 
	printf("Time taken is %d",time1);
	fprintf(f,"%d\t%d\t%d\n",n,time,time1);

	return 0;
}