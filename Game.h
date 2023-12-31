#pragma once
#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Gamelevel.h"
#include "PowerUp.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // Game state
    GameState              State;
    GLboolean              Keys[1024];
    GLuint                 Width, Height;
    std::vector<Gamelevel>Levels;
    GLuint Level;
    GLuint Lives;

    GLboolean KeysProcessed[1024];

    // Constructor/Destructor
    Game(GLuint width, GLuint height);
    ~Game();
    // Initialize game state (load all shaders/textures/levels)
    void Init();
    // GameLoop
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollisions();
    // Reset
    void ResetLevel();
    void ResetPlayer();

    std::vector<PowerUp> PowerUps;
    void SpawnPowerUps(GameObject& block);
    void UpdatePowerUps(GLfloat dt);

};

#endif