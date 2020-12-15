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
		CrymiumContainer() = default;

		void Register(std::unique_ptr<ICrymiumCefSettings> crymiumCefSettings) override;
		ICrymiumCefSettings* GetCrymiumCefSettings() override;
		
		void Register(std::unique_ptr<ICrymiumCefAppInitialiser> cefInitialiser) override;
		ICrymiumCefAppInitialiser* GetCrymiumCefAppInitialiser() override;

		void Register(std::unique_ptr<ICaptureFrameListener> cefCaptureFrameListener) override;
		ICaptureFrameListener* GetCrymiumCefCaptureFrameListener() override;
		
		void Register(std::unique_ptr<Crymium::Core::ICrymiumInitialiser> initialiser) override;
		Crymium::Core::ICrymiumInitialiser* GetCrymiumInitialiser() override;

		void Register(std::unique_ptr<ITextureUpdater> textureUpdater) override;
		ITextureUpdater* GetTextureUpdater() override;
		
		void Register(std::unique_ptr<IRendererSettings> renderSettings) override;
		IRendererSettings* GetRendererSettings() override;

		void Register(std::unique_ptr<IRendererProvider> rendererProvider) override;
		IRendererProvider* GetRendererProvider() override;

		void Register(std::unique_ptr<IBufferSettings> bufferSettings) override;
		IBufferSettings* GetBufferSettings() override;

		void Register(std::unique_ptr<ICrymiumCefRectSettings> cefRectSettings) override;
		ICrymiumCefRectSettings* GetCrymiumCefRectSettings() override;

		void Register(std::unique_ptr<IBufferProvider> bufferProvider) override;
		IBufferProvider* GetBufferProvider() override;

		void Register(std::unique_ptr<ITextureSettings> textureSettings) override;
		ITextureSettings* GetTextureSettings() override;

		void Register(std::unique_ptr<IInputEventListener> cefInputEventListener) override;
		IInputEventListener* GetCrymiumInputEventListener() override;

		void Register(std::unique_ptr<ICrymiumCefInitialiser> crymiumCefInitialiser) override;
		ICrymiumCefInitialiser* GetCrymiumCefInitialiser() override;

		void Register(std::unique_ptr<ICryInitialiser> cryInitialiser) override;
		ICryInitialiser* GetCryInitialiser() override;

		void Register(std::unique_ptr<IBrowser> crymiumBrowser) override;
		IBrowser* GetBrowser() override;

		void Register(std::unique_ptr<IInputMapper> inputMapper) override;
		IInputMapper* GetInputMapper() override;

		void Register(std::unique_ptr<IKeyIdMapper> keyIdMapper) override;
		IKeyIdMapper* GetKeyIdMapper() override;

		void Register(std::unique_ptr<IInputStateMapper> inputStateMapper) override;
		IInputStateMapper* GetInputStateMapper() override;

		void Register(std::unique_ptr<IWindowInfoCreator> windowInfoCreator) override;
		IWindowInfoCreator* GetWindowInfoCreator() override;

		void Register(std::unique_ptr<IBrowserSettingsCreator> browserSettingsCreator) override;
		IBrowserSettingsCreator* GetBrowserSettingsCreator() override;

		void Register(std::unique_ptr<ICrymiumCefSettingsCreator> crymiumCefSettingsCreator) override;
		ICrymiumCefSettingsCreator* GetCrymiumCefSettingsCreator() override;

		void Register(std::unique_ptr<ICrymiumCefMainArgsCreator> crymiumCefMainArgsCreator) override;
		ICrymiumCefMainArgsCreator* GetCrymiumCefMainArgsCreator() override;

		void Register(std::unique_ptr<ICrymiumSandboxInfoCreator> crymiumSandboxInfoCreator) override;
		ICrymiumSandboxInfoCreator* GetCrymiumSandboxInfoCreator() override;

		void Register(std::unique_ptr<IBufferSizeProvider> bufferSizeProvider) override;
		IBufferSizeProvider* GetBufferSizeProvider() override;

		void Register(std::unique_ptr<ITextureRemover> textureRemover) override;
		ITextureRemover* GetTextureRemover() override;

		void Register(std::unique_ptr<ITextureDrawer> textureDrawer) override;
		ITextureDrawer* GetTextureDrawer() override;

		void Register(std::unique_ptr<ITextureRenderer> textureRenderer) override;
		ITextureRenderer* GetTextureRenderer() override;

		void Register(std::unique_ptr<ITextureCreator> textureCreator) override;
		ITextureCreator* GetTextureCreator() override;

		void Register(std::unique_ptr<ITextureProvider> textureProvider) override;
		ITextureProvider* GetTextureProvider() override;

		void Register(std::unique_ptr<ICrymiumRenderer> crymiumRenderer) override;
		ICrymiumRenderer* GetCrymiumRenderer() override;

		void Register(std::unique_ptr<ICrymiumRendererInitialiser> crymiumRendererInitialiser) override;
		ICrymiumRendererInitialiser* GetCrymiumRendererInitialiser() override;

		void Register(std::unique_ptr<IInputInitialiser> crymiumInputInitialiser) override;
		IInputInitialiser* GetInputInitialiser() override;

		void Register(std::unique_ptr<IJavaScriptFunctionCallBuilder> javaScriptFunctionCallBuilder) override;
		IJavaScriptFunctionCallBuilder* GetJavaScriptFunctionCallBuilder() override;

		void Register(std::unique_ptr<IJavaScriptExecutor> javaScriptExecutor) override;
		IJavaScriptExecutor* GetJavaScriptExecutor() override;

		void Register(std::unique_ptr<IJavaScriptFunctionExecutor> javaScriptFunctionExecutor) override;
		IJavaScriptFunctionExecutor* GetJavaScriptFunctionExecutor() override;

		void Register(std::unique_ptr<Crymium::Uis::Core::IUiActivator> uiActivator) override;
		Crymium::Uis::Core::IUiActivator* GetUiActivator() override;

		void Register(std::unique_ptr<Crymium::Uis::Core::IUiPathResolver> uiPathResolver) override;
		Crymium::Uis::Core::IUiPathResolver* GetUiPathResolver() override;

		void Register(std::unique_ptr<Crymium::Uis::Core::IUiCloser> uiCloser) override;
		Crymium::Uis::Core::IUiCloser* GetUiCloser() override;

		void Register(std::unique_ptr<Crymium::Uis::Core::IUiSettings> uiSettings) override;
		Crymium::Uis::Core::IUiSettings* GetUiSettings() override;
		
		void Set(ICefMessageHandler* cefMessageHandler) override;

		void Register(std::unique_ptr<Crymium::Uis::Core::IUiDirectoryProvider> uiDirectoryProvider) override;
		Crymium::Uis::Core::IUiDirectoryProvider* GetUiDirectoryProvider() override;
		
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
	};
}

using namespace Crymium;