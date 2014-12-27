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
#include "gl2dx.h"
#include "VertexBuilder.h"
#include <map>
#include "OpenGL.h"

using namespace gl2dx;

OpenGL* _openGL;

void gl2dxAssert(bool condition, char* message)
{
   if (condition == false)
   {
      throw new GL2DXException(message);
   }
}

void gl2dxNotSupported(char* message)
{
   throw new GL2DXException(message);
}

void gl2dxInit(ID3D11Device* device, ID3D11DeviceContext* context)
{
   _openGL = new OpenGL(device, context);
}

void gl2dxStartFrame()
{
   _openGL->StartFrame();
}

void gl2dxEndFrame()
{
   _openGL->EndFrame();
}

void glBindTexture(GLenum target, GLuint texture)
{
   gl2dxAssert(target == GL_TEXTURE_2D, "GL_TEXTURE_2D is the only supported target in glBindTexture");
   _openGL->BindTexture(target, texture);
}

void glBlendFunc (GLenum sfactor, GLenum dfactor)
{
   //gl2dxAssert(sfactor == GL_SRC_ALPHA, "GL_SRC_ALPHA is the only supported sfactor for glBlendFunc");
   //gl2dxAssert(dfactor == GL_ONE_MINUS_SRC_ALPHA, "GL_ONE_MINUS_SRC_ALPHA is the only supported sfactor for glBlendFunc");
   _openGL->BlendFunc(sfactor, dfactor);
}

void glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
   _openGL->SetColor(red, green, blue, alpha);
}

void glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
   _openGL->SetColorPointer(size, type, stride, pointer);
}

void glDeleteTextures (GLsizei n, const GLuint *textures)
{
   _openGL->DeleteTextures(n, textures);
}

void glDisable (GLenum cap)
{
   _openGL->Disable(cap);
}

void glDisableClientState (GLenum array)
{
   _openGL->DisableClientState(array);
}

void glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
   _openGL->DrawArrays(mode, first, count);
}

void glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
   gl2dxAssert(mode == GL_TRIANGLE_STRIP, "GL_TRIANGLE_STRIP is the only mode supported by glDrawElements");
   gl2dxAssert(type == GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE is the only type supported by glDrawElements");

   _openGL->DrawElements(mode, count, type, indices);
}

void glEnable (GLenum cap)
{
   _openGL->Enable(cap);
}

void glEnableClientState (GLenum array)
{
   _openGL->EnableClientState(array);
}

void glGenTextures (GLsizei n, GLuint *textures)
{
   _openGL->GenTextures(n, textures);
}

void glLineWidth (GLfloat width)
{
   _openGL->SetLineWidth(width);   
}

void glLoadMatrixf (const GLfloat *m)
{
   _openGL->LoadMatrix(m);
}

void glLoadIdentity (void)
{
   _openGL->LoadIdentityMatrix();
}

void glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
   _openGL->Ortho(left, right, bottom, top, zNear, zFar);
}

void glPopMatrix (void)
{
   _openGL->PopMatrix();
}

void glPushMatrix (void)
{
   _openGL->PushMatrix();
}

void glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
   _openGL->Rotate(angle, x, y, z);
}

void glScalef (GLfloat x, GLfloat y, GLfloat z)
{
   _openGL->Scale(x, y, z);
}

void glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
   _openGL->Scissor(x, y, width, height);
}

void glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
   _openGL->SetTexCoordPointer(size, type, stride, pointer);
}

void glTexEnvf (GLenum target, GLenum pname, GLfloat param)
{
   // TODO:
}

void glTexEnvi (GLenum target, GLenum pname, GLint param)
{
   // TODO:
}

void glMatrixMode (GLenum mode)
{
   // TODO:
}

void glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
   // TODO:
}

void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
   gl2dxAssert(target == GL_TEXTURE_2D, "GL_TEXTURE_2D is the only supported target in glTextImage2D");
   gl2dxAssert(level == 0, "Only MipMap level 0 is supported");
   //gl2dxAssert(internalformat == GL_RGBA, "GL_RGBA is the only supported internalformat in glTextImage2D");
   //gl2dxAssert(format == GL_RGBA, "GL_RGBA is the only supported format in glTextImage2D");
   //gl2dxAssert(type == GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE is the only supported type in glTextImage2D");

   _openGL->TexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void glTexParameteri (GLenum target, GLenum pname, GLint param)
{
   // usage: glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);   // Linear Filtering
   // TODO:
}

void glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
   // usage: glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);   // Linear Filtering
   // TODO:
}

void glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
   _openGL->Translate(x, y, z);
}

void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
   _openGL->SetVertexPointer(size, type, stride, pointer);
}

void glGetIntegerv(GLenum pname, GLint *params)
{
   _openGL->GetInteger(pname, params);
}

void gl2dxLoadTexture(const wchar_t * fileName)
{
	_openGL->LoadTexture(fileName);
}

void gl2dxDrawTexture(float x, float y, float w, float h, int * tiv)
{
	_openGL->DrawTexture(x, y, w, h, tiv);
}