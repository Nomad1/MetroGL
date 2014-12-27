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
#include "DirectXPage.xaml.h"

using namespace DirectXApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::ApplicationSettings;
using namespace Windows::UI::Input;
using namespace Windows::UI::Core;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Graphics::Display;

DirectXPage::DirectXPage()
{
   InitializeComponent();

   _DirectXGame = ref new DirectXGame();
   _DirectXGame->Initialize(
      Window::Current->CoreWindow,
      this,
      DisplayProperties::LogicalDpi
      );
   Window::Current->CoreWindow->SizeChanged += 
      ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &DirectXPage::OnWindowSizeChanged);

   DisplayProperties::LogicalDpiChanged +=
      ref new DisplayPropertiesEventHandler(this, &DirectXPage::OnLogicalDpiChanged);

   CompositionTarget::Rendering::add(ref new EventHandler<Object^>(this, &DirectXPage::OnRendering));
}

DirectXPage::~DirectXPage()
{
}

void DirectXPage::OnSuspending()
{
}

void DirectXPage::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
   _DirectXGame->UpdateForWindowSizeChange();
}

void DirectXPage::OnLogicalDpiChanged(Platform::Object^ sender)
{
   _DirectXGame->SetDpi(DisplayProperties::LogicalDpi);
}

void DirectXPage::OnRendering(Platform::Object^ sender, Platform::Object^ args)
{
   _DirectXGame->Render();
   _DirectXGame->Present();
}
