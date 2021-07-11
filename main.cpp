//dimonds,club,hearts,spades;
//game load s contain all data from file

#include<stdio.h>
#include<stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#define WINDOW_WIDTH (1220)
#define WINDOW_HEIGHT (610)

struct imginfo
{
   SDL_Texture* tex;
   SDL_Rect dest;

};
typedef struct imginfo imginfo;

#define SCROLL_SPEED (900)
#define RECT_SPEED (5.0)
#include "score.h"
#include "cardshow.h"
#include "point.h"
#include "bid.h"
#include "graphicsrelatedfunctions.h"
#include "cppcoderelatedfunctions.h"
#include "dealcard.h"
#include "buttonpressed.h"


int main()
{

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
    SDL_Window* win = SDL_CreateWindow("SDL Demonstration",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    TTF_Init();



    imginfo n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,n26;
    int p1[13],finalscore[4]= {0},gameover,close,icon,fg,x,p2[13],p3[13],p4[13],shufflecard[52]= {0},gameno=0,data[100000],card[52]= {0},i,j,k,temp,start,flag=0,res=0,rem=0,test;
    char ch;
    dataload(data);



    SDL_Surface* surface;
    SDL_Texture* tex;
    SDL_Rect dest;



    surface = IMG_Load("pic/bg.jpg");
    SDL_Texture* texbg = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect destbg;
    SDL_QueryTexture(texbg, NULL, NULL, &destbg.w, &destbg.h);
    destbg.w = 1280;
    destbg.h = 720;
    destbg.x = 0;
    destbg.y = 0;



    surface = IMG_Load("Number/0.jpg");
    SDL_Texture* tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest0;
    SDL_QueryTexture(tex0, NULL, NULL, &dest0.w, &dest0.h);
    dest0.w = 45;
    dest0.h = 20;
    n0.tex=tex0;
    n0.dest=dest0;





    surface = IMG_Load("Number/1.jpg");
    SDL_Texture* tex1 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest1;
    SDL_QueryTexture(tex1, NULL, NULL, &dest1.w, &dest1.h);
    dest1.w = 45;
    dest1.h = 20;
    n1.tex=tex1;
    n1.dest=dest1;





    surface = IMG_Load("Number/2.jpg");
    SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest2;
    SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);
    dest2.w = 45;
    dest2.h = 20;
    n2.tex=tex2;
    n2.dest=dest2;




    surface = IMG_Load("Number/3.jpg");
    SDL_Texture* tex3 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest3;
    SDL_QueryTexture(tex3, NULL, NULL, &dest3.w, &dest3.h);
    dest3.w = 45;
    dest3.h = 20;
    n3.tex=tex3;
    n3.dest=dest3;





    surface = IMG_Load("Number/4.jpg");
    SDL_Texture* tex4 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest4;
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w = 45;
    dest4.h = 20;
    n4.tex=tex4;
    n4.dest=dest4;






    surface = IMG_Load("Number/5.jpg");
    SDL_Texture* tex5 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest5;
    SDL_QueryTexture(tex5, NULL, NULL, &dest5.w, &dest5.h);
    dest5.w = 45;
    dest5.h = 20;
    n5.tex=tex5;
    n5.dest=dest5;







    surface = IMG_Load("Number/6.jpg");
    SDL_Texture* tex6 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest6;
    SDL_QueryTexture(tex6, NULL, NULL, &dest6.w, &dest6.h);
    dest6.w = 45;
    dest6.h = 20;
    n6.tex=tex6;
    n6.dest=dest6;






    surface = IMG_Load("Number/7.jpg");
    SDL_Texture* tex7 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest7;
    SDL_QueryTexture(tex7, NULL, NULL, &dest7.w, &dest7.h);
    dest7.w = 45;
    dest7.h = 20;
    n7.tex=tex7;
    n7.dest=dest7;






    surface = IMG_Load("Number/8.jpg");
    SDL_Texture* tex8 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest8;
    SDL_QueryTexture(tex8, NULL, NULL, &dest8.w, &dest8.h);
    dest8.w = 45;
    dest8.h = 20;
    n8.tex=tex8;
    n8.dest=dest8;





    surface = IMG_Load("Number/9.jpg");
    SDL_Texture* tex9 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest9;
    SDL_QueryTexture(tex9, NULL, NULL, &dest9.w, &dest9.h);
    dest9.w = 45;
    dest9.h = 20;
    n9.tex=tex9;
    n9.dest=dest9;






    surface = IMG_Load("Number/10.jpg");
    SDL_Texture* tex10 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest10;
    SDL_QueryTexture(tex10, NULL, NULL, &dest10.w, &dest10.h);
    dest10.w = 45;
    dest10.h = 20;
    n10.tex=tex10;
    n10.dest=dest10;






    surface = IMG_Load("Number/11.jpg");
    SDL_Texture* tex11 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest11;
    SDL_QueryTexture(tex11, NULL, NULL, &dest11.w, &dest11.h);
    dest11.w = 45;
    dest11.h = 20;
    n11.tex=tex11;
    n11.dest=dest11;





    surface = IMG_Load("Number/12.jpg");
    SDL_Texture* tex12 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest12;
    SDL_QueryTexture(tex12, NULL, NULL, &dest12.w, &dest12.h);
    dest12.w = 45;
    dest12.h = 20;
    n12.tex=tex12;
    n12.dest=dest12;





    surface = IMG_Load("Number/13.jpg");
    SDL_Texture* tex13 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest13;
    SDL_QueryTexture(tex13, NULL, NULL, &dest13.w, &dest13.h);
    dest13.w = 45;
    dest13.h = 20;
    n13.tex=tex13;
    n13.dest=dest13;





    surface = IMG_Load("Number/14.jpg");
    SDL_Texture* tex14 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest14;
    SDL_QueryTexture(tex14, NULL, NULL, &dest14.w, &dest14.h);
    dest14.w = 45;
    dest14.h = 20;
    n14.tex=tex14;
    n14.dest=dest14;





    surface = IMG_Load("Number/15.jpg");
    SDL_Texture* tex15 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest15;
    SDL_QueryTexture(tex15, NULL, NULL, &dest15.w, &dest15.h);
    dest15.w = 45;
    dest15.h = 20;
    n15.tex=tex15;
    n15.dest=dest15;





    surface = IMG_Load("Number/16.jpg");
    SDL_Texture* tex16 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest16;
    SDL_QueryTexture(tex16, NULL, NULL, &dest16.w, &dest16.h);
    dest16.w = 45;
    dest16.h = 20;
    n16.tex=tex16;
    n16.dest=dest16;





    surface = IMG_Load("Number/17.jpg");
    SDL_Texture* tex17 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest17;
    SDL_QueryTexture(tex17, NULL, NULL, &dest17.w, &dest17.h);
    dest17.w = 45;
    dest17.h = 20;
    n17.tex=tex17;
    n17.dest=dest17;





    surface = IMG_Load("Number/18.jpg");
    SDL_Texture* tex18 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest18;
    SDL_QueryTexture(tex18, NULL, NULL, &dest18.w, &dest18.h);
    dest18.w = 45;
    dest18.h = 20;
    n18.tex=tex18;
    n18.dest=dest18;





    surface = IMG_Load("Number/19.jpg");
    SDL_Texture* tex19 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest19;
    SDL_QueryTexture(tex19, NULL, NULL, &dest19.w, &dest19.h);
    dest19.w = 45;
    dest19.h = 20;
    n19.tex=tex19;
    n19.dest=dest19;





    surface = IMG_Load("Number/20.jpg");
    SDL_Texture* tex20 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest20;
    SDL_QueryTexture(tex20, NULL, NULL, &dest20.w, &dest20.h);
    dest20.w = 45;
    dest20.h = 20;
    n20.tex=tex20;
    n20.dest=dest20;





    surface = IMG_Load("Number/21.jpg");
    SDL_Texture* tex21 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest21;
    SDL_QueryTexture(tex21, NULL, NULL, &dest21.w, &dest21.h);
    dest21.w = 45;
    dest21.h = 20;
    n21.tex=tex21;
    n21.dest=dest21;





    surface = IMG_Load("Number/22.jpg");
    SDL_Texture* tex22 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest22;
    SDL_QueryTexture(tex22, NULL, NULL, &dest22.w, &dest22.h);
    dest22.w = 45;
    dest22.h = 20;
    n22.tex=tex22;
    n22.dest=dest22;





    surface = IMG_Load("Number/23.jpg");
    SDL_Texture* tex23 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest23;
    SDL_QueryTexture(tex23, NULL, NULL, &dest23.w, &dest23.h);
    dest23.w = 45;
    dest23.h = 20;
    n23.tex=tex23;
    n23.dest=dest23;





    surface = IMG_Load("Number/24.jpg");
    SDL_Texture* tex24 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest24;
    SDL_QueryTexture(tex24, NULL, NULL, &dest24.w, &dest24.h);
    dest24.w = 45;
    dest24.h = 20;
    n24.tex=tex24;
    n24.dest=dest24;





    surface = IMG_Load("Number/25.jpg");
    SDL_Texture* tex25 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest25;
    SDL_QueryTexture(tex25, NULL, NULL, &dest25.w, &dest25.h);
    dest25.w = 45;
    dest25.h = 20;
    n25.tex=tex25;
    n25.dest=dest25;


    //temp = numberload(rend,&n0,&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,&n10,&n11,&n12,&n13,&n14,&n15,&n16,&n17,&n18,&n19,&n20,&n21,&n22,&n23,&n24,&n25);


    surface = IMG_Load("pic/Bid .jpg");
    SDL_Texture* texbid = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Rect biddest;
    biddest.w=1280;
    biddest.h=720;




    test=welcome(rend);
    if(test==1||test==1000)
    {
        return 0;
    }







          //hey dear game has been started

    int highestpoint=0;
    int tempe=0;

    while(highestpoint<=24)
    {

        shuffle(data,shufflecard,&gameno); //taking card from database

        //distributing card to each player:
        distribute(p1,1,shufflecard);
        distribute(p2,2,shufflecard);
        distribute(p3,3,shufflecard);
        distribute(p4,4,shufflecard);

        //sorting each player card according to the card colour as well card power
        sorting(p1);
        for(int i=0;i<13;i++)
        sorting(p2);
        sorting(p3);
        sorting(p4);



        int call[4]= {0},cardnumber,current=1,battlenumber=1,sc1=0,sc2=0,sc3=0,sc4=0,given[4],fl1=0,fl2=0,score[4]= {0},rslt,newgame=0;

        while(battlenumber<14)
        {

             Mix_PauseMusic();
            if(battlenumber==1)  //this condition is for taking call when a particular slot of game just suppose to start with first battle
            {

                 Mix_PauseMusic();
                while(current==1) //this loop will continue untill getting valid call
                {

                    call[0]= biddingwindow(rend,texbid,biddest,p1,call[0]/1000);
                    if(call[0]==1000)
                    {
                        return 0;
                    }
                    else if(call[0]>999&&call[0]<10000)
                    {
                        //a number has been pressed
                        continue;

                    }
                    else if(call[0]>0&&call[0]<50)
                    {
                        // bid has been clicked with a number
                        current=0;
                        break;

                    }
                }
                call[1]=bid(p2);
                call[2]=bid(p3);
                call[3]=bid(p4);


                    Mix_Music*backgroundSound=Mix_LoadMUS("sound/shuffle.mp3");
                    Mix_PlayMusic(backgroundSound, -1);
                    SDL_Delay(800);
                    Mix_PauseMusic();


            }

            //taking bid is complete


            //#playcard start and calling screen is done


                    Mix_Music*backgroundSound=Mix_LoadMUS("sound/mouseclick.mp3");
                    Mix_PlayMusic(backgroundSound, -1);
                    SDL_Delay(300);
                    Mix_PauseMusic();



            start=0;
            int retfromplaycard=5000;
            while(retfromplaycard)
            {
                if(!start) // this condition is for the initial attempt to play a card
                {
                    SDL_RenderClear(rend);
                    constantwindow(rend,texbg,destbg);
                    temp = pointcopy(rend,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,score);

                     temp = callnumbercopy(rend,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,call);


                    for(int i=0; i<14-battlenumber; i++)
                    {
                        cardshow(p1[i],i+1,rend);

                    }

                    SDL_RenderPresent(rend); //this renderer will present the table with the card guest that guest have yet



                    x=playcard(battlenumber,rend);
                    while(x>14-battlenumber&&x!=1000&&x!=1001&&x!=1002&&x!=1003) //this loop is for taking card from guest and that will dismiss any kind of unwanted click or key press
                    {
                        x=playcard(battlenumber,rend);
                    }



                }

                else if(retfromplaycard>999&&retfromplaycard<1005) //if the condition satisfied that means guest didn't play card rather than clicked on a button
                {
                    x=retfromplaycard;
                }





                if(x==1000)  //if the condition satisfied that means guest requested to close the game
                {
                    datarearrange(data);
                    return 0;
                }
                else if(x==1001)// //if the condition satisfied that means guest has been pressed continue button . this block operates the playcard process again
                {
                    SDL_RenderClear(rend);
                    constantwindow(rend,texbg,destbg);

                    temp = callnumbercopy(rend,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,call);
                    temp = pointcopy(rend,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,score);

                    for(int i=0; i<14-battlenumber; i++)
                    {
                        cardshow(p1[i],i+1,rend);

                    }

                    SDL_RenderPresent(rend);



                    retfromplaycard = playcard(battlenumber,rend);
                    while(retfromplaycard>14-battlenumber&&retfromplaycard!=1000&&retfromplaycard!=1001&&retfromplaycard!=1002&&retfromplaycard!=1003) //this loop is for taking card from guest and that will dismiss any kind of unwanted click or key press
                    {
                        retfromplaycard=playcard(battlenumber,rend);
                    }

                    x=retfromplaycard;

                }

                else if(x==1002) //newgame button has been clicked
                {
                    finalscore[4]= {0};
                    newgame =1;
                    datarearrange(data);
                    break;

                }

                else if(x>0&&x<15)//card has been clicked
                {
                    x=x;
                    break;
                }
                else if(x==1003)//pointable has been clicked
                {

                      finalscorepresenting(finalscore,rend);
                      SDL_RenderPresent(rend);
                      temp= pointableokbutton(rend);


                    if(temp==1000)
                    {
                        return 0;
                    }

                    x=1001;
                     Mix_PauseMusic();


                }



            }
            if(newgame==1) //that condition commands to have a new game anyway
            {   for(int j=0; j<4; j++)
                {
                  finalscore[j]=0;
                }
                break;
            }

             // guest commanded to play his or her particular card;

            given[0]=takecard(p1,0,battlenumber,1,x);
            given[1]=takecard(p2,1,battlenumber,given[0],x);
            given[2]=takecard(p3,1,battlenumber,given[0],x);
            given[3]=takecard(p4,1,battlenumber,given[0],x);

           // card has been played by guest and given array taking the card that played other player as well guest



            // now preparing the render that will present the played card on the table;
            SDL_RenderClear(rend);
            constantwindow(rend,texbg,destbg);


                    temp = callnumbercopy(rend,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,call);
                    temp = pointcopy(rend,n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,score);

            cardshowtable(given[0],0,rend);
            cardshowtable(given[1],1,rend);
            cardshowtable(given[2],2,rend);
            cardshowtable(given[3],3,rend);
            for(int i=0; i<14-battlenumber-1; i++)
            {
                cardshow(p1[i],i+1,rend);

            }



            SDL_RenderPresent(rend); //this renderer will present the table with the cards that have been played on table
            icon= winclose(rend);
            if(icon==1000)     //if the condition satisfied that means guest requested to close the game
            {
                 datarearrange(data);
                return 0;
            }

            else if(icon==1002) //newgame button has been clicked
            {
                datarearrange(data);
               // finalscore[4]= {0};
                newgame=1;
                break;
            }
            else if(icon==1003) //pointable has been clicked
            {

                                    //  Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
                     //SDL_Delay(400);


                finalscorepresenting(finalscore,rend);
                SDL_RenderPresent(rend);

                temp= pointableokbutton(rend);

                if(temp==1000) //if the condition satisfied that means guest requested to close the game
                {
                    return 0;
                }


            }


            if(newgame==1)  // if new game pressed before that loop will assigned each score 0 and will start a new game
            {
                for(int j=0; j<4; j++)
                {
                  finalscore[j]=0;
                }

                break;
            }

            //#played cards have been shown on the table


            // below codes are for resulting the issue who have won that battle according to the played card
            rslt=result(given);
            score[rslt]++;
            battlenumber++;



            // battlenumber ==14 refers that there are no more available to anybody to play. so this is time for scoring according to the bid that each set and compared with the achieved point at this particulur slot
            if(battlenumber==14)
            {
                highestpoint = scoring(finalscore,score,call); // highest point is taking to make decision if any player already won ?


                // this blocks of code is written to presents the final pointable after completing a single slot of a game


                SDL_RenderClear(rend);
                surface = IMG_Load("pic/scoreboard.jpg");
                SDL_Texture* texfinalpointtable = SDL_CreateTextureFromSurface(rend, surface);
                SDL_FreeSurface(surface);
                SDL_Rect destfinalpointtable;
                SDL_QueryTexture(texfinalpointtable, NULL, NULL, &destfinalpointtable.w, &destfinalpointtable.h);
                destfinalpointtable.w = 1280;
                destfinalpointtable.h = 720;
                SDL_RenderCopy(rend, texfinalpointtable, NULL,&destfinalpointtable);
                finalscorepresenting(finalscore,rend);
                SDL_RenderPresent(rend);

                Mix_Music*backgroundSound=Mix_LoadMUS("sound/game.mp3");
                Mix_PlayMusic(backgroundSound, -1);

                temp= pointableokbutton(rend);
                 Mix_PauseMusic();
                if(temp==1000)// if close button has been clicked
                {
                    return 0;
                }



            }






        }


        gameno++;
        if(highestpoint>24) // that means a player have been won already
        {
            highestpoint = 0;
            gameno=0;
            datarearrange(data);
                test=welcome(rend);
               if(test==1||test==1000)
              {
                   return 0;
               }

               for(int j=0; j<4; j++)
                finalscore[j]=0;


        }

    }


    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}




