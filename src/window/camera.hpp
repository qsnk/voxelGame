#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../includes.hpp"

class Camera {
  public:
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 direction;
	glm::vec3 up;
    glm::vec3 right;
	glm::vec3 front;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;
	float yaw;
	float pitch;
    float fov;
    float zoom;
    const float speed;

    Camera(glm::vec3 position, float fov);

    void move(float speed, glm::vec3 front);
    void rotate(float x, float y, float z);
    void zoomView(GLFWwindow* window, double xoffset, double yoffset);

};

#endif //CAMERA_HPP