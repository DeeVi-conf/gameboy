#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

/* Sets constants */
#define WIDTH 800
#define HEIGHT 720
#define DELAY 300

int MakeWindow ()
{
  /* Initialises data */
  SDL_Window *window = NULL;
  
  /*
  * Initialises the SDL video subsystem (as well as the events subsystem).
  * Returns 0 on success or a negative error code on failure using SDL_GetError().
  */
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

  /* Creates a SDL window */
  window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
			    WIDTH, /* Width of the window in pixels */
			    HEIGHT, /* Height of the window in pixels */
			    0); /* Additional flag(s) */

  SDL_ShowWindow(window);

  /* Checks if window has been created; if not, exits program */
  if (window == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Event event;
  while(1){
    while(SDL_PollEvent(&event)){
      if (event.type == SDL_QUIT) {
        goto exit_loop;
      }
    }
  }

exit_loop:
  /* Pauses all SDL subsystems for a variable amount of milliseconds */
  SDL_Delay(DELAY);

  /* Frees memory */
  SDL_DestroyWindow(window);
  
  /* Shuts down all SDL subsystems */
  SDL_Quit(); 
  
  return 0;
}