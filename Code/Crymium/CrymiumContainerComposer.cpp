#include "CrymiumContainerComposer.h"
#include "Crymium/Browsers/Browser.h"
#include "Crymium/Browsers/BrowserSettingsCreator.h"
#include "Crymium/Browsers/WindowInfoCreator.h"
#include "CrymiumContainer.h"
#include "CrymiumInitialiser.h"
#include "Cef/CefMessageHandler.h"
#include "Crymium/Cef/CefCaptureFrameListener.h"
#include "Crymium/Rendering/RendererSettings.h"
#include "Crymium/Rendering/RendererProvider.h"
#include "Crymium/Buffer/BufferSettings.h"
#include "Crymium/Cef/CefRectSettings.h"
#include "Crymium/Buffer/BufferProvider.h"
#include "Crymium/Cef/CefInitialiser.h"
#include "Crymium/Buffer/BufferRenderHandler.h"
#include "Crymium/Buffer/BufferSizeProvider.h"
#include "Crymium/Cef/CefInputEventListener.h"
#include "Crymium/Cef/CrymiumCefInitialiser.h"
#include "Crymium/Cef/CrymiumCefMainArgsCreator.h"
#include "Crymium/Cef/CrymiumCefSettings.h"
#include "Crymium/Cef/CrymiumCefSettingsCreator.h"
#include "Crymium/Cef/CrymiumSandboxInfoCreator.h"
#include "Crymium/Cry/CryInitialiser.h"
#include "Crymium/Inputs/InputInitialiser.h"
#include "Crymium/Inputs/InputMapper.h"
#include "Crymium/Inputs/InputStateMapper.h"
#include "Crymium/Inputs/KeyIdMapper.h"
#include "Crymium/JavaScript/JavaScriptExecutor.h"
#include "Crymium/JavaScript/JavaScriptFunctionCallBuilder.h"
#include "Crymium/JavaScript/JavaScriptFunctionExecutor.h"
#include "Crymium/Rendering/CrymiumRenderer.h"
#include "Crymium/Rendering/CrymiumRendererInitialiser.h"
#include "Crymium/Textures/TextureUpdater.h"
#include "Crymium/Textures/TextureSettings.h"
#include "Crymium/Textures/TextureCreator.h"
#include "Crymium/Textures/TextureDrawer.h"
#include "Crymium/Textures/TextureProvider.h"
#include "Crymium/Textures/TextureRemover.h"
#include "Crymium/Textures/TextureRenderer.h"
#include "Crymium/Uis/UiActivator.h"
#include "Crymium/Uis/UiCloser.h"
#include "Crymium/Uis/UiPathResolver.h"
#include "Crymium/Uis/UiSettings.h"
#include "Crymium/Uis/CryUiDirectoryProvider.h"
#include "Crymium/Uis/UiDirectoryProvider.h"

std::unique_ptr<ICrymiumContainer> CrymiumContainerComposer::Compose(std::string uiDirectory)
{
	auto container = std::make_unique<CrymiumContainer>();

	container->Register(std::make_unique<CrymiumCefSettings>(
		"Crymium.SubProcess.exe",
		true,
		LOGSEVERITY_WARNING,
		8012,
		CefColorSetARGB(0, 0, 0, 0)
		));
	
	container->Register(std::make_unique<CrymiumCefSettingsCreator>(
		container->GetCrymiumCefSettings()
		));

	container->Register(std::make_unique<CrymiumCefMainArgsCreator>());

	container->Register(std::make_unique<CrymiumSandboxInfoCreator>());
	
	container->Register(std::make_unique<CrymiumCefAppInitialiser>(
		container->GetCrymiumCefSettingsCreator(),
		container->GetCrymiumCefMainArgsCreator(),
		container->GetCrymiumSandboxInfoCreator()
		));

	container->Register(std::make_unique<RendererProvider>());
	
	container->Register(std::make_unique<RendererSettings>(
		container->GetRendererProvider()
		));

	container->Register(std::make_unique<BufferSettings>(
		4
		));

	container->Register(std::make_unique<CrymiumCefRectSettings>(
		0,
		0
		));

	container->Register(std::make_unique<BufferSizeProvider>(
		container->GetRendererSettings(),
		container->GetBufferSettings()
		));
	
	container->Register(std::make_unique<BufferProvider>(
		container->GetBufferSizeProvider()
		));
	
	auto cefRenderHandler = new BufferRenderHandler(
		container->GetCrymiumCefRectSettings(),
		container->GetRendererSettings(),
		container->GetBufferProvider()
	);

	container->Register(std::make_unique<KeyIdMapper>());

	container->Register(std::make_unique<InputStateMapper>());
	
	container->Register(std::make_unique<InputMapper>(
		container->GetKeyIdMapper(),
		container->GetInputStateMapper()
		));

	container->Register(std::make_unique<CrymiumRenderer>());

	container->Register(std::make_unique<WindowInfoCreator>(
		container->GetCrymiumRenderer()
		));

	container->Register(std::make_unique<BrowserSettingsCreator>());

	container->Register(std::make_unique<JavaScriptFunctionCallBuilder>());

	container->Register(std::make_unique<CefMessageHandler>(std::vector<ICefQueryHandler*>()));
	
	container->Register(std::make_unique<Browser>(
		cefRenderHandler,
		container->GetInputMapper(),
		container->GetWindowInfoCreator(),
		container->GetBrowserSettingsCreator(),
		container->GetJavaScriptFunctionCallBuilder(),
		container->GetCefMessageHandler()
		));

	container->Register(std::make_unique<JavaScriptExecutor>(
		container->GetBrowser()
		));

	container->Register(std::make_unique<JavaScriptFunctionExecutor>(
		container->GetJavaScriptFunctionCallBuilder(),
		container->GetJavaScriptExecutor()
		));

	container->Register(std::make_unique<TextureSettings>(
		"CefTexture",
		1,
		FILTER_LINEAR | FT_NOMIPS | FT_DONT_STREAM,
		eTF_B8G8R8A8,
		container->GetRendererSettings()
		));

	container->Register(std::make_unique<TextureProvider>());

	container->Register(std::make_unique<TextureRemover>(
		container->GetTextureProvider(),
		container->GetCrymiumRenderer()
		));

	container->Register(std::make_unique<TextureDrawer>(
		container->GetTextureProvider()
		));

	container->Register(std::make_unique<TextureCreator>(
		container->GetTextureSettings(),
		container->GetBufferProvider(),
		container->GetTextureProvider(),
		container->GetCrymiumRenderer()
		));
	
	container->Register(std::make_unique<TextureRenderer>(
		container->GetTextureCreator(),
		container->GetTextureDrawer()
		));
	
	container->Register(std::make_unique<TextureUpdater>(
		container->GetTextureRemover(),
		container->GetTextureRenderer()
		));

	container->Register(std::make_unique<CrymiumCefCaptureFrameListener>(
		container->GetTextureUpdater()
		));

	container->Register(std::make_unique<CrymiumRendererInitialiser>(
		container->GetCrymiumRenderer(),
		container->GetCrymiumCefCaptureFrameListener()
		));

	container->Register(std::make_unique<CefInputEventListener>(
		container.get()
		));

	container->Register(std::make_unique<CrymiumCefInitialiser>(
		container->GetCrymiumCefAppInitialiser(),
		container->GetBrowser()
		));

	container->Register(std::make_unique<InputInitialiser>(
		container->GetCrymiumInputEventListener()
		));
	
	container->Register(std::make_unique<CryInitialiser>(
		container->GetCrymiumRendererInitialiser(),
		container->GetInputInitialiser()
		));
	
	container->Register(std::make_unique<CrymiumInitialiser>(
		container->GetCrymiumCefInitialiser(),
		container->GetCryInitialiser()
		));

	if (uiDirectory.empty())
	{
		container->Register(std::make_unique<CryUiDirectoryProvider>());
	}
	else
	{
		container->Register(std::make_unique<UiDirectoryProvider>(uiDirectory));
	}
	
	container->Register(std::make_unique<UiSettings>(
		"index",
		"html"
		));
	
	container->Register(std::make_unique<UiPathResolver>(
		container->GetUiSettings(),
		container->GetUiDirectoryProvider()
		));
	
	container->Register(std::make_unique<UiActivator>(
		container->GetUiPathResolver(),
		container->GetBrowser()
		));

	container->Register(std::make_unique<UiCloser>(
		container->GetBrowser()
		));

	return container;
}
