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

	// 构造函数，使用 std::vector
	GLMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

	// 构造函数，使用 C 风格数组
	GLMesh(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount);

	void Flush() const;

	// 析构函数，清理资源
	~GLMesh();

private:
	// 初始化 VAO, VBO, EBO
	void Initialize(const float vertices[], unsigned int verticesCount, const unsigned int indices[], unsigned int indicesCount);
};

