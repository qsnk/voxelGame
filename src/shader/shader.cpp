#include "shader.hpp"
#include "../includes.hpp"

unsigned int Shader::create(int type){
	return glCreateShader(type);
}

const char* Shader::load(const char* path){
	const char* shaderCode;
	try {
		std::string shaderCode;
		std::ifstream file;
        std::stringstream buffer;

        file.open(path);

        buffer << file.rdbuf();

        file.close();

        shaderCode = buffer.str();
		std::cout << shaderCode << std::endl;

	}
    catch(std::ifstream::failure& e) {
    	std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    	shaderCode = "";
    }
	return shaderCode;
}

void Shader::setSource(unsigned int shader, int count, const char* path, const int* length){
	auto shaderCode = Shader::load(path);
	glShaderSource(shader, count, &shaderCode, length);
}

void Shader::del(unsigned int shader){
  	glDeleteShader(shader);
}

void Shader::compile(unsigned int shader){
  	glCompileShader(shader);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type){
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if(!success){
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}