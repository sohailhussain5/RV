#include<stdio.h>
#include<string.h>
#include<sys/time.h>
char t[500], p[500];
int brute(char t[], char p[])
{
	int i, j, m, n;
	n=strlen(t);
	m=strlen(p);
	for(i=0;i<n;i++)
	{
		j=0;
		while(j<m&&p[j]==t[i+j])
		{
			j++;
			if (j==m)
				return i+1;
		}
	}
	return -1;
}
void main()
{
	struct timeval e, s;
	int pos, time, n, time1;
	FILE *a;
	a=fopen("1.txt", "a");
	printf("Enter the text\n");
	gets(t);
	n=strlen(t);
	printf("Enter the pattern for best case\n");
	gets(p);
	gettimeofday(&s, 0);
	pos=brute(t, p);
	gettimeofday(&e, 0);
	time=e.tv_usec-s.tv_usec;
	if (pos == -1)
		printf("Not found\n");
	else
		printf("Found at %d position\n", pos);
	printf("Time taken is %d\n", time);
	printf("Enter the pattern for worst case\n");
        gets(p);
        gettimeofday(&s, 0);
        pos=brute(t, p);
        gettimeofday(&e, 0);
        time1=e.tv_usec-s.tv_usec;
        if (pos == -1)
                printf("Not found\n");
        else
                printf("Found at %d position\n", pos);
        printf("Time taken is %d\n", time1);
	fprintf(a, "%d\t%d\t%d\n", n, time, time1);
}

