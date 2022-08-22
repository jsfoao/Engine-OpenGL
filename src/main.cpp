#pragma once
#include "nata.h"
#include "math/math.h"

#include "graphics/buffer.h"
#include "graphics/index_buffer.h"
#include "graphics/vertex_array.h"

#include "graphics/renderer2d.h"
#include "graphics/simple_2drenderer.h"

using namespace Nata;

int main(int argc, char** argv)
{
    LOG("Start Application");
    Window* win = new Window("Nata Engine", 960, 540);

    Simple2DRenderer renderer;

    Matrix4 ortho = Matrix4::Ortographic(0.0f, 16.f, 0.0f, 9.0f, -1.0f, 1.0f);
    Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader.Enable();
    shader.SetUniformMat4("pr_matrix", ortho);

    Renderable2D sprite(Vector3(5, 5, 0), Vector2(4, 4), Vector4(1, 0, 0, 1), &shader);
    Renderable2D sprite2(Vector3(5, 5, 0), Vector2(2, 3), Vector4(0, 1, 0, 1), &shader);

    while (!win->Closed())
    {
        win->Clear();

        Vector2 mousePos = win->GetInput()->GetMousePos();
        //shader.SetUniform2f("light_pos", Vector2((mousePos.x * 16.f) / 960.f, (9.f - mousePos.y * 9.f / 540.f)));
        
        sprite.SetPosition(Vector3((mousePos.x * 16.f) / 960.f, (9.f - mousePos.y * 9.f / 540.f), 0.f));
        renderer.Submit(&sprite);
        renderer.Submit(&sprite2);

        renderer.Flush();
        win->Update();
    }
    return 0;
}