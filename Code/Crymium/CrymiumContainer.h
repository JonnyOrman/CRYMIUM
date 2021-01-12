#pragma once
#include <memory>
#include "Crymium/Core/ICrymiumContainer.h"

namespace Crymium
{
	class CrymiumContainer
		:
		public ICrymiumContainer
	{
	public:
		__declspec(dllexport) CrymiumContainer() = default;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumCefSettings> crymiumCefSettings) override;
		__declspec(dllexport) ICrymiumCefSettings* GetCrymiumCefSettings() override;
		
		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumCefAppInitialiser> cefInitialiser) override;
		__declspec(dllexport) ICrymiumCefAppInitialiser* GetCrymiumCefAppInitialiser() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICaptureFrameListener> cefCaptureFrameListener) override;
		__declspec(dllexport) ICaptureFrameListener* GetCrymiumCefCaptureFrameListener() override;
		
		__declspec(dllexport) void Register(std::unique_ptr<Crymium::Core::ICrymiumInitialiser> initialiser) override;
		__declspec(dllexport) Crymium::Core::ICrymiumInitialiser* GetCrymiumInitialiser() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureUpdater> textureUpdater) override;
		__declspec(dllexport) ITextureUpdater* GetTextureUpdater() override;
		
		__declspec(dllexport) void Register(std::unique_ptr<IRendererSettings> renderSettings) override;
		__declspec(dllexport) IRendererSettings* GetRendererSettings() override;

		__declspec(dllexport) void Register(std::unique_ptr<IRendererProvider> rendererProvider) override;
		__declspec(dllexport) IRendererProvider* GetRendererProvider() override;

		__declspec(dllexport) void Register(std::unique_ptr<IBufferSettings> bufferSettings) override;
		__declspec(dllexport) IBufferSettings* GetBufferSettings() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumCefRectSettings> cefRectSettings) override;
		__declspec(dllexport) ICrymiumCefRectSettings* GetCrymiumCefRectSettings() override;

		__declspec(dllexport) void Register(std::unique_ptr<IBufferProvider> bufferProvider) override;
		__declspec(dllexport) IBufferProvider* GetBufferProvider() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureSettings> textureSettings) override;
		__declspec(dllexport) ITextureSettings* GetTextureSettings() override;

		__declspec(dllexport) void Register(std::unique_ptr<IInputEventListener> cefInputEventListener) override;
		__declspec(dllexport) IInputEventListener* GetCrymiumInputEventListener() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumCefInitialiser> crymiumCefInitialiser) override;
		__declspec(dllexport) ICrymiumCefInitialiser* GetCrymiumCefInitialiser() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICryInitialiser> cryInitialiser) override;
		__declspec(dllexport) ICryInitialiser* GetCryInitialiser() override;

		__declspec(dllexport) void Register(std::unique_ptr<IBrowser> crymiumBrowser) override;
		__declspec(dllexport) IBrowser* GetBrowser() override;

		__declspec(dllexport) void Register(std::unique_ptr<IInputMapper> inputMapper) override;
		__declspec(dllexport) IInputMapper* GetInputMapper() override;

		__declspec(dllexport) void Register(std::unique_ptr<IKeyIdMapper> keyIdMapper) override;
		__declspec(dllexport) IKeyIdMapper* GetKeyIdMapper() override;

		__declspec(dllexport) void Register(std::unique_ptr<IInputStateMapper> inputStateMapper) override;
		__declspec(dllexport) IInputStateMapper* GetInputStateMapper() override;

		__declspec(dllexport) void Register(std::unique_ptr<IWindowInfoCreator> windowInfoCreator) override;
		__declspec(dllexport) IWindowInfoCreator* GetWindowInfoCreator() override;

		__declspec(dllexport) void Register(std::unique_ptr<IBrowserSettingsCreator> browserSettingsCreator) override;
		__declspec(dllexport) IBrowserSettingsCreator* GetBrowserSettingsCreator() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumCefSettingsCreator> crymiumCefSettingsCreator) override;
		__declspec(dllexport) ICrymiumCefSettingsCreator* GetCrymiumCefSettingsCreator() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumCefMainArgsCreator> crymiumCefMainArgsCreator) override;
		__declspec(dllexport) ICrymiumCefMainArgsCreator* GetCrymiumCefMainArgsCreator() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumSandboxInfoCreator> crymiumSandboxInfoCreator) override;
		__declspec(dllexport) ICrymiumSandboxInfoCreator* GetCrymiumSandboxInfoCreator() override;

		__declspec(dllexport) void Register(std::unique_ptr<IBufferSizeProvider> bufferSizeProvider) override;
		__declspec(dllexport) IBufferSizeProvider* GetBufferSizeProvider() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureRemover> textureRemover) override;
		__declspec(dllexport) ITextureRemover* GetTextureRemover() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureDrawer> textureDrawer) override;
		__declspec(dllexport) ITextureDrawer* GetTextureDrawer() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureRenderer> textureRenderer) override;
		__declspec(dllexport) ITextureRenderer* GetTextureRenderer() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureCreator> textureCreator) override;
		__declspec(dllexport) ITextureCreator* GetTextureCreator() override;

		__declspec(dllexport) void Register(std::unique_ptr<ITextureProvider> textureProvider) override;
		__declspec(dllexport) ITextureProvider* GetTextureProvider() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumRenderer> crymiumRenderer) override;
		__declspec(dllexport) ICrymiumRenderer* GetCrymiumRenderer() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICrymiumRendererInitialiser> crymiumRendererInitialiser) override;
		__declspec(dllexport) ICrymiumRendererInitialiser* GetCrymiumRendererInitialiser() override;

		__declspec(dllexport) void Register(std::unique_ptr<IInputInitialiser> crymiumInputInitialiser) override;
		__declspec(dllexport) IInputInitialiser* GetInputInitialiser() override;

		__declspec(dllexport) void Register(std::unique_ptr<IJavaScriptFunctionCallBuilder> javaScriptFunctionCallBuilder) override;
		__declspec(dllexport) IJavaScriptFunctionCallBuilder* GetJavaScriptFunctionCallBuilder() override;

		__declspec(dllexport) void Register(std::unique_ptr<IJavaScriptExecutor> javaScriptExecutor) override;
		__declspec(dllexport) IJavaScriptExecutor* GetJavaScriptExecutor() override;

		__declspec(dllexport) void Register(std::unique_ptr<IJavaScriptFunctionExecutor> javaScriptFunctionExecutor) override;
		__declspec(dllexport) IJavaScriptFunctionExecutor* GetJavaScriptFunctionExecutor() override;

		__declspec(dllexport) void Register(std::unique_ptr<Crymium::Uis::Core::IUiActivator> uiActivator) override;
		__declspec(dllexport) Crymium::Uis::Core::IUiActivator* GetUiActivator() override;

		__declspec(dllexport) void Register(std::unique_ptr<Crymium::Uis::Core::IUiPathResolver> uiPathResolver) override;
		__declspec(dllexport) Crymium::Uis::Core::IUiPathResolver* GetUiPathResolver() override;

		__declspec(dllexport) void Register(std::unique_ptr<Crymium::Uis::Core::IUiCloser> uiCloser) override;
		__declspec(dllexport) Crymium::Uis::Core::IUiCloser* GetUiCloser() override;

		__declspec(dllexport) void Register(std::unique_ptr<Crymium::Uis::Core::IUiSettings> uiSettings) override;
		__declspec(dllexport) Crymium::Uis::Core::IUiSettings* GetUiSettings() override;
		
		__declspec(dllexport) void Register(std::unique_ptr<Crymium::Uis::Core::IUiDirectoryProvider> uiDirectoryProvider) override;
		__declspec(dllexport) Crymium::Uis::Core::IUiDirectoryProvider* GetUiDirectoryProvider() override;

		__declspec(dllexport) void Register(std::unique_ptr<ICefMessageHandler> cefMessageHandler) override;
		__declspec(dllexport) ICefMessageHandler* GetCefMessageHandler() override;
		
		__declspec(dllexport) void Add(ICefQueryHandler* cefQueryHandler) override;
	
	private:
		std::unique_ptr<ICrymiumCefAppInitialiser> _cefInitialiser;
		std::unique_ptr<ICaptureFrameListener> _cefCaptureFrameListener;
		std::unique_ptr<Crymium::Core::ICrymiumInitialiser> _initialiser;
		std::unique_ptr<ITextureUpdater> _textureUpdater;
		std::unique_ptr<IRendererSettings> _renderSettings;
		std::unique_ptr<IBufferSettings> _bufferSettings;
		std::unique_ptr<ICrymiumCefRectSettings> _cefRectSettings;
		std::unique_ptr<IBufferProvider> _bufferProvider;
		std::unique_ptr<ITextureSettings> _textureSettings;
		std::unique_ptr<IInputEventListener> _cefInputEventListener;
		std::unique_ptr<ICrymiumCefInitialiser> _crymiumCefInitialiser;
		std::unique_ptr<ICryInitialiser> _cryInitialiser;
		std::unique_ptr<IBrowser> _crymiumBrowser;
		std::unique_ptr<IInputMapper> _inputMapper;
		std::unique_ptr<IKeyIdMapper> _keyIdMapper;
		std::unique_ptr<IInputStateMapper> _inputStateMapper;
		std::unique_ptr<IWindowInfoCreator> _windowInfoCreator;
		std::unique_ptr<IBrowserSettingsCreator> _browserSettingsCreator;
		std::unique_ptr<ICrymiumCefSettingsCreator> _crymiumCefSettingsCreator;
		std::unique_ptr<ICrymiumCefMainArgsCreator> _crymiumCefMainArgsCreator;
		std::unique_ptr<ICrymiumSandboxInfoCreator> _crymiumSandboxInfoCreator;
		std::unique_ptr<IBufferSizeProvider> _bufferSizeProvider;
		std::unique_ptr<ITextureRemover> _textureRemover;
		std::unique_ptr<ITextureDrawer> _textureDrawer;
		std::unique_ptr<ITextureRenderer> _textureRenderer;
		std::unique_ptr<ITextureCreator> _textureCreator;
		std::unique_ptr<ITextureProvider> _textureProvider;
		std::unique_ptr<IRendererProvider> _rendererProvider;
		std::unique_ptr<ICrymiumRenderer> _crymiumRenderer;
		std::unique_ptr<ICrymiumRendererInitialiser> _crymiumRendererInitialiser;
		std::unique_ptr<IInputInitialiser> _crymiumInputInitialiser;
		std::unique_ptr<ICrymiumCefSettings> _crymiumCefSettings;
		std::unique_ptr<IJavaScriptFunctionCallBuilder> _javaScriptFunctionCallBuilder;
		std::unique_ptr<IJavaScriptExecutor> _javaScriptExecutor;
		std::unique_ptr<IJavaScriptFunctionExecutor> _javaScriptFunctionExecutor;
		std::unique_ptr<Crymium::Uis::Core::IUiActivator> _uiActivator;
		std::unique_ptr<Crymium::Uis::Core::IUiPathResolver> _uiPathResolver;
		std::unique_ptr<Crymium::Uis::Core::IUiCloser> _uiCloser;
		std::unique_ptr<Crymium::Uis::Core::IUiSettings> _uiSettings;
		std::unique_ptr<Crymium::Uis::Core::IUiDirectoryProvider> _uiDirectoryProvider;
		std::unique_ptr<ICefMessageHandler> _cefMessageHandler;
	};
}

using namespace Crymium;