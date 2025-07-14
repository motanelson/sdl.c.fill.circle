#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>
#include <math.h>
#include "SDLs.h"
#include <SDL_image.h>
#include <emscripten.h>
SDL_Surface *screen = NULL;

void kernel_main(){
   printf("ok\n");
 }

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  screen =(SDL_Surface *) SDL_SetVideoMode(800,600, 32, SDL_SWSURFACE);
#ifdef TEST_SDL_LOCK_OPTS
  EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif
  
  if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
  clears(screen, 255, 255, 0);
  int poly[]={100,50,150,100,50,100,0,0,0,0,0};
  polygon(screen,poly,6,0,0,0);

  printf("\n\nok\n ");
  
  if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);     
  SDL_Flip(screen);
     
  return 0;
}
