#include <raylib.h>
#include "gameMain.h"
#include <iostream>
#include <fstream>
#include <asserts.h>

struct GameData
{
	float positionX = 100;
	float positionY = 100;

}gameData;

bool initGame()
{
	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	if (IsKeyDown(KEY_A)) { gameData.positionX -= 200 * deltaTime; }
	if (IsKeyDown(KEY_D)) { gameData.positionX += 200 * deltaTime; }
	if (IsKeyDown(KEY_W)) { gameData.positionY -= 200 * deltaTime; }
	if (IsKeyDown(KEY_S)) { gameData.positionY += 200 * deltaTime; }
	//           posX		 posY		sizeX	sizeY
	DrawRectangle(gameData.positionX, gameData.positionY, 50, 50, {255, 0, 200, 255});

	return true;
}

void closeGame()
{
}