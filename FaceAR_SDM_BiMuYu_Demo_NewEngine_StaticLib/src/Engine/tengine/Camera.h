#pragma once

#include "MatrixConfig.h"
#include "Transform.h"

namespace tezcat
{
	class Camera
	{
	public:
		~Camera();

		static Camera *create()
		{
			auto p = new std::aligned_storage<sizeof(Camera), std::alignment_of<Camera>::value>::type();
			return new (p) Camera();
		}

		static Camera *create(const float &fov, const float &window_width, const float &window_height, const float &near_, const float &far_)
		{
			auto p = new std::aligned_storage<sizeof(Camera), std::alignment_of<Camera>::value>::type();
			return new (p) Camera(fov, window_width, window_height, near_, far_);
		}

		void render();

		void resetPerspective(const float &fov, const float &window_width, const float &window_height, const float &near_, const float &far_);
		void resetPerspective();

		void setUp(const glm::vec3 &head_up)
		{
			m_Up = head_up;
			m_NeedUpdata = true;
		}

		void setUp(const float &x, const float &y, const float &z)
		{
			m_Up.x = x;
			m_Up.y = y;
			m_Up.z = z;
			m_NeedUpdata = true;
		}

		void setPostion(const float &x, const float &y, const float &z)
		{
			m_Position.x = x;
			m_Position.y = y;
			m_Position.z = z;
			m_NeedUpdata = true;
		}

		glm::vec3 &getPosition() { return m_Position; }

		void setYaw(const float &val) { m_Yaw = val; }
		void setPitch(const float &val) { m_Pitch = val; }
		void setSpeed(const float &val) { m_Speed = val; }

		const glm::mat4 &getProjectionMatrix() const { return m_ProjectionMatrix; }

		const glm::mat4 &getViewMatrix() const { return m_ViewMatrix; }

		glm::mat4 getPVMatrix() { return m_ProjectionMatrix * m_ViewMatrix; }

	public:
		void forward(const float &dt)
		{
			m_Position += m_Front * m_Speed * dt;
			m_NeedUpdata = true;
		}

		void back(const float &dt)
		{
			m_Position -= m_Front * m_Speed * dt;
			m_NeedUpdata = true;
		}

		void left(const float &dt)
		{
			m_Position -= m_Right * m_Speed * dt;
			m_NeedUpdata = true;
		}

		void right(const float &dt)
		{
			m_Position += m_Right * m_Speed * dt;
			m_NeedUpdata = true;
		}

		void up(const float &dt)
		{
			m_Position += m_Up * m_Speed * dt;
			m_NeedUpdata = true;
		}

		void down(const float &dt)
		{
			m_Position -= m_Up * m_Speed * dt;
			m_NeedUpdata = true;
		}

	public:
		void onMouse(float x_offset, float y_offset, bool constrain_pitch = true);

		void setTransformParent()
		{ 
			m_Transform = m_Transform->getParent();
		}
		void setTransformParent(Transform *transform) { m_Transform = transform; }

	private:
		Camera();
		Camera(const float &fov, const float &window_width, const float &window_height, const float &near_, const float &far_);

		void updata();

	private:
		Transform *m_Transform;

		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;

		glm::vec3 m_Position;
		glm::vec3 m_Front;
		glm::vec3 m_Up;
		glm::vec3 m_Right;

		bool m_NeedUpdata;
		float m_WindowWidth, m_WindowHeight;
		float m_Near, m_Far;
		float m_Fov;
		float m_Aspect;
		float m_Speed;
		float m_Pitch, m_Yaw, m_Roll;
	};
}