#pragma once
#include <memory>
#include <CryInput/IInput.h>
#include "Crymium/Cef/Core/ICrymiumCefSettings.h"
#include "Crymium/Buffer/Core/IBufferSizeProvider.h"
#include "Crymium/Cef/Core/ICrymiumSandboxInfoCreator.h"
#include "Crymium/Cef/Core/ICrymiumCefMainArgsCreator.h"
#include "Crymium/Cef/Core/ICrymiumCefSettingsCreator.h"
#include "Crymium/Browsers/Core/IBrowserSettingsCreator.h"
#include "Crymium/Browsers/Core/IWindowInfoCreator.h"
#include "Crymium/Browsers/Core/IBrowser.h"
#include "Crymium/Cef/Core/ICrymiumCefInitialiser.h"
#include "Crymium/Cry/Core/ICryInitialiser.h"
#include "Crymium/Cef/Core/ICefMessageHandler.h"
#include "Crymium/Core/IInitialiser.h"
#include "Crymium/Cef/Core/ICefInitialiser.h"
#include "Crymium/Rendering/Core/IRendererSettings.h"
#include "Crymium/Rendering/Core/IRendererProvider.h"
#include "Crymium/Buffer/Core/IBufferSettings.h"
#include "Crymium/Cef/Core/ICefRectSettings.h"
#include "Crymium/Buffer/Core/IBufferProvider.h"
#include "Crymium/Inputs/Core/IInputMapper.h"
#include "Crymium/Inputs/Core/IKeyIdMapper.h"
#include "Crymium/Inputs/Core/IInputStateMapper.h"
#include "Crymium/Textures/Core/ITextureUpdater.h"
#include "Crymium/Textures/Core/ITextureSettings.h"
#include "Crymium/Textures/Core/ITextureCreator.h"
#include "Crymium/Textures/Core/ITextureDrawer.h"
#include "Crymium/Textures/Core/ITextureProvider.h"
#include "Crymium/Textures/Core/ITextureRemover.h"
#include "Crymium/Textures/Core/ITextureRenderer.h"
#include "Crymium/Rendering/Core/ICrymiumRenderer.h"
#include "Crymium/Inputs/Core/IInputInitialiser.h"
#include "Crymium/Rendering/Core/ICrymiumRendererInitialiser.h"
#include "Crymium/JavaScript/Core/IJavaScriptFunctionCallBuilder.h"
#include "Crymium/JavaScript/Core/IJavaScriptExecutor.h"
#include "Crymium/JavaScript/Core/IJavaScriptFunctionExecutor.h"
#include "Crymium/Uis/Core/IUiActivator.h"
#include "Crymium/Uis/Core/IUiPathResolver.h"
#include "Crymium/Uis/Core/IUiCloser.h"
#include "Crymium/Uis/Core/IUiSettings.h"
#include "Crymium/Uis/Core/IUiDirectoryProvider.h"

namespace Crymium::Core
{
	struct ICrymiumContainer
	{
		virtual ~ICrymiumContainer() = default;

		virtual void Register(std::unique_ptr<ICrymiumCefSettings> crymiumCefSettings) = 0;
		virtual ICrymiumCefSettings* GetCrymiumCefSettings() = 0;
		
		virtual void Register(std::unique_ptr<ICrymiumCefAppInitialiser> crymiumCefAppInitialiser) = 0;
		virtual ICrymiumCefAppInitialiser* GetCrymiumCefAppInitialiser() = 0;

		virtual void Register(std::unique_ptr<ICaptureFrameListener> crymiumCefCaptureFrameListener) = 0;
		virtual ICaptureFrameListener* GetCrymiumCefCaptureFrameListener() = 0;

		virtual void Register(std::unique_ptr<ICrymiumInitialiser> crymiumInitialiser) = 0;
		virtual ICrymiumInitialiser* GetCrymiumInitialiser() = 0;

		virtual void Register(std::unique_ptr<ICrymiumRenderer> crymiumRenderer) = 0;
		virtual ICrymiumRenderer* GetCrymiumRenderer() = 0;

		virtual void Register(std::unique_ptr<ICrymiumRendererInitialiser> crymiumRendererInitialiser) = 0;
		virtual ICrymiumRendererInitialiser* GetCrymiumRendererInitialiser() = 0;
		
		virtual void Register(std::unique_ptr<IRendererSettings> rendererSettings) = 0;
		virtual IRendererSettings* GetRendererSettings() = 0;

		virtual void Register(std::unique_ptr<IRendererProvider> rendererProvider) = 0;
		virtual IRendererProvider* GetRendererProvider() = 0;

		virtual void Register(std::unique_ptr<IBufferSettings> bufferSettings) = 0;
		virtual IBufferSettings* GetBufferSettings() = 0;

		virtual void Register(std::unique_ptr<ICrymiumCefRectSettings> crymiumCefRectSettings) = 0;
		virtual ICrymiumCefRectSettings* GetCrymiumCefRectSettings() = 0;

		virtual void Register(std::unique_ptr<IBufferProvider> bufferProvider) = 0;
		virtual IBufferProvider* GetBufferProvider() = 0;

		virtual void Register(std::unique_ptr<ITextureSettings> textureSettings) = 0;
		virtual ITextureSettings* GetTextureSettings() = 0;

		virtual void Register(std::unique_ptr<IInputEventListener> crymiumInputEventListener) = 0;
		virtual IInputEventListener* GetCrymiumInputEventListener() = 0;

		virtual void Register(std::unique_ptr<ICrymiumCefInitialiser> crymiumCefInitialiser) = 0;
		virtual ICrymiumCefInitialiser* GetCrymiumCefInitialiser() = 0;

		virtual void Register(std::unique_ptr<ICryInitialiser> cryInitialiser) = 0;
		virtual ICryInitialiser* GetCryInitialiser() = 0;

		virtual void Register(std::unique_ptr<IBrowser> crymiumBrowser) = 0;
		virtual IBrowser* GetBrowser() = 0;

		virtual void Register(std::unique_ptr<IInputMapper> inputMapper) = 0;
		virtual IInputMapper* GetInputMapper() = 0;

		virtual void Register(std::unique_ptr<IKeyIdMapper> keyIdMapper) = 0;
		virtual IKeyIdMapper* GetKeyIdMapper() = 0;

		virtual void Register(std::unique_ptr<IInputStateMapper> inputStateMapper) = 0;
		virtual IInputStateMapper* GetInputStateMapper() = 0;

		virtual void Register(std::unique_ptr<IWindowInfoCreator> windowInfoCreator) = 0;
		virtual IWindowInfoCreator* GetWindowInfoCreator() = 0;

		virtual void Register(std::unique_ptr<IBrowserSettingsCreator> browserSettingsCreator) = 0;
		virtual IBrowserSettingsCreator* GetBrowserSettingsCreator() = 0;

		virtual void Register(std::unique_ptr<ICrymiumCefSettingsCreator> crymiumCefSettingsCreator) = 0;
		virtual ICrymiumCefSettingsCreator* GetCrymiumCefSettingsCreator() = 0;

		virtual void Register(std::unique_ptr<ICrymiumCefMainArgsCreator> crymiumCefMainArgsCreator) = 0;
		virtual ICrymiumCefMainArgsCreator* GetCrymiumCefMainArgsCreator() = 0;

		virtual void Register(std::unique_ptr<ICrymiumSandboxInfoCreator> crymiumSandboxInfoCreator) = 0;
		virtual ICrymiumSandboxInfoCreator* GetCrymiumSandboxInfoCreator() = 0;

		virtual void Register(std::unique_ptr<IBufferSizeProvider> bufferSizeProvider) = 0;
		virtual IBufferSizeProvider* GetBufferSizeProvider() = 0;

		virtual void Register(std::unique_ptr<ITextureUpdater> textureUpdater) = 0;
		virtual ITextureUpdater* GetTextureUpdater() = 0;

		virtual void Register(std::unique_ptr<ITextureRemover> textureRemover) = 0;
		virtual ITextureRemover* GetTextureRemover() = 0;

		virtual void Register(std::unique_ptr<ITextureDrawer> textureDrawer) = 0;
		virtual ITextureDrawer* GetTextureDrawer() = 0;

		virtual void Register(std::unique_ptr<ITextureRenderer> textureRenderer) = 0;
		virtual ITextureRenderer* GetTextureRenderer() = 0;

		virtual void Register(std::unique_ptr<ITextureCreator> textureCreator) = 0;
		virtual ITextureCreator* GetTextureCreator() = 0;

		virtual void Register(std::unique_ptr<ITextureProvider> textureProvider) = 0;
		virtual ITextureProvider* GetTextureProvider() = 0;

		virtual void Register(std::unique_ptr<IInputInitialiser> crymiumInputInitialiser) = 0;
		virtual IInputInitialiser* GetInputInitialiser() = 0;

		virtual void Register(std::unique_ptr<IJavaScriptFunctionCallBuilder> javaScriptFunctionCallBuilder) = 0;
		virtual IJavaScriptFunctionCallBuilder* GetJavaScriptFunctionCallBuilder() = 0;

		virtual void Register(std::unique_ptr<IJavaScriptExecutor> javaScriptExecutor) = 0;
		virtual IJavaScriptExecutor* GetJavaScriptExecutor() = 0;

		virtual void Register(std::unique_ptr<IJavaScriptFunctionExecutor> javaScriptFunctionExecutor) = 0;
		virtual IJavaScriptFunctionExecutor* GetJavaScriptFunctionExecutor() = 0;

		virtual void Register(std::unique_ptr<Crymium::Uis::Core::IUiActivator> uiActivator) = 0;
		virtual Crymium::Uis::Core::IUiActivator* GetUiActivator() = 0;

		virtual void Register(std::unique_ptr<Crymium::Uis::Core::IUiPathResolver> uiPathResolver) = 0;
		virtual Crymium::Uis::Core::IUiPathResolver* GetUiPathResolver() = 0;

		virtual void Register(std::unique_ptr<Crymium::Uis::Core::IUiCloser> uiCloser) = 0;
		virtual Crymium::Uis::Core::IUiCloser* GetUiCloser() = 0;

		virtual void Register(std::unique_ptr<Crymium::Uis::Core::IUiSettings> uiSettings) = 0;
		virtual Crymium::Uis::Core::IUiSettings* GetUiSettings() = 0;

		virtual void Register(std::unique_ptr<Crymium::Uis::Core::IUiDirectoryProvider> uiDirectoryProvider) = 0;
		virtual Crymium::Uis::Core::IUiDirectoryProvider* GetUiDirectoryProvider() = 0;

		virtual void Set(ICefMessageHandler* cefMessageHandler) = 0;
	};
}

using namespace Crymium::Core;