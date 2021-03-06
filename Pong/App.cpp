//==============================================================================
#include "App.h"
#include "Log.h"

App App::Instance;

//==============================================================================
App::App() {
}

//------------------------------------------------------------------------------
void App::OnEvent(SDL_Event* Event) {
    if (Event->type == SDL_KEYDOWN)
        Running = false;
    if (Event->type == SDL_MOUSEBUTTONDOWN)
        Running = false;
}

//------------------------------------------------------------------------------
bool App::Init() {

    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    	Log("Unable to Init SDL: %s", SDL_GetError());
    	return false;
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        Log("Unable to Init hinting: %s", SDL_GetError());
    }

    if((Window = SDL_CreateWindow(
    	"My SDL Game",
    	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    	WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
    ) == NULL) {
    	Log("Unable to create SDL Window: %s", SDL_GetError());
    	return false;
    }

    PrimarySurface = SDL_GetWindowSurface(Window);

    if((Renderer = SDL_GetRenderer(Window)) == NULL) {
        Log("Unable to create Renderer: %s", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);
    
    Pong::Init(Renderer, App::WindowHeight, App::WindowWidth);
    return true;
}

//------------------------------------------------------------------------------
void App::Loop() {
    Pong* pong = Pong::GetInstance();
    std::vector<Entity*> entities = pong->entities;
    for (int i = 0; i < entities.size(); i++) {
        entities[i]->Update();
    }
}

//------------------------------------------------------------------------------
void App::Render() {
    SDL_RenderClear(Renderer);

    Surface* surface = new Surface();
    
//    SDL_Texture* tex = surface->Load(Renderer, "/../leonardo1.bmp");
    Pong* pong = Pong::GetInstance();
    std::vector<Entity*> entities = pong->entities;
    for (int i = 0; i < entities.size(); i++) {
        surface->RenderTexture(entities[i]->texture, Renderer, entities[i]->x, entities[i]->y);
    }
    
	SDL_RenderPresent(Renderer);
}

//------------------------------------------------------------------------------
void App::Cleanup() {
	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_Quit();
}

//------------------------------------------------------------------------------
int App::Execute(int argc, char* argv[]) {
	if(!Init()) return 0;

	SDL_Event Event;

	while(Running) {
		while(SDL_PollEvent(&Event) != 0) {
			OnEvent(&Event);

			if(Event.type == SDL_QUIT) Running = false;
		}

		Loop();
		Render();

		SDL_Delay(1); // Breath
	}

	Cleanup();

	return 1;
}

//==============================================================================
App* App::GetInstance() { return &App::Instance; }

int App::GetWindowWidth()  { return WindowWidth; }
int App::GetWindowHeight() { return WindowHeight; }

//==============================================================================
