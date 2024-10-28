namespace CSharpTestsMyGL
{
    internal class Program
    {
        static void Main(string[] args)
        {
            GLSWindow.Init(800, 800, "CSharpOpneGL");

            while (!GLSWindow.ShouldClose())
            {
                GLSWindow.Render();
            }

            GLSWindow.Close();
        }
    }
}
