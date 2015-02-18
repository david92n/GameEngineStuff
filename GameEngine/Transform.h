#pragma once
#include <glm/glm.hpp>

class Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));
	~Transform();

	glm::mat4 GetModel() const;

	inline glm::vec3& GetPos() { return m_pos; }
	inline glm::vec3& GetRot() { return m_rot; }
	inline glm::vec3& GetScale() { return m_scale; }

	inline void SetPos(glm::vec3& pos) { m_pos = pos; }
	inline void SetRot(glm::vec3& rot) { m_rot = rot; }
	inline void SetScale(glm::vec3& scale) { m_scale = scale; }
private:
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scale;
};
