#ifdef BUILD_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#include <vector>

class DLL_API GLMesh {
public:
	unsigned int VAO, VBO, EBO;
	int indicesCount;

	// ���캯����ʹ�� std::vector
	GLMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

	// ���캯����ʹ�� C �������
	GLMesh(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount);

	void Flush() const;

	// ����������������Դ
	~GLMesh();

private:
	// ��ʼ�� VAO, VBO, EBO
	void Initialize(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount);
};

