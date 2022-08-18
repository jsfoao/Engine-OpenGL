#include "nata.h"
#include "math/math.h"
using namespace Nata;

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id); 

    // Error handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, vertexShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

class Game : public Nata::Application
{
    Input* input = nullptr;

public:
	Game() {}
	~Game() {}

	int Run()
	{
        Window* win = new Window("Nata Engine", 600,600);

        Matrix4 mat;
        mat.m00 = 1.f;

        Vector2 vec1 = Vector2::one;
        Vector2 vec2 = 2.f * vec1;

        LOGVEC(vec2.x, vec2.y);

        while (!win->Closed())
        {
            win->Clear();

            // simple rendering
            glBegin(GL_QUADS);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(-0.5f, 0.5f);
            glVertex2f(0.5f, 0.5f);
            glVertex2f(0.5f, -0.5f);
            glEnd();

            win->Update();
        }
        return 0;
	}
};

Application* CreateApplication()
{
	printf("Created application\n");
	return new Game();
}

