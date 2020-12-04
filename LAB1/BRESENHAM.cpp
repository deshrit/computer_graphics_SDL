/// BRESENHAM LINE ALGORITHM

#include <iostream>
#include <SDL.h>

using namespace std;

void BRESENHAM(int x1, int y1, int x2, int y2, SDL_Renderer *renderer)
{
    // Set drawing color r,g,b,a
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    int steps;
    int x, y, dx, dy, d;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    d = 2 * dy - dx;

    steps = abs(x2);

    while(x <= steps) {
        if(d >= 0) {
            SDL_RenderDrawPoint(renderer, x, y);
            d = d + 2*dy - 2*dx;
            x = x + 1;
            y = y + 1;

        }
        else if(d < 0){
            SDL_RenderDrawPoint(renderer, x, y);
            d = d + 2*dy;
            x = x + 1;
            y = y;
        }
    }

    // Presnent to window
    SDL_RenderPresent(renderer);

}

int main(int argc, char* argv[])
{
    cout << "### BRESENHAM LINE ALGORITHM ###\n\n";
    int x1, y1, x2, y2;
    cout << "Enter x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 and y2: ";
    cin >> x2 >> y2;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window *window = SDL_CreateWindow("BRESENHAM LINE ALGORITHM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT)
                quit = true;
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        BRESENHAM(x1, y1, x2, y2, renderer);

        SDL_Delay(100);
   }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
