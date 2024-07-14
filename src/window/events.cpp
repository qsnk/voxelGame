#include "events.hpp"
#include "../includes.hpp"

void Events::pollEvents() {
    glfwPollEvents();
}
