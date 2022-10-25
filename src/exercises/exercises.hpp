#include "nata.h"
namespace Nata
{
	namespace Exercises
	{
		int HelloTriangle_1()
		{
            Window* win = new Window("Nata Engine", 960, 540);
            Input* input = win->GetInput();

            float vertices[] =
            {
                -1.f, -0.5f, 0.f,
                -0.5f, 0.5f, 0.f,
                 0.f, -0.5f, 0.f,

                 0.f, -0.5f, 0.f,
                 0.5f, 0.5f, 0.f,
                 1.f, -0.5f, 0.f,
            };

            unsigned int indices[] =
            {  // note that we start from 0!
                0, 1, 3,   // first triangle
                1, 2, 3    // second triangle
            };

            //
            // 1. Initializing objects
            // 
            // Creating and binding Vertex Array Object
            unsigned int VAO;
            glGenVertexArrays(1, &VAO);
            glBindVertexArray(VAO);
            // Creating and binding Vertex Buffer Object
            unsigned int VBO;
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);


            // Creating and binding Element Buffer Object
            unsigned int EBO;
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            // 
            // 2. Sending data to objects
            //
            // Data to render (vertices and indices)
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

            // Set how to interpret data
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
            glEnableVertexAttribArray(0);

            //
            // 3. Initializing Shader Program object
            // 
            // Create shaders and program object

            // Reading vertex shader file from path
            std::string tempVertPath = FileUtils::ReadFile("src\\shaders\\test.vert");
            const char* vertPath = tempVertPath.c_str();

            // Creating vertex shader object
            unsigned int vertShader;
            vertShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertShader, 1, &vertPath, NULL);
            glCompileShader(vertShader);

            int success;
            char infoLog[512];
            glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

            // Reading fragment shader file from path
            std::string tempFragPath = FileUtils::ReadFile("src\\shaders\\test.frag");
            const char* fragPath = tempFragPath.c_str();

            // Creating fragment shader object
            unsigned int fragShader;
            fragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragShader, 1, &fragPath, NULL);
            glCompileShader(fragShader);

            glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

            // PROGRAM
            // Shader program object is final linked version of multiple shaders combined
            unsigned int shaderProgram;
            shaderProgram = glCreateProgram();
            glAttachShader(shaderProgram, vertShader);
            glAttachShader(shaderProgram, fragShader);
            glLinkProgram(shaderProgram);

            glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
            }

            // Delete shaders once they've been linked to program
            glDeleteShader(vertShader);
            glDeleteShader(fragShader);

            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            while (!win->Closed())
            {
                win->Clear();
                //
                // 4. Rendering
                // 
                // Every shader and rendering call after this willl use this program object
                glUseProgram(shaderProgram);
                glBindVertexArray(VAO);

                glDrawArrays(GL_TRIANGLES, 0, 6);

                glBindVertexArray(NULL);
                win->Update();
            }
            // Clean/deleted all allocated resources
            glfwTerminate();
            return 0;
		}
        
        int HelloTriangle_2_3()
        {
            Window* win = new Window("Nata Engine", 960, 540);
            Input* input = win->GetInput();

            std::string tempVertPath = FileUtils::ReadFile("src\\shaders\\test.vert");
            const char* vertPath = tempVertPath.c_str();

            unsigned int vertShader;
            vertShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertShader, 1, &vertPath, NULL);
            glCompileShader(vertShader);

            int success;
            char infoLog[512];
            glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

            // Reading fragment shader file from path
            std::string tempFragPath = FileUtils::ReadFile("src\\shaders\\test.frag");
            const char* fragPath = tempFragPath.c_str();

            // Creating fragment shader object
            unsigned int fragShader;
            fragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragShader, 1, &fragPath, NULL);
            glCompileShader(fragShader);

            glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

            // PROGRAM
            // Shader program object is final linked version of multiple shaders combined
            unsigned int shaderProgram;
            shaderProgram = glCreateProgram();
            glAttachShader(shaderProgram, vertShader);
            glAttachShader(shaderProgram, fragShader);
            glLinkProgram(shaderProgram);

            glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
            }

            unsigned int shaderProgram2;
            shaderProgram2 = glCreateProgram();
            glAttachShader(shaderProgram2, vertShader);

            tempFragPath = FileUtils::ReadFile("src\\shaders\\test2.frag");
            fragPath = tempFragPath.c_str();
            fragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragShader, 1, &fragPath, NULL);
            glCompileShader(fragShader);

            glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            }
            
            glAttachShader(shaderProgram2, fragShader);
            glLinkProgram(shaderProgram2);

            // Delete shaders once they've been linked to program
            glDeleteShader(vertShader);
            glDeleteShader(fragShader);

            //
            // VERTEX DATA
            //
            float vertices1[] =
            {
                -1.f, -0.5f, 0.f,
                -0.5f, 0.5f, 0.f,
                 0.f, -0.5f, 0.f,
            };

            float vertices2[] =
            {
                0.f, -0.5f, 0.f,
                0.5f, 0.5f, 0.f,
                1.f, -0.5f, 0.f,
            };

            //
            // 1. Initializing objects
            // 
            unsigned int VAOs[2];
            glGenVertexArrays(2, VAOs);
            unsigned int VBOs[2];
            glGenBuffers(2, VBOs);

            // 
            // 2. Sending data to objects
            //
            glBindVertexArray(VAOs[0]);
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
            glEnableVertexAttribArray(0);

            
            glBindVertexArray(VAOs[1]);
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
            glEnableVertexAttribArray(0);

            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            while (!win->Closed())
            {
                win->Clear();
                glUseProgram(shaderProgram);
                glBindVertexArray(VAOs[0]);
                glDrawArrays(GL_TRIANGLES, 0, 3);

                glUseProgram(shaderProgram2);
                glBindVertexArray(VAOs[1]);
                glDrawArrays(GL_TRIANGLES, 0, 3);

                glBindVertexArray(NULL);
                win->Update();
            }

            glfwTerminate();
            return 0;
        }
	}
}