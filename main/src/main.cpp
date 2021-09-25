#include "declaration/define.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "declaration/globale.hpp"



int main()
    {

        #include "init_destroy/init_gl_window.hpp"

        std::cout<<glGetString(GL_VERSION)<<std::endl;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);



            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
        return 0;
    }