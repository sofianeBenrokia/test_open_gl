/*
* S_ : is for static
*
*
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#define LOG(text) std::cout<<text<<std::endl

static unsigned int S_compile_shader(const unsigned int TYPE , std::string& source)
    {
        unsigned int id = glCreateShader(TYPE);

        if(id == 0)
            LOG("ERROR :creating shader");
        
        const char* temp_source = source.c_str();
        
        glShaderSource(id , 1 , &temp_source , NULL);

        glCompileShader(id);

        return id ;
    }

static unsigned int S_create_shader(std::string& vertex_shader , std::string& fragment_shader)
    {
        unsigned int program = glCreateProgram();
        unsigned int temp_vertex_shader = S_compile_shader(GL_VERTEX_SHADER , vertex_shader);
        unsigned int temp_fragment_shader =  S_compile_shader(GL_FRAGMENT_SHADER , fragment_shader);

        glAttachShader(program , temp_vertex_shader);
        glAttachShader(program , temp_fragment_shader);

        glLinkProgram(program);
        
        glValidateProgram(program);
            
        glDeleteShader(temp_vertex_shader);
        glDeleteShader(temp_fragment_shader);

        return program ;

    }

int main(void)
    {
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        if(glewInit() != GLEW_OK)
            return -2 ;

        std::cout<<glGetString(GL_VERSION)<<std::endl;

        /*
        * start
        */

        float triangle_cordoner[6]
            {
                -0.5f , -0.5f,
                 0.0f ,  0.5f,
                 0.5f , -0.5f
            };

        unsigned int triangle ;

        glGenBuffers(1 , &triangle);

        LOG("triangle :"<<triangle);

        glBindBuffer(GL_ARRAY_BUFFER , triangle);
        glBufferData(GL_ARRAY_BUFFER , sizeof(triangle_cordoner) , triangle_cordoner , GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0 , 2 , GL_FLOAT , GL_FALSE , 2 * sizeof(float) , 0);

        std::string vertex_shader =
            "#version 330 core\n"
            "\n"
            "layout(location = 0) in vec4 triangle_cordoner;\n"
            "\n"
            "void main()\n"
            "{\n"
            "   gl_Position = triangle_cordoner;\n"
            "}\n";

        std::string fragment_shader =
            "#version 330 core\n"
            "\n"
            "layout(location = 0) out vec4 color;\n"
            "\n"
            "void main()\n"
            "{\n"
            "   color = vec4(1.0 , 0.0 , 0.0 , 1.0);\n"
            "}\n";

        unsigned int shader = S_create_shader(vertex_shader , fragment_shader);

        glUseProgram(shader);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            glDrawArrays(GL_TRIANGLES , 0 , 3);


            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glDeleteProgram(shader);

        glfwTerminate();
        return 0;
    }