#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void ordena(char str[])
{
	for(int i=0; str[i] != '\0'; i++)
	{
		int x=str[i];
		int j=i-1;
		while(j>=0 && str[j] >x)
		{
			str[j+1]=str[j];
			j--;
		}
		str[j+1]=x;
	}
}

void normalizar(char str[])
{
	int aux=0,j;
	int size=strlen(str);
	
	ordena(str);
	
	for(int i=0; i<size; i++)
	{
		if(isalpha(str[i]))
		{
		str[i] = tolower(str[i]);
		}
	}
	
	for(int i=0; str[i] != '\0'; i++)
	{
		while(!isalpha(str[i]))
		{
			
			for(j=i; str[j]!='\0'; j++)
			{
				str[j] =str[j+1];
			}
			str[j]='\0';
		}
		
	} 

}

int anagrama(char str1[], char str2[])
{
	normalizar(str1);
	
	normalizar(str2);
	
	
	int size1=strlen(str1);
	int size2=strlen(str2);
	
	if(size1 != size2)
	{
		return 0;
	}
	for(int i=0; i<size1; i++)
	{
		if(str1[i] != str2[i])
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	char str1[100], str2[100];
	
	fgets(str1, 100, stdin);
	fflush(stdin);
	fgets(str2,100, stdin);
	
	normalizar(str1);
	normalizar(str2);
	int size1=strlen(str1);
	int size2=strlen(str2); 
	
	printf("%d\n", anagrama(str1, str2));
	
}


	


