#ifndef CEF_TESTS_SHARED_RENDERER_CLIENT_APP_RENDERER_H_
#define CEF_TESTS_SHARED_RENDERER_CLIENT_APP_RENDERER_H_
#pragma once

#include <set>
#include "DelegateCollection.h"
#include "ClientRenderDelegate.h"
#include "include/cef_app.h"

namespace Crymium::SubProcess::Renderer {
	class ClientAppRenderer
		:
		public CefApp,
		public CefRenderProcessHandler
	{
	public:
		ClientAppRenderer() {
			_delegates = new DelegateCollection();
			_delegates->Add(new ClientRenderDelegate());
		};

		CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE {
			return this;
		}

		void OnWebKitInitialized() OVERRIDE;

		CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE;
		void OnContextCreated(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefRefPtr<CefV8Context> context) OVERRIDE;

		void OnContextReleased(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefRefPtr<CefV8Context> context) OVERRIDE;

		bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefProcessId source_process,
			CefRefPtr<CefProcessMessage> message) OVERRIDE;

		IDelegateCollection* _delegates;

		IMPLEMENT_REFCOUNTING(ClientAppRenderer);
		DISALLOW_COPY_AND_ASSIGN(ClientAppRenderer);
	};
}

#endif

using namespace Crymium::SubProcess::Renderer;