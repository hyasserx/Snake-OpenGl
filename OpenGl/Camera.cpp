#include "Camera.h"
Camera::Camera() {

}
Camera::Camera(vec3 _Postion, vec3 _lookAtPoint, vec3 upDirection) {
	vec3 frontDir = normalize(_lookAtPoint - _Postion); //Get the Fronr direction and normalize it
	Right = normalize(cross(frontDir, upDirection));// Get the Right Vector  By Cross Product and normalize it
	Up = normalize(cross(Right,frontDir));//Get The real Up victor by Cross Product and normalize it
	Back = -frontDir;// According to Right Hand Rule for mahe Rules
	Postion = _Postion;// Saving The Postion and LOOK at Point 
}
void Camera::Strafe(float steps) {
	
	Postion += Right*steps;
}
void Camera::Walk(float steps) {
	Postion -= (Back*steps);
}
void Camera::Fly(float steps) {
	Postion += (Up*steps);
}
void Camera::Yaw(float angle) {
	Right = rotate(Right, angle, Up);
	Back = rotate(Back, angle, Up);
}
mat4 Camera::getViewMatrix() {
	vec3 Center = -Back + Postion;
	return lookAt(Postion, Center, Up);
} //Sends The View Matrix Directly Main



Camera::~Camera()
{
}
