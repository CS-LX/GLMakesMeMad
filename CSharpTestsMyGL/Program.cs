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
            GLSVertex[] vertices = [
                new GLSVertex(new SVector3(-0.5f, -0.5f, 0.0f),  new SColor(0.0f, 0.0f, 1.0f, 1.0f),  new SVector3(0.0f, 0.0f, 1.0f),  new SVector2(0.0f, 0.0f)),
                new GLSVertex(new SVector3(-0.5f,  0.5f, 0.0f),  new SColor(0.0f, 1.0f, 1.0f, 1.0f),  new SVector3(0.0f, 0.0f, 1.0f),  new SVector2(0.0f, 1.0f)),
                new GLSVertex(new SVector3( 0.5f,  0.5f, 0.0f),  new SColor(1.0f, 1.0f, 1.0f, 1.0f),  new SVector3(0.0f, 0.0f, 1.0f),  new SVector2(1.0f, 1.0f)),
                new GLSVertex(new SVector3( 0.5f, -0.5f, 0.0f),  new SColor(1.0f, 0.0f, 1.0f, 1.0f),  new SVector3(0.0f, 0.0f, 1.0f),  new SVector2(1.0f, 0.0f))
            ];
            uint[] indices = [0, 1, 2, 0, 2, 3];
            mesh = new GLSMesh(vertices, indices);
        }

        static void OnRender()
        {
            shader.Use();
            shader.SetMatrix("u_matrix", SMatrix.Identity(), false);
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
