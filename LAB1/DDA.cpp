/// DDA LINE DRAWING ALGORITHM

#include <iostream>
#include <SDL.h>
#include <cmath>

using namespace std;

void DDA(int x1, int y1, int x2, int y2, SDL_Renderer *renderer)
{
    // Set color for drawing
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    int steps;
    float Xinc, Yinc, x, y, m, dx, dy;

    dx = x2 - x1;
    dy = y2 - y1;

    if(dx < 0) {
        x = x2;
        y = y2;
    }
    else {
        x = x1;
        y = y1;
    }

    m = dy / dx;

    if(m < 1) {
        steps = abs(dx);
        Xinc = 1;
        Yinc = m;
    }
    else if(m > 1) {
        steps = abs(dy);
        Xinc = 1/m;
        Yinc = 1;
    }
    else if(m == 1) {
        steps = abs(dx);
        Xinc = 1;
        Yinc = 1;
    }

    for(int i = 0; i < steps; i++) {
        SDL_RenderDrawPoint(renderer, round(x), round(y));
        x = x + Xinc;
        y = y + Yinc;
    }

    // Present to window
    SDL_RenderPresent(renderer);

}

int main(int argc, char* argv[])
{
    cout << "### DDA LINE ALGORITHM ###\n\n";
    int x1, y1, x2, y2;
    cout << "Enter x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 and y2: ";
    cin >> x2 >> y2;

    SDL_Init(SDL_INIT_VIDEO);

    bool quit = false;
    SDL_Window *window = SDL_CreateWindow("DDA LINE ALGORITHM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT)
                quit = true;
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0,  0);
        SDL_RenderClear(renderer);

        DDA(x1, y1, x2, y2, renderer);

        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
