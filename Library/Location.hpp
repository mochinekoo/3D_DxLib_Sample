#include <cmath>

class Location3D {
private:
public:
	float x_, y_, z_;

	Location3D() {
		x_ = 0;
		y_ = 0;
		z_ = 0;
	}

	Location3D(float x, float y, float z) {
		x_ = x;
		y_ = y;
		z_ = z;
	}

	Location3D Add(float x, float y, float z) const {
		float newX = x_ + x;
		float newY = y_ + y;
		float newZ = z_ + z;
		return Location3D(newX, newY, newZ);
	}

	Location3D Add(const Location3D& other) const {
		return Add(other.x_, other.y_, other.z_);
	}

	Location3D operator+(const Location3D& other) const {
		return Add(other);
	}

	Location3D Subtract(float x, float y, float z) const {
		float newX = x_ - x;
		float newY = y_ - y;
		float newZ = z_ - z;
		return Location3D(newX, newY, newZ);
	}

	Location3D Subtract(const Location3D& other) const {
		return Subtract(other.x_, other.y_, other.z_);
	}

	Location3D operator-(const Location3D& other) const {
		return Subtract(other);
	}

	Location3D Scalar(float scalar) const {
		float newX = x_ * scalar;
		float newY = y_ * scalar;
		float newZ = z_ * scalar;
		return Location3D(newX, newY, newZ);
	}

	Location3D operator*(float scalar) const {
		return Scalar(scalar);
	}

	float Distance(const Location3D& other) const {
		float newX = (x_ - other.x_) * (x_ - other.x_);
		float newY = (y_ - other.y_) * (y_ - other.y_);
		float newZ = (z_ - other.z_) * (z_ - other.z_);
		return std::sqrt(newX + newY + newZ);
	}
};