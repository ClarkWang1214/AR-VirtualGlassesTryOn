#pragma once

#include <unordered_map>
#include "MatrixConfig.h"

namespace tezcat
{
	class Transform
	{
		enum UpdataWho : unsigned int
		{
			NoUpdata = 0,
			Position = 1,
			Rotation = 1 << 1,
			Scale = 1 << 2,
			UpdataAll = Position + Rotation + Scale
		};
	public:
		Transform();
		~Transform();

		static Transform *create()
		{
			auto p = new std::aligned_storage<sizeof(Transform), std::alignment_of<Transform>::value>::type();
			return new (p) Transform();
		}

		Transform *getParent() const { return m_Parent; }
		void setParent(Transform * val){ m_Parent = val; }

		const std::string &getName() const { return m_Name; }
		void setName(const std::string &val) { m_Name = val; }

		glm::mat4 &getWorldMatrix() { return m_WorldMatrix; }
		glm::mat4 &getLocationMatrix() { return m_LocationMatrix; }

		//************************************
		// 函数名:	logic
		// 全名:		tezcat::Transform::logic
		// 权限:		public 
		// 返回值:   void
		// 限定符:	
		// 功能:		
		//************************************
		void logic();

		//************************************
		// 函数名:	setMatrix
		// 全名:		tezcat::Transform::setMatrix
		// 权限:		public 
		// 返回值:   void
		// 限定符:	
		// 参数:		const float & col11
		// 参数:		const float & col12
		// 参数:		const float & col13
		// 参数:		const float & col21
		// 参数:		const float & col22
		// 参数:		const float & col23
		// 参数:		const float & col31
		// 参数:		const float & col32
		// 参数:		const float & col33
		// 参数:		const float & col41
		// 参数:		const float & col42
		// 参数:		const float & col43
		// 功能:		
		//************************************
		void setMatrix(
			const float &col11, const float &col12, const float &col13,
			const float &col21, const float &col22, const float &col23,
			const float &col31, const float &col32, const float &col33,
			const float &col41, const float &col42, const float &col43);
	public:
		glm::vec3 getPosition() const { return m_Position; }
		float getPositionX() const { return m_Position.x; }
		float getPositionY() const { return m_Position.y; }
		float getPositionZ() const { return m_Position.z; }

		void setPosition(const glm::vec3 &val)
		{
			m_Position = val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionX(const float &val)
		{
			m_Position.x = val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionY(const float &val)
		{
			m_Position.y = val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionZ(const float &val)
		{
			m_Position.z = val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPosition(const float &x, const float &y, const float &z)
		{
			m_Position.x = x;
			m_Position.y = y;
			m_Position.z = z;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionByOffset(const glm::vec3 &val)
		{
			m_Position += val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionByOffset(const float &x, const float &y, const float &z)
		{
			m_Position.x += x;
			m_Position.y += y;
			m_Position.z += z;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionXByOffset(const float &val)
		{
			m_Position.x += val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionYByOffset(const float &val)
		{
			m_Position.y += val;
			m_UpdataWho |= UpdataWho::Position;
		}

		void setPositionZByOffset(const float &val)
		{
			m_Position.z += val;
			m_UpdataWho |= UpdataWho::Position;
		}

		glm::mat4 &getTransformMatrix()
		{
			return m_TranslationMatrix;
		}

	public:
		glm::vec3 &getRotation() { return m_Rotation; }
		float &getRotationX() { return m_Rotation.x; }
		float &getRotationY() { return m_Rotation.y; }
		float &getRotationZ() { return m_Rotation.z; }

		void setRotation(const glm::vec3 &val)
		{
			m_Rotation = glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotation(const float &x, const float &y, const float &z)
		{
			m_Rotation.x = glm::radians(x);
			m_Rotation.y = glm::radians(y);
			m_Rotation.z = glm::radians(z);

			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationX(const float &val)
		{
			m_Rotation.x = glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationY(const float &val)
		{
			m_Rotation.y = glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationZ(const float &val)
		{
			m_Rotation.z = glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationByOffset(const glm::vec3 &val)
		{
			m_Rotation += glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationByOffset(const float &x, const float &y, const float &z)
		{
			m_Rotation.x += glm::radians(x);
			m_Rotation.y += glm::radians(y);
			m_Rotation.z += glm::radians(z);


			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationXByOffset(const float &val)
		{
			m_Rotation.x += glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationYByOffset(const float &val)
		{
			m_Rotation.y += glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		void setRotationZByOffset(const float &val)
		{
			m_Rotation.z += glm::radians(val);
			m_UpdataWho |= UpdataWho::Rotation;
		}

		glm::mat4 &getRotationMatrix()
		{
			return m_RotationMatrix;
		}


	public:
		glm::vec3 getScale() const { return m_Scale; }
		float getScaleX() { return m_Scale.x; }
		float getScaleY() { return m_Scale.y; }
		float getScaleZ() { return m_Scale.z; }

		void setScale(const glm::vec3 &val)
		{
			m_Scale = val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScale(const float &x, const float &y, const float &z)
		{
			m_Scale.x = x;
			m_Scale.y = y;
			m_Scale.z = z;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleX(const float &val)
		{
			m_Scale.x = val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleY(const float &val)
		{
			m_Scale.y = val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleZ(const float &val)
		{
			m_Scale.z = val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleByOffset(const glm::vec3 &val)
		{
			m_Scale += val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleByOffset(const float &x, const float &y, const float &z)
		{
			m_Scale.x += x;
			m_Scale.y += y;
			m_Scale.z += z;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleXByOffset(const float &val)
		{
			m_Scale.x += val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleYByOffset(const float &val)
		{
			m_Scale.y += val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		void setScaleZByOffset(const float &val)
		{
			m_Scale.z += val;
			m_UpdataWho |= UpdataWho::Scale;
		}

		glm::mat4 &getScaleMatrix()
		{
			return m_ScaleMatrix;
		}

	private:
		std::string m_Name;
		Transform *m_Parent;

		glm::vec3 m_Position;
		glm::vec3 m_LocalPosition;
		glm::vec3 m_Scale;
		glm::vec3 m_LocalScale;
		glm::vec3 m_Rotation;
		glm::vec3 m_LocalRotation;

		glm::mat4 m_TranslationMatrix;
		glm::mat4 m_ScaleMatrix;
		glm::mat4 m_RotationMatrix;
		glm::mat4 m_WorldMatrix;
		glm::mat4 m_LocationMatrix;

		unsigned int m_UpdataWho;

	public:
		static Transform *SwapTransform;
	};
}