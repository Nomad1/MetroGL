#include "pch.h"
#include "OpenGL.h"
#include "gl2dx.h"
#include "Bitmap.h"

//#define GL_DRAWTEX

using namespace MetroGL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::Graphics::Display;

OpenGL::OpenGL()
{
	Oes = this;
}

void OpenGL::Initialize(SwapChainBackgroundPanel^ panel)
{
	m_game = ref new DirectXGame();
	m_game->OnInit += ref new DirectXInitDelegate(this, &OpenGL::OnInternalInit);
	m_game->OnResize += ref new DirectXResizeDelegate(this, &OpenGL::OnInternalResize);

	m_game->Initialize(
		Window::Current->CoreWindow,
		panel,
		DisplayProperties::LogicalDpi
		);


	Window::Current->CoreWindow->SizeChanged += 
		ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &OpenGL::OnWindowSizeChanged);

	DisplayProperties::LogicalDpiChanged +=
		ref new DisplayPropertiesEventHandler(this, &OpenGL::OnLogicalDpiChanged);

	CompositionTarget::Rendering::add(ref new EventHandler<Object^>(this, &OpenGL::OnRendering));
}

void OpenGL::OnRendering(Platform::Object^ sender, Platform::Object^ args)
{
	m_game->Render();

	OnRender();

	m_game->Present();
}

void OpenGL::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	m_game->UpdateForWindowSizeChange();
}

void OpenGL::OnLogicalDpiChanged(Object^ sender)
{
	m_game->SetDpi(DisplayProperties::LogicalDpi);
}

void OpenGL::OnInternalInit(Object^ sender)
{
	OnInit();
}

void OpenGL::OnInternalResize(Object^ sender, int width, int height)
{
	OnResize(width, height);
}

unsigned int OpenGL::LoadTexture(String ^ name)
{
	unsigned int result;
	
	::glGenTextures(1, &result);
	::glBindTexture(GL_TEXTURE_2D, result);

	::gl2dxLoadTexture(name->Data());

	::glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	::glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	::glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	return result;
}
///
void OpenGL::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	::glOrtho(left, right, bottom, top, zNear, zFar);
}

void OpenGL::PopMatrix()
{
	::glPopMatrix();
}

void OpenGL::PushMatrix()
{
	::glPushMatrix();
}

void OpenGL::LoadIdentity()
{
	::glLoadIdentity();
}

void OpenGL::Viewport(int x, int y, int width, int height)
{
    ::glViewport(x, y, width, height);
}

void OpenGL::Rotate(float angle, float x, float y, float z)
{
	::glRotatef(angle, x, y, z);
}

void OpenGL::Translate(float x, float y, float z)
{
	::glTranslatef(x, y, z);
}

void OpenGL::Enable(All cap)
{
	::glEnable((int)cap);
}

void OpenGL::Disable(All cap)
{
	::glDisable((int)cap);
}

void OpenGL::MatrixMode(All mode)
{
    ::glMatrixMode((int)mode);
}

void OpenGL::EnableClientState(All cap)
{
	::glEnableClientState((int)cap);
}

void OpenGL::DisableClientState(All cap)
{
	::glDisableClientState((int)cap);
}

void OpenGL::Scale(float x, float y, float z)
{
	::glScalef(x, y, z);
}

void OpenGL::Color4(float r, float g, float b, float a)
{
	::glColor4ub((unsigned char)(r*255),(unsigned char)(g*255),(unsigned char)(b*255),(unsigned char)(a*255));
}

void OpenGL::VertexPointer(int size, All type, int stride, const Array<float>^ pointer)
{
	::glVertexPointer(size, (int)type, stride, pointer->Data);
}

void OpenGL::VertexPointer(int size, All type, int stride, int64 pointer)
{
	::glVertexPointer(size, (int)type, stride, (void*)pointer);
}

void OpenGL::DrawArrays(All mode, int first, int count)
{
	::glDrawArrays((int)mode, first, count);
}

void OpenGL::TexCoordPointer(int size, All type, int stride, const Array<float>^ pointer)
{
	::glTexCoordPointer(size, (int)type, stride, pointer->Data);
}

void OpenGL::TexCoordPointer(int size, All type, int stride, int64 pointer)
{
	::glTexCoordPointer(size, (int)type, stride, (void*)pointer);
}

void OpenGL::BindTexture(All target, int texture)
{
	::glBindTexture((int)target, texture);
}

void OpenGL::TexParameter(All target, All pname, const Array<int>^ pparam)
{
	if (pname == All::TextureCropRectOes)
	{
		m_textureCropOesTiv[0] = pparam->get(0);
		m_textureCropOesTiv[1] = pparam->get(1);
		m_textureCropOesTiv[2] = pparam->get(2);
		m_textureCropOesTiv[3] = pparam->get(3);
		return;
	}

	::glTexParameteri((int)target, (int)pname, pparam[0]);
}

void OpenGL::TexParameter(All target, All pname, int pparam)
{
	::glTexParameteri((int)target, (int)pname, pparam);
}

void OpenGL::TexParameter(All target, All pname, const Array<float>^ pparam)
{
	::glTexParameterf((int)target, (int)pname, pparam[0]);
}

void OpenGL::TexParameter(All target, All pname, float pparam)
{
	::glTexParameterf((int)target, (int)pname, pparam);
}

void OpenGL::TexEnv(All target, All pname, int pparam)
{
	::glTexEnvi((int)target, (int)pname, pparam);
}

void OpenGL::TexEnv(All target, All pname, const Array<int>^ pparam)
{
	::glTexEnvi((int)target, (int)pname, pparam[0]);
}

void OpenGL::TexEnv(All target, All pname, float pparam)
{
	::glTexEnvf((int)target, (int)pname, pparam);
}

void OpenGL::TexEnv(All target, All pname, const Array<float>^ pparam)
{
	::glTexEnvf((int)target, (int)pname, pparam[0]);
}

void OpenGL::DrawTex(float x, float y, float z, float w, float h)
{
#ifdef GL_DRAWTEX
	static float s_vertexValues[] = { -0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f };

	::glPushMatrix();
	::glLoadIdentity();

	/// TODO: invert y axis!

	::glTranslatef(w / 2.0f + x, h / 2.0f + y, 0.0f);

	::glScalef(w, h, 1.0f);
	
	int * tiv = m_textureCropOesTiv;

	int texW;
	::glGetIntegerv(GL_TEXTURE_WIDTH, &texW); /// NOTE: Does not work in real OpenGL ES!!
	int texH;
	::glGetIntegerv(GL_TEXTURE_HEIGHT, &texH); /// NOTE: Does not work in real OpenGL ES!!

	float texCoordValues[8];

	float left = (tiv[0] + tiv[2]) / (float) texW;
	float bottom = tiv[1] / (float) texH;
	float right = tiv[0] / (float) texW;
	float top = (tiv[1] + tiv[3]) / (float) texH;

	texCoordValues[0] = right;
	texCoordValues[2] = left;
	texCoordValues[4] = right;
	texCoordValues[6] = left;

	texCoordValues[1] = bottom;
	texCoordValues[3] = bottom;
	texCoordValues[5] = top;
	texCoordValues[7] = top;

	::glEnableClientState(GL_VERTEX_ARRAY);
	::glVertexPointer(2, GL_FLOAT, 0, s_vertexValues);

	::glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	::glTexCoordPointer(2, GL_FLOAT, 0, texCoordValues);

	::glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	::glPopMatrix();
#else
    gl2dxDrawTexture(x, y, w, h, m_textureCropOesTiv);
#endif
}

void OpenGL::BlendFunc(All sfactor, All dfactor)
{
	//::glBlendFunc((int)sfactor, (int)dfactor);
}

void OpenGL::TexImage2D(All target, int level, All internalFormat, int width,
                    int height, int border, All format, All type, const Array<unsigned char>^ data)
{
	::glTexImage2D((int)target, (int)level, (int)internalFormat, width, height, border, (int)format, (int)type, data->Data);
}

void OpenGL::TexImage2D(All target, int level, int internalFormat, int width,
                    int height, int border, All format, All type, int64 data)
{
	::glTexImage2D((int)target, (int)level, (int)internalFormat, width, height, border, (int)format, (int)type, (void*)data);
}


void OpenGL::GenTextures(int count, const Array<int>^ textures)
{
	::glGenTextures(count, (unsigned int*)textures->Data);
}

void OpenGL::DeleteTextures(int count, const Array<int>^ textures)
{
	::glDeleteTextures(count, (unsigned int*)textures->Data);
}

All OpenGL::GetError()
{
	return All::NoError;
}

void OpenGL::GetInteger(All pname, Platform::WriteOnlyArray<int>^ params)
{
	int * iparams = new int[params->Length];
	::glGetIntegerv((int)pname, iparams);

	for(size_t i=0;i<params->Length;i++)
		params->set(i, iparams[i]);
}