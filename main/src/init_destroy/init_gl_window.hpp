/* Initialize the library */
if (!glfwInit())
    return -1;

/* Create a windowed mode window and its OpenGL context */
window = glfwCreateWindow( window_width , window_height , "Hello World" , NULL, NULL);
if (!window)
{
    glfwTerminate();
    return -1;
}

/* Make the window's context current */
glfwMakeContextCurrent(window);

if(glewInit() != GLEW_OK)
    return -2 ;