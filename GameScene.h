#pragma once
#include "Scene.h"
#include "Snake.h"

class GameScene : public Scene
{
public:
    GameScene();
    ~GameScene();

    void start() override;
    void update() override;
    void draw() override;

private:
    Snake* snake;
};
