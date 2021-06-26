#include<stdio.h>

int datarearrange(int *s)
{
    FILE *file;
    int t=0;
    char name[5][20];
    int age[100];
    file=fopen("anik.txt","r");
    if(file==NULL)
    {
        printf("there is something wrong\n");
        return 0;
    }
    else
    {
        while(!feof(file))
        {
            fscanf(file,"%d",&s[t]);
            t++;
        }
        fclose(file);
    }

    printf("value of t is %d\n",t);
    int limit=t-1;


    t=52;
    file=fopen("anik.txt","w");
    if(file==NULL)
    {
        printf("there is something wrong with anik\n");
        return 0;
    }
    else
    {
        while(t<limit)
        {
            fprintf(file,"%d\n",s[t]);
            t++;
        }
        //fclose(file);
    }
    t=0;
     while(t<=51)
        {
            fprintf(file,"%d\n",s[t]);
            t++;
        }
        fclose(file);


    return 0;
}



int main()
{
  int data[1000000];
  dataload(data);




}
