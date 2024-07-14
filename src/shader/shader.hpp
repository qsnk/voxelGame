#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

class Shader {
  public:
    static unsigned int create(int type);
    static const char* load(const char* path);
    static void setSource(unsigned int shader, int count, const char *path, const int *length);
    static void compile(unsigned int shader);
    static void del(unsigned int shader);
    static void checkCompileErrors(unsigned int shader, std::string type);

};

#endif //SHADER_HPP