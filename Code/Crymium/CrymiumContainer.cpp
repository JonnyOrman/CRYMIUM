#include "CrymiumContainer.h"

void CrymiumContainer::Register(std::unique_ptr<ICrymiumCefSettings> crymiumCefSettings)
{
	_crymiumCefSettings = std::move(crymiumCefSettings);
}

ICrymiumCefSettings* CrymiumContainer::GetCrymiumCefSettings()
{
	return _crymiumCefSettings.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumCefAppInitialiser> cefInitialiser)
{
	_cefInitialiser = std::move(cefInitialiser);
}

ICrymiumCefAppInitialiser* CrymiumContainer::GetCrymiumCefAppInitialiser()
{
	return _cefInitialiser.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICaptureFrameListener> cefCaptureFrameListener)
{
	_cefCaptureFrameListener = std::move(cefCaptureFrameListener);
}

ICaptureFrameListener* CrymiumContainer::GetCrymiumCefCaptureFrameListener()
{
	return _cefCaptureFrameListener.get();
}

void CrymiumContainer::Register(std::unique_ptr<Crymium::Core::ICrymiumInitialiser> initialiser)
{
	_initialiser = std::move(initialiser);
}

Crymium::Core::ICrymiumInitialiser* CrymiumContainer::GetCrymiumInitialiser()
{
	return _initialiser.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureUpdater> textureUpdater)
{
	_textureUpdater = std::move(textureUpdater);
}

ITextureUpdater* CrymiumContainer::GetTextureUpdater()
{
	return _textureUpdater.get();
}

void CrymiumContainer::Register(std::unique_ptr<IRendererSettings> renderSettings)
{
	_renderSettings = std::move(renderSettings);
}

IRendererSettings* CrymiumContainer::GetRendererSettings()
{
	return _renderSettings.get();
}

void CrymiumContainer::Register(std::unique_ptr<IRendererProvider> rendererProvider)
{
	_rendererProvider = std::move(rendererProvider);
}

IRendererProvider* CrymiumContainer::GetRendererProvider()
{
	return _rendererProvider.get();
}

void CrymiumContainer::Register(std::unique_ptr<IBufferSettings> BufferSettings)
{
	_bufferSettings = std::move(BufferSettings);
}

IBufferSettings* CrymiumContainer::GetBufferSettings()
{
	return _bufferSettings.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumCefRectSettings> cefRectSettings)
{
	_cefRectSettings = std::move(cefRectSettings);
}

ICrymiumCefRectSettings* CrymiumContainer::GetCrymiumCefRectSettings()
{
	return _cefRectSettings.get();
}

void CrymiumContainer::Register(std::unique_ptr<IBufferProvider> bufferProvider)
{
	_bufferProvider = std::move(bufferProvider);
}

IBufferProvider* CrymiumContainer::GetBufferProvider()
{
	return _bufferProvider.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureSettings> textureSettings)
{
	_textureSettings = std::move(textureSettings);
}

ITextureSettings* CrymiumContainer::GetTextureSettings()
{
	return _textureSettings.get();
}

void CrymiumContainer::Register(std::unique_ptr<IInputEventListener> cefInputEventListener)
{
	_cefInputEventListener = std::move(cefInputEventListener);
}

IInputEventListener* CrymiumContainer::GetCrymiumInputEventListener()
{
	return _cefInputEventListener.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumCefInitialiser> crymiumCefInitialiser)
{
	_crymiumCefInitialiser = std::move(crymiumCefInitialiser);
}

ICrymiumCefInitialiser* CrymiumContainer::GetCrymiumCefInitialiser()
{
	return _crymiumCefInitialiser.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICryInitialiser> cryInitialiser)
{
	_cryInitialiser = std::move(cryInitialiser);
}

ICryInitialiser* CrymiumContainer::GetCryInitialiser()
{
	return _cryInitialiser.get();
}

void CrymiumContainer::Register(std::unique_ptr<IBrowser> crymiumBrowser)
{
	_crymiumBrowser = std::move(crymiumBrowser);
}

IBrowser* CrymiumContainer::GetBrowser()
{
	return _crymiumBrowser.get();
}

void CrymiumContainer::Register(std::unique_ptr<IInputMapper> inputMapper)
{
	_inputMapper = std::move(inputMapper);
}

IInputMapper* CrymiumContainer::GetInputMapper()
{
	return _inputMapper.get();
}

void CrymiumContainer::Register(std::unique_ptr<IKeyIdMapper> keyIdMapper)
{
	_keyIdMapper = std::move(keyIdMapper);
}

IKeyIdMapper* CrymiumContainer::GetKeyIdMapper()
{
	return _keyIdMapper.get();
}

void CrymiumContainer::Register(std::unique_ptr<IInputStateMapper> inputStateMapper)
{
	_inputStateMapper = std::move(inputStateMapper);
}

IInputStateMapper* CrymiumContainer::GetInputStateMapper()
{
	return _inputStateMapper.get();
}

void CrymiumContainer::Register(std::unique_ptr<IWindowInfoCreator> windowInfoCreator)
{
	_windowInfoCreator = std::move(windowInfoCreator);
}

IWindowInfoCreator* CrymiumContainer::GetWindowInfoCreator()
{
	return _windowInfoCreator.get();
}

void CrymiumContainer::Register(std::unique_ptr<IBrowserSettingsCreator> browserSettingsCreator)
{
	_browserSettingsCreator = std::move(browserSettingsCreator);
}

IBrowserSettingsCreator* CrymiumContainer::GetBrowserSettingsCreator()
{
	return _browserSettingsCreator.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumCefSettingsCreator> crymiumCefSettingsCreator)
{
	_crymiumCefSettingsCreator = std::move(crymiumCefSettingsCreator);
}

ICrymiumCefSettingsCreator* CrymiumContainer::GetCrymiumCefSettingsCreator()
{
	return _crymiumCefSettingsCreator.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumCefMainArgsCreator> crymiumCefMainArgsCreator)
{
	_crymiumCefMainArgsCreator = std::move(crymiumCefMainArgsCreator);
}

ICrymiumCefMainArgsCreator* CrymiumContainer::GetCrymiumCefMainArgsCreator()
{
	return _crymiumCefMainArgsCreator.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumSandboxInfoCreator> crymiumSandboxInfoCreator)
{
	_crymiumSandboxInfoCreator = std::move(crymiumSandboxInfoCreator);
}

ICrymiumSandboxInfoCreator* CrymiumContainer::GetCrymiumSandboxInfoCreator()
{
	return _crymiumSandboxInfoCreator.get();
}

void CrymiumContainer::Register(std::unique_ptr<IBufferSizeProvider> bufferSizeProvider)
{
	_bufferSizeProvider = std::move(bufferSizeProvider);
}

IBufferSizeProvider* CrymiumContainer::GetBufferSizeProvider()
{
	return _bufferSizeProvider.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureRemover> textureRemover)
{
	_textureRemover = std::move(textureRemover);
}

ITextureRemover* CrymiumContainer::GetTextureRemover()
{
	return _textureRemover.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureDrawer> textureDrawer)
{
	_textureDrawer = std::move(textureDrawer);
}

ITextureDrawer* CrymiumContainer::GetTextureDrawer()
{
	return _textureDrawer.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureRenderer> textureRenderer)
{
	_textureRenderer = std::move(textureRenderer);
}

ITextureRenderer* CrymiumContainer::GetTextureRenderer()
{
	return _textureRenderer.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureCreator> textureCreator)
{
	_textureCreator = std::move(textureCreator);
}

ITextureCreator* CrymiumContainer::GetTextureCreator()
{
	return _textureCreator.get();
}

void CrymiumContainer::Register(std::unique_ptr<ITextureProvider> textureProvider)
{
	_textureProvider = std::move(textureProvider);
}

ITextureProvider* CrymiumContainer::GetTextureProvider()
{
	return _textureProvider.get();
}

void CrymiumContainer::Set(ICefMessageHandler* cefMessageHandler)
{
	GetBrowser()->Set(cefMessageHandler);
}

void CrymiumContainer::Register(std::unique_ptr<Crymium::Uis::Core::IUiDirectoryProvider> uiDirectoryProvider)
{
	_uiDirectoryProvider = std::move(uiDirectoryProvider);
}

Crymium::Uis::Core::IUiDirectoryProvider* CrymiumContainer::GetUiDirectoryProvider()
{
	return _uiDirectoryProvider.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumRenderer> crymiumRenderer)
{
	_crymiumRenderer = std::move(crymiumRenderer);
}

ICrymiumRenderer* CrymiumContainer::GetCrymiumRenderer()
{
	return _crymiumRenderer.get();
}

void CrymiumContainer::Register(std::unique_ptr<ICrymiumRendererInitialiser> crymiumRendererInitialiser)
{
	_crymiumRendererInitialiser = std::move(crymiumRendererInitialiser);
}

ICrymiumRendererInitialiser* CrymiumContainer::GetCrymiumRendererInitialiser()
{
	return _crymiumRendererInitialiser.get();
}

void CrymiumContainer::Register(std::unique_ptr<IInputInitialiser> crymiumInputInitialiser)
{
	_crymiumInputInitialiser = std::move(crymiumInputInitialiser);
}

IInputInitialiser* CrymiumContainer::GetInputInitialiser()
{
	return _crymiumInputInitialiser.get();
}

void CrymiumContainer::Register(std::unique_ptr<IJavaScriptFunctionCallBuilder> javaScriptFunctionCallBuilder)
{
	_javaScriptFunctionCallBuilder = std::move(javaScriptFunctionCallBuilder);
}

IJavaScriptFunctionCallBuilder* CrymiumContainer::GetJavaScriptFunctionCallBuilder()
{
	return _javaScriptFunctionCallBuilder.get();
}

void CrymiumContainer::Register(std::unique_ptr<IJavaScriptExecutor> javaScriptExecutor)
{
	_javaScriptExecutor = std::move(javaScriptExecutor);
}

IJavaScriptExecutor* CrymiumContainer::GetJavaScriptExecutor()
{
	return _javaScriptExecutor.get();
}

void CrymiumContainer::Register(std::unique_ptr<IJavaScriptFunctionExecutor> javaScriptFunctionExecutor)
{
	_javaScriptFunctionExecutor = std::move(javaScriptFunctionExecutor);
}

IJavaScriptFunctionExecutor* CrymiumContainer::GetJavaScriptFunctionExecutor()
{
	return _javaScriptFunctionExecutor.get();
}

void CrymiumContainer::Register(std::unique_ptr<IUiActivator> uiActivator)
{
	_uiActivator = std::move(uiActivator);
}

IUiActivator* CrymiumContainer::GetUiActivator()
{
	return _uiActivator.get();
}

void CrymiumContainer::Register(std::unique_ptr<Crymium::Uis::Core::IUiPathResolver> uiPathResolver)
{
	_uiPathResolver = std::move(uiPathResolver);
}

Crymium::Uis::Core::IUiPathResolver* CrymiumContainer::GetUiPathResolver()
{
	return _uiPathResolver.get();
}

void CrymiumContainer::Register(std::unique_ptr<Crymium::Uis::Core::IUiCloser> uiCloser)
{
	_uiCloser = std::move(uiCloser);
}

Crymium::Uis::Core::IUiCloser* CrymiumContainer::GetUiCloser()
{
	return _uiCloser.get();
}

void CrymiumContainer::Register(std::unique_ptr<Crymium::Uis::Core::IUiSettings> uiSettings)
{
	_uiSettings = std::move(uiSettings);
}

Crymium::Uis::Core::IUiSettings* CrymiumContainer::GetUiSettings()
{
	return _uiSettings.get();
}
