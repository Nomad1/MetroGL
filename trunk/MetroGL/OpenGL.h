#pragma once

#include "DirectXGame.h"
#include "Enums.h"

namespace MetroGL
{
	public delegate void RenderDelegate();
	public delegate void InitDelegate();
	public delegate void ResizeDelegate(int width, int height);

    [Windows::Foundation::Metadata::WebHostHiddenAttribute]
	public ref class OpenGL sealed
    {
	private:
		DirectXGame ^ m_game;
		int m_textureCropOesTiv[4];

    public:
        OpenGL();

		void Initialize(Windows::UI::Xaml::Controls::SwapChainBackgroundPanel^ panel);

		event RenderDelegate^ OnRender;
		event InitDelegate^ OnInit;
		event ResizeDelegate^ OnResize;

		unsigned int LoadTexture(String ^ name);

		property OpenGL ^ Oes;

	private:
         void OnWindowSizeChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::WindowSizeChangedEventArgs^ args);
         void OnLogicalDpiChanged(Object^ sender);
         void OnRendering(Object^ sender, Object^ args);
		 void OnInternalInit(Object^);
		 void OnInternalResize(Object^, int width, int height);
	public:
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
		void VertexPointer(int size, All type, int stride, const Array<float>^ pointer);
        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		void TexCoordPointer(int size, All type, int stride, const Array<float>^ pointer);
		void VertexPointer(int size, All type, int stride, int64 pointer);
		void TexCoordPointer(int size, All type, int stride, int64 pointer);

		void DrawArrays(All mode, int first, int count);

		void GenTextures(int count, const Array<int>^ textures);
		void DeleteTextures(int count, const Array<int>^ textures);
		void BindTexture(All target, int texture);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		void TexParameter(All target, All pname, int pparam);
		void TexParameter(All target, All pname, const Array<int>^ pparam);
		void TexParameter(All target, All pname, float pparam);
		void TexParameter(All target, All pname, const Array<float>^ pparam);

		void DrawTex(float x, float y, float z, float width, float height);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
		void TexImage2D(All target, int level, All internalFormat, int width,
                    int height, int border, All format, All type, const Array<unsigned char>^ data);
		void TexImage2D(All target, int level, int internalFormat, int width,
                    int height, int border, All format, All type, int64 data);

        [Windows::Foundation::Metadata::DefaultOverloadAttribute]
        void TexEnv(All target, All pname, int pparam);
        void TexEnv(All target, All pname, const Array<int>^ pparam); 
        void TexEnv(All target, All pname, float pparam);
        void TexEnv(All target, All pname, const Array<float>^ pparam); 

		void GetInteger(All pname, Platform::WriteOnlyArray<int>^ params);

        void Viewport(int x, int y, int width, int height);

		All GetError();
	};
}