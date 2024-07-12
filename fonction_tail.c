#include "fonction_tail.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void open_close(FILE*f,char* chaine,char* argv[])
{
	if(strchr(argv[1],'-')==NULL)
	{
		f=fopen(argv[1],"r");
		if(f==NULL)
		{
			printf("Le fichier ne s'ouvre pas!");
		}
		else
		{
			liat(f,chaine,argv);
			fclose(f);
		}
	}
	else if(strcmp(argv[1],"-n")==0)
	{
		f=fopen(argv[3],"r");
		if(f==NULL)
		{
			printf("Le fichier ne s'ouvre pas!");
		}
		else
		{
			liat(f,chaine,argv);
			fclose(f);
		}
	}
	else
	{
		f=fopen(argv[2],"r");
		if(f==NULL)
		{
			printf("Le fichier ne s'ouvre pas!");
		}
		else
		{
			liat(f,chaine,argv);
			fclose(f);
		}
	}
}

void liat(FILE*f,char* chaine,char* argv[])
{
	int count1=1,nbr=0,count2=1,cast;
	if(strchr(argv[1],'-')==NULL)
	{
		while(feof(f)!=1)
			{
				fgets(chaine,100,f);
				count1++;	
			}
			fclose(f);
			f=fopen(argv[1],"r");
			nbr=count1-10;
			while(feof(f)!=1)
			{
				fgets(chaine,100,f);
				if(count2>=nbr)
				{
					printf("%s",chaine);
				}
				count2++;
			}
	}
		
	if(strcmp(argv[1],"-n")==0)
	{
		while(feof(f)!=1)
			{
				fgets(chaine,100,f);
				count1++;	
			}
			fclose(f);
			f=fopen(argv[3],"r");
			cast=atoi(argv[2]);
			nbr=count1-cast;
			while(feof(f)!=1)
			{
				fgets(chaine,100,f);
				if(count2>=nbr)
				{
					printf("%s",chaine);
				}
				count2++;
			}
	}
	if(strcmp(argv[1],"-v")==0)
	{
		printf("==> %s <==\n",argv[2]);
		while(feof(f)!=1)
			{
				fgets(chaine,100,f);
				count1++;	
			}
			fclose(f);
			f=fopen(argv[2],"r");
			nbr=count1-10;
			while(feof(f)!=1)
			{
				fgets(chaine,100,f);
				if(count2>=nbr)
				{
					printf("%s",chaine);
				}
				count2++;
			}
	}
}
