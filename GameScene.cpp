#include "GameScene.h"
#include "draw.h"
#include <SDL_render.h>

GameScene::GameScene()
{
    snake = new Snake();
    addGameObject(snake);
}

GameScene::~GameScene()
{
    delete snake;
}

void GameScene::start()
{
    Scene::start();
}

void GameScene::update()
{
    Scene::update();
}

void GameScene::draw()
{
    SDL_SetRenderDrawColor(app.renderer, 25, 25, 30, 255);
    SDL_RenderClear(app.renderer);

    Scene::draw();
}
