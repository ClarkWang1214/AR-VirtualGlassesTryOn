#pragma once

#include <cassert>
#include <type_traits>
#include <string>
//#include "xsystem/XList.h"

namespace tezcat
{
	class RenderCommand;
	class Material;
	class Camera;
	class Mesh;
	class Transform;
	class RenderObject
	{
//		XLIST_CREATE_NODE(RenderObject *);
	public:
		enum class ObjectType
		{
			Type_Null,			//空类型
			Type_Node,			//节点类型
			Type_Mesh,			//模型
			Type_Skybox,		//天空盒
			Type_Quadrangle,	//四边形
			Type_Light,			//灯光
			Type_Camera,		//相机
			Type_Point,			//点
			Type_Line			//线
		};

	public:
		RenderObject();
		virtual ~RenderObject();

		//command
		void setRenderCommand(RenderCommand *cmd) { m_RenderCommand = cmd; }
		RenderCommand *getRenderCommand() { return m_RenderCommand; }
		template<class RC>
		typename std::enable_if<std::is_base_of<RenderCommand, RC>::value, RC *>::type *getRenderCommand()
		{
			return static_cast<RC *>(m_RenderCommand);
		}

		//mesh
		void setMesh(Mesh *mesh)
		{
			assert(m_ObjectType == ObjectType::Type_Null || m_ObjectType == ObjectType::Type_Mesh);
			m_ObjectType = ObjectType::Type_Mesh;
			m_Mesh = mesh;
		}
		Mesh* getMesh() { return m_Mesh; }

		//material
		void setMaterial(Material *material)
		{
			assert(m_ObjectType == ObjectType::Type_Mesh ||
				m_ObjectType == ObjectType::Type_Quadrangle ||
				m_ObjectType == ObjectType::Type_Skybox);
			m_Material = material;
		}
		Material *getMaterial() { return m_Material; }
		template<class Mat>
        typename std::enable_if<std::is_base_of<Material, Mat>::value, Mat *>::type getMaterial() { return static_cast<Mat *>(m_Material); }

		//camera
		void setCamera(Camera *camera)
		{
			assert(m_ObjectType == ObjectType::Type_Null || m_ObjectType == ObjectType::Type_Camera);
			m_ObjectType = ObjectType::Type_Camera;
			m_Camera = camera;
		}

		Camera *getCamera()
		{
			assert(m_ObjectType == ObjectType::Type_Camera);
			return m_Camera;
		}

		//type
		void setObjectType(const RenderObject::ObjectType &type) { m_ObjectType = type; }
		const RenderObject::ObjectType &getObjectType() const { return m_ObjectType; }

		//transform
		Transform* getTransform() const { return m_Transform; }
		void setTransform(Transform* val) { m_Transform = val; }

		const bool &getVisible() const { return m_Visible; }
		void setVisible(const bool &val) { m_Visible = val; }

		//=======================================================================
		void uploadRenderCommand();

	protected:
		bool			m_Visible;
		RenderCommand*	m_RenderCommand;
		Material*		m_Material;
		Mesh*			m_Mesh;
		Camera*			m_Camera;
		Transform*		m_Transform;
		ObjectType		m_ObjectType;
	};

#define RENDER_OBJECT_GET_TYPE \
public:\
	virtual const RenderObject::ObjectType &getObjectType() const override\
	{\
		return m_ObjectType;\
	}\
private:\
	static ObjectType m_ObjectType;

#define RENDER_OBJECT_SET_TYPE(Object, Type)\
RenderObject::ObjectType Object::m_ObjectType = RenderObject::ObjectType::Type;

}
