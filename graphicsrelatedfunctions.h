int battlewon(SDL_Renderer* rend) //that function will take the pointable background to the renderer
{



    SDL_RenderClear(rend);
    SDL_Surface* surface = IMG_Load("pic/finalpointtable.jpg");
    SDL_Texture* texfinalpointtable = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect destfinalpointtable;
    SDL_QueryTexture(texfinalpointtable, NULL, NULL, &destfinalpointtable.w, &destfinalpointtable.h);
    destfinalpointtable.w = 1280;
    destfinalpointtable.h = 720;
    SDL_RenderCopy(rend, texfinalpointtable, NULL,&destfinalpointtable);

    return 0;

}

int welcome(SDL_Renderer* rend) // this function will present the most beginning window
{

    SDL_Surface* surface = IMG_Load("image/game surface.jpg");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    int x;
    int okyfine = 0;
    int fg=0;
    int mousex, mousey;

    surface = IMG_Load("image/play.jpg");
    SDL_Texture* tex2= SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect play;
    play.w=300;
    play.h =75;
    play.x = 465;
    play.y = 60;


    surface = IMG_Load("image/soundgame.jpg");
    SDL_Texture* texsound = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect sound;
    sound.w=1280;
    sound.h =720;
    sound.x = 0;
    sound.y = 0;

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texsound, NULL, &sound);
    SDL_RenderPresent(rend);

    while(!okyfine&&fg==0)
    {
        SDL_Event event;
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

                    SDL_GetMouseState(&mousex, &mousey);
                    //printf("%d %d\n",mousex,mousey);
                    if(mousex>197&&mousex<432&&mousey>477&&mousey<619) //yes is clicked
                    {


                        surface = IMG_Load("button/yes.jpg");
                        SDL_Texture* texokbutton = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect okbuttton;
                        okbuttton.w=250;
                        okbuttton.h =155;
                        okbuttton.x = 190;
                        okbuttton.y = 470;


                        SDL_RenderCopy(rend, texokbutton, NULL, &okbuttton);
                        SDL_RenderPresent(rend);
                        SDL_Delay(300);


                        //printf("left button pressed\n");

                        fg=1;

                        //music load
                        Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                        Mix_Music*backgroundSound=Mix_LoadMUS("game.mp3");
                        Mix_PlayMusic(backgroundSound, -1);
                        bool success = true;



                    }
                    else if(mousex>522&&mousex<791&&mousey>474&&mousey<619) //no is clicked
                    {



                        surface = IMG_Load("button/no.jpg");
                        SDL_Texture* texokbutton = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect okbuttton;
                        okbuttton.w=280;
                        okbuttton.h =155;
                        okbuttton.x = 519;
                        okbuttton.y = 470;


                        SDL_RenderCopy(rend, texokbutton, NULL, &okbuttton);
                        SDL_RenderPresent(rend);
                        SDL_Delay(300);

                        fg=1;
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
                            surface = IMG_Load("button/play.png");
                            SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect redline;
                            redline.w=310;
                            redline.h =85;
                            redline.x = 460;
                            redline.y = 55;
                            SDL_RenderCopy(rend, tex01, NULL,&redline);
                            SDL_RenderPresent(rend);
                            SDL_Delay(500);


                            okyfine=1;
                            break;
                        }
                        else if(mousey>220&&mousey<295)//instructions
                        {
                            surface = IMG_Load("button/ins.jpg");
                            SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect redline;
                            redline.w=310;
                            redline.h =85;
                            redline.x = 460;
                            redline.y = 215;
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




                            SDL_RenderClear(rend);
                            SDL_RenderCopy(rend, tex, NULL, NULL);
                            SDL_RenderCopy(rend, tex2, NULL, &play);
                            SDL_RenderCopy(rend, tex3, NULL, &instruction);
                            SDL_RenderCopy(rend, tex4, NULL, &credit);
                            SDL_RenderCopy(rend, tex5, NULL, &quit);
                            SDL_RenderPresent(rend);


                            // okyfine=1;
                            break;
                        }




                        else if(mousey>380&&mousey<455)//credit
                        {

                            surface = IMG_Load("button/Credit.png");
                            SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect redline;
                            redline.w=310;
                            redline.h =85;
                            redline.x = 460;
                            redline.y = 375;
                            SDL_RenderCopy(rend, tex01, NULL,&redline);
                            SDL_RenderPresent(rend);
                            SDL_Delay(300);


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
                                        if(event.button.button==SDL_BUTTON_LEFT)
                                        {
                                            SDL_GetMouseState(&mousex, &mousey);

                                            if(mousex>20&&mousex<220&&mousey>10&&mousey<120) //back is clicked
                                            {

                                                //printf("oky \n");
                                                fg=1;

                                                surface = IMG_Load("button/Back.png");
                                                SDL_Texture* texbackbutton = SDL_CreateTextureFromSurface(rend, surface);
                                                SDL_FreeSurface(surface);
                                                SDL_Rect backbutton;
                                                backbutton.w=200;
                                                backbutton.h=125;
                                                backbutton.x = 28;
                                                backbutton.y = 5;

                                                SDL_RenderCopy(rend, texbackbutton, NULL,&backbutton);
                                                SDL_RenderPresent(rend);
                                                SDL_Delay(300);


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

                            surface = IMG_Load("button/quit.png");
                            SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                            SDL_FreeSurface(surface);
                            SDL_Rect redline;
                            redline.w=310;
                            redline.h =85;
                            redline.x = 460;
                            redline.y = 535;
                            SDL_RenderCopy(rend, tex01, NULL,&redline);
                            SDL_RenderPresent(rend);
                            SDL_Delay(500);


                            return 1;
                        }

                    }

                }
                else if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    printf("right button pressed\n");
                    SDL_GetMouseState(&mousex, &mousey);
                    printf("%d %d\n\n",mousex,mousey);


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

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex, NULL,&dest);
    SDL_RenderPresent(rend);


    int icon=-1,close=0,fg=0,menuoutput,flag=0;
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
                    if(mousex>525&&mousex<775&&mousey>87&&mousey<211) //continue has benn pressed
                    {
                        surface = IMG_Load("button/Continue.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=260;
                        redline.h =145;
                        redline.x = 520;
                        redline.y = 87;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(500);


                        //continue has been clicked
                        return 500;

                    }
                    else if(mousex>525&&mousex<775&&mousey>295&&mousey<425) //new game has been clicked
                    {

                        surface = IMG_Load("button/New.jpg");
                        SDL_Texture* tex01 = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect redline;
                        redline.w=260;
                        redline.h =145;
                        redline.x = 525;
                        redline.y = 285;
                        SDL_RenderCopy(rend, tex01, NULL,&redline);
                        SDL_RenderPresent(rend);
                        SDL_Delay(500);

                        //new game has been clicked
                        return 600;

                    }
                    else if(mousex>525&&mousex<775&&mousey>496&&mousey<621)
                    {
                        surface = IMG_Load("button/Quit.jpg");
                        SDL_Texture* texquit = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect quit;
                        quit.w=260;
                        quit.h =145;
                        quit.x = 525;
                        quit.y = 490;
                        SDL_RenderCopy(rend, texquit, NULL,&quit);
                        SDL_RenderPresent(rend);
                        SDL_Delay(300);


                        surface = IMG_Load("pic/quitwindow.jpg");  //this block is to render the window that display if really guest want to quit or not
                        SDL_Texture* texquitwindow = SDL_CreateTextureFromSurface(rend, surface);
                        SDL_FreeSurface(surface);
                        SDL_Rect quitwindow;
                        quitwindow.w=700;
                        quitwindow.h =280;
                        quitwindow.x = 280;
                        quitwindow.y = 208;
                        SDL_RenderCopy(rend, texquitwindow, NULL,&quitwindow);
                        SDL_RenderPresent(rend);


                        int Close=0, flag=0;
                        while(!close&&fg==0)
                        {
                            SDL_Event Event;
                            while(SDL_PollEvent(&Event))
                            {
                                switch(Event.type)
                                {
                                case SDL_QUIT:
                                    Close = 1;
                                    return 1000;
                                    break;
                                case SDL_MOUSEBUTTONDOWN:
                                    if(Event.button.button==SDL_BUTTON_LEFT)
                                    {
                                        SDL_GetMouseState(&mousex, &mousey);
                                        if(mousex>410&&mousex<570&&mousey>390&&mousey<445) // quit button is clicked and that will terminate the game
                                        {

                                            fg=1;
                                            quit.w=170;
                                            quit.h =65;
                                            quit.x = 405;
                                            quit.y = 385;
                                            SDL_RenderCopy(rend, texquit, NULL,&quit);
                                            SDL_RenderPresent(rend);
                                            SDL_Delay(300);
                                            return 700;

                                        }
                                        else if(event.button.button==SDL_BUTTON_LEFT)
                                        {
                                            SDL_GetMouseState(&mousex, &mousey);
                                            if(mousex>700&&mousex<860&&mousey>390&&mousey<445) //stay is clicked and that will continue the game
                                            {

                                                fg=1;
                                                surface = IMG_Load("button/Stay.jpg");
                                                SDL_Texture* texstay = SDL_CreateTextureFromSurface(rend, surface);
                                                SDL_FreeSurface(surface);
                                                SDL_Rect staybutton;
                                                staybutton.w=170;
                                                staybutton.h =65;
                                                staybutton.x = 690;
                                                staybutton.y = 385;
                                                SDL_RenderCopy(rend, texstay, NULL,&staybutton);
                                                SDL_RenderPresent(rend);
                                                SDL_Delay(300);
                                                return 500;
                                            }


                                        }



                                    }
                                    else if(Event.button.button==SDL_BUTTON_RIGHT)
                                    {
                                        printf("right button pressed\n");
                                        SDL_GetMouseState(&mousex, &mousey);
                                        printf("%d %d\n",mousex,mousey);


                                    }

                                }

                            }

                        }





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


int constantwindow(SDL_Renderer* rend,SDL_Texture* texbg, SDL_Rect destbg)  //SDL_RenderCopy(rend, tex, NULL,&dest);
{
    SDL_RenderCopy(rend, texbg, NULL,&destbg);
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

