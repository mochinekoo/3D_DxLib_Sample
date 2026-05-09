#include <cmath>
#include "Vector.hpp"

class Matrix3D {

	float m00_, m01_, m02_, m03_;
	float m10_, m11_, m12_, m13_;
	float m20_, m21_, m22_, m23_;
	float m30_, m31_, m32_, m33_;
	
	static Matrix3D Identity() {
		Matrix3D matrix = { 0 };
		matrix.m00_ = 1.0f; matrix.m01_ = 0.0f; matrix.m02_ = 0.0f; matrix.m03_ = 0.0f;
		matrix.m10_ = 0.0f; matrix.m11_ = 1.0f; matrix.m12_ = 0.0f; matrix.m13_ = 0.0f;
		matrix.m20_ = 0.0f; matrix.m21_ = 0.0f; matrix.m22_ = 1.0f; matrix.m23_ = 0.0f;
		matrix.m30_ = 0.0f; matrix.m31_ = 0.0f; matrix.m32_ = 0.0f; matrix.m33_ = 1.0f;
		return matrix;
	}

	static Matrix3D RotationX(float angle) {
		/*
		* [ 1 0 0 0 ]
		* [ 0 cos(angle) -sin(angle) 0 ]
		* [ 0 sin(angle) cos(angle) 0 ]
		* [ 0 0 0 1 ]
		*/

		Matrix3D matrix = { 0 };
		matrix.m00_ = 1.0f; matrix.m01_ = 0.0f; matrix.m02_ = 0.0f; matrix.m03_ = 0.0f;
		matrix.m10_ = 0.0f; matrix.m11_ = cos(angle); matrix.m12_ = -sin(angle); matrix.m13_ = 0.0f;
		matrix.m20_ = 0.0f; matrix.m21_ = sin(angle); matrix.m22_ = cos(angle); matrix.m23_ = 0.0f;
		matrix.m30_ = 0.0f; matrix.m31_ = 0.0f; matrix.m32_ = 0.0f; matrix.m33_ = 1.0f;
	}

	static Matrix3D RotationY(float angle) {
		/*
		* [ cos(angle) 0 sin(angle) 0 ]
		* [ 0 1 0 0 ]
		* [ -sin(angle) 0 cos(angle) 0 ]
		* [ 0 0 0 1 ]
		*/

		Matrix3D matrix = { 0 };
		matrix.m00_ = cos(angle); matrix.m01_ = 0.0f; matrix.m02_ = sin(angle); matrix.m03_ = 0.0f;
		matrix.m10_ = 0.0f; matrix.m11_ = 1.0f; matrix.m12_ = 0.0f; matrix.m13_ = 0.0f;
		matrix.m20_ = -sin(angle); matrix.m21_ = 0.0f; matrix.m22_ = cos(angle); matrix.m23_ = 0.0f;
		matrix.m30_ = 0.0f; matrix.m31_ = 0.0f; matrix.m32_ = 0.0f; matrix.m33_ = 1.0f;
	}

	static Matrix3D RotationZ(float angle) {
		/*
		* [ cos(angle) -sin(angle) 0 0 ]
		* [ sin(angle) cos(angle) 0 0 ]
		* [ 0 0 1 0 ]
		*/

		Matrix3D matrix = { 0 };
		matrix.m00_ = cos(angle); matrix.m01_ = -sin(angle); matrix.m02_ = 0.0f; matrix.m03_ = 0.0f;
		matrix.m10_ = sin(angle); matrix.m11_ = cos(angle); matrix.m12_ = 0.0f; matrix.m13_ = 0.0f;
		matrix.m20_ = 0.0f; matrix.m21_ = 0.0f; matrix.m22_ = 1.0f; matrix.m23_ = 0.0f;
		matrix.m30_ = 0.0f; matrix.m31_ = 0.0f; matrix.m32_ = 0.0f; matrix.m33_ = 1.0f;
	}

	static Matrix3D Translation(float x, float y, float z) {
		/*
		* [ 1 0 0 x ]
		* [ 0 1 0 y ]
		* [ 0 0 1 z ]
		* [ 0 0 0 1 ]
		*/
		Matrix3D matrix = { 0 };
		matrix.m00_ = 1.0f; matrix.m01_ = 0.0f; matrix.m02_ = 0.0f; matrix.m03_ = x;
		matrix.m10_ = 0.0f; matrix.m11_ = 1.0f; matrix.m12_ = 0.0f; matrix.m13_ = y;
		matrix.m20_ = 0.0f; matrix.m21_ = 0.0f; matrix.m22_ = 1.0f; matrix.m23_ = z;
		matrix.m30_ = 0.0f; matrix.m31_ = 0.0f; matrix.m32_ = 0.0f; matrix.m33_ = 1.0f;
	}

	static Matrix3D Scaling(float x, float y, float z) {
		/*
		* [ x 0 0 0 ]
		* [ 0 y 0 0 ]
		* [ 0 0 z 0 ]
		* [ 0 0 0 1 ]
		*/
		Matrix3D matrix = { 0 };
		matrix.m00_ = x; matrix.m01_ = 0.0f; matrix.m02_ = 0.0f; matrix.m03_ = 0.0f;
		matrix.m10_ = 0.0f; matrix.m11_ = y; matrix.m12_ = 0.0f; matrix.m13_ = 0.0f;
		matrix.m20_ = 0.0f; matrix.m21_ = 0.0f; matrix.m22_ = z; matrix.m23_ = 0.0f;
		matrix.m30_ = 0.0f; matrix.m31_ = 0.0f; matrix.m32_ = 0.0f; matrix.m33_ = 1.0f;
	}

	Vector3D operator*(const Vector3D& vector) const {
		float newX = m00_ * vector.x_ + m01_ * vector.y_ + m02_ * vector.z_ + m03_;
		float newY = m10_ * vector.x_ + m11_ * vector.y_ + m12_ * vector.z_ + m13_;
		float newZ = m20_ * vector.x_ + m21_ * vector.y_ + m22_ * vector.z_ + m23_;
		return Vector3D(newX, newY, newZ);
	}
	
};