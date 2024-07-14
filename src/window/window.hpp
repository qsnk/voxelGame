#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../includes.hpp"

class Window {
    static GLFWwindow* window;
    public:
        static int width;
        static int height;
        static int posX;
        static int posY;
        static bool fullscreen;


        static int  initialize();
		static GLFWwindow* create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
		static void clear();
		static void clearDepthBuffer();
		static void terminate();
		static void renderLoop();
        static void swapBuffers(GLFWwindow* window);
		static void makeContextCurrent(GLFWwindow* window);
        static void setViewport(int x, int y, int width, int height);
        static void setBgColor(float red, float green, float blue, float alpha);
        static void setTitle(GLFWwindow* window, const char* title);
		static void setShouldClose(GLFWwindow* window, bool value);
		static bool isFullscreen(bool fullscreen);
		static bool isClosed(GLFWwindow* window);

};

#endif //WINDOW_HPP