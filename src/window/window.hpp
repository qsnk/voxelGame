#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <sys/types.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window {
    static GLFWwindow* window;
    public:
        static int width;
        static int height;
        static int posX;
        static int posY;

        static void setViewport(int x, int y, int width, int height);
        static int  initialize();
        static void clear();
        static void clearDepthBuffer();
        static void terminate();
        static void swapBuffers(GLFWwindow* window);
        static void setBgColor(float red, float green, float blue, float alpha);
        static void setTitle(GLFWwindow* window, const char* title);

};

#endif //WINDOW_HPP
