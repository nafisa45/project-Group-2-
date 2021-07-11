
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



void okayscorecopy(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect dest,int i)
{
    dest.w = 45;
    dest.h = 20;
    if(i==0)
    {
        dest.x = 105;
        dest.y = 458;
    }
    else if(i==1)
    {
        dest.x = 1076;
        dest.y = 255;
    }

    else if(i==2)
    {
        dest.x = 687;
        dest.y = 92;
    }

    else if(i==3)
    {
        dest.x = 105;
        dest.y = 254;
    }
    //  dest.x = 130+46*i;

    // dest.y = 0;

    SDL_RenderCopy(rend, tex, NULL,&dest);

}


void pointprint(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect dest,int i)
{
    dest.w = 45;
    dest.h = 20;
    if(i==0)
    {
        dest.x = 105;
        dest.y = 458;
    }
    else if(i==1)
    {
        dest.x = 1076;
        dest.y = 255;
    }

    else if(i==2)
    {
        dest.x = 687;
        dest.y = 92;
    }

    else if(i==3)
    {
        dest.x = 105;
        dest.y = 254;
    }
    //  dest.x = 130+46*i;

    // dest.y = 0;

    SDL_RenderCopy(rend, tex, NULL,&dest);

}



void bscorecopy(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect dest,int i)
{
    dest.w = 140;
    dest.h = 65;

    if(i==0)
    {
        dest.x = 472;
        dest.y = 365;
    }
    else if(i==3)
    {
        dest.x = 622;
        dest.y = 365;
    }

    else if(i==2)
    {
        dest.x = 785;
        dest.y = 365;
    }

    else if(i==1)
    {
        dest.x = 930;
        dest.y = 365;
    }

    SDL_RenderCopy(rend, tex, NULL,&dest);

}


void scorecopy(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect dest,int i)
{
    dest.w = 45;
    dest.h = 20;

    if(i==0)
    {
        dest.x = 160;
        dest.y = 458;
    }
    else if(i==1)
    {
        dest.x = 1128;
        dest.y = 255;
    }

    else if(i==2)
    {
        dest.x = 738;
        dest.y = 92;
    }

    else if(i==3)
    {
        dest.x = 160;
        dest.y = 254;
    }

    SDL_RenderCopy(rend, tex, NULL,&dest);

}



void callcopy(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect dest,int i)
{
    dest.w = 45;
    dest.h = 20;

    if(i==0)
    {
        dest.x = 160;
        dest.y = 458;
    }
    else if(i==1)
    {
        dest.x = 1128;
        dest.y = 255;
    }

    else if(i==2)
    {
        dest.x = 738;
        dest.y = 92;
    }

    else if(i==3)
    {
        dest.x = 160;
        dest.y = 254;
    }

    SDL_RenderCopy(rend, tex, NULL,&dest);

}


void finalscorepresenting(int *finalscore,SDL_Renderer* rend) // when point table clicked this function will present the pointtable
{


    char jk[4];
    SDL_Surface* surfaceMessage;
    SDL_Texture* number;
    SDL_Rect number_rect;
    number_rect.w = 100;
    number_rect.h = 70;
    number_rect.y = 455;



    TTF_Font* Sans = TTF_OpenFont("anik.ttf",90);
    SDL_Color White = {255, 255, 255};


    for(int i=0; i<4; i++) // this loop will seperately print the number on the window accordingly the players
    {
        jk[0]=0;
        jk[1]=0;
        jk[2]=0;
        jk[3]=0;


        if(finalscore[i]<0)
        {
            finalscore[i]=-1*finalscore[i];
            jk[0]=45;
            if(finalscore[i]>9)
            {
                jk[1]=finalscore[i]/10+48;
                jk[2]=finalscore[i]%10+48;
            }
            else
            {
                jk[1]=finalscore[i]+48;

            }
            finalscore[i]=-1*finalscore[i];
        }

        else if(finalscore[i]>9)
        {
            jk[0]=finalscore[i]/10+48;
            jk[1]=finalscore[i]%10+48;
        }
        else
        {
            jk[0]=finalscore[i]+48;

        }

        surfaceMessage = TTF_RenderText_Solid(Sans,jk, White);
        number = SDL_CreateTextureFromSurface(rend, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

        //create a rect
        if(i==0)
            number_rect.x = 365;
        else if(i==3)
            number_rect.x = 520;
        else if(i==2)
            number_rect.x = 680;
        else if(i==1)
            number_rect.x = 832;


        SDL_RenderCopy(rend, number, NULL, &number_rect);

    }




}


int battlewon(SDL_Renderer* rend) //that function will take the pointable background to the renderer
{



    SDL_RenderClear(rend);
    SDL_Surface* surface = IMG_Load("pic/scoreboard.jpg");
    SDL_Texture* texfinalpointtable = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect destfinalpointtable;
    SDL_QueryTexture(texfinalpointtable, NULL, NULL, &destfinalpointtable.w, &destfinalpointtable.h);
    destfinalpointtable.w = 1280;
    destfinalpointtable.h = 720;
    SDL_RenderCopy(rend, texfinalpointtable, NULL,&destfinalpointtable);

    return 0;

}



int numbercopy(SDL_Renderer* rend,imginfo n0,imginfo n1,imginfo n2,imginfo n3,imginfo n4,imginfo n5,imginfo n6,imginfo n7,imginfo n8,imginfo n9,imginfo n10,imginfo n11,imginfo n12,imginfo n13,imginfo n14,imginfo n15,imginfo n16,imginfo n17,imginfo n18,imginfo n19,imginfo n20,imginfo n21,imginfo n22,imginfo n23,imginfo n24,imginfo n25,int* score)
{
    for(int i=0; i<4; i++)
    {
        int x=score[i];
        if(x==0)
        {
            okayscorecopy(rend,n0.tex,n0.dest,i );
        }

        else if(x==1)
        {
            okayscorecopy(rend,n1.tex,n1.dest,i );
        }
        else if(x==2)
        {
            okayscorecopy(rend,n2.tex,n2.dest,i );
        }
        else if(x==3)
        {
            okayscorecopy(rend,n3.tex,n3.dest,i );
        }
        else if(x==4)
        {
            okayscorecopy(rend,n4.tex,n4.dest,i );
        }
        else if(x==5)
        {
            okayscorecopy(rend,n5.tex,n5.dest,i );
        }
        else if(x==6)
        {
            okayscorecopy(rend,n6.tex,n6.dest,i );
        }
        else if(x==7)
        {
            okayscorecopy(rend,n7.tex,n7.dest,i );
        }
        else if(x==8)
        {
            okayscorecopy(rend,n8.tex,n8.dest,i );
        }
        else if(x==9)
        {
            okayscorecopy(rend,n9.tex,n9.dest,i );
        }
        else if(x==10)
        {
            okayscorecopy(rend,n10.tex,n10.dest,i );
        }
    }
    return 0;


}



int pointcopy(SDL_Renderer* rend,imginfo n0,imginfo n1,imginfo n2,imginfo n3,imginfo n4,imginfo n5,imginfo n6,imginfo n7,imginfo n8,imginfo n9,imginfo n10,imginfo n11,imginfo n12,imginfo n13,imginfo n14,imginfo n15,imginfo n16,imginfo n17,imginfo n18,imginfo n19,imginfo n20,imginfo n21,imginfo n22,imginfo n23,imginfo n24,imginfo n25,int* score)
{
    for(int i=0; i<4; i++)
    {
        int x=score[i];
        if(x==0)
        {
            pointprint(rend,n0.tex,n0.dest,i );
        }

        else if(x==1)
        {
            pointprint(rend,n1.tex,n1.dest,i );
        }
        else if(x==2)
        {
            pointprint(rend,n2.tex,n2.dest,i );
        }
        else if(x==3)
        {
            pointprint(rend,n3.tex,n3.dest,i );
        }
        else if(x==4)
        {
            pointprint(rend,n4.tex,n4.dest,i );
        }
        else if(x==5)
        {
            pointprint(rend,n5.tex,n5.dest,i );
        }
        else if(x==6)
        {
            pointprint(rend,n6.tex,n6.dest,i );
        }
        else if(x==7)
        {
            pointprint(rend,n7.tex,n7.dest,i );
        }
        else if(x==8)
        {
            pointprint(rend,n8.tex,n8.dest,i );
        }
        else if(x==9)
        {
            pointprint(rend,n9.tex,n9.dest,i );
        }
        else if(x==10)
        {
            pointprint(rend,n10.tex,n10.dest,i );
        }
    }
    return 0;


}



