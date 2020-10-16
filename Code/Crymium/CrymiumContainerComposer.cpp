#include "CrymiumContainerComposer.h"
#include "Browsers/Browser.h"
#include "Browsers/BrowserSettingsCreator.h"
#include "Browsers/WindowInfoCreator.h"
#include "CrymiumContainer.h"
#include "CrymiumInitialiser.h"
#include "Cef/CefCaptureFrameListener.h"
#include "Rendering/RendererSettings.h"
#include "Rendering/RendererProvider.h"
#include "Buffer/BufferSettings.h"
#include "Cef/CefRectSettings.h"
#include "Buffer/BufferProvider.h"
#include "Cef/CefInitialiser.h"
#include "Buffer/BufferRenderHandler.h"
#include "Buffer/BufferSizeProvider.h"
#include "Cef/CefInputEventListener.h"
#include "Cef/CrymiumCefInitialiser.h"
#include "Cef/CrymiumCefMainArgsCreator.h"
#include "Cef/CrymiumCefSettings.h"
#include "Cef/CrymiumCefSettingsCreator.h"
#include "Cef/CrymiumSandboxInfoCreator.h"
#include "Cry/CryInitialiser.h"
#include "Inputs/InputInitialiser.h"
#include "Inputs/InputMapper.h"
#include "Inputs/InputStateMapper.h"
#include "Inputs/KeyIdMapper.h"
#include "JavaScript/JavaScriptExecutor.h"
#include "JavaScript/JavaScriptFunctionCallBuilder.h"
#include "JavaScript/JavaScriptFunctionExecutor.h"
#include "Rendering/CrymiumRenderer.h"
#include "Rendering/CrymiumRendererInitialiser.h"
#include "Textures/TextureUpdater.h"
#include "Textures/TextureSettings.h"
#include "Textures/TextureCreator.h"
#include "Textures/TextureDrawer.h"
#include "Textures/TextureProvider.h"
#include "Textures/TextureRemover.h"
#include "Textures/TextureRenderer.h"
#include "Uis/UiActivator.h"
#include "Uis/UiCloser.h"
#include "Uis/UiPathResolver.h"
#include "Uis/UiSettings.h"
#include "Uis/CryUiDirectoryProvider.h"
#include "Uis/UiDirectoryProvider.h"

std::unique_ptr<ICrymiumContainer> ContainerComposer::Compose(std::string uiDirectory)
{
	auto container = std::make_unique<CrymiumContainer>();

	container->Register(std::make_unique<CrymiumCefSettings>(
		"cefclient.exe",
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
	
	container->Register(std::make_unique<Browser>(
		cefRenderHandler,
		container->GetInputMapper(),
		container->GetWindowInfoCreator(),
		container->GetBrowserSettingsCreator(),
		container->GetJavaScriptFunctionCallBuilder()
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
