#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "glm/gtc/type_ptr.hpp"

namespace tezcat
{
	const static glm::vec3 AxisX = glm::vec3(1, 0, 0);
	const static glm::vec3 AxisY = glm::vec3(0, 1, 0);
	const static glm::vec3 AxisZ = glm::vec3(0, 0, 1);
	const static glm::mat4 IdentifyMat4 = glm::mat4(1.0f);
	const static glm::quat IdentifyQuat = glm::quat();

// #define ALIGNED_STORAGE_NEW(type) \
// public:\
// 	static type *create()\
// 	{\
// 		auto p = new std::aligned_storage<sizeof(type), std::alignment_of<type>::value>::type();\
// 		return new (p) type();\
// 	}
}

