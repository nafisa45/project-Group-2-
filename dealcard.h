

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


int playcard(int battlenumber,SDL_Renderer* rend) // this  function will be used to play a card for guest
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




