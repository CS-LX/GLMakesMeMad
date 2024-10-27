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

// 构造函数，使用 C 风格数组
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

// 析构函数，清理资源
GLMesh::~GLMesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

// 初始化 VAO, VBO, EBO
void GLMesh::Initialize(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount)
{
	this->indicesCount = indicesCount;

	// 创建 VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);// 1. 绑定VAO

	// 创建 VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);// 2. 把我们的顶点数组复制到一个顶点缓冲中，供OpenGL使用
	glBufferData(GL_ARRAY_BUFFER, verticesCount * sizeof(float), vertices, GL_STATIC_DRAW);

	// 创建 EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);// 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	// 假设每个顶点有3个float坐标，glVertexAttribPointer第一个参数n对应vsh里面layout (location = n)
	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色属性
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// 顶点法向
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 + 4 * sizeof(float)));
	glEnableVertexAttribArray(2);
	// 纹理坐标
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 + 4 + 3 * sizeof(float)));
	glEnableVertexAttribArray(3);

	// 解绑 VAO
	glBindVertexArray(0);
}