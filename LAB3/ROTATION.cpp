/// ROTATION

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

void ROTATION(SDL_Point a, SDL_Point b, SDL_Point c, int rdeg, SDL_Renderer* renderer)
{
    float angle = rdeg * 3.1415/180;
    float cosine = cos(angle);
    float sine = sin(angle);

    a.x = round(a.x*cosine - a.y*sine);
    a.y = round(a.y*cosine + a.x*sine);

    b.x = round(b.x*cosine - b.y*sine);
    b.y = round(b.y*cosine + b.x*sine);

    c.x = round(c.x*cosine - c.y*sine);
    c.y = round(c.y*cosine + c.x*sine);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, b.x, b.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, a.x, a.y);

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    cout << "### ROTATION ###\n\n";
    int x1, y1, x2, y2, x3, y3;
    float rdeg;
    cout << "Enter 3 vertices of triangle: "; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Rotation factor(deg): "; cin >> rdeg;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window* window = SDL_CreateWindow("ROTATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 640, SDL_WINDOW_SHOWN);
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
        ROTATION(a, b, c, rdeg, renderer);

        SDL_Delay(100);
   }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
