#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include<cstdio>

int main(int argc, char** argv){
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(1366, 768, "Bedroom", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    return 0;
}