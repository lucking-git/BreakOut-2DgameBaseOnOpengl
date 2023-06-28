#pragma once
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Shader.h"
#include "Texture2D.h"
#include "GameObject.h"


// Represents a single particle and its state
struct Particle {
    glm::vec2 Position, Velocity;
    glm::vec4 Color;
    GLfloat Life;

    Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) { }
};

class ParticleGenerator
{
public:
    ParticleGenerator(Shader shader, Texture2D texture, GLuint amount);

    void Update(GLfloat dt, GameObject& object, GLuint newParticles, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
    void Draw();
private:
    std::vector<Particle> particles;
    GLuint amount;

    Shader shader;
    Texture2D texture;
    GLuint VAO;
    void init();
    GLuint firstUnusedParticle();
    void respawnParticle(Particle& partilce, GameObject& object, glm::vec2 offset = glm::vec2(0.0f, 0.0f));


};

