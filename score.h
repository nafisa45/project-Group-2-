




int scoring(int* finalscore,int *score,int *call) // that function will used to count score
{
    int i,j,temp,maximum=0;
    for(i=0; i<4; i++)
    {
        if(call[i]>score[i])
        {
            finalscore[i]=finalscore[i]-call[i];
        }
        else
        {

            finalscore[i]=finalscore[i]+call[i];
        }


        if(finalscore[i]>maximum)
        {
            maximum=finalscore[i];
        }
    }

    return maximum;

}









int result(int *given) // that function will results the score accordingl to the bid and achieved score
{
    int trump=0,flag=0,fl=0,first,i,Max=given[0],pos,ret=0,ind=-1;
    int res;

    if((given[0]%13)==0)
    {
        res=((given[0]-1)/13)*13;
    }
    else
    {
        res=(given[0]/13)*13;
    }


    for(i=0; i<4; i++)
    {
        if(given[i]>39)
        {
            flag=1;
            if(given[i]>trump)
            {
                trump=given[i];
                ind=i;
            }
        }
        else
        {
            if(i>0)
            {
                if(given[i]>res&&given[i]<=res+13)
                {
                    fl=1;
                    if(Max<given[i])
                    {
                        ret=i;
                        Max=given[i];
                    }
                }
            }
        }

    }

    //for(int i=0;i<4;i++) printf("given array is %d  \n",given[i]);

    if(flag==1)
    {
        return ind;
    }
    else
    {
        return ret;
    }

}


