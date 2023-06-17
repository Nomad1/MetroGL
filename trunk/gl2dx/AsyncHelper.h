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

#include <wrl/client.h>
#include <ppl.h>
#include <ppltasks.h>

namespace dx2gl
{
   inline void ThrowIfFailed(HRESULT hr)
   {
      if (FAILED(hr))
      {
         // Set a breakpoint on this line to catch DirectX API errors
         throw Platform::Exception::CreateException(hr);
      }
   }

   struct ByteArray { Platform::Array<byte>^ data; };

   // function that reads from a binary file asynchronously
   inline Concurrency::task<ByteArray> ReadDataAsync(Platform::String^ filename)
   {
      using namespace Windows::Storage;
      using namespace Concurrency;

      auto folder = Windows::ApplicationModel::Package::Current->InstalledLocation;

      task<StorageFile^> getFileTask(folder->GetFileAsync(filename));

      auto readBufferTask = getFileTask.then([] (StorageFile^ f) 
      {
         return FileIO::ReadBufferAsync(f);
      });

      auto byteArrayTask = readBufferTask.then([] (Streams::IBuffer^ b) -> ByteArray 
      {
         auto a = ref new Platform::Array<byte>(b->Length);
         Streams::DataReader::FromBuffer(b)->ReadBytes(a);
         ByteArray ba = { a };
         return ba;
      });

      return byteArrayTask;
   }
}
