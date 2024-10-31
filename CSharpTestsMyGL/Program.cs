namespace CSharpTestsMyGL
{
    internal class Program
    {
        public static GLSShader shader;
        public static GLSMesh mesh;

        static void Main(string[] args)
        {
            GLSWindow.RegisterOnInit(OnInit);
            GLSWindow.RegisterOnRendering(OnRender);
            GLSWindow.RegisterOnClosing(OnClose);
            GLSWindow.RegisterOnMouseMoving(OnMouseMoving);
            GLSWindow.RegisterOnScrollRolling(OnScrollRolling);
            GLSWindow.Init(800, 800, "CSharpOpneGL");
            while (!GLSWindow.ShouldClose())
            {
                GLSWindow.Render();
            }

            GLSWindow.Close();
        }

        static void OnInit()
        {
            shader = new GLSShader(File.ReadAllText("VertexShader.vsh"), File.ReadAllText("FragmentShader.psh"));
            float[] vertices = [
                -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
                -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
                 0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,
                 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f
            ];
            uint[] indices = [0, 1, 2, 0, 2, 3];
            mesh = new GLSMesh(vertices, indices);
        }

        static void OnRender()
        {
            SMatrix m1 = SMatrix.CreateScale(0.8f, 1.5f, 1.0f);
            SMatrix m2 = SMatrix.CreateRotationZ(3.1415926f / 4.0f);
            SMatrix m3 = SMatrix.CreateTranslation(0, 1, 0);
            m2 = m2 * m3;

            shader.Use();
            shader.SetMatrix("u_matrix", SMatrix.Lerp(m1, m2, MathF.Sin(DateTime.Now.Millisecond / 1000f * 0.5f + 0.5f)), false);
            mesh.Flush();
        }

        static void OnClose()
        {
            Console.WriteLine("Close");
        }

        static void OnMouseMoving(float x, float y)
        {
            Console.WriteLine(x + " " + y);
        }

        static void OnScrollRolling(float x, float y)
        {
            Console.WriteLine(x + " " + y);
        }
    }
}
