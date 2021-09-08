#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#define LOG(text) std::cout<<text<<std::endl

static unsigned int S_create_shader(std::string vertex_shader , std::string fragment_shader)
    {
        
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

        glfwTerminate();
        return 0;
    }