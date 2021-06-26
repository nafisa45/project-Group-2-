int dataload(int *s)
{
    FILE *file;
    int t=0;
    char name[5][20];
    int age[100];
    file=fopen("data.txt","r");
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


void shuffle(int *data,int *shufflecard,int *gameno)
{
    int j=((*gameno)+1)*52,i,t=0;
    for(i=(*gameno)*52; i<j; i++)
    {
        shufflecard[t]=data[i];
        t++;

    }
    printf("\n");

}


void distribute(int *playerhand, int playernum, int *cardsetaftershuffle)
{
    int i;
    for(i=0; i<13; i++)
    {
        playerhand[i]=cardsetaftershuffle[i*4+playernum-1];
    }
}


void sorting(int *a)
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



void arraycombine(int *ar,int battle,int pos)
{

    for(int i=pos; i<13-battle; i++)
    {
        ar[i]=ar[i+1];
    }

}



int bid(int *p)
{
    int i,j,count=0;

    for(i=0; i<13; i++)
    {
        if(p[i]>39)
            count++;
    }
    return count;
}




int tawinclose(SDL_Renderer* rend)
{



    int close = 0,icon=-2,ree;
    int gameover = 0,fg=0;
    int mousex, mousey;
    // int  close = 0,icon=-2,gameover = 0,fg=0;


    while(!close&&fg==0)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                return 1000;
                break;
            case SDL_KEYDOWN:
                fg=1;
            case SDL_MOUSEBUTTONDOWN:
                fg=1;
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    // printf("left button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    //printf("%d %d\n",mousex,mousey);
                    if(mousex>38&&mousex<160&&mousey>40&&mousey<92)
                    {
                        //condition will be set for okay

                    }


                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n",mousex,mousey);


                }

            }

        }

    }
    return 0;

}



int pointableokbutton(SDL_Renderer* rend)
{



    int close = 0,icon=-2,ree;
    int gameover = 0,fg=0;
    int mousex, mousey;
    // int  close = 0,icon=-2,gameover = 0,fg=0;


    while(!close&&fg==0)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                close = 1;
                return 1000;
                break;
            case SDL_KEYDOWN:
            {
              if (event.key.keysym.scancode==SDL_SCANCODE_KP_ENTER)
                 {
                   fg=1;
                    SDL_Surface* surface = IMG_Load("button/Ok.jpg");
                    SDL_Texture* texok = SDL_CreateTextureFromSurface(rend, surface);
                    SDL_FreeSurface(surface);
                    SDL_Rect okbutton;
                    okbutton.w=135;
                    okbutton.h =75;
                    okbutton.x = 195;
                    okbutton.y = 258;
                    SDL_RenderCopy(rend, texok, NULL,&okbutton);
                    SDL_RenderPresent(rend);
                    SDL_Delay(300);

                 }


            }

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    // printf("left button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    //printf("%d %d\n",mousex,mousey);
                    if(mousex>204&&mousex<328&&mousey>266&&mousey<328)
                    {

                    fg=1;
                    SDL_Surface* surface = IMG_Load("button/Ok.jpg");
                    SDL_Texture* texok = SDL_CreateTextureFromSurface(rend, surface);
                    SDL_FreeSurface(surface);
                    SDL_Rect okbutton;
                    okbutton.w=135;
                    okbutton.h =75;
                    okbutton.x = 195;
                    okbutton.y = 258;
                    SDL_RenderCopy(rend, texok, NULL,&okbutton);
                    SDL_RenderPresent(rend);
                    SDL_Delay(300);
                    }


                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n",mousex,mousey);


                }

            }

        }

    }
    return 0;

}




int scoring(int* finalscore,int *score,int *call)
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




int takecard(int *ar,int fl,int battlenumber,int firstcard,int x)
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



int result(int *given)
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



int playcard(int battlenumber,SDL_Renderer* rend)
{


    int close = 0,icon=-2,ree;
    int gameover = 0,fg=0;
    int mousex, mousey;

    while(!close&&fg==0)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                close = 1;
                return 1000;
                break;
            case SDL_KEYDOWN:
                fg=1;
                switch(event.key.keysym.scancode)
                {
                case SDL_SCANCODE_1:
                    icon=1;
                    break;
                case SDL_SCANCODE_2:
                    icon=2;
                    break;
                case SDL_SCANCODE_3:
                    icon=3;
                    break;
                case SDL_SCANCODE_4:
                    icon=4;
                    break;
                case SDL_SCANCODE_5:
                    icon=5;
                    break;
                case SDL_SCANCODE_6:
                    icon=6;
                    break;
                case SDL_SCANCODE_7:
                    icon=7;
                    break;
                case SDL_SCANCODE_8:
                    icon=8;
                    break;
                case SDL_SCANCODE_9:
                    icon=9;
                    break;
                case SDL_SCANCODE_A:
                    icon=10;
                    break;
                case SDL_SCANCODE_B:
                    icon=11;
                    break;
                case SDL_SCANCODE_C:
                    icon=12;
                    break;
                case SDL_SCANCODE_D:
                    icon=13;
                    break;
                default:
                    icon=18;

                }
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mousex, &mousey);

                    if(mousex>160&&mousex<1200&&mousey>550&&mousey<700) //card is clicked
                    {
                        fg=1;
                        mousex=mousex-170;
                        ree=mousex/75;
                        icon=ree+1;


                    }


                    else if(mousex>40&&mousex<160&&mousey>15&&mousey<70) //menu button clicked
                    {

                        SDL_Surface* surface = IMG_Load("button/Menu.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=130;
                        redline.h =60;
                        redline.x = 40;
                        redline.y = 15;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(500);


                        fg=1;
                        int menuoutput=menu(rend);
                        if(menuoutput==500)
                        {

                            //continue has been clicked
                            return 1001;

                        }
                        else if(menuoutput==600)
                        {
                            //new game is clicked
                            return 1002;
                        }
                        else if(menuoutput==700)
                        {
                            //quit hasbeen clicked
                            return 1000;
                        }


                    }

                    else if(mousex>1140&&mousex<1260&&mousey>30&&mousey<80)//pointable button clicked
                    {


                        SDL_Surface* surface = IMG_Load("button/Point.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=120;
                        redline.h =60;
                        redline.x = 1140;
                        redline.y = 35;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(500);

                        battlewon(rend);
                        //SDL_RenderClear(rend);
                        //  SDL_RenderCopy(rend, tex01, NULL,&redline);


                        //  SDL_RenderPresent(rend);


                        // icon= tawinclose(rend);
                        return 1003;


                    }

                    else if(mousex>190&&mousex<305&&mousey>15&&mousey<70) //help button clicked
                    {

                        SDL_Surface* surface = IMG_Load("button/Help.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=130;
                        redline.h =60;
                        redline.x = 190;
                        redline.y = 15;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(300);


                            surface = IMG_Load("pic/Instructions.jpg");
                            SDL_Texture* texinstructionswindow = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect instructionwindow;
                            instructionwindow.w=1280;
                            instructionwindow.h=720;
                            instructionwindow.x = 0;
                            instructionwindow.y = 0;



                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, texinstructionswindow, NULL, &instructionwindow);
                            SDL_RenderPresent(rend);

                            int  close = 0,icon=-2,gameover = 0,fg=0;
                            while(!close&&fg==0)
                            {
                                SDL_Event event;
                                while(SDL_PollEvent(&event))
                                {
                                    switch(event.type)
                                    {
                                    case SDL_QUIT:
                                        close = 1;
                                        return 1000;
                                        break;

                                    case SDL_MOUSEBUTTONDOWN:
                                        if(event.button.button==SDL_BUTTON_LEFT)
                                        {
                                            SDL_GetMouseState(&mousex, &mousey);

                                            if(mousex>1140&&mousex<1275&&mousey>0&&mousey<60) //ok is clicked
                                            {
                                                fg=1;
                                                surface = IMG_Load("button/Ok.jpg");
                                                SDL_Texture* texokbutton = SDL_CreateTextureFromSurface(rend, surface);
                                                SDL_FreeSurface(surface);
                                                SDL_Rect okbutton;
                                                okbutton.w=140;
                                                okbutton.h =65;
                                                okbutton.x = 1135;
                                                okbutton.y = 0;
                                                SDL_RenderCopy(rend, texokbutton, NULL,&okbutton);
                                                SDL_RenderPresent(rend);
                                                SDL_Delay(300);

                                               return 1001;

                                            }
                                            break;

                                        }

                                        else if(event.button.button==SDL_BUTTON_RIGHT)
                                        {
                                            printf("right button pressed mouse point is:\n");
                                            SDL_GetMouseState(&mousex, &mousey);
                                            printf("%d %d\n\n",mousex,mousey);


                                        }

                                    }

                                }

                            }






                        printf("help button clicked\n");

                    }

                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed mouse point is:\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n\n",mousex,mousey);


                }
                break;

            }

        }

    }
    return icon;

}



int winclose(SDL_Renderer* rend)
{

    int  close = 0,icon=-2,gameover = 0,fg=0;
    int mousex, mousey;

    while(!close&&fg==0)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                close = 1;
                return 1000;
                break;
            case SDL_KEYDOWN:
                fg=1;
            case SDL_MOUSEBUTTONDOWN:
                fg=1;
                if(event.button.button==SDL_BUTTON_LEFT)
                {

                    SDL_GetMouseState(&mousex, &mousey);

                    if(mousex>40&&mousex<160&&mousey>15&&mousey<70) //menu button clicked
                    {

                        SDL_Surface* surface = IMG_Load("button/Menu.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=130;
                        redline.h =60;
                        redline.x = 40;
                        redline.y = 15;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(500);


                        fg=1;
                        int menuoutput=menu(rend);
                        if(menuoutput==500)
                        {

                            //continue has been clicked
                            return 1001;

                        }
                        else if(menuoutput==600)
                        {
                            //new game is clicked
                            return 1002;
                        }
                        else if(menuoutput==700)
                        {
                            //new game is clicked
                            return 1000;
                        }


                    }

                    else if(mousex>1140&&mousex<1260&&mousey>30&&mousey<80)//pointable button clicked
                    {

                        SDL_Surface* surface = IMG_Load("button/Point.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=120;
                        redline.h =60;
                        redline.x = 1140;
                        redline.y = 35;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(500);


                        battlewon(rend);
                        return 1003;
                    }

                    else if(mousex>190&&mousex<305&&mousey>15&&mousey<70) //help button clicked
                    {
                        SDL_Surface* surface = IMG_Load("button/Help.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=130;
                        redline.h =60;
                        redline.x = 190;
                        redline.y = 15;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(300);


                            surface = IMG_Load("pic/Instructions.jpg");
                            SDL_Texture* texinstructionswindow = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect instructionwindow;
                            instructionwindow.w=1280;
                            instructionwindow.h=720;
                            instructionwindow.x = 0;
                            instructionwindow.y = 0;



                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, texinstructionswindow, NULL, &instructionwindow);
                            SDL_RenderPresent(rend);

                            int  close = 0,icon=-2,gameover = 0,fg=0;
                            while(!close&&fg==0)
                            {
                                SDL_Event event;
                                while(SDL_PollEvent(&event))
                                {
                                    switch(event.type)
                                    {
                                    case SDL_QUIT:
                                        close = 1;
                                        return 1000;
                                        break;

                                    case SDL_MOUSEBUTTONDOWN:
                                        if(event.button.button==SDL_BUTTON_LEFT)
                                        {
                                            SDL_GetMouseState(&mousex, &mousey);

                                            if(mousex>1140&&mousex<1275&&mousey>0&&mousey<60) //ok is clicked
                                            {
                                                fg=1;
                                                surface = IMG_Load("button/Ok.jpg");
                                                SDL_Texture* texokbutton = SDL_CreateTextureFromSurface(rend, surface);
                                                SDL_FreeSurface(surface);
                                                SDL_Rect okbutton;
                                                okbutton.w=140;
                                                okbutton.h =65;
                                                okbutton.x = 1135;
                                                okbutton.y = 0;
                                                SDL_RenderCopy(rend, texokbutton, NULL,&okbutton);
                                                SDL_RenderPresent(rend);
                                                SDL_Delay(300);

                                               return 1001;

                                            }
                                            break;

                                        }

                                        else if(event.button.button==SDL_BUTTON_RIGHT)
                                        {
                                            printf("right button pressed mouse point is:\n");
                                            SDL_GetMouseState(&mousex, &mousey);
                                            printf("%d %d\n\n",mousex,mousey);


                                        }

                                    }

                                }

                            }
                        printf("help button clicked\n");

                    }

                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed mouse point is:\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n\n",mousex,mousey);


                }
            }

        }

    }
    return 0;

}






