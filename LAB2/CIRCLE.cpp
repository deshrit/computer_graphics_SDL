/// MIDPOINT CIRCLE ALGORITHM

#include <iostream>
#include <SDL.h>

using namespace std;

void MIDPOINTCIRCLE(int a, int b, int r, SDL_Renderer *renderer)
{
    // Set color for drawing
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    int x = 0, y = r; float p;
    SDL_RenderDrawPoint(renderer, a, b+r);
    SDL_RenderDrawPoint(renderer, a, b-r);
    SDL_RenderDrawPoint(renderer, a-r, b);
    SDL_RenderDrawPoint(renderer, a+r, b);

    p = (5 / 4) - r;
    while(x <= y) {
        x++;
        if(p < 0) {
            p = p + 2 * x + 3;
        }
        else {
            p = p + 2*x - 2*y + 5;
            y--;
        }

        SDL_RenderDrawPoint(renderer, a+x, b+y);
        SDL_RenderDrawPoint(renderer, a-x, b+y);

        SDL_RenderDrawPoint(renderer, a+x, b-y);
        SDL_RenderDrawPoint(renderer, a-x, b-y);

        SDL_RenderDrawPoint(renderer, a+y, b+x);
        SDL_RenderDrawPoint(renderer, a-y, b+x);

        SDL_RenderDrawPoint(renderer, a+y, b-x);
        SDL_RenderDrawPoint(renderer, a-y, b-x);
    }

    // Draw to window
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
    cout << "### MID POINT CIRCLE ###\n\n";
    int a, b, r;
    cout << "Enter center: ";
    cin >> a >> b;
    cout << "Enter radius r: ";
    cin >> r;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window *window = SDL_CreateWindow("MID POINT CIRCLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
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

        MIDPOINTCIRCLE(a, b, r, renderer);

        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
