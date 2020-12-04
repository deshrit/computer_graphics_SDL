/// SCALING

#include <iostream>
#include <SDL.h>
#include <cmath>

using namespace std;

void TRIANGLE(SDL_Point a, SDL_Point b, SDL_Point c, SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, b.x, b.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, a.x, a.y);

    SDL_RenderPresent(renderer);
}

void SCALING(SDL_Point a, SDL_Point b, SDL_Point c, float sf, SDL_Renderer* renderer)
{
    float ax, ay, bx, by, cx, cy;
    ax = abs(round(a.x * sf));
    ay = abs(round(a.y * sf));

    bx = abs(round(b.x * sf));
    by = abs(round(b.y * sf));

    cx = abs(round(c.x * sf));
    cy = abs(round(c.y * sf));

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, ax, ay, bx, by);
    SDL_RenderDrawLine(renderer, bx, by, cx, cy);
    SDL_RenderDrawLine(renderer, cx, cy, ax, ay);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    cout << "### SCALING ###\n\n";
    int x1, y1, x2, y2, x3, y3;
    float sf;
    cout << "Enter 3 vertices of triangle: "; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Scaling factor: "; cin >> sf;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window* window = SDL_CreateWindow("SCALING", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 640, SDL_WINDOW_SHOWN);
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
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        TRIANGLE(a, b, c, renderer);
        SCALING(a, b, c, sf, renderer);

        SDL_Delay(100);
   }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
