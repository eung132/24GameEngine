#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Star.hpp"
#include "MSList.h"

void errorCallback(int error, const char* description)
{
    std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int initialize()
{
    return 0;
}

int release()
{
    return 0;
}

int update()
{
    return 0;
}

int render(const MSList& starList)
{
    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (MSList::iterator it = starList.begin(); it != starList.end(); ++it) {
        (*it).render();
    }

    return 0;
}


int main(void)
{
    // Seed the random number generator
    srand(time(NULL));

    //glfw라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "Stars", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    initialize();

    MSList starList;
    for (int i = 0; i < 300; ++i) {
        Star star;
        starList.insert(star);
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        update();
        render(starList);
        glfwSwapBuffers(window);
    }

    release();

    glfwTerminate();
    return 0;
}
