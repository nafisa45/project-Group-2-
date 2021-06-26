
int cardshowtable(int x,int y,SDL_Renderer* rend)
{

    SDL_Surface* surface;

//printf("x is %d y is %d\n",x,y);
    if(x==1)
    {
        surface = IMG_Load("allcards/img1.png");
    }
    else if(x==2)
    {
        surface = IMG_Load("allcards/img2.png");
    }
    else if(x==3)
    {
        surface = IMG_Load("allcards/img3.png");
    }
    else if(x==4)
    {
        surface = IMG_Load("allcards/img4.png");
    }
    else if(x==5)
    {
        surface = IMG_Load("allcards/img5.png");
    }
    else if(x==6)
    {
        surface = IMG_Load("allcards/img6.png");
    }
    else if(x==7)
    {
        surface = IMG_Load("allcards/img7.png");
    }
    else if(x==8)
    {
        surface = IMG_Load("allcards/img8.png");
    }
    else if(x==9)
    {
        surface = IMG_Load("allcards/img9.png");
    }
    else if(x==10)
    {
        surface = IMG_Load("allcards/img10.png");
    }
    else if(x==11)
    {
        surface = IMG_Load("allcards/img11.png");
    }
    else if(x==12)
    {
        surface = IMG_Load("allcards/img12.png");
    }
    else if(x==13)
    {
        surface = IMG_Load("allcards/img13.png");
    }
    else if(x==14)
    {
        surface = IMG_Load("allcards/img14.png");
    }
    else if(x==15)
    {
        surface = IMG_Load("allcards/img15.png");
    }
    else if(x==16)
    {
        surface = IMG_Load("allcards/img16.png");
    }
    else if(x==17)
    {
        surface = IMG_Load("allcards/img17.png");
    }
    else if(x==18)
    {
        surface = IMG_Load("allcards/img18.png");
    }
    else if(x==19)
    {
        surface = IMG_Load("allcards/img19.png");
    }
    else if(x==20)
    {
        surface = IMG_Load("allcards/img20.png");
    }
    else if(x==21)
    {
        surface = IMG_Load("allcards/img21.png");
    }
    else if(x==22)
    {
        surface = IMG_Load("allcards/img22.png");
    }
    else if(x==23)
    {
        surface = IMG_Load("allcards/img23.png");
    }
    else if(x==24)
    {
        surface = IMG_Load("allcards/img24.png");
    }
    else if(x==25)
    {
        surface = IMG_Load("allcards/img25.png");
    }
    else if(x==26)
    {
        surface = IMG_Load("allcards/img26.png");
    }
    else if(x==27)
    {
        surface = IMG_Load("allcards/img27.png");
    }
    else if(x==28)
    {
        surface = IMG_Load("allcards/img28.png");
    }
    else if(x==29)
    {
        surface = IMG_Load("allcards/img29.png");
    }
    else if(x==30)
    {
        surface = IMG_Load("allcards/img30.png");
    }
    else if(x==31)
    {
        surface = IMG_Load("allcards/img31.png");
    }
    else if(x==32)
    {
        surface = IMG_Load("allcards/img32.png");
    }
    else if(x==33)
    {
        surface = IMG_Load("allcards/img33.png");
    }
    else if(x==34)
    {
        surface = IMG_Load("allcards/img34.png");
    }
    else if(x==35)
    {
        surface = IMG_Load("allcards/img35.png");
    }
    else if(x==36)
    {
        surface = IMG_Load("allcards/img36.png");
    }
    else if(x==37)
    {
        surface = IMG_Load("allcards/img37.png");
    }
    else if(x==38)
    {
        surface = IMG_Load("allcards/img38.png");
    }
    else if(x==39)
    {
        surface = IMG_Load("allcards/img39.png");
    }
    else if(x==40)
    {
        surface = IMG_Load("allcards/img40.png");
    }
    else if(x==41)
    {
        surface = IMG_Load("allcards/img41.png");
    }
    else if(x==42)
    {
        surface = IMG_Load("allcards/img42.png");
    }
    else if(x==43)
    {
        surface = IMG_Load("allcards/img43.png");
    }
    else if(x==44)
    {
        surface = IMG_Load("allcards/img44.png");
    }
    else if(x==45)
    {
        surface = IMG_Load("allcards/img45.png");
    }
    else if(x==46)
    {
        surface = IMG_Load("allcards/img46.png");
    }
    else if(x==47)
    {
        surface = IMG_Load("allcards/img47.png");
    }
    else if(x==48)
    {
        surface = IMG_Load("allcards/img48.png");
    }
    else if(x==49)
    {
        surface = IMG_Load("allcards/img49.png");
    }
    else if(x==50)
    {
        surface = IMG_Load("allcards/img50.png");
    }
    else if(x==51)
    {
        surface = IMG_Load("allcards/img51.png");
    }
    else if(x==52)
    {
        surface = IMG_Load("allcards/img52.png");
    }

    //card numbering done

    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    /*	if(!tex){
    		printf("Redline Texture %s\n",SDL_GetError());
    		SDL_DestroyRenderer(rend);
    		SDL_DestroyWindow(win);
    		SDL_Quit();
    	return 1;
    	}
    */

    SDL_Rect dest;
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w = 75+40;
    dest.h = 100+45;
    if(y==0)
    {
        dest.x = 565;//+y*85+20;
        dest.y = 340+30;

    }
    else if(y==1)
    {
        dest.x = 715;//+y*85+20;
        dest.y = 260+30;

    }
    else if(y==2)
    {
        dest.x = 565;//+y*85+20;
        dest.y = 170+30;

    }
    else if(y==3)
    {
        dest.x = 420;//+y*85+20;
        dest.y = 260+30;

    }


    SDL_RenderCopy(rend, tex, NULL,&dest);

}

int cardshow(int x,int y,SDL_Renderer* rend)
{

    SDL_Surface* surface;

//printf("x is %d y is %d\n",x,y);
    if(x==1)
    {
        surface = IMG_Load("allcards/img1.png");
    }
    else if(x==2)
    {
        surface = IMG_Load("allcards/img2.png");
    }
    else if(x==3)
    {
        surface = IMG_Load("allcards/img3.png");
    }
    else if(x==4)
    {
        surface = IMG_Load("allcards/img4.png");
    }
    else if(x==5)
    {
        surface = IMG_Load("allcards/img5.png");
    }
    else if(x==6)
    {
        surface = IMG_Load("allcards/img6.png");
    }
    else if(x==7)
    {
        surface = IMG_Load("allcards/img7.png");
    }
    else if(x==8)
    {
        surface = IMG_Load("allcards/img8.png");
    }
    else if(x==9)
    {
        surface = IMG_Load("allcards/img9.png");
    }
    else if(x==10)
    {
        surface = IMG_Load("allcards/img10.png");
    }
    else if(x==11)
    {
        surface = IMG_Load("allcards/img11.png");
    }
    else if(x==12)
    {
        surface = IMG_Load("allcards/img12.png");
    }
    else if(x==13)
    {
        surface = IMG_Load("allcards/img13.png");
    }
    else if(x==14)
    {
        surface = IMG_Load("allcards/img14.png");
    }
    else if(x==15)
    {
        surface = IMG_Load("allcards/img15.png");
    }
    else if(x==16)
    {
        surface = IMG_Load("allcards/img16.png");
    }
    else if(x==17)
    {
        surface = IMG_Load("allcards/img17.png");
    }
    else if(x==18)
    {
        surface = IMG_Load("allcards/img18.png");
    }
    else if(x==19)
    {
        surface = IMG_Load("allcards/img19.png");
    }
    else if(x==20)
    {
        surface = IMG_Load("allcards/img20.png");
    }
    else if(x==21)
    {
        surface = IMG_Load("allcards/img21.png");
    }
    else if(x==22)
    {
        surface = IMG_Load("allcards/img22.png");
    }
    else if(x==23)
    {
        surface = IMG_Load("allcards/img23.png");
    }
    else if(x==24)
    {
        surface = IMG_Load("allcards/img24.png");
    }
    else if(x==25)
    {
        surface = IMG_Load("allcards/img25.png");
    }
    else if(x==26)
    {
        surface = IMG_Load("allcards/img26.png");
    }
    else if(x==27)
    {
        surface = IMG_Load("allcards/img27.png");
    }
    else if(x==28)
    {
        surface = IMG_Load("allcards/img28.png");
    }
    else if(x==29)
    {
        surface = IMG_Load("allcards/img29.png");
    }
    else if(x==30)
    {
        surface = IMG_Load("allcards/img30.png");
    }
    else if(x==31)
    {
        surface = IMG_Load("allcards/img31.png");
    }
    else if(x==32)
    {
        surface = IMG_Load("allcards/img32.png");
    }
    else if(x==33)
    {
        surface = IMG_Load("allcards/img33.png");
    }
    else if(x==34)
    {
        surface = IMG_Load("allcards/img34.png");
    }
    else if(x==35)
    {
        surface = IMG_Load("allcards/img35.png");
    }
    else if(x==36)
    {
        surface = IMG_Load("allcards/img36.png");
    }
    else if(x==37)
    {
        surface = IMG_Load("allcards/img37.png");
    }
    else if(x==38)
    {
        surface = IMG_Load("allcards/img38.png");
    }
    else if(x==39)
    {
        surface = IMG_Load("allcards/img39.png");
    }
    else if(x==40)
    {
        surface = IMG_Load("allcards/img40.png");
    }
    else if(x==41)
    {
        surface = IMG_Load("allcards/img41.png");
    }
    else if(x==42)
    {
        surface = IMG_Load("allcards/img42.png");
    }
    else if(x==43)
    {
        surface = IMG_Load("allcards/img43.png");
    }
    else if(x==44)
    {
        surface = IMG_Load("allcards/img44.png");
    }
    else if(x==45)
    {
        surface = IMG_Load("allcards/img45.png");
    }
    else if(x==46)
    {
        surface = IMG_Load("allcards/img46.png");
    }
    else if(x==47)
    {
        surface = IMG_Load("allcards/img47.png");
    }
    else if(x==48)
    {
        surface = IMG_Load("allcards/img48.png");
    }
    else if(x==49)
    {
        surface = IMG_Load("allcards/img49.png");
    }
    else if(x==50)
    {
        surface = IMG_Load("allcards/img50.png");
    }
    else if(x==51)
    {
        surface = IMG_Load("allcards/img51.png");
    }
    else if(x==52)
    {
        surface = IMG_Load("allcards/img52.png");
    }




    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest;
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w = 130;
    dest.h = 150;
    dest.x = 95+y*(110-35);
    dest.y = 560;

    SDL_RenderCopy(rend, tex, NULL,&dest);

}

int battlewon(SDL_Renderer* rend, SDL_Texture* texbg, SDL_Rect destbg, SDL_Texture* texp2, SDL_Rect destp2,SDL_Texture* texp3, SDL_Rect destp3,SDL_Texture* texp4, SDL_Rect destp4,SDL_Texture* texbatt, SDL_Rect destbatt)
{




    destp4.x+=50;
    destp2.x-=150;
    SDL_RenderCopy(rend, texbg, NULL,&destbg);
    SDL_RenderCopy(rend, texp3, NULL,&destp3);
    SDL_RenderCopy(rend, texp2, NULL,&destp2);
    SDL_RenderCopy(rend, texp4, NULL,&destp4);
    SDL_RenderCopy(rend, texbatt, NULL,&destbatt);
    //SDL_RenderCopy(rend, texsco, NULL,&destsco);

    return 0;

}

int welcome(SDL_Renderer* rend)
{
    /*
        Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
        	// load music
    				Mix_Music*backgroundSound=Mix_LoadMUS("game.mp3");
    				Mix_PlayMusic(backgroundSound, -1);
    bool success = true;
    */

    SDL_Surface* surface = IMG_Load("image/game surface.jpg");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    int x;
    surface = IMG_Load("image/play.jpg");
    SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect play;
    play.w=300;
    play.h =75;
    play.x = 465;
    play.y = 60;




    surface = IMG_Load("image/instruction.jpg");
    SDL_Texture* tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect instruction;
    instruction.w=300;
    instruction.h =75;
    instruction.x = 465;
    instruction.y = 220;

    surface = IMG_Load("image/credit.jpg");
    SDL_Texture* tex4 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect credit;
    credit.w=300;
    credit.h =75;
    credit.x = 465;
    credit.y = 380;



    surface = IMG_Load("image/quit.jpg");
    SDL_Texture* tex5 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect quit;
    quit.w=300;
    quit.h =75;
    quit.x = 465;
    quit.y = 540;

    int okyfine = 0;
    int mousex, mousey;
    while(!okyfine)
    {
        SDL_Event event;
        //int buttons = SDL_GetMouseState(&mousex, &mousey);
        // printf("%d %d\n",mousex,mousey);




        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex, NULL, NULL);
        SDL_RenderCopy(rend, tex2, NULL, &play);
        SDL_RenderCopy(rend, tex3, NULL, &instruction);
        SDL_RenderCopy(rend, tex4, NULL, &credit);
        SDL_RenderCopy(rend, tex5, NULL, &quit);
        SDL_RenderPresent(rend);

        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                okyfine = 1;
                return 1;
            }
            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    //printf("left button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    //printf("%d %d\n",mousex,mousey);
                    if(mousex>465&&mousex<765)
                    {
                        if(mousey>60&&mousey<135)
                        {
                            okyfine=1;
                            break;
                        }
                        else if(mousey>220&&mousey<295)//instructions
                        {
                            // okyfine=1;
                            break;
                        }
                        else if(mousey>380&&mousey<455)//credit
                        {
                            surface = IMG_Load("pic/credit.jpg");
                            SDL_Texture* texcredit = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect credit;
                            credit.w=1280;
                            credit.h=720;
                            credit.x = 0;
                            credit.y = 0;



                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, texcredit, NULL, &credit);
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
                                        fg=1;
                                        break;

                                    }
                                }

                            }




                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, tex, NULL, NULL);
                            SDL_RenderCopy(rend, tex2, NULL, &play);
                            SDL_RenderCopy(rend, tex3, NULL, &instruction);
                            SDL_RenderCopy(rend, tex4, NULL, &credit);
                            SDL_RenderCopy(rend, tex5, NULL, &quit);
                            SDL_RenderPresent(rend);






                            break;
                        }
                        else if(mousey>540&&mousey<615)//quit
                        {
                            return 1;
                        }

                    }

                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");

                }
            }
        }


    }



}

int menu(SDL_Renderer* rend)
{

    SDL_Surface* surface;
    SDL_Rect dest;

    surface = IMG_Load("pic/menuoption.jpg");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w = 1280;
    dest.h = 720;
    dest.x = 0;
    dest.y = 0;
    //SDL_RenderClear(rend);
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex, NULL,&dest);
    SDL_RenderPresent(rend);


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

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mousex, &mousey);
                    if(mousex>525&&mousex<775&&mousey>87&&mousey<211)
                    {
                        //continue has been clicked
                        return 500;

                    }
                    else if(mousex>525&&mousex<775&&mousey>295&&mousey<425)
                    {
                        //new game has been clicked
                        return 600;

                    }
                    else if(mousex>525&&mousex<775&&mousey>496&&mousey<621)
                    {

                        //quit return 600;

                    }


                }

                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n",mousex,mousey);


                }
                //break;




            }

        }


    }

    return icon;



}
int biddingwindow(SDL_Renderer* rend, SDL_Texture* texbid, SDL_Rect biddest,int *p1)
{

    SDL_Surface* surface;
    SDL_Texture* tex;
    SDL_Rect dest;
/*
    surface = IMG_Load("pic/bid.jpg");

    tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w = 600;
    dest.h = 350;
    dest.x = 366;
    dest.y = 142;
    //SDL_RenderClear(rend);

    //SDL_RenderCopy(rend, texbg, NULL,&destbg);
    SDL_RenderCopy(rend, tex, NULL,&dest);
    SDL_RenderPresent(rend);
    // SDL_Delay(1000);
*/



                  SDL_RenderClear(rend);
                  SDL_RenderCopy(rend, texbid, NULL,&biddest);
                  for(int i=0; i<13; i++)
                        {
                            cardshow(p1[i],i+1,rend);

                        }

                SDL_RenderPresent(rend);
    //int close = 0,icon=-2,ree;
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
                fg=1;
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
                case SDL_SCANCODE_7:
                    icon=7;
                    break;
                case SDL_SCANCODE_8:
                    icon=8;
                    break;
                case SDL_SCANCODE_9:
                    icon=9;
                    break;
                default:
                    icon=-1;

                }
         /*
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    // printf("left button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    //  printf("%d %d\n",mousex,mousey);
                    if(mousex>38&&mousex<160&&mousey>40&&mousey<92)
                    {
                        fg=1;
                        menuoutput=menu(rend);
                        // printf("menuout is %d",menuoutput);
                        if(menuoutput==500)
                        {
                            return 1001;
                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, tex, NULL,&dest);
                            SDL_RenderCopy(rend, tex, NULL,&dest);
                            SDL_RenderPresent(rend);


                        }
                        else if(menuoutput==600)
                        {
                            return 1002;
                        }


                    }

                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n",mousex,mousey);


                }
                break;

                */


            }

        }

    }


    return icon;
}

//int okayscorecopy(SDL_Renderer* rend,int* given)
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
    dest.w = 145;
    dest.h = 65;

    if(i==0)
    {
        dest.x = 535;
        dest.y = 540;
    }
    else if(i==1)
    {
        dest.x = 830;
        dest.y = 260+40;
    }

    else if(i==2)
    {
        dest.x = 535;
        dest.y = 155+10;
    }

    else if(i==3)
    {
        dest.x = 170+80;
        dest.y = 260+40;
    }
    /*
    dest.x = WINDOW_WIDTH-46*(4-i);
    dest.y = 0;
    */
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
int constantwindow(SDL_Renderer* rend,int *given,int* score, SDL_Texture* texbg, SDL_Rect destbg, SDL_Texture* texp2, SDL_Rect destp2,SDL_Texture* texp3, SDL_Rect destp3,SDL_Texture* texp4, SDL_Rect destp4,SDL_Texture* texsco, SDL_Rect destsco,SDL_Texture* texbat, SDL_Rect destbat)  //SDL_RenderCopy(rend, tex, NULL,&dest);
{
    SDL_RenderCopy(rend, texbg, NULL,&destbg);
    //SDL_RenderCopy(rend, texp3, NULL,&destp3);
    //SDL_RenderCopy(rend, texp2, NULL,&destp2);
    //SDL_RenderCopy(rend, texp4, NULL,&destp4);
    //SDL_RenderCopy(rend, texbat, NULL,&destbat);
    //SDL_RenderCopy(rend, texsco, NULL,&destsco);
    return 0;

}


