
#include<stdio.h>
#include<stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#define WINDOW_WIDTH (900)
#define WINDOW_HEIGHT (500)
#define SCROLL_SPEED (900)
#define RECT_SPEED (5.0)
#include <SDL2/SDL_ttf.h>




int winclose()
{

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
            case SDL_KEYDOWN:
                fg=1;

            }

        }

    }
    return 0;

}



int welcome(SDL_Renderer* rend)
{
    SDL_Surface* surface;
    SDL_Texture* tex;
    SDL_Rect dest;
    int icon,close=0,fg=0;

    surface = IMG_Load("pic/bg.jpg");

    tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w = WINDOW_WIDTH;
    dest.h = WINDOW_HEIGHT;
    dest.x = 0;
    dest.y = 0;



              SDL_RenderCopy(rend, tex, NULL,&dest);

               int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    //success = false;
                }

                 //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                   // success = false;
                }


    //this opens a font style and sets a size
    TTF_Font* Sans = TTF_OpenFont("arial.ttf",24);

    if(!Sans)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        // handle error
    }
    printf("i am done\n");


// this is the color in rgb format,
// maxing out all would give you the color white,
// and it will be your text's color
    SDL_Color White = {255, 255, 255};

// as TTF_RenderText_Solid could only be used on
// SDL_Surface then you have to create the surface first
    char str[5];
    scanf("%s",&str);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans,str, White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(rend, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 50; // controls the height of the rect


    SDL_RenderCopy(rend, Message, NULL, &Message_rect);

// Don't forget to free your surface and texture




    SDL_RenderPresent(rend);
    winclose();
    //SDL_Delay(3000);
}







int main()
{


    int p1[13],finalscore[4]= {0},gameover,close,icon,fg,x,p2[13],p3[13],p4[13],shufflecard[52]= {0},gameno=0,data[100000],card[52]= {0},i,j,k,temp,flag=0,res=0,rem=0,test;

    char ch;

    SDL_Surface* surface;
    SDL_Texture* tex;
    SDL_Rect dest;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
    {
        printf("video and timer: %s\n",SDL_GetError());
    }

    printf("Initialization Complete\n");

    SDL_Window* win = SDL_CreateWindow("SDL Demonstration",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (!win)
    {
        printf("window: %s\n",SDL_GetError());
        SDL_Quit();
        return 1;
    }



    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend)
    {
        printf("renderer: %s\n",SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }





    test=welcome(rend);
    winclose();


    return 0;
}





