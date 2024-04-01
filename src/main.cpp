#include <SDL3/SDL.h>
#include <iostream>
#include <rpppConfig.h>

#ifdef USE_TESTLIB
    #include "TestLib.h"
#endif

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char *argv[]) {
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    SDL_bool loopShouldStop = SDL_FALSE;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    win = SDL_CreateWindow("Hello World", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!win) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(win, NULL, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // The bitmap loading code is commented out as it depends on your actual resources.
    // bitmapSurface = SDL_LoadBMP("img/hello.bmp");
    // bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    // SDL_FreeSurface(bitmapSurface);

    while (!loopShouldStop) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                loopShouldStop = SDL_TRUE;
            }
        }

        SDL_RenderClear(renderer);
        // Render the texture (if you have one loaded and it's assigned to bitmapTex)
        // SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    // SDL_DestroyTexture(bitmapTex); // Uncomment if you have loaded a texture.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    const std::string inputName = "Mr. Anderson";
    #ifdef USE_TESTLIB
        greetings(inputName);
    #else
        std::cout << "Hello from " << inputName << " main.cpp" << std::endl;
    #endif  
    
    return 0;
}
