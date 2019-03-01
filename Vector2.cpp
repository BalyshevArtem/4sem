#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class Vector2 {
public:
	float x, y;
	Vector2() {
		x = 0;
		y = 0;
	}
	Vector2(float a, float b) {
		x = a;
		y = b;
	}
	Vector2& operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 operator*(float k) {
		return Vector2(x * k, y * k);
	}

	Vector2 operator/(float k) {
		if(k != 0) return Vector2(x / k, y / k);
		else return Vector2();
	}

	Vector2 perp() {
		return Vector2(y, -x);
	}
	
	Vector2 norm() {
		return Vector2(x / (sqrt(x * x + y * y)), y / (sqrt(x * x + y * y)));
	}

	float len() {
		return sqrt(x * x + y * y);
	}
	Vector2 operator-() {
		return Vector2(-x, -y);
	}

	Vector2& rotate(const float alfa) {
		float x1, y1;
		x1 = x; y1 = y;
		x = x1 * cos(alfa) - y1 * sin(alfa);
		y = y1 * cos(alfa) + x1 * sin(alfa);
		return *this;
	}
	Vector2& getRotated(const float alfa) {
		Vector2 v;
		v.x = x * cos(alfa) + y * sin(alfa);
		v.y = y * cos(alfa) - x * sin(alfa);
		return v;
	}
	Vector2& operator+(const Vector2& other1) {
		Vector2 v;
		v.x = other1.x + x;
		v.y = other1.y + y;
		return v;
	}

	Vector2& operator-(const Vector2& other1) {
		Vector2 v;
		v.x = other1.x - x;
		v.y = other1.y - y;
		return v;
	}

	float operator*(const Vector2& other1) {
		float res;
		res = other1.x * x + other1.y * y;
		return res;
	}

	float operator^(const Vector2& other1) {
		float res;
		res = other1.x * y - x * other1.y;
		return res;
	}
};

Vector2 operator*(const float k, const Vector2& v) {
	return Vector2(k * v.x, k * v.y);
}

std::ostream& operator<<(std::ostream& str, const Vector2& v) {
	str << "x : " << v.x << ", y : " << v.y << endl;
	return str;
}

std::istream& operator>>(std::istream& str, Vector2& v) {
		str >> v.x >> v.y;
		return str;
	}



int main() {
	Vector2 a;
	Vector2 b(3, 4);
	const float PI = 3.141592653589;
	std::cout << a << endl;
	std::cout << "b = " << b << endl;
	cout << "-b = " << -b;
	cout << " b rotate = " << b.rotate(PI / 2) << endl;
	Vector2 z;
	z = b.getRotated(PI / 2);
	cout << " b GetRotated = " << z << endl;
	cout << b.norm() << endl;
	cout << "perpendicular = " << b.perp() << endl;
	cout << "len = " << b.len() << endl;
	std::cin >> a;
	std::cout <<"a = " << a << endl;
	cout << "b / 3 = " << b / 3 << endl;
	cout << "3 * b = " << 3 * b << endl;
	cout << "scalyrnoe proizvedenie = " << a * b << endl;
	a += b;
	cout << "a = " << a << endl;
	Vector2 c;
	c = a + b;
	cout << c;
	system("pause");
}
