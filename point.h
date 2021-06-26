
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

void finalscorepresenting(int *finalscore,SDL_Renderer* rend) // when point table clicked this function will present the pointtable
{


    char jk[4];
    SDL_Surface* surfaceMessage;
    SDL_Texture* number;
    SDL_Rect number_rect;
    number_rect.w = 140;
    number_rect.h = 65;
    number_rect.y = 365;



    TTF_Font* Sans = TTF_OpenFont("arial.ttf",24);
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
            number_rect.x = 472;
        else if(i==3)
            number_rect.x = 622;
        else if(i==2)
            number_rect.x = 785;
        else if(i==1)
            number_rect.x = 930;


        SDL_RenderCopy(rend, number, NULL, &number_rect);

    }




}



