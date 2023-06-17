//-----------------------------------------------------------------------------------------------
// Copyright (c) 2012 Andrew Garrison
//-----------------------------------------------------------------------------------------------
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
// and associated documentation files (the "Software"), to deal in the Software without 
// restriction, including without limitation the rights to use, copy, modify, merge, publish, 
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or 
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//-----------------------------------------------------------------------------------------------
#pragma once

#include <d3d11_1.h>
#include <DirectXMath.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <list>

#include "gl.h"
#include "GL2DXException.h"
#include "OpenGLVertex.h"

namespace gl2dx
{
	class VertexBuilder;

	// Constant buffer used by the OpenGLVS.hlsl Vertex shader.
	struct ModelViewProjectionConstantBuffer
	{
		DirectX::XMMATRIX model;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX projection;
	};

	// The maximum number of vertices that can be rendered in a single batch
	const int MaxBatchVertices = 25000;

	// Manages the conversion of native OpenGL calls into their DirectX equivalents.
	class DXOpenGL
	{
	public:
		// Ctor
		DXOpenGL(ID3D11Device* device, ID3D11DeviceContext* context);

		// Dtor
		~DXOpenGL();

		// Must be called at the start of every frame
		void StartFrame();

		// Must be called at the end of every frame
		void EndFrame();

		// Loads WIC texture
		void LoadTexture(const wchar_t* fileName);
	public:

		// Handles glBindTexture
		void BindTexture(GLenum target, GLuint texture);

		// Handles glSetColor
		void SetColor(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);

		// Handles glSetColorPointer
		void SetColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

		// Handles glDisable
		void Disable(GLenum cap);

		// Handles glDisableClientState
		void DisableClientState(GLenum array);

		// Handles glDrawArrays
		void DrawArrays(GLenum mode, GLint first, GLsizei count);

		// Handles glDrawElements
		void DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);

		// Handles glEnable
		void Enable(GLenum cap);

		// Handles glEnableClientState
		void EnableClientState(GLenum array);

		// Handles glGenTextures
		void GenTextures(GLsizei n, GLuint* textures);

		// Handles glDeleteTextures
		void DeleteTextures(GLsizei n, const GLuint* textures);

		// Handles glTexImage2D
		void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);

		// Handles glSetVertexPointer
		void SetVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

		// Handles glSetTexCoordPointer
		void SetTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

		// Handles glOrtho
		void Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);

		// Handles glScissor
		void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);

		// Handles glLoadMatrix
		void LoadMatrix(const GLfloat* m);

		// Handles glLoadIdentity
		void LoadIdentityMatrix();

		// Handles glPushMatrix
		void PushMatrix();

		// Handles glPopMatrix
		void PopMatrix();

		// Handles glTranslate
		void Translate(GLfloat x, GLfloat y, GLfloat z);

		// Handles glScale
		void Scale(GLfloat x, GLfloat y, GLfloat z);

		// Handles glRotate
		void Rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

		// Handles glSetLineWidth
		void SetLineWidth(GLfloat width);

		// Handles glGetIntegerv
		void GetInteger(GLenum pname, GLint* params);

		// Custom method for glDrawTexfOES
		void DrawTexture(float x, float y, float w, float h, int* tiv);

		void DrawTextureNoBatch(float x, float y, float w, float h, ID3D11ShaderResourceView* texture);

		// Handles glBlendFunc
		void BlendFunc(GLenum sfactor, GLenum dfactor);

		void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);

		void TexParameter(GLenum target, GLenum pname, GLint param);

		void TexParameter(GLenum target, GLenum pname, GLfloat param);

		void TexEnv(GLenum target, GLenum pname, GLfloat param);

		void TexEnv(GLenum target, GLenum pname, GLint param);

		void MatrixMode(GLenum mode);

private:
		// Adds the list of vertices to the current batch of vertices to be rendered with the next call to DrawBatch
		void Draw(const OpenGLVertex* vertices, GLsizei count);

		// Draws the current batch of vertices.
		void DrawBatch();

		// Initialize vertex buffers, etc.
		void FrameInit();

	private:
		// Updates the current scissor state.
		void UpdateScissorState(bool enabled);

	private:
		// The DX vertex buffer
		ID3D11Buffer* _vertexBuffer;

		// Indicates the first call to Draw in the frame.
		bool _firstDrawInFrame;

		// Orthogonal view projection coordinates
		float _orthoLeft;
		float _orthoRight;
		float _orthoBottom;
		float _orthoTop;

		// Texture state parameters
		GLuint _currentTextureId;
		bool _enableTexture2D;
		GLuint _batchCurrentTextureId;
		bool _batchEnableTexture2D;
		std::map<GLuint, ID3D11ShaderResourceView*> _textures;
		std::map<GLuint, std::pair<int, int>> _textureDimensions;

		// Handles conversions between OpenGL color, vertex, and texture coordinate pointers into a single list
		// of OpenGLVertex objects.
		VertexBuilder* _vertexBuilder;

		// Indicates the async loading of the shaders is finished
		bool _loadingComplete;

		// The max number of vertices that can be rendered in a single DrawBatch call
		int _maxVertices;

		// References to DirectX objects
		ID3D11InputLayout* _inputLayout;
		ID3D11VertexShader* _vertexShader;
		ID3D11PixelShader* _pixelShaderTexture;
		ID3D11PixelShader* _pixelShaderColor;
		ID3D11Buffer* _constantBuffer;
		D3D11_RASTERIZER_DESC _rasterizerDesc;
		ID3D11Device* _device;
		ID3D11DeviceContext* _context;
		ID3D11BlendState* _alphaSimpleBlend;
		ID3D11BlendState* _alphaComplexBlend;
		ID3D11SamplerState* _texSamplerState;

		// Scissor state
		bool _enableScissoring;
		D3D11_RECT _scissorRect;

		// The current projection matrix
		DirectX::XMFLOAT4X4 _projectionMatrix;

		// The constant buffer, which is shared with the vertex shader
		ModelViewProjectionConstantBuffer _constantBufferData;

		// The current stack of model view matrices
		std::stack<DirectX::XMFLOAT4X4*> _matrices;

		// The current set of vertices to render with the next DrawBatch call
		OpenGLVertex _batchVertices[MaxBatchVertices];
		int _currentBatchVertex;
	};
}
