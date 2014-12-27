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

#include "gl2dx.h"
#include <list>

namespace gl2dx
{
   // Tracks glVertexPointer, glColorPointer, and glTexCoordPointer calls and combines them into
   // a single vertex structure that can be used by DirectX.
   class VertexBuilder
   {
   public:
      // Ctor
      VertexBuilder();

	  ~VertexBuilder();

      // Assigns the current vertex pointer.
      void SetVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

      // Turns the texture coordinate pointer on or off.
      void EnableTexCoordPointer(bool enable);

      // Assigns the texture coordinate pointer.
      void SetTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

      // Requests the specified number of vertices from this class by combining the color, vertex, and texture coordinate
      // pointers into a single list of OpenGLVertex objects.
      const OpenGLVertex * GetOpenGLVertices(GLenum mode, GLint first, GLsizei count, GLsizei & vertexCount);

      // Requests the specified number of vertices from this class by combining the color, vertex, and texture coordinate
      // pointers into a single list of OpenGLVertex objects. The indices array provides the set of indices to use when
      // building the resulting OpenGLVertex list.
      const OpenGLVertex * GetVerticesFromIndices(const std::vector<int> indices, GLsizei & vertexCount);

      // Turns the color pointer on or off.
      void EnableColorPointer(bool enable);

      // Assigns the current color pointer.
      void SetColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

      // Sets the current color, which is used when the color pointer is disabled.
      void SetColor(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);

      // Sets the current line width.
      void SetLineWidth(GLfloat width);

      void InitVertex(float x, float y, float z, float u, float v, OpenGLVertex & vertex);

   private:
      // Returns an OpenGLVertex created from the index offset into the enabled vertex, color, and texture coordinate pointers.
      OpenGLVertex GetVertexAtIndex(unsigned int index);

	  void EnsureVertices(GLsizei count);

   private:
      // Vertex Pointer information
      GLint _vectorPointerSize;
      GLenum _vectorPointerType;
      GLsizei _vectorPointerStride;
      GLsizei _vectorPointerMemberSize;
      const GLbyte* _vectorPointer;

      // Color Pointer information
      bool _colorPointerEnabled;
      GLint _colorPointerSize;
      GLenum _colorPointerType;
      GLsizei _colorPointerStride;
      GLubyte* _colorPointer;

      // Tex Coord Pointer information
      bool _texCoordPointerEnabled;
      GLint _texCoordPointerSize; 
      GLenum _texCoordPointerType;
      GLsizei _texCoordPointerStride;
      const GLbyte* _texCoordPointer;

      // Current line width.
      float _lineWidth;

      // Color
      GLfloat _red;
      GLfloat _green;
      GLfloat _blue;
      GLfloat _alpha;

      // The list of vertices returned from the previous GetOpenGLVertices or GetVerticesFromIndices
      // call. This is kept as a private member variable so that those methods can return a const reference
      // to this list which is more performant than returning a copy of the list. Certainly not a best practice.
      //std::vector<OpenGLVertex> _vertices;
	  OpenGLVertex * _vertices;
	  GLsizei _vertexCount;
   };
}
