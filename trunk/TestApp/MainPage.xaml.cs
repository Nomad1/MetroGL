using System;
using System.Diagnostics;
using MetroGL;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace TestApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage
    {
        private readonly OpenGL m_gl;
        private int m_textureId1;
        private int m_textureId2;
        private float m_height;
        private float m_width;

        private float m_updateFps;
        private int m_lastFrameUpdate;
        private int m_updateFrames;

        public OpenGL GL
        {
            get { return m_gl; }
        }

        public MainPage()
        {
            this.InitializeComponent();
            m_gl = new OpenGL();

            GL.OnRender += Render;
            GL.OnInit += Init;
            GL.OnResize += Resize;

            GL.Initialize(this);
        }

        private void Render()
        {
            GL.Enable(All.ColorMaterial);
            GL.Enable(All.Texture2D);
            GL.Color4(1.0f, 1.0f, 1.0f, 1.0f);

            GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 0, 0, 1024, 1024 });
            GL.BindTexture(All.Texture2D, m_textureId1);
            GL.DrawTex(0, - (m_width - m_height) / 2, 0, m_width, m_width);
            
            for (int i = 0; i < 10; i++)
            {
                if (i % 2 == 0)
                {
                    GL.BindTexture(All.Texture2D, m_textureId2);
                    GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 0, 0, 256, 256 });
                }
                else
                {
                    GL.BindTexture(All.Texture2D, m_textureId2);
                    GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 256, 0, 256, 256 });
                }
                
                int aqPadding = 20;
                int fishSize = 128;
                int aqWidth = (int)m_width - aqPadding * 2 - fishSize;

                float x = (Environment.TickCount / (i + 10)) % aqWidth;
                float alpha = 1.0f;
                if (x < fishSize)
                    alpha = x / fishSize;
                else
                    if (x > aqWidth - fishSize)
                        alpha = (aqWidth - x - fishSize) / 128.0f;

                GL.Color4(1.0f, 1.0f, 1.0f, alpha);
                GL.DrawTex(x + aqPadding, m_height / 20 * (i + 5), 0, fishSize, fishSize);
            }

            m_updateFrames++;
            if (m_updateFrames >= Math.Min(m_updateFps * 2, 60))
            {
                m_updateFps = 1000 * m_updateFrames / (int)(Environment.TickCount - m_lastFrameUpdate + 1);
                m_lastFrameUpdate = Environment.TickCount;
                m_updateFrames = 0;
                FpsLabel.Text = m_updateFps.ToString();
            }
        }

        private void Init()
        {
            Debug.WriteLine("Init callback");

            m_textureId1 = (int)GL.LoadTexture("back.jpg");
            m_textureId2 = (int)GL.LoadTexture("fish.png");
        }

        private void Resize(int width, int height)
        {
            Debug.WriteLine("Resize callback " + width + ", " + height);
            GL.Ortho(0, width, 0, height, -1, 1);
            m_width = width;
            m_height = height;
        }

    }
}
