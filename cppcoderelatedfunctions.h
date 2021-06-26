int dataload(int *s) // this function will load data from file and data will regared as the cards each
{
    FILE *file;
    int t=0;
    char name[5][20];
    int age[100];
    file=fopen("dataset.txt","r");
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

    return 0;
}


int datarearrange(int *s)  //this function will rearrange the data after completeing the game
{
    FILE *file;
    int t=0;
    char name[5][20];
    int age[100];
    file=fopen("dataset.txt","r");
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

  //  printf("value of t is %d\n",t);
    int limit=t-1;


    t=52;
    file=fopen("dataset.txt","w");
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



void shuffle(int *data,int *shufflecard,int *gameno) //52 card will be assigned to play and the card became shuffled
{
    int j=((*gameno)+1)*52,i,t=0;
    for(i=(*gameno)*52; i<j; i++)
    {
        shufflecard[t]=data[i];
        t++;

    }
    printf("\n");

}


void distribute(int *playerhand, int playernum, int *cardsetaftershuffle) // this function will distribute card to everyboday and each will get 13 cards
{
    int i;
    for(i=0; i<13; i++)
    {
        playerhand[i]=cardsetaftershuffle[i*4+playernum-1];
    }
}


void sorting(int *a) //this function will sorting every player cards to play card easily
{
    int ind,temp,pos,i,j,t;
    for(i=1; i<13; i++)
    {
        if(a[i]>a[i-1])
        {
            pos=a[i];
            for(j=i; a[j-1]<pos&&j!=0; j--)
            {
                a[j]=a[j-1];
            }
            a[j]=pos;
        }
    }
}



void arraycombine(int *ar,int battle,int pos) // that function will reduce the card after it made played
{

    for(int i=pos; i<13-battle; i++)
    {
        ar[i]=ar[i+1];
    }

}





