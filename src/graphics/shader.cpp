#include "shader.hpp"
#include "../includes.hpp"

Shader::Shader(unsigned int id) {
	this->id = id;
}

Shader::~Shader() {
	glDeleteProgram(id);
}

Shader* Shader::create(const std::string& vertexFile, const std::string& fragmentFile) {
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	std::cout << "Vertex Shader File: " << vertexFile << std::endl;
	std::cout << "Fragment Shader File: " << fragmentFile << std::endl;
	try {
        std::stringstream vertexBuffer, fragmentBuffer;

        vShaderFile.open(vertexFile);
		fShaderFile.open(fragmentFile);

		if (!vShaderFile.is_open() || !fShaderFile.is_open()) {
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_OPENED" << std::endl;
			return nullptr;
		}

        vertexBuffer << vShaderFile.rdbuf();
		fragmentBuffer << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vertexBuffer.str();
		fragmentCode = fragmentBuffer.str();

	}
    catch(std::ifstream::failure& e) {
    	std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    	return nullptr;
    }

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	unsigned int vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, nullptr);
	glCompileShader(vertex);
	Shader::checkCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, nullptr);
	glCompileShader(fragment);
	Shader::checkCompileErrors(fragment, "FRAGMENT");

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex);
	glAttachShader(shaderProgram, fragment);
	glLinkProgram(shaderProgram);
	Shader::checkCompileErrors(shaderProgram, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return new Shader(shaderProgram);
}

void Shader::use() const {
	glUseProgram(id);
}

void Shader::checkCompileErrors(unsigned int shader, const std::string& type) {
	int success;
	char infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	} else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
}