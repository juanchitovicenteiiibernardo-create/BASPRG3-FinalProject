#pragma once
#include "GameObject.h"
class Food : public GameObject
{
public:
	void start() override;
	void update() override;
	void draw() override;
	void respawn(); 
	int getX() const; 
	int getY() const; 
private:
	int x;
	int y;
	int size;
};
