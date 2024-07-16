#ifndef MESH_HPP
#define MESH_HPP

#include <stdlib.h>

class Mesh {
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	size_t verticesCount;
public:
    Mesh(const float* buffer, size_t vertices, const int* attributes);
    ~Mesh();
    void draw(unsigned int primitive_type);
	void draw();
};
#endif //MESH_HPP