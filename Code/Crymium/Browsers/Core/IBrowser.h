#pragma once
#include <string>
#include <vector>
#include <CryInput/IInput.h>

namespace Crymium::Browsers::Core
{
	struct IBrowser
	{
		virtual ~IBrowser() = default;

		virtual void Initialise() = 0;

		virtual void SendInputEvent(const SInputEvent& inputEvent) = 0;

		virtual void GoTo(std::string url) = 0;
		
		virtual void ExecuteJavaScriptString(const char* javaScript) = 0;

		virtual void ExecuteJavaScriptFunction(const char* functionName, std::vector<std::string> parameters) = 0;

		virtual bool IsReady() = 0;

		virtual void Update() = 0;

		virtual std::string GetCurrentUrl() = 0;
	};
}

using namespace Crymium::Browsers::Core;