#pragma once
#include "GameObject.h"
#include "Food.h"
#include <SDL.h>
#include <vector>
class Snake : public GameObject
{
public:
	~Snake(); 
	void start() override;
	void update() override;
	void draw() override;
private:
	int gridSize;
	int dirX;
	int dirY;
	int nextDirX;
	int nextDirY; 
	
	int moveDelay;
	int moveTimer; 
	bool isAlive; 

	std::vector<SDL_Point> body; 
	Food* food; 

	void resetGame(); 
	bool checkCollision(int targetX, int targetY);
};
