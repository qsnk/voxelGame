#include "mesh.hpp"
#include "../includes.hpp"

Mesh::Mesh(const float* buffer, size_t verticesCount, const int* attributes){
  	this->verticesCount = verticesCount;
	int vertexSize = 0;
    for (int i = 0; attributes[i]; i++) {
		vertexSize += attributes[i];
    }
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(float) * verticesCount, buffer, GL_STATIC_DRAW);

    int offset = 0;
    for (int i = 0; attributes[i]; i++) {
      	int size = attributes[i];
		glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(offset*sizeof(float)));
    	glEnableVertexAttribArray(i);
        offset += size;
    }
	glBindVertexArray(0);
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Mesh::draw(unsigned int primitive_type){
  	glBindVertexArray(VAO);
  	glDrawArrays(primitive_type, 0, verticesCount);
  	glBindVertexArray(0);
}

void Mesh::draw(){
	Mesh::draw(GL_TRIANGLES);
}