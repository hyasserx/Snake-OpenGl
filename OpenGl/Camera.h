/*Camera Movment Class*/
#pragma once

#include <glm\glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm\gtx\transform.hpp>
#include<glm\gtx\rotate_vector.hpp>
using namespace glm;
class Camera
{
	vec3 Postion;
	vec3 Back, Up, Right;

public:
	Camera();
	Camera(vec3 _Postion, vec3 _lookAtPoint, vec3 upDirection);
	void Strafe( float steps);
	void Walk(float steps);
	void Fly(float steps);
	void Yaw(float angle);
	mat4 getViewMatrix();

	~Camera();
};

