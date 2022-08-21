#pragma once
#include "nata.h"
using namespace Nata;

int main(int argc, char** argv)
{
    LOG("Run");
    Window* win = new Window("Nata Engine", 600, 600);

    if (win->failed)
        return 0;

    float vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    // Initalize GL
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    //

    //Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
    //shader.Enable();

    while (!win->Closed())
    {
        win->Clear();

        glDrawArrays(GL_TRIANGLES, 0, 6);

        win->Update();
    }
    return 0;
}