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


int takecard(int *ar,int fl,int battlenumber,int firstcard,int x) // that function will take card to play for other user
{

    int ret,i,temp,var,pos,rem,res,maxv,minv,Max=0,Min=60,flag=0,trump=0,mai,mii,post,flt=0;


    if(fl==1)
    {
        res=firstcard/13;
        rem=firstcard%13;
        if(rem==0)
        {
            res--;
        }
        //rem=firstcard%13;
        minv=res*13+1;
        maxv=(res+1)*13;

        for(i=0; i<14-battlenumber; i++)
        {

            if(ar[i]>=minv&&ar[i]<=maxv)
            {
                flag=1;
                if(ar[i]>Max)
                {
                    Max=ar[i];
                    mai=i;
                    //printf("%d %d\t",Max,mai);
                }
                if(ar[i]<Min)
                {
                    Min=ar[i];
                    mii=i;
                }

            }



            else if(((ar[i]/13==3&&ar[i]%13!=0)||ar[i]/13==4)&&trump==0)
            {
                trump=ar[i];
                post=i;
            }


        }
        if(flag==1)
        {
            // printf("first condition\n");
            if(firstcard>Max)
            {
                ret=ar[mii];

                pos=mii;

            }
            else if(firstcard<Max)
            {
                ret=ar[mai];
                pos=mai;
                //printf("%d ",pos);

            }

        }
        else if(trump!=0)
        {
            //printf("second condition\n");
            ret=trump;
            pos=post;

        }
        else if(flag==0&&trump==0)
        {
            //printf("third condition\n");
            pos=13-battlenumber;//last card
            ret=ar[pos];
        }

        arraycombine(ar,battlenumber,pos);
        return ret;

    }
    else if(fl==0)
    {
        pos=x;
        ret=ar[pos-1];
        arraycombine(ar,battlenumber,pos-1);
        return ret;
    }


}






