#include "Snake.h"
#include "GameScene.h"
#include "draw.h"
#include <SDL.h>

Snake::~Snake()
{
	body.clear();
}

void Snake::start()
{
	gridSize = 20;
	moveDelay = 8;
	food = new Food();
	getScene()->addGameObject(food);
	resetGame();
}

void Snake::resetGame()
{
	body.clear();
	int startX = (SCREEN_WIDTH / 2 / gridSize) * gridSize;
	int startY = (SCREEN_HEIGHT / 2 / gridSize) * gridSize;

	body.push_back({ startX, startY });
	body.push_back({ startX - gridSize, startY });
	body.push_back({ startX - (gridSize * 2), startY });

	dirX = 1;
	dirY = 0;
	nextDirX = 1;
	nextDirY = 0;

	moveTimer = 0;
	isAlive = true;

	if (food != nullptr)
	{
		food->respawn();
	}
}

void Snake::update()
{
	if (!isAlive)
	{
		if (app.keyboard[SDL_SCANCODE_SPACE])
		{
			resetGame();
		}
		return;
	}

	if (app.keyboard[SDL_SCANCODE_W] && dirY != 1)
	{
		nextDirX = 0;
		nextDirY = -1;
	}
	if (app.keyboard[SDL_SCANCODE_S] && dirY != -1)
	{
		nextDirX = 0;
		nextDirY = 1;
	}
	if (app.keyboard[SDL_SCANCODE_A] && dirX != 1)
	{
		nextDirX = -1;
		nextDirY = 0;
	}
	if (app.keyboard[SDL_SCANCODE_D] && dirX != -1)
	{
		nextDirX = 1;
		nextDirY = 0;
	}
	moveTimer++;
	if (moveTimer < moveDelay)
	{
		return;
	}
	moveTimer = 0;

	dirX = nextDirX;
	dirY = nextDirY;

	int newX = body[0].x + (dirX * gridSize);
	int newY = body[0].y + (dirY * gridSize);

	if (checkCollision(newX, newY))
	{
		isAlive = false;
		return;
	}

	body.insert(body.begin(), { newX, newY });

	if (newX == food->getX() && newY == food->getY())
	{
		do
		{
			food->respawn();
		} while (checkCollision(food->getX(), food->getY()));
	}
	else
	{
		body.pop_back();
	}
}

void Snake::draw()
{
	for (size_t i = 0; i < body.size(); i++)
	{
		if (!isAlive)
		{
			SDL_SetRenderDrawColor(app.renderer, 120, 120, 120, 255);
		}
		else if (i == 0)
		{
			SDL_SetRenderDrawColor(app.renderer, 50, 220, 50, 255);
		}
		else
		{
			SDL_SetRenderDrawColor(app.renderer, 30, 160, 30, 255);
		}

		SDL_Rect rect = { body[i].x + 1, body[i].y + 1, gridSize - 2, gridSize - 2 };
		SDL_RenderFillRect(app.renderer, &rect);
	}
}

bool Snake::checkCollision(int targetX, int targetY)
{
	if (targetX < 0 || targetX >= SCREEN_WIDTH || targetY < 0 || targetY >= SCREEN_HEIGHT)
	{
		return true;
	}
	for (size_t i = 0; i < body.size(); i++)
	{
		if (body[i].x == targetX && body[i].y == targetY)
		{
			return true;
		}
	}
	return false;
}
