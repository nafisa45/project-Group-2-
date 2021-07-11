
int biddingwindow(SDL_Renderer* rend, SDL_Texture* texbid, SDL_Rect biddest,int *p1,int st)
{

    SDL_Surface* surface;
    SDL_Texture* tex;
    SDL_Rect dest;



    surface = IMG_Load("button/call.png");
    SDL_Texture* texstate = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect state;
    state.w=65;
    state.h =70;
    state.y = 270;



    // SDL_RenderCopy(rend, tex3, NULL,&instruction);
    SDL_RenderClear(rend);

    SDL_RenderCopy(rend, texbid, NULL,&biddest);


    if(st==1)
    {
        state.x = 454+6;
        //state.x = 523;
    }
    else if(st==2)
    {
        //state.x = 454;
        state.x = 523+5+3;
    }
    else if(st==3)
    {
        state.x = 606-1;
        // state.x = 523;
    }
    else if(st==4)
    {
        state.x = 680-6;
        // state.x = 523;
    }
    else if(st==5)
    {
        state.x = 747-5;
        // state.x = 523;
    }
    else if(st==6)
    {
        state.x = 816-6;
        // state.x = 523;
    }

    if(st)
        SDL_RenderCopy(rend, texstate, NULL,&state);


    for(int i=0; i<13; i++)
    {
        cardshow(p1[i],i+1,rend);

    }

    SDL_RenderPresent(rend); //after presenting this render game will wait for having bid of everybody


    int icon=-1,close=0,fg=0,menuoutput;
    int gameover = 0,ree;
    int mousex, mousey;
    while(!close&&icon==-1)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                close = 1;
                icon=1000;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode)
                {
                case SDL_SCANCODE_0:
                    icon=0;
                    break;
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
                case SDL_SCANCODE_RIGHT:
                    if(st==6)
                    {
                        icon=-1;
                    }
                    else if(st==0)
                    {
                        return 1001;
                    }
                    else
                    {
                        return (st+1)*1000;
                    }
                    break;
                case SDL_SCANCODE_LEFT:
                    if(st==0)
                    {
                        icon=-1;
                    }
                    else if(st==2)
                    {
                        return 1001;
                    }

                    else
                    {
                        return (st-1)*1000;
                    }
                    break;
                case SDL_SCANCODE_KP_ENTER:
                {
                    surface = IMG_Load("button/Bidbutton.jpg");
                    SDL_Texture* texbidbutton = SDL_CreateTextureFromSurface(rend, surface);
                    SDL_FreeSurface(surface);
                    SDL_Rect bidbutton;
                    bidbutton.w=100;
                    bidbutton.h =45;
                    bidbutton.x = 590;
                    bidbutton.y = 428;


                    SDL_RenderCopy(rend, texbidbutton, NULL,&bidbutton);
                    SDL_RenderPresent(rend);
                    SDL_Delay(300);
                    //printf("value is %d\n",st);
                    return st;
                }
                break;
                default:
                    icon=-1;

                }

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mousex, &mousey);


                    if(mousex>454&&mousex<511&&mousey>270&&mousey<325) //1 is clicked
                    {
                        return 1001;
                    }
                    else if(mousex>523&&mousex<585&&mousey>270&&mousey<325) //2 is clicked
                    {
                        return 2000;
                    }
                    else if(mousex>606&&mousex<670&&mousey>270&&mousey<325) //3 is clicked
                    {
                        return 3000;
                    }
                    else if(mousex>680&&mousex<740&&mousey>270&&mousey<325) //4 is clicked
                    {
                        return 4000;
                    }
                    else if(mousex>747&&mousex<807&&mousey>270&&mousey<325) //5 is clicked
                    {
                        return 5000;
                    }
                    else if(mousex>816&&mousex<875&&mousey>270&&mousey<325) //6 is clicked
                    {
                        return 6000;
                    }
                    else if(mousex>590&&mousex<690&&mousey>428&&mousey<473) //bid button is clicked and that will set the guest's bid with the last number guest has been clicked
                    {

                        surface = IMG_Load("button/Bidbutton.jpg");
                        SDL_Texture* texbidbutton = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect bidbutton;
                        bidbutton.w=100;
                        bidbutton.h =45;
                        bidbutton.x = 590;
                        bidbutton.y = 428;


                        SDL_RenderCopy(rend, texbidbutton, NULL,&bidbutton);
                        SDL_RenderPresent(rend);
                        SDL_Delay(300);
                        printf("value is %d\n",st);
                        return st;
                    }


                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n",mousex,mousey);



                }
                break;




            }

        }

    }


    return icon;
}



int callnumbercopy(SDL_Renderer* rend,imginfo n0,imginfo n1,imginfo n2,imginfo n3,imginfo n4,imginfo n5,imginfo n6,imginfo n7,imginfo n8,imginfo n9,imginfo n10,imginfo n11,imginfo n12,imginfo n13,imginfo n14,imginfo n15,imginfo n16,imginfo n17,imginfo n18,imginfo n19,imginfo n20,imginfo n21,imginfo n22,imginfo n23,imginfo n24,imginfo n25,int* score)
{
    for(int i=0; i<4; i++)
    {
        int x=score[i];
        if(x==0)
        {
            callcopy(rend,n0.tex,n0.dest,i );
        }

        else if(x==1)
        {
            callcopy(rend,n1.tex,n1.dest,i );
        }
        else if(x==2)
        {
            callcopy(rend,n2.tex,n2.dest,i );
        }
        else if(x==3)
        {
            callcopy(rend,n3.tex,n3.dest,i );
        }
        else if(x==4)
        {
            callcopy(rend,n4.tex,n4.dest,i );
        }
        else if(x==5)
        {
            callcopy(rend,n5.tex,n5.dest,i );
        }
        else if(x==6)
        {
            callcopy(rend,n6.tex,n6.dest,i );
        }
        else if(x==7)
        {
            callcopy(rend,n7.tex,n7.dest,i );
        }
        else if(x==8)
        {
            callcopy(rend,n8.tex,n8.dest,i );
        }
        else if(x==9)
        {
            callcopy(rend,n9.tex,n9.dest,i );
        }
        else if(x==10)
        {
            callcopy(rend,n10.tex,n10.dest,i );
        }
    }
    return 0;


}


int bid(int *p) // that function will make bid for all other player without guest
{
    int i,j,count=0;

    for(i=0; i<13; i++)
    {
        if(p[i]>39)
            count++;
    }
    return count;
}


