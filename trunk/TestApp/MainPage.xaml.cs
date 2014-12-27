using System;
using System.Diagnostics;
using MetroGL;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace TestApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage
    {
        private readonly OpenGL m_gl;
        private float m_angle;
        private uint m_textureId1;
        private uint m_textureId2;
        private float m_height;
        private float m_width;
        private int m_frames;

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

            GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 0, 1024, 1024, -1024 });
            GL.BindTexture(All.Texture2D, m_textureId1);
            //GL.DrawTex(100, 500, 0, 250, 250);
            
            for (int i = 0; i < 500; i++)
            {
                if (i%10 > 5)
                {
                    GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] {0, 1024, 1024, -1024});
                    GL.BindTexture(All.Texture2D, m_textureId1);
                }
                else
                {
                    GL.BindTexture(All.Texture2D, m_textureId2);
                    GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 0, 512, 512, -512 });
                }
                
                float pos = (float) Math.Sin(i/100.0f + Environment.TickCount/1000.0f);
                GL.DrawTex(10 + (i % 200) * 5, (pos + 1)* m_height + (i/200) * 10, 0, 50, 50);
            }
            /*
            GL.BindTexture(All.Texture2D, m_textureId2);
            GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 0, 512, 512, -512 });
            for (int i = 500; i < 1000; i++)
            {
                float pos = (float)Math.Sin(i / 100.0f + Environment.TickCount / 1000.0f);
                GL.DrawTex(10 + (i % 200) * 5, (pos + 1) * m_height + (i / 200) * 10, 0, 50, 50);
            }
            /*
            GL.BindTexture(All.Texture2D, m_textureId2);
            GL.Color4(1.0f, 1.0f, 1.0f, 1.0f);
            GL.TexParameter(All.Texture2D, All.TextureCropRectOes, new int[] { 0, 512, 512, -512 });
            GL.DrawTexfOES(400, 500, 0, 200, 200);*/

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

            m_textureId1 = GL.LoadTexture("ui.png");
            m_textureId2 = GL.LoadTexture("background.bmp");
        }

        private void Resize(int width, int height)
        {
            Debug.WriteLine("Resize callback " + width + ", " + height);
            GL.Ortho(0, width, 0, height, -1, 1);
            m_width = width;
            m_height = (height / 2) - 50;
        }

    }
}
