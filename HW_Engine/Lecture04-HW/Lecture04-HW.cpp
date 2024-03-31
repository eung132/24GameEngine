#include <iostream>
#include <GLFW/glfw3.h>

// 라이브러리 종속성 추가
#pragma comment(lib, "opengl32.lib")

bool isLeftButtonPressed = false;
bool isRightButtonPressed = false;

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
            isLeftButtonPressed = true;
            // 녹색창
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        }
        else if (action == GLFW_RELEASE)
        {
            isLeftButtonPressed = false;
            // 거믕색
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            isRightButtonPressed = true;
            // 빨간색창
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
        else if (action == GLFW_RELEASE)
        {
            isRightButtonPressed = false;
            // 거믕색
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
}

double PreXpos = 0, PreYpos = 0;
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{

    if (isLeftButtonPressed)
    {
        if ((PreXpos == xpos) || (PreYpos == ypos))
        {
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);// 녹색
        }
        else
        {
            // 왼쪽 마우스를 누른 상태에서 드래그할 때는 마젠타색으로 설정
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색
        }
    }
    else if (isRightButtonPressed)
    {
        if ((PreXpos == xpos) || (PreYpos == ypos))
        {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);// 빨간색
        }
        else
        {
            // 오른쪽 마우스를 누른 상태에서 드래그할 때는 파란색으로 설정
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파란색
        }
    }
    else
    {
        // 마우스 버튼을 누르지 않은 상태에서는 검은색 배경 유지
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }
    PreXpos = xpos; PreYpos = ypos;

}

int main(void)
{
    /* glfw 라이브러리 초기화 */
    if (!glfwInit())
        return -1;

    GLFWwindow* window;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 768, "1 + 1 = window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
 

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* 없으면 마우스가 무한 로딩해여 */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
