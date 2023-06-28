#pragma once
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"

class Gamelevel
{
public:
	std::vector<GameObject> Bricks;

	Gamelevel() {}
	void Load(const GLchar* file, GLuint levelWidth, GLuint levelHeight);

	void Draw(SpriteRenderer& renderer);

	GLboolean IsCompleted();

private:
	void init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);



};

