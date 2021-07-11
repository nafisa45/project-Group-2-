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
                        Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                        Mix_Music*backgroundSound=Mix_LoadMUS("sound/game.mp3");
                        Mix_PlayMusic(backgroundSound, -1);


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
                            Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                            Mix_Music*backgroundSound=Mix_LoadMUS("sound/mouseclick.mp3");
                            Mix_PlayMusic(backgroundSound, -1);
                            SDL_Delay(400);
                            Mix_PauseMusic();

                            return 1001;

                        }
                        else if(menuoutput==600)
                        {
                            //new game is clicked
                            Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                            Mix_Music*backgroundSound=Mix_LoadMUS("sound/mouseclick.mp3");
                            Mix_PlayMusic(backgroundSound, -1);
                            SDL_Delay(400);
                            Mix_PauseMusic();

                            return 1002;
                        }
                        else if(menuoutput==700)
                        {
                            //quit hasbeen clicked
                            Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                            Mix_Music*backgroundSound=Mix_LoadMUS("sound/mouseclick.mp3");
                            Mix_PlayMusic(backgroundSound, -1);
                            SDL_Delay(400);
                            Mix_PauseMusic();

                            return 1000;
                        }


                    }

                    else if(mousex>1140&&mousex<1260&&mousey>30&&mousey<80)//pointable button clicked
                    {

                        Mix_Music*backgroundSound=Mix_LoadMUS("sound/game.mp3");
                        Mix_PlayMusic(backgroundSound, -1);

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
                        SDL_Delay(300);

                        battlewon(rend);
                        return 1003;


                    }

                    else if(mousex>190&&mousex<305&&mousey>15&&mousey<70) //help button clicked
                    {

                        //Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                        Mix_Music*backgroundSound=Mix_LoadMUS("sound/game.mp3");
                        Mix_PlayMusic(backgroundSound, -1);

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


                        surface = IMG_Load("pic/help.jpg");
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
                                case SDL_KEYDOWN:
                                {
                                    if(event.key.keysym.scancode==SDL_SCANCODE_KP_ENTER)
                                    {

                                        fg=1;
                                        surface = IMG_Load("button/round.png");
                                        SDL_Texture* texokbutton = SDL_CreateTextureFromSurface(rend, surface);
                                        SDL_FreeSurface(surface);
                                        SDL_Rect okbutton;
                                        okbutton.w=98;
                                        okbutton.h =60;
                                        okbutton.x = 1169;
                                        okbutton.y = 21;
                                        SDL_RenderCopy(rend, texokbutton, NULL,&okbutton);
                                        SDL_RenderPresent(rend);
                                        SDL_Delay(300);
                                        Mix_Music*backgroundSound=Mix_LoadMUS("sound/mouseclick.mp3");
                                        Mix_PlayMusic(backgroundSound, -1);
                                        SDL_Delay(300);
                                        Mix_PauseMusic();

                                        return 1001;



                                    }
                                    else if(event.key.keysym.scancode== SDL_SCANCODE_M)
                                    {
                                        Mix_PauseMusic();
                                    }
                                    else if(event.key.keysym.scancode== SDL_SCANCODE_P)
                                    {
                                        Mix_Music*backgroundSound=Mix_LoadMUS("sound/game.mp3");
                                        Mix_PlayMusic(backgroundSound, -1);

                                    }






                                }
                                case SDL_MOUSEBUTTONDOWN:
                                    if(event.button.button==SDL_BUTTON_LEFT)
                                    {
                                        SDL_GetMouseState(&mousex, &mousey);

                                        if(mousex>1170&&mousex<1270&&mousey>22&&mousey<80) //ok is clicked
                                        {
                                            fg=1;
                                            surface = IMG_Load("button/round.png");
                                            SDL_Texture* texokbutton = SDL_CreateTextureFromSurface(rend, surface);
                                            SDL_FreeSurface(surface);
                                            SDL_Rect okbutton;
                                            okbutton.w=98;
                                            okbutton.h =60;
                                            okbutton.x = 1169;
                                            okbutton.y = 21;
                                            SDL_RenderCopy(rend, texokbutton, NULL,&okbutton);
                                            SDL_RenderPresent(rend);
                                            Mix_Music*backgroundSound=Mix_LoadMUS("sound/mouseclick.mp3");
                                            Mix_PlayMusic(backgroundSound, -1);
                                            SDL_Delay(300);
                                            Mix_PauseMusic();
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
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Music*backgroundSound=Mix_LoadMUS("sound/cardplay.mp3");
    Mix_PlayMusic(backgroundSound, -1);
    SDL_Delay(400);
    Mix_PauseMusic();

    return icon;

}




