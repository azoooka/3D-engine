#include "TestObject.h"


TestObject::TestObject()
{

}

TestObject::TestObject(vec3 p_position)
{
	m_transform.SetPosition(p_position);
	float scale = 0.1;
	m_transform.SetScale(vec3(scale, scale, scale));
	m_movement = 0;
}


TestObject::~TestObject()
{
}

void TestObject::Update(float p_right, float p_forward)
{
	float moveSpeed = 0.1;
	float rotationSpeed = 1;
	float moveRotationSpeed = 1;

	m_transform.AlterRotation(vec3(0, p_right*rotationSpeed, 0));
	

	vec4 direction4 = rotate(m_transform.GetRotation().y, vec3(0, 1, 0))*vec4(1,0,0,0);

	m_direction.x = direction4.x;
	m_direction.y = direction4.y;
	m_direction.z = direction4.z;
	//p_forward *= -1;
	m_transform.AlterPosition(m_direction*moveSpeed*p_forward);



}

void TestObject::Draw(GraphicHandler* p_graphicsHandler)
{
	vector<mat4> matrix;
	matrix.push_back(m_transform.GetWorldMatrix());
	p_graphicsHandler->DrawInstanced(MESH_BTH, SHADER_BASIC_INSTANCED, matrix);
}
