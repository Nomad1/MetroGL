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
#include "pch.h"

#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <memory>
#include "DirectXGame.h"
#include <DirectXMath.h>
#include "DirectXHelper.h"

#include "Utility.h"
#include "gl2dx.h"
#include "Bitmap.h"

using namespace Microsoft::WRL;
using namespace ::Windows::Foundation;
using namespace ::Windows::UI::Core;
using namespace DirectX;
using namespace Windows::UI::ViewManagement;

namespace DirectXApp
{
   DirectXGame::DirectXGame()
   {
      _textureId = 0;
   }

   unsigned int DirectXGame::LoadTexture(const std::string& fileName)
   {
      unsigned int textureId = 0;

      Bitmap bitmap;
      bitmap.Load(fileName.c_str());

      glGenTextures(1, &textureId);
      glBindTexture(GL_TEXTURE_2D, textureId);

      int imageWidth  = bitmap.GetWidth();
      int imageHeight = bitmap.GetHeight();

      unsigned char* data = bitmap.GetData();

      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

      return textureId;
   }

   DirectXGame::~DirectXGame()
   {
   }

   void DirectXGame::CreateDeviceResources()
   {
      DirectXBase::CreateDeviceResources();
      gl2dxInit(m_d3dDevice.Get(), m_d3dContext.Get());

      _textureId = LoadTexture("Assets\\texture.bmp");
   }

   void DirectXGame::CreateWindowSizeDependentResources()
   {
      DirectXBase::CreateWindowSizeDependentResources();
      glOrtho(0, m_renderTargetSize.Width, 0, m_renderTargetSize.Height, -1, 1);
   }

   void DirectXGame::Render()
   {
      // Clear the screen
      const float black[] = { 0.f, 0.f, 0.f, 1.000f };
      m_d3dContext->ClearRenderTargetView(m_renderTargetView.Get(), black);
      m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
      m_d3dContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());

      gl2dxStartFrame();
    
      if (_textureId > 0)
      {
         static GLfloat lcVertices[8] = 
         {
            -0.5f, -0.5f,
             0.5f, -0.5f,
            -0.5f,  0.5f,
             0.5f,  0.5f,
         };

         static GLfloat textureCoords[8] = 
         {
            0.0f, 0.0f, 
            1.0f, 0.0f, 
            0.0f, 1.0f, 
            1.0f, 1.0f, 
         };

         glDisable(GL_TEXTURE_2D);
         glEnable (GL_BLEND); 
         glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

         float width = 512.f;
         float height = 512.f;

         float x = m_renderTargetSize.Width / 2.f;
         float y = m_renderTargetSize.Height / 2.f;

         glEnable(GL_TEXTURE_2D);
         glBindTexture(GL_TEXTURE_2D, _textureId);

         glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
         glEnableClientState(GL_TEXTURE_COORD_ARRAY);

         glEnable(GL_COLOR_MATERIAL);

         glPushMatrix();
         glTranslatef(x, y, 0);

         glColor4ub(255, 255, 255, 255);
         glScalef(width, height, 1);
      
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(2, GL_FLOAT, 0, lcVertices);

         glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

         glPopMatrix();
      }

      gl2dxEndFrame();
   }
}
