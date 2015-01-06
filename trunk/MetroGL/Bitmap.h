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

#include <stdio.h>

const short BITMAP_MAGIC_NUMBER=19778;
const int RGB_BYTE_SIZE=3;

#pragma pack(push,bitmap_data,1)

typedef struct
{
   unsigned char blue;
   unsigned char green;
   unsigned char red;
} RgbTriple;

typedef struct 
{
   unsigned char blue;
   unsigned char green;
   unsigned char red;
   unsigned char reserved;
} RgbQuad;


typedef struct 
{
   unsigned short bfType;
   unsigned int bfSize;
   unsigned short bfReserved1;
   unsigned short bfReserved2;
   unsigned int bfOffBits;
} BitmapFileHeader;

typedef struct 
{
   unsigned int biSize;
   int biWidth;
   int biHeight;
   unsigned short biPlanes;
   unsigned short biBitCount;
   unsigned int biCompression;
   unsigned int biSizeImage;
   int biXPelsPerMeter;
   int biYPelsPerMeter;
   unsigned int biClrUsed;
   unsigned int biClrImportant;
} BitmapInfoHeader;

#pragma pack(pop,bitmap_data)

class Bitmap
{
public:
   Bitmap();
   ~Bitmap();

   bool Load(const wchar_t* fileName);

   const char* GetFileName() const;
   int GetWidth() const;
   int GetHeight() const;
   unsigned char* GetData() const;

private:
   int m_width;
   int m_height;
   unsigned char* m_data;
   BitmapFileHeader m_cFileHeader;
   BitmapInfoHeader m_cInfoHeader;
};

Bitmap::Bitmap()
{
}

Bitmap::~Bitmap()
{

}

int Bitmap::GetWidth() const
{
   return m_width;
}

int Bitmap::GetHeight() const
{
   return m_height;
}

unsigned char* Bitmap::GetData() const
{
   return m_data;
}

bool Bitmap::Load(const wchar_t* fileName)
{
   int i;
   int j=0;
   FILE *pFile;

   // Open the file for reading
   _wfopen_s(&pFile, fileName, L"rb");
   if (pFile == NULL)
   {
      return false;
   }
      
   // Read the fileheader
   fread(&m_cFileHeader, sizeof(m_cFileHeader), 1, pFile);
      
   // Jump the fileheader
   fseek(pFile, sizeof(m_cFileHeader), SEEK_SET);
      
   // Read the infoheader
   fread(&m_cInfoHeader, sizeof(m_cInfoHeader), 1, pFile);

   m_width  = m_cInfoHeader.biWidth;
   m_height = m_cInfoHeader.biHeight;

   // Now allocate memory for our image (width * height * color depth)
   m_data = new unsigned char[m_width * m_height * 4];

   if(m_cInfoHeader.biBitCount == 24)
   {
      RgbTriple lcRgb;

      // At this point we can read every pixel of the image
      for (i = 0; i < m_width * m_height; i++)
      {
         // Read RGB values from file
         fread(&lcRgb, sizeof(lcRgb), 1, pFile); 

         // Store it in memory
         m_data[j+0] = lcRgb.red;
         m_data[j+1] = lcRgb.green;
         m_data[j+2] = lcRgb.blue;
         m_data[j+3] = 255;

         // Go to the next position
         j += 4; 
      }
   } else
	   if(m_cInfoHeader.biBitCount == 32)
   {
      RgbQuad lcRgb;

      // At this point we can read every pixel of the image
      for (i = 0; i < m_width * m_height; i++)
      {
         // Read RGB values from file
         fread(&lcRgb, sizeof(lcRgb), 1, pFile); 

         // Store it in memory
         m_data[j+0] = lcRgb.red;
         m_data[j+1] = lcRgb.green;
         m_data[j+2] = lcRgb.blue;
		 m_data[j+3] = lcRgb.reserved;

         // Go to the next position
         j += 4; 
      }
   }

   fclose(pFile);

   return(true);
}
