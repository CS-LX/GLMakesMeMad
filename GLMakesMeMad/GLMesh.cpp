#include "GLMesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLMesh::GLMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
{
	Initialize(vertices.data(), vertices.size(), indices.data(), indices.size());
}

GLMesh::GLMesh(const std::vector<GLVertex>& vertices, const std::vector<unsigned int>& indices)
{
	std::vector<float> verticesRaw;
	for (auto& v : vertices)
	{
		verticesRaw.push_back(v.Position.x);
		verticesRaw.push_back(v.Position.y);
		verticesRaw.push_back(v.Position.z);
		verticesRaw.push_back(v.VertexColor.r);
		verticesRaw.push_back(v.VertexColor.g);
		verticesRaw.push_back(v.VertexColor.b);
		verticesRaw.push_back(v.VertexColor.a);
		verticesRaw.push_back(v.Normal.x);
		verticesRaw.push_back(v.Normal.y);
		verticesRaw.push_back(v.Normal.z);
		verticesRaw.push_back(v.TextureCoordinate.x);
		verticesRaw.push_back(v.TextureCoordinate.y);
	}
	Initialize(verticesRaw.data(), verticesRaw.size(), indices.data(), indices.size());
}

// ���캯����ʹ�� C �������
GLMesh::GLMesh(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount)
{
	Initialize(vertices, verticesCount, indices, indicesCount);
}




void GLMesh::Flush() const
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}

// ����������������Դ
GLMesh::~GLMesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

// ��ʼ�� VAO, VBO, EBO
void GLMesh::Initialize(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount)
{
	this->indicesCount = indicesCount;

	// ���� VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);// 1. ��VAO

	// ���� VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);// 2. �����ǵĶ������鸴�Ƶ�һ�����㻺���У���OpenGLʹ��
	glBufferData(GL_ARRAY_BUFFER, verticesCount * sizeof(float), vertices, GL_STATIC_DRAW);

	// ���� EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);// 3. �������ǵ��������鵽һ�����������У���OpenGLʹ��
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	// ����ÿ��������3��float���꣬glVertexAttribPointer��һ������n��Ӧvsh����layout (location = n)
	// λ������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// ��ɫ����
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// ���㷨��
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 + 4 * sizeof(float)));
	glEnableVertexAttribArray(2);
	// ��������
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 + 4 + 3 * sizeof(float)));
	glEnableVertexAttribArray(3);

	// ��� VAO
	glBindVertexArray(0);
}