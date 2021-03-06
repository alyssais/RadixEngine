#ifndef RADIX_CAMERA_HPP
#define RADIX_CAMERA_HPP

#include <radix/core/math/Math.hpp>
#include <radix/core/math/Matrix4f.hpp>
#include <radix/core/math/Vector3f.hpp>
#include <radix/core/math/Quaternion.hpp>

namespace radix {

class Camera {
public:
  static constexpr const float DEFAULT_FOVY = rad(60);
  static constexpr const float DEFAULT_ASPECT = 1;
  static constexpr const float DEFAULT_ZNEAR = 0.1f;
  static constexpr const float DEFAULT_ZFAR = 100;
  static constexpr const bool  DEFAULT_PERSPECTIVE = true;
  static constexpr const float DEFAULT_TOP = 0.5f;
  static constexpr const float DEFAULT_BOTTOM = -0.5f;
  static constexpr const float DEFAULT_LEFT = -0.5f;
  static constexpr const float DEFAULT_RIGHT = 0.5f;

  Camera() = default;
  Camera(const float fovy, const float aspect, const float zNear, const float zFar);

  void getProjMatrix(Matrix4f &m) const;
  void setProjMatrix(const Matrix4f &m);
  void getViewMatrix(Matrix4f &m) const;
  void setViewMatrix(const Matrix4f &m);
  void getInvViewMatrix(Matrix4f &m) const;

  void setFovy(const float fovy);
  float getFovy() const;
  void setAspect(const float aspect);
  float getAspect() const;
  void setZNear(const float zNear);
  float getZNear() const;
  void setZFar(const float zFar);
  float getZFar() const;
  void setPerspective();
  void setOrthographic();
  void setBounds(const float left, const float right, const float bottom, const float top);

  Vector3f getPosition() const;
  void setPosition(const Vector3f&);
  Quaternion getOrientation() const;
  void setOrientation(const Quaternion&);

private:
  Vector3f position;
  Quaternion orientation;

  void calcProj();
  void calcView();
  Matrix4f projMatrix;
  Matrix4f viewMatrix;
  Matrix4f invViewMatrix;

  bool perspective = DEFAULT_PERSPECTIVE;
  float fovy    = DEFAULT_FOVY;
  float aspect  = DEFAULT_ASPECT;
  float zNear   = DEFAULT_ZNEAR;
  float zFar    = DEFAULT_ZFAR;

  float top     = DEFAULT_TOP;
  float bottom  = DEFAULT_BOTTOM;
  float left    = DEFAULT_LEFT;
  float right   = DEFAULT_RIGHT;
};

} /* namespace radix */

#endif /* RADIX_CAMERA_HPP */
