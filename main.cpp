#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void init_glfw();

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

int main()
{

    init_glfw();

    // Create window
    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // On resize, call framebuffer_size_callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // On key press, call key_callback
    glfwSetKeyCallback(window, key_callback);

    // Load openGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // On window close, terminate
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key == GLFW_KEY_R && action == GLFW_PRESS)
    {
        GLfloat bkColor[4];
        glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
        if (mods == GLFW_MOD_SHIFT)
        {
            glClearColor(bkColor[0] - 0.1f, bkColor[1], bkColor[2], 1.0f);
        }
        else
        {
            glClearColor(bkColor[0] + 0.1f, bkColor[1], bkColor[2], 1.0f);
        }
    }
    if (key == GLFW_KEY_G && action == GLFW_PRESS)
    {
        GLfloat bkColor[4];
        glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
        if (mods == GLFW_MOD_SHIFT)
        {
            glClearColor(bkColor[0], bkColor[1] - 0.1f, bkColor[2], 1.0f);
        }
        else
        {
            glClearColor(bkColor[0], bkColor[1] + 0.1f, bkColor[2], 1.0f);
        }
    }
    if (key == GLFW_KEY_B && action == GLFW_PRESS)
    {
        GLfloat bkColor[4];
        glGetFloatv(GL_COLOR_CLEAR_VALUE, bkColor);
        if (mods == GLFW_MOD_SHIFT)
        {
            glClearColor(bkColor[0], bkColor[1], bkColor[2] - 0.1f, 1.0f);
        }
        else
        {
            glClearColor(bkColor[0], bkColor[1], bkColor[2] + 0.1f, 1.0f);
        }
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void init_glfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
}
