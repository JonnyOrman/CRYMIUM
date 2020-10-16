#pragma once
#include "Cef/CefBrowserClient.h"
#include "Browsers/Core/IBrowser.h"
#include "Browsers/Core/IBrowserSettingsCreator.h"
#include "Browsers/Core/IWindowInfoCreator.h"
#include "Buffer/BufferRenderHandler.h"
#include "Cef/Core/ICefMessageHandler.h"
#include "Inputs/Core/IInputMapper.h"
#include "JavaScript/Core/IJavaScriptFunctionCallBuilder.h"

namespace Crymium::Browsers
{
	class Browser
		: public IBrowser
	{
	public:
		__declspec(dllexport) Browser(
			BufferRenderHandler* renderHandler,
			IInputMapper* inputMapper,
			IWindowInfoCreator* windowInfoCreator,
			IBrowserSettingsCreator* browserSettingsCreator,
			IJavaScriptFunctionCallBuilder* javaScriptFunctionCallBuilder
		);

		__declspec(dllexport) void Initialise() override;

		__declspec(dllexport) void SendInputEvent(const SInputEvent& inputEvent) override;

		__declspec(dllexport) void GoTo(std::string url) override;

		__declspec(dllexport) void Set(ICefMessageHandler* cefMessageHandler) override;

		__declspec(dllexport) void ExecuteJavaScriptString(const char* javaScript) override;

		__declspec(dllexport) void ExecuteJavaScriptFunction(const char* functionName, std::vector<std::string> parameters) override;

		__declspec(dllexport) bool IsReady() override;

		__declspec(dllexport) void Update() override;

		__declspec(dllexport) std::string GetCurrentUrl() override;
		
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