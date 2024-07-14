#include "window.hpp"
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow* Window::window = nullptr;
int Window::width = 800;
int Window::height = 600;
int Window::posX = 0;
int Window::posY = 0;

int Window::initialize() {
    if (!glfwInit()) {
        Window::terminate();
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);
#else
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);

    Window::setViewport(posX, posY, width, height);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        Window::setBgColor(0.2f, 0.3f, 0.3f, 1.0f);
        Window::clear();

        Window::swapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}

void Window::swapBuffers(GLFWwindow* window) {
    glfwSwapBuffers(window);
}

void Window::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::clearDepthBuffer() {
    glClearDepth(GL_DEPTH_BUFFER_BIT);
}

void Window::terminate() {
    glfwTerminate();
}

void Window::setBgColor(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
}

void Window::setViewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

void Window::setTitle(GLFWwindow* window, const char* title) {
    glfwSetWindowTitle(window, title);
}

