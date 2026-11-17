#include "Food.h"
#include <SDL_render.h>
#include "draw.h"

void Food::start()
{
	size = 20;
	respawn(); 
}

void Food::update()
{

}

void Food::draw()
{
	SDL_SetRenderDrawColor(app.renderer, 220, 40, 40, 255);
	SDL_Rect rect = { x + 2, y + 2, size - 4, size - 4 }; 
	SDL_RenderFillRect(app.renderer, &rect); 
}

void Food::respawn()
{
	int cols = SCREEN_WIDTH / size;
	int rows = SCREEN_HEIGHT / size; 
	x = (rand() % cols) * size; 
	y = (rand() % rows) * size;
}

int Food::getX() const
{
	return x; 
}

int Food::getY() const
{
	return y;
}
