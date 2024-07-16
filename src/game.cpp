#include <iostream>
#include "window/window.hpp"
#include "window/events.hpp"
#include "graphics/shader.hpp"
#include "graphics/mesh.hpp"
#include "includes.hpp"

// float floorVertices[] = {
//     -5.0f, 0.0f,  5.0f,
//      5.0f, 0.0f,  5.0f,
//      5.0f, 0.0f, -5.0f,
//     -5.0f, 0.0f, -5.0f
// };

float floorVertices[] = {
    0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f
};

const int attributes[] = {
    0, 1, 2,
    2, 3, 0
};

int main() {
    try {
        Window::initialize();
        Window::setBgColor(0.2f, 0.3f, 0.3f, 1.0f);

        Shader* shader = Shader::create("/Users/mikhail_root/CLionProjects/voxelGame/src/graphics/planeShader.glslv", "/Users/mikhail_root/CLionProjects/voxelGame/src/graphics/planeShader.glslf");
        if (!shader) {
            std::cerr << "Failed to load shaders" << std::endl;
            Window::terminate();
        }

        Mesh* mesh = new Mesh(floorVertices, 6, attributes);

        while (!Window::isClosed()) {
            Window::clear();

            shader->use();
            mesh->draw();

            Window::swapBuffers();
            Events::pollEvents();
        }

        delete shader;
        delete mesh;
        Window::terminate();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}