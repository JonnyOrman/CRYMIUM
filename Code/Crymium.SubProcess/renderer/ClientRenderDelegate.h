#ifndef CEF_TESTS_CEFCLIENT_RENDERER_CLIENT_RENDERER_H_
#define CEF_TESTS_CEFCLIENT_RENDERER_CLIENT_RENDERER_H_
#pragma once
#include "IDelegate.h"
#include "include/wrapper/cef_message_router.h"

namespace Crymium::SubProcess::Renderer
{
	class ClientRenderDelegate
		: public IDelegate
	{
	public:
		ClientRenderDelegate() = default;

		void OnWebKitInitialized() OVERRIDE;

		void OnContextCreated(
			const scoped_refptr<CefBrowser>& browser,
			const scoped_refptr<CefFrame>& frame,
			const scoped_refptr<CefV8Context>& context) OVERRIDE;

		void OnContextReleased(
			const scoped_refptr<CefBrowser>& browser,
			const scoped_refptr<CefFrame>& frame,
			const scoped_refptr<CefV8Context>& context) OVERRIDE;

		bool OnProcessMessageReceived(
			const scoped_refptr<CefBrowser>& browser,
			const scoped_refptr<CefFrame>& frame,
			CefProcessId sourceProcess,
			const scoped_refptr<CefProcessMessage>& message) OVERRIDE;

	private:
		CefRefPtr<CefMessageRouterRendererSide> _messageRouter;

		DISALLOW_COPY_AND_ASSIGN(ClientRenderDelegate);
	};
}

#endif
using namespace Crymium::SubProcess::Renderer;