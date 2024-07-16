#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

class Shader {
	unsigned int id;
public:
	explicit Shader(unsigned int id);
	~Shader();

    static Shader* create(const std::string& vertexFile, const std::string& fragmentFile);
	void use() const;
    static void checkCompileErrors(unsigned int shader, const std::string &type);
};
#endif //SHADER_HPP