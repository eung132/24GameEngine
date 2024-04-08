#include <GLFW/glfw3.h>
#include <iostream>

#pragma comment(lib, "Opengl32.lib")

float scaleFactor = 1.0f;
double prevMouseX = 0.0;
double prevMouseY = 0.0;
bool isLeftDragging = false;
bool isRightDragging = false;
float movementSpeed = 0.003f; // 별의 이동 속도

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            isLeftDragging = true;
            glfwGetCursorPos(window, &prevMouseX, &prevMouseY);
        }
        else if (action == GLFW_RELEASE)
        {
            isLeftDragging = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            isRightDragging = true;
            glfwGetCursorPos(window, &prevMouseX, &prevMouseY);
        }
        else if (action == GLFW_RELEASE)
        {
            isRightDragging = false;
        }
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (isLeftDragging)
    {
        double deltaX = xpos - prevMouseX;
        double deltaY = ypos - prevMouseY;

        glTranslatef(deltaX * movementSpeed, -deltaY * movementSpeed, 0.0f);

        prevMouseX = xpos;
        prevMouseY = ypos;
    }
    if (isRightDragging)
    {
        double deltaX = xpos - prevMouseX;

        if (deltaX > 0) // 우측으로 드래그한 경우 확대
        {
            scaleFactor += 0.1f;
        }
        else if (deltaX < 0) // 좌측으로 드래그한 경우 축소
        {
            scaleFactor -= 0.1f;
            if (scaleFactor < 0.1f)
                scaleFactor = 0.1f;
        }

        prevMouseX = xpos;
    }
}

int render()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f * scaleFactor, 0.25f * scaleFactor);
    glVertex2f(-0.15f * scaleFactor, -0.25f * scaleFactor);
    glVertex2f(0.1f * scaleFactor, -0.05f * scaleFactor);

    glVertex2f(0.0f * scaleFactor, 0.25f * scaleFactor);
    glVertex2f(0.15f * scaleFactor, -0.25f * scaleFactor);
    glVertex2f(-0.1f * scaleFactor, -0.05f * scaleFactor);

    glVertex2f(-0.25f * scaleFactor, 0.05f * scaleFactor);
    glVertex2f(0.25f * scaleFactor, 0.05f * scaleFactor);
    glVertex2f(0.0f * scaleFactor, -0.13f * scaleFactor);
    glEnd();

    return 0;
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "Star", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
