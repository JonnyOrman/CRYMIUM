#pragma once
#include "Cef/CefBrowserClient.h"
#include "Crymium/Browsers/Core/IBrowser.h"
#include "Crymium/Browsers/Core/IBrowserSettingsCreator.h"
#include "Crymium/Browsers/Core/IWindowInfoCreator.h"
#include "Crymium/Buffer/BufferRenderHandler.h"
#include "Crymium/Cef/Core/ICefMessageHandler.h"
#include "Crymium/Inputs/Core/IInputMapper.h"
#include "Crymium/JavaScript/Core/IJavaScriptFunctionCallBuilder.h"

namespace Crymium::Browsers
{
	class Browser
		: public IBrowser
	{
	public:
		Browser(
			BufferRenderHandler* renderHandler,
			IInputMapper* inputMapper,
			IWindowInfoCreator* windowInfoCreator,
			IBrowserSettingsCreator* browserSettingsCreator,
			IJavaScriptFunctionCallBuilder* javaScriptFunctionCallBuilder
		);

		void Initialise() override;

		void SendInputEvent(const SInputEvent& inputEvent) override;

		void GoTo(std::string url) override;

		void Set(ICefMessageHandler* cefMessageHandler) override;

		void ExecuteJavaScriptString(const char* javaScript) override;

		void ExecuteJavaScriptFunction(const char* functionName, std::vector<std::string> parameters) override;

		bool IsReady() override;

		void Update() override;

		std::string GetCurrentUrl() override;
		
	private:
		CefRefPtr<CefBrowserClient> _browserClient;
		CefRefPtr<CefBrowser> _browser;
		BufferRenderHandler* _renderHandler;
		ICefMessageHandler* _cefMessageHandler;
		IInputMapper* _inputMapper;
		IWindowInfoCreator* _windowInfoCreator;
		IBrowserSettingsCreator* _browserSettingsCreator;
		IJavaScriptFunctionCallBuilder* _javaScriptFunctionCallBuilder;
	};
}

using namespace Crymium::Browsers;