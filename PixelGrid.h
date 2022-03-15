#pragma once
#include <vector>
#include "PixelChunk.h"
#include <SDL.h>
#include "ResourceObject.h"
using std::vector;

class PixelGrid
{
	vector<vector<PixelChunk*>> grid;
	int width;
	int height;
	int originX;
	int originY;
	int chunkWidth;
	int chunkHeight;
	int pixelSize;

	public: 
		PixelGrid(int gridWidth, int gridHeight, int chunkWidth, int chunkHeight, int pixelSize, int originX, int originY);
		~PixelGrid(void);
		void Advance(void);		// make this only advance active grid and the grid thats affected by advancing
		PixelChunk* Get(int chunkId);
		void Draw(SDL_Renderer* renderer, ResourceObject* textureObj);	// make this only show visible chunks on screen
		void Set(int mousePosX, int mousePosY, short value);
};
