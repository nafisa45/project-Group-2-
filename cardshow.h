int cardshowtable(int x,int y,SDL_Renderer* rend) // this function card shows on table
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

int cardshow(int x,int y,SDL_Renderer* rend) //make visiul of guests card
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


