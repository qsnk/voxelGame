#include "world.hpp"
#include "../includes.hpp"
#include "../shader/shader.hpp"

float floorVertices[] = {
	-5.0f, 0.0f,  5.0f,
	 5.0f, 0.0f,  5.0f,
	 5.0f, 0.0f, -5.0f,
	-5.0f, 0.0f, -5.0f
};

unsigned int indices[] = {
  	0, 1, 2,
    2, 3, 0
};


void World::createPlane() {
	unsigned int vertexShader = Shader::create(GL_VERTEX_SHADER);
    Shader::setSource(vertexShader, 1, "../shader/planeShader.glslv", NULL);
    Shader::compile(vertexShader);
    Shader::checkCompileErrors(vertexShader, "VERTEX");

    unsigned int fragmentShader = Shader::create(GL_FRAGMENT_SHADER);
    Shader::setSource(fragmentShader, 1, "../shader/planeShader.glslf", NULL);
	Shader::compile(fragmentShader);
	Shader::checkCompileErrors(vertexShader, "FRAGMENT");

	unsigned int VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	// Bind and set VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);

	// Bind and set EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Set vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbind VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}