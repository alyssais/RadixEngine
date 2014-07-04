#include "Camera.hpp"

#include <math.h>
#include "../Window.hpp"

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089

namespace glPortal {

Camera::Camera(float fovy, float aspect, float zNear, float zFar) {
  this->fovy = fovy;
  this->aspect = aspect;
  this->zNear = zNear;
  this->zFar = zFar;
  recalculate();
}

void Camera::recalculate() {
  aspect = Window::aspect;
  float fovyr = fovy * (PI / 180);
  projectionMatrix.array[0] = (float) (1 / tan(fovyr / 2)) / aspect;
  projectionMatrix.array[5] = (float) (1 / tan(fovyr / 2));
  projectionMatrix.array[10] = (zNear + zFar) / (zNear - zFar);
  projectionMatrix.array[11] = -1;
  projectionMatrix.array[14] = (2 * zNear * zFar) / (zNear - zFar);
  projectionMatrix.array[15] = 0;
}

Matrix4f Camera::getProjectionMatrix() {
  return projectionMatrix;
}

void Camera::setFovy(float fovy) {
  this->fovy = fovy;
  recalculate();
}

void Camera::setAspect(float aspect) {
  this->aspect = aspect;
  recalculate();
}

void Camera::setZNear(float zNear) {
  this->zNear = zNear;
  recalculate();
}

void Camera::setZFar(float zFar) {
  this->zFar = zFar;
  recalculate();
}

} /* namespace glPortal */