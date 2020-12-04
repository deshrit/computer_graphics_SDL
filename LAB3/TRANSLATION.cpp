/// TRANSLATION

#include <iostream>
#include <SDL.h>

using namespace std;

void TRIANGLE(SDL_Point a, SDL_Point b, SDL_Point c, SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, b.x, b.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, a.x, a.y);

    SDL_RenderPresent(renderer);
}

void TRANSLATION(SDL_Point a, SDL_Point b, SDL_Point c, int tfx, int tfy, SDL_Renderer* renderer)
{
    a.x += tfx;
    a.y += tfy;
    b.x += tfx;
    b.y += tfy;
    c.x += tfx;
    c.y += tfy;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, b.x, b.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, a.x, a.y);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    cout << "### TRANSLATION ###\n\n";
    int x1, y1, x2, y2, x3, y3, tfx, tfy;
    cout << "Enter 3 vertices of triangle: "; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Enter translation factor x and y: "; cin >> tfx >> tfy;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window* window = SDL_CreateWindow("TRANSLATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 640, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    SDL_Point a = {x1, y1}, b = {x2, y2}, c = {x3, y3};

    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT)
                quit = true;
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        TRIANGLE(a, b, c, renderer);
        TRANSLATION(a, b, c, tfx, tfy, renderer);

        SDL_Delay(100);
   }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
