#pragma once


#include "gl2dx/DXOpenGL.h"
#include "Enums.h"

namespace MetroGL
{
	public delegate void RenderDelegate();
	public delegate void InitDelegate();
	public delegate void ResizeDelegate(int width, int height);

	/// This class mimics OpenTK::GL class but having DirectX calls instead
    [Windows::Foundation::Metadata::WebHostHiddenAttribute]
	public ref class OpenGL sealed
    {
	private:
		gl2dx::DXOpenGL * m_gl;

		int m_textureCropOesTiv[4];

		// Clear parameters
		float _clearColorValue[4];
		float _clearDepthValue;
		int _clearMask;
    public:
        OpenGL();
		virtual ~OpenGL();

		void Initialize(Windows::UI::Xaml::Controls::SwapChainPanel^ panel);

		event RenderDelegate^ OnRender;
		event InitDelegate^ OnInit;
		event ResizeDelegate^ OnResize;

		unsigned int LoadTexture(Platform::String ^ name);

		property OpenGL ^ Oes;

	private:
         void OnWindowSizeChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::WindowSizeChangedEventArgs^ args);
         void OnLogicalDpiChanged(Object^ sender);
         void OnRendering(Object^ sender, Object^ args);
	public:
		// Clearing
		void SetClearMask(int mask);
		void SetClearColor(float red, float green, float blue, float alpha);
		void SetClearDepth(float depth);

		void Ortho(float left, float right, float bottom, float top, float zNear, float zFar);

		void PopMatrix();
		void PushMatrix();
		void LoadIdentity();

		void Rotate(float angle, float x, float y, float z);
		void Translate(float x, float y, float z);
		void Scale(float x, float y, float z);
		void Color4(float r, float g, float b, float a);

		void Enable(All cap);
		void EnableClientState(All cap);
		void Disable(All cap);
		void DisableClientState(All cap);
		void BlendFunc(All sfactor, All dfactor);
        void MatrixMode(All mode);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		[Windows::Foundation::Metadata::OverloadAttribute("VertexPointera")]
		void VertexPointer(int size, All type, int stride, const Platform::Array<float>^ pointer);
		[Windows::Foundation::Metadata::OverloadAttribute("VertexPointerfp")]
		void VertexPointer(int size, All type, int stride, int64 pointer);
		
		[Windows::Foundation::Metadata::DefaultOverloadAttribute]
		[Windows::Foundation::Metadata::OverloadAttribute("TexCoordPointera")]
		void TexCoordPointer(int size, All type, int stride, const Platform::Array<float>^ pointer);
		[Windows::Foundation::Metadata::OverloadAttribute("TexCoordPointerp")]
		void TexCoordPointer(int size, All type, int stride, int64 pointer);

		void DrawArrays(All mode, int first, int count);

		void GenTextures(int count, const Platform::Array<int>^ textures);
		void DeleteTextures(int count, const Platform::Array<int>^ textures);
		void BindTexture(All target, int texture);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		[Windows::Foundation::Metadata::OverloadAttribute("TexParameteri")]
		void TexParameter(All target, All pname, int pparam);
		[Windows::Foundation::Metadata::OverloadAttribute("TexParameteria")]
		void TexParameter(All target, All pname, const Platform::Array<int>^ pparam);
		[Windows::Foundation::Metadata::OverloadAttribute("TexParameterf")]
		void TexParameter(All target, All pname, float pparam);
		[Windows::Foundation::Metadata::OverloadAttribute("TexParameteraf")]
		void TexParameter(All target, All pname, const Platform::Array<float>^ pparam);

		void DrawTex(float x, float y, float z, float width, float height);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		[Windows::Foundation::Metadata::OverloadAttribute("TexImage2Da")]
		void TexImage2D(All target, int level, All internalFormat, int width,
                    int height, int border, All format, All type, const Platform::Array<unsigned char>^ data);
		[Windows::Foundation::Metadata::OverloadAttribute("TexImage2Dp")]
		void TexImage2D(All target, int level, int internalFormat, int width,
                    int height, int border, All format, All type, int64 data);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		[Windows::Foundation::Metadata::OverloadAttribute("TexEnvi")]
        void TexEnv(All target, All pname, int pparam);
		[Windows::Foundation::Metadata::OverloadAttribute("TexEnvai")]
        void TexEnv(All target, All pname, const Platform::Array<int>^ pparam); 
		[Windows::Foundation::Metadata::OverloadAttribute("TexEnvf")]
        void TexEnv(All target, All pname, float pparam);
		[Windows::Foundation::Metadata::OverloadAttribute("TexEnvaf")]
        void TexEnv(All target, All pname, const Platform::Array<float>^ pparam); 

		void GetInteger(All pname, Platform::WriteOnlyArray<int>^ params);

        void Viewport(int x, int y, int width, int height);

		All GetError();

		void CreateDeviceResources();
		void CreateWindowSizeDependentResources();

		void Render();
	// DirectXBase
	internal:
		void Initialize(Windows::UI::Core::CoreWindow^ window, Windows::UI::Xaml::Controls::SwapChainPanel^ panel, float dpi);
		void CreateDeviceIndependentResources();
		void SetDpi(float dpi);
		void UpdateForWindowSizeChange();
		void Present();
		float ConvertDipsToPixels(float dips);

		void InternalCreateWindowSizeDependentResources();
		void InternalCreateDeviceResources();

#ifdef WIN8
		void SetApplicationViewState(ApplicationViewState viewState);
		ApplicationViewState GetApplicationViewState();
#endif
	protected private:

		Platform::Agile<Windows::UI::Core::CoreWindow>         m_window;
		Windows::UI::Xaml::Controls::SwapChainPanel^			m_panel;

		// Direct2D Objects
		//Microsoft::WRL::ComPtr<ID2D1Factory1>                  m_d2dFactory;
		//Microsoft::WRL::ComPtr<ID2D1Device>                    m_d2dDevice;
		//Microsoft::WRL::ComPtr<ID2D1DeviceContext>             m_d2dContext;
		//Microsoft::WRL::ComPtr<ID2D1Bitmap1>                   m_d2dTargetBitmap;

		// DirectWrite & Windows Imaging Component Objects
		//Microsoft::WRL::ComPtr<IDWriteFactory1>                m_dwriteFactory;
		//Microsoft::WRL::ComPtr<IWICImagingFactory2>            m_wicFactory;

		// Direct3D Objects
		Microsoft::WRL::ComPtr<ID3D11Device1>                  m_d3dDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext1>           m_d3dContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain1>                m_swapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>         m_renderTargetView;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>         m_depthStencilView;

		Microsoft::WRL::ComPtr<ID3D11Texture2D>					renderTargetTextureMap;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>			m_renderTargetViewTexture;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>		shaderResourceViewMap;
		Microsoft::WRL::ComPtr<ID3D11Buffer>					d2dIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>					d2dVertBuffer;

		D3D_FEATURE_LEVEL                                      m_featureLevel;
		Windows::Foundation::Size                              m_renderTargetSize;
		float													m_windowBoundsWidth;
		float													m_windowBoundsHeight;
		float                                                  m_dpi;
#ifdef WIN8
		ApplicationViewState                                   m_viewState;
#endif
	};
}