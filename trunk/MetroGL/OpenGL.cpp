#include <d3d11_1.h>
#include <dwrite_1.h>
#include <wincodec.h>
#include <agile.h>
#include <DirectXMath.h>
#include "Enums.h"
#include "OpenGL.h"

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
	:
	m_gl(NULL),
	m_dpi(-1.0f)
#ifdef WIN8
	,
	m_viewState(ApplicationViewState::FullScreenLandscape)
#endif
{
	Oes = this;
	_clearColorValue[0] = 0.0f;
	_clearColorValue[1] = 0.0f;
	_clearColorValue[2] = 0.0f;
	_clearColorValue[3] = 1.0f;
	_clearMask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
}

OpenGL::~OpenGL()
{
	if (m_gl)
		delete m_gl;
}

void OpenGL::Initialize(SwapChainPanel^ panel)
{
	//m_game = ref new DirectXGame();
	//this->OnInit += ref new DirectXInitDelegate(this, &OpenGL::OnInternalInit);
	//this->OnResize += ref new DirectXResizeDelegate(this, &OpenGL::OnInternalResize);

	this->Initialize(
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

void OpenGL::SetClearMask(int mask)
{
	_clearMask = mask;
}

void OpenGL::SetClearColor(float red, float green, float blue, float alpha)
{
	_clearColorValue[0] = red;
	_clearColorValue[1] = green;
	_clearColorValue[2] = blue;
	_clearColorValue[3] = alpha;
}

void OpenGL::SetClearDepth(float depth)
{
	_clearDepthValue = depth;
}


void OpenGL::OnRendering(Platform::Object^ sender, Platform::Object^ args)
{
	Render();
}

void OpenGL::Render()
{
	if (_clearMask & 0x8000000) // draw everything twice
	{
		if (_clearMask & GL_COLOR_BUFFER_BIT)
			m_d3dContext->ClearRenderTargetView(m_renderTargetViewTexture.Get(), _clearColorValue);
		if (_clearMask & GL_DEPTH_BUFFER_BIT)
			m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH, _clearDepthValue, 0);

		m_d3dContext->OMSetRenderTargets(1, m_renderTargetViewTexture.GetAddressOf(), m_depthStencilView.Get());

		m_gl->StartFrame();

		OnRender();

		m_gl->EndFrame();

		//if (_clearMask & GL_COLOR_BUFFER_BIT)
		//m_d3dContext->ClearRenderTargetView(m_renderTargetView.Get(), _clearColorValue);
		//if (_clearMask & GL_DEPTH_BUFFER_BIT)
		m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH, _clearDepthValue, 0);

		m_d3dContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());

		m_d3dContext->OMSetBlendState(0, 0, 0xffffffff);

		m_gl->DrawTextureNoBatch(0, 0, (float)m_renderTargetSize.Width, (float)m_renderTargetSize.Height, shaderResourceViewMap.Get());
	}
	 else
	{
		if (_clearMask & GL_COLOR_BUFFER_BIT)
			m_d3dContext->ClearRenderTargetView(m_renderTargetView.Get(), _clearColorValue);
		if (_clearMask & GL_DEPTH_BUFFER_BIT)
			m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH, _clearDepthValue, 0);

		m_d3dContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());

		m_gl->StartFrame();

		OnRender();

		m_gl->EndFrame();

		//m_d3dContext->OMSetBlendState(0, 0, 0xffffffff);
	}
	
	this->Present();
}

void OpenGL::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	this->UpdateForWindowSizeChange();
}

void OpenGL::OnLogicalDpiChanged(Object^ sender)
{
	this->SetDpi(DisplayProperties::LogicalDpi);
}

void OpenGL::CreateDeviceResources()
{
	InternalCreateDeviceResources();

    if (m_gl)
        delete m_gl;

    m_gl = new gl2dx::DXOpenGL(this->m_d3dDevice.Get(), this->m_d3dContext.Get());
    
	OnInit();
}

void OpenGL::CreateWindowSizeDependentResources()
{
	InternalCreateWindowSizeDependentResources();

	OnResize((int)m_renderTargetSize.Width, (int)m_renderTargetSize.Height);
}

unsigned int OpenGL::LoadTexture(String ^ name)
{
	unsigned int result;
	
	m_gl->GenTextures(1, &result);
	m_gl->BindTexture(GL_TEXTURE_2D, result);

	m_gl->LoadTexture(name->Data());

	m_gl->TexParameter(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	m_gl->TexParameter(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	m_gl->TexEnv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	return result;
}
///
void OpenGL::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	m_gl->Ortho(left, right, bottom, top, zNear, zFar);
}

void OpenGL::PopMatrix()
{
	m_gl->PopMatrix();
}

void OpenGL::PushMatrix()
{
	m_gl->PushMatrix();
}

void OpenGL::LoadIdentity()
{
	m_gl->LoadIdentityMatrix();
}

void OpenGL::Viewport(int x, int y, int width, int height)
{
    m_gl->Viewport(x, y, width, height);
}

void OpenGL::Rotate(float angle, float x, float y, float z)
{
	m_gl->Rotate(angle, x, y, z);
}

void OpenGL::Translate(float x, float y, float z)
{
	m_gl->Translate(x, y, z);
}

void OpenGL::Enable(All cap)
{
	m_gl->Enable((int)cap);
}

void OpenGL::Disable(All cap)
{
	m_gl->Disable((int)cap);
}

void OpenGL::MatrixMode(All mode)
{
    m_gl->MatrixMode((int)mode);
}

void OpenGL::EnableClientState(All cap)
{
	m_gl->EnableClientState((int)cap);
}

void OpenGL::DisableClientState(All cap)
{
	m_gl->DisableClientState((int)cap);
}

void OpenGL::Scale(float x, float y, float z)
{
	m_gl->Scale(x, y, z);
}

void OpenGL::Color4(float r, float g, float b, float a)
{
	m_gl->SetColor((unsigned char)(r*255),(unsigned char)(g*255),(unsigned char)(b*255),(unsigned char)(a*255));
}

void OpenGL::VertexPointer(int size, All type, int stride, const Array<float>^ pointer)
{
	m_gl->SetVertexPointer(size, (int)type, stride, pointer->Data);
}

void OpenGL::VertexPointer(int size, All type, int stride, int64 pointer)
{
	m_gl->SetVertexPointer(size, (int)type, stride, (void*)pointer);
}

void OpenGL::DrawArrays(All mode, int first, int count)
{
	m_gl->DrawArrays((int)mode, first, count);
}

void OpenGL::TexCoordPointer(int size, All type, int stride, const Array<float>^ pointer)
{
	m_gl->SetTexCoordPointer(size, (int)type, stride, pointer->Data);
}

void OpenGL::TexCoordPointer(int size, All type, int stride, int64 pointer)
{
	m_gl->SetTexCoordPointer(size, (int)type, stride, (void*)pointer);
}

void OpenGL::BindTexture(All target, int texture)
{
	m_gl->BindTexture((int)target, texture);
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

	m_gl->TexParameter((int)target, (int)pname, pparam[0]);
}

void OpenGL::TexParameter(All target, All pname, int pparam)
{
	m_gl->TexParameter((int)target, (int)pname, pparam);
}

void OpenGL::TexParameter(All target, All pname, const Array<float>^ pparam)
{
	m_gl->TexParameter((int)target, (int)pname, pparam[0]);
}

void OpenGL::TexParameter(All target, All pname, float pparam)
{
	m_gl->TexParameter((int)target, (int)pname, pparam);
}

void OpenGL::TexEnv(All target, All pname, int pparam)
{
	m_gl->TexEnv((int)target, (int)pname, pparam);
}

void OpenGL::TexEnv(All target, All pname, const Array<int>^ pparam)
{
	m_gl->TexEnv((int)target, (int)pname, pparam[0]);
}

void OpenGL::TexEnv(All target, All pname, float pparam)
{
	m_gl->TexEnv((int)target, (int)pname, pparam);
}

void OpenGL::TexEnv(All target, All pname, const Array<float>^ pparam)
{
	m_gl->TexEnv((int)target, (int)pname, pparam[0]);
}

void OpenGL::DrawTex(float x, float y, float z, float w, float h)
{
#ifdef GL_DRAWTEX
	static float s_vertexValues[] = { -0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f };

	m_gl->PushMatrix();
	m_gl->LoadIdentity();

	/// TODO: invert y axis!

	m_gl->Translatef(w / 2.0f + x, h / 2.0f + y, 0.0f);

	m_gl->Scalef(w, h, 1.0f);
	
	int * tiv = m_textureCropOesTiv;

	int texW;
	m_gl->GetIntegerv(GL_TEXTURE_WIDTH, &texW); /// NOTE: Does not work in real OpenGL ES!!
	int texH;
	m_gl->GetIntegerv(GL_TEXTURE_HEIGHT, &texH); /// NOTE: Does not work in real OpenGL ES!!

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

	m_gl->EnableClientState(GL_VERTEX_ARRAY);
	m_gl->VertexPointer(2, GL_FLOAT, 0, s_vertexValues);

	m_gl->EnableClientState(GL_TEXTURE_COORD_ARRAY);
	m_gl->TexCoordPointer(2, GL_FLOAT, 0, texCoordValues);

	m_gl->DrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	m_gl->PopMatrix();
#else
    m_gl->DrawTexture(x, y, w, h, m_textureCropOesTiv);
#endif
}

void OpenGL::BlendFunc(All sfactor, All dfactor)
{
	m_gl->BlendFunc((int)sfactor, (int)dfactor);
}

void OpenGL::TexImage2D(All target, int level, All internalFormat, int width,
                    int height, int border, All format, All type, const Array<unsigned char>^ data)
{
	m_gl->TexImage2D((int)target, (int)level, (int)internalFormat, width, height, border, (int)format, (int)type, data->Data);
}

void OpenGL::TexImage2D(All target, int level, int internalFormat, int width,
                    int height, int border, All format, All type, int64 data)
{
	m_gl->TexImage2D((int)target, (int)level, (int)internalFormat, width, height, border, (int)format, (int)type, (void*)data);
}


void OpenGL::GenTextures(int count, const Array<int>^ textures)
{
	m_gl->GenTextures(count, (unsigned int*)textures->Data);
}

void OpenGL::DeleteTextures(int count, const Array<int>^ textures)
{
	m_gl->DeleteTextures(count, (unsigned int*)textures->Data);
}

All OpenGL::GetError()
{
	return All::NoError;
}

void OpenGL::GetInteger(All pname, Platform::WriteOnlyArray<int>^ params)
{
	int * iparams = new int[params->Length];
	m_gl->GetInteger((int)pname, iparams);

	for(size_t i=0;i<params->Length;i++)
		params->set((unsigned int)i, iparams[i]);
}