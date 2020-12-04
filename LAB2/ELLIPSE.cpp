/// MID POINT ELLIPSE

#include <iostream>
#include <SDL.h>
#include <cmath>

using namespace std;

void MIDPOINTELIPSE(int a, int b, int rx, int ry, SDL_Renderer* renderer)
{
    // Set Color for the drawing
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    int x = 0, y = ry; float p1, p2;

    SDL_RenderDrawPoint(renderer, a, b+ry);
    SDL_RenderDrawPoint(renderer, a, b-ry);

    // Region one
    p1 = ry*ry + (rx*rx)/4 - ry*rx*rx;
    while((2*x*ry*ry) <= (2*y*rx*rx)) {
        x++;
        if(p1 < 0) {
            p1 = p1 + ry*ry*(2*x + 1);
        }
        else {
            y--;
            p1 = p1 + 2*x*ry*ry + ry*ry - 2*y*rx*rx;
        }
        SDL_RenderDrawPoint(renderer, a+x, b+y);
        SDL_RenderDrawPoint(renderer, a+x, b-y);
        SDL_RenderDrawPoint(renderer, a-x, b+y);
        SDL_RenderDrawPoint(renderer, a-x, b-y);
    }

    // Region two
    p2 = pow(ry, 2)*pow((x + 1/2), 2) + pow(rx, 2)*pow((y-1), 2)-(rx*rx*ry*ry);
    while(y >= 0) {
        y--;
        if(p2 < 0) {
            x++;
            p2 = p2 + ry*ry*(2*x) -2*y*rx*rx + rx*rx;
        }
        else {
            p2 = p2 - (2*y*rx*rx) + rx*rx;
        }
        SDL_RenderDrawPoint(renderer, a+x, b+y);
        SDL_RenderDrawPoint(renderer, a+x, b-y);
        SDL_RenderDrawPoint(renderer, a-x, b+y);
        SDL_RenderDrawPoint(renderer, a-x, b-y);
    }

    // Display to window
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    cout << "### MID POINT ELIPSE ###\n\n";
    int a, b, rx, ry;
    cout << "Enter center: ";
    cin >> a >> b;
    cout << "Enter radius rx and ry: ";
    cin >> rx >> ry;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window *window = SDL_CreateWindow("MID POINT ELLIPSE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT)
                quit = true;
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        MIDPOINTELIPSE(a, b, rx, ry, renderer);

        SDL_Delay(100);
   }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
