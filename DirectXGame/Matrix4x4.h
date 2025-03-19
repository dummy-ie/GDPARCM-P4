#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <memory>
#include <DirectXMath.h>

#include "Vector3D.h"
#include "Vector4D.h"

namespace gdeng03
{
	class Matrix4x4
	{
	public:
		Matrix4x4()
		{
			setIdentity();
		}
		~Matrix4x4() = default;

		void setIdentity()
		{
			::memset(mat, 0, sizeof(float) * 16);
			mat[0][0] = 1;
			mat[1][1] = 1;
			mat[2][2] = 1;
			mat[3][3] = 1;
		}

		void setTranslation(const Vector3D& translation)
		{
			setIdentity();
			mat[3][0] = translation.x;
			mat[3][1] = translation.y;
			mat[3][2] = translation.z;
		}

		void setTranslationWithoutReset(const Vector3D& translation)
		{
			//setIdentity();
			mat[3][0] = translation.x;
			mat[3][1] = translation.y;
			mat[3][2] = translation.z;
		}

		void setScale(const Vector3D& scale)
		{
			setIdentity();
			mat[0][0] = scale.x;
			mat[1][1] = scale.y;
			mat[2][2] = scale.z;
		}

		void setRotationX(const float x)
		{
			setIdentity();
			mat[1][1] = cos(x);
			mat[1][2] = sin(x);
			mat[2][1] = -sin(x);
			mat[2][2] = cos(x);
		}

		void setRotationY(const float y)
		{
			setIdentity();
			mat[0][0] = cos(y);
			mat[0][2] = -sin(y);
			mat[2][0] = sin(y);
			mat[2][2] = cos(y);
		}

		void setRotationZ(const float z)
		{
			setIdentity();
			mat[0][0] = cos(z);
			mat[0][1] = sin(z);
			mat[1][0] = -sin(z);
			mat[1][1] = cos(z);
		}

		float getDeterminant() const
		{
			Vector4D minor;

			const Vector4D v1 = Vector4D(this->mat[0][0], this->mat[1][0], this->mat[2][0], this->mat[3][0]);
			const Vector4D v2 = Vector4D(this->mat[0][1], this->mat[1][1], this->mat[2][1], this->mat[3][1]);
			const Vector4D v3 = Vector4D(this->mat[0][2], this->mat[1][2], this->mat[2][2], this->mat[3][2]);


			minor.cross(v1, v2, v3);
			const float det = -(this->mat[0][3] * minor.x + this->mat[1][3] * minor.y + this->mat[2][3] * minor.z +
				this->mat[3][3] * minor.w);
			return det;
		}

		void inverse()
		{
			Matrix4x4 out;
			Vector4D v;

			const float det = this->getDeterminant();
			if (!det) return;
			for (int i = 0; i < 4; i++)
			{
				Vector4D vec[3];
				for (int j = 0; j < 4; j++)
				{
					if (j != i)
					{
						int a = j;
						if (j > i) a = a - 1;
						vec[a].x = (this->mat[j][0]);
						vec[a].y = (this->mat[j][1]);
						vec[a].z = (this->mat[j][2]);
						vec[a].w = (this->mat[j][3]);
					}
				}
				v.cross(vec[0], vec[1], vec[2]);

				out.mat[0][i] = static_cast<float>(pow(-1.0f, i)) * v.x / det;
				out.mat[1][i] = static_cast<float>(pow(-1.0f, i)) * v.y / det;
				out.mat[2][i] = static_cast<float>(pow(-1.0f, i)) * v.z / det;
				out.mat[3][i] = static_cast<float>(pow(-1.0f, i)) * v.w / det;
			}

			this->setMatrix(out);
		}

		void setOrthographicProjection(const float width, const float height, const float nearPlane, const float farPlane)
		{
			setIdentity();
			mat[0][0] = 2.0f / width;
			mat[1][1] = 2.0f / height;
			mat[2][2] = 1.0f / (farPlane - nearPlane);
			mat[3][2] = -(nearPlane / (farPlane - nearPlane));
		}

		void setPerspectiveProjection(const float fov, const float aspect, const float zNear, const float zFar)
		{
			// DirectX::XMMATRIX perspective = DirectX::XMMatrixPerspectiveFovLH(fov, aspect, zNear, zFar);
			//
			// for (int i = 0; i < 4; ++i)
			// {
			// 	for (int j = 0; j < 4; ++j)
			// 	{
			// 		mat[i][j] = perspective.r[i].m128_f32[j];
			// 	}
			// }

			setIdentity();
			const float yScale = 1.0f / static_cast<float>(tan((fov * (M_PI / 180.f)) / 2.0f));
			const float xScale = yScale / aspect;
			mat[0][0] = xScale;
			mat[1][1] = yScale;
			mat[2][2] = zFar / (zFar - zNear);
			mat[2][3] = 1.0f;
			mat[3][2] = (-zNear * zFar) / (zFar - zNear);
		}


		void setMatrix(const Matrix4x4& matrix)
		{
			::memcpy(mat, matrix.mat, sizeof(float) * 16);
		}

		void setMatrix(float matrix[16])
		{
			::memcpy(mat, matrix, sizeof(float) * 16);
		}

		void setMatrix(float matrix[4][4])
		{
			::memcpy(mat, matrix, sizeof(float) * 16);
		}

		Vector3D getZDirection() const
		{
			return Vector3D(mat[2][0], mat[2][1], mat[2][2]);
		}

		Vector3D getXDirection() const
		{
			return Vector3D(mat[0][0], mat[0][1], mat[0][2]);
		}

		Vector3D getYDirection() const
		{
			return Vector3D(mat[1][0], mat[1][1], mat[1][2]);
		}

		Vector3D getTranslation() const
		{
			return Vector3D(mat[3][0], mat[3][1], mat[3][2]);
		}

		void operator *=(const Matrix4x4& matrix)
		{
			Matrix4x4 out;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					out.mat[i][j] =
						mat[i][0] * matrix.mat[0][j] + mat[i][1] * matrix.mat[1][j] +
						mat[i][2] * matrix.mat[2][j] + mat[i][3] * matrix.mat[3][j];
				}
			}
			setMatrix(out);
		}

		Matrix4x4 multiplyTo(const Matrix4x4& matrix) const
		{
			Matrix4x4 out;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					out.mat[i][j] =
						this->mat[i][0] * matrix.mat[0][j] + this->mat[i][1] * matrix.mat[1][j] +
						this->mat[i][2] * matrix.mat[2][j] + this->mat[i][3] * matrix.mat[3][j];
				}
			}

			return out;
		}

		Matrix4x4 operator*(const Matrix4x4& matrix) const
		{
			Matrix4x4 out;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					out.mat[i][j] =
						mat[i][0] * matrix.mat[0][j] + mat[i][1] * matrix.mat[1][j] +
						mat[i][2] * matrix.mat[2][j] + mat[i][3] * matrix.mat[3][j];
				}
			}
			return out;
		}

		void transpose()
		{
			float transpose[4][4] = {};
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j) {
					transpose[j][i] = mat[i][j];
				}

			setMatrix(transpose);
		}

		Matrix4x4 getTranspose() const
		{
			Matrix4x4 transposed;

			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j) {
					transposed.mat[j][i] = mat[i][j];
				}

			return transposed;
		}

		friend std::ostream& operator<< (std::ostream& outs, const Matrix4x4& mat) {
			return outs << "\n\n(" << mat.mat[0][0] << ", " << mat.mat[0][1] << ", " << mat.mat[0][2] << ", " << mat.mat[0][3] << ")" << "\n"
				<< "(" << mat.mat[1][0] << ", " << mat.mat[1][1] << ", " << mat.mat[1][2] << ", " << mat.mat[1][3] << ")" << "\n"
				<< "(" << mat.mat[2][0] << ", " << mat.mat[2][1] << ", " << mat.mat[2][2] << ", " << mat.mat[2][3] << ")" << "\n"
				<< "(" << mat.mat[3][0] << ", " << mat.mat[3][1] << ", " << mat.mat[3][2] << ", " << mat.mat[3][3] << ")" << "\n";
		}

		std::string toString() const
		{
			return  "\n\n(" + std::to_string(mat[0][0]) + ", " + std::to_string(mat[0][1]) + ", " + std::to_string(mat[0][2]) + ", " + std::to_string(mat[0][3]) + ")" + "\n"
				+ "(" + std::to_string(mat[1][0]) + ", " + std::to_string(mat[1][1]) + ", " + std::to_string(mat[1][2]) + ", " + std::to_string(mat[1][3]) + ")" + "\n"
				+ "(" + std::to_string(mat[2][0]) + ", " + std::to_string(mat[2][1]) + ", " + std::to_string(mat[2][2]) + ", " + std::to_string(mat[2][3]) + ")" + "\n"
				+ "(" + std::to_string(mat[3][0]) + ", " + std::to_string(mat[3][1]) + ", " + std::to_string(mat[3][2]) + ", " + std::to_string(mat[3][3]) + ")" + "\n";
		}

		float* getMatrix()
		{
			return *mat;
		}

		static void decomposeMatrix(const Matrix4x4& matrix, Vector3D& position, Vector3D& rotation, Vector3D& scale) {
			// Extract position
			position.x = matrix.mat[3][0];
			position.y = matrix.mat[3][1];
			position.z = matrix.mat[3][2];

			// Extract scale
			scale.x = sqrt(matrix.mat[0][0] * matrix.mat[0][0] + matrix.mat[0][1] * matrix.mat[0][1] + matrix.mat[0][2] * matrix.mat[0][2]);
			scale.y = sqrt(matrix.mat[1][0] * matrix.mat[1][0] + matrix.mat[1][1] * matrix.mat[1][1] + matrix.mat[1][2] * matrix.mat[1][2]);
			scale.z = sqrt(matrix.mat[2][0] * matrix.mat[2][0] + matrix.mat[2][1] * matrix.mat[2][1] + matrix.mat[2][2] * matrix.mat[2][2]);

			// Normalize
			Matrix4x4 rotationMatrix = matrix;
			for (int i = 0; i < 3; ++i) {
				rotationMatrix.mat[i][0] /= scale.x;
				rotationMatrix.mat[i][1] /= scale.y;
				rotationMatrix.mat[i][2] /= scale.z;
			}

			// Extract rotation (Euler angles)
			rotation.y = std::asin(-rotationMatrix.mat[0][2]); // Pitch
			if (std::cos(rotation.y) > 0.0001f) {
				rotation.x = std::atan2(rotationMatrix.mat[1][2], rotationMatrix.mat[2][2]); // Yaw
				rotation.z = std::atan2(rotationMatrix.mat[0][1], rotationMatrix.mat[0][0]); // Roll
			}
			else {
				rotation.x = std::atan2(-rotationMatrix.mat[2][0], rotationMatrix.mat[1][1]);
				rotation.z = 0.0f;
			}
		}

	public:
		float mat[4][4] = {};
	};
}
