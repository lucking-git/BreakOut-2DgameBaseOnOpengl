#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <GL/glew.h>

#include "Texture2D.h"
#include "Shader.h"


class ResourceManager
{
public:
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture2D> Textures;

	static Shader LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);

	static Shader& GetShader(std::string name);

	static Texture2D LoadTexture(const GLchar* file, GLboolean alpha, std::string name);

	static Texture2D& GetTexture(std::string name);
	
	static void Clear();

private:
	ResourceManager() {};
	static Shader loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);
	static Texture2D loadTextureFromFile(const GLchar* file, GLboolean alpha);



};


#endif
