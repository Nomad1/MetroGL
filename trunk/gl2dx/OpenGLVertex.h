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

namespace gl2dx
{
   // The vertex type used in the GL2DX library.
   struct OpenGLVertex
   {
      // Ctor
      OpenGLVertex()
      {
         x = 0.f;
         y = 0.f;
         z = 0.f;
         r = 1.f;
         g = 1.f;
         b = 1.f;
         a = 1.f;
         u = 0.f;
         v = 0.f;
      }

      // Ctor
      OpenGLVertex(GLfloat ix, GLfloat iy, GLfloat iz)
      {
         x = ix;
         y = iy;
         z = iz;
         r = 1.f;
         g = 1.f;
         b = 1.f;
         a = 1.f;
         u = 0.f;
         v = 0.f;
      }

      // x, y, z coordinates
      GLfloat x, y, z;

      // RGBA color values
      float r, g, b, a;

      // Texture coordinates
      float u, v;
   };
}
