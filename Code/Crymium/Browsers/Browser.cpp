#include "Browser.h"
#include "Crymium/Cef/CefBrowserClient.h"

Browser::Browser(
    BufferRenderHandler* renderHandler,
    IInputMapper* inputMapper,
    IWindowInfoCreator* windowInfoCreator,
    IBrowserSettingsCreator* browserSettingsCreator,
    IJavaScriptFunctionCallBuilder* javaScriptFunctionCallBuilder
)
:
_renderHandler(renderHandler),
_inputMapper(inputMapper),
_windowInfoCreator(windowInfoCreator),
_browserSettingsCreator(browserSettingsCreator),
_javaScriptFunctionCallBuilder(javaScriptFunctionCallBuilder)
{
}

void Browser::Initialise()
{
    auto info = _windowInfoCreator->Create();
	
    auto browserSettings = _browserSettingsCreator->Create();

    CefMessageRouterConfig config;
    auto messageRouter = CefMessageRouterBrowserSide::Create(config);

    auto messageHandler = new MessageHandler(
        _cefMessageHandler
    );
	
    _browserClient = new CefBrowserClient(
        _renderHandler,
        messageRouter,
        messageHandler
    );

    _browser = CefBrowserHost::CreateBrowserSync(*info, _browserClient.get(), "", browserSettings, nullptr, nullptr);
}

void Browser::SendInputEvent(const SInputEvent& inputEvent)
{
    auto cefKeyEvent = _inputMapper->Map(inputEvent);

    _browser->GetHost()->SendKeyEvent(cefKeyEvent);
}

void Browser::GoTo(std::string url)
{
    _browser->GetMainFrame()->LoadURL(url);
}

void Browser::Set(ICefMessageHandler* cefMessageHandler)
{
    _cefMessageHandler = cefMessageHandler;
}

void Browser::ExecuteJavaScriptString(const char* javaScript)
{
    _browser->GetMainFrame()->ExecuteJavaScript(
        javaScript,
        _browser->GetMainFrame()->GetURL(),
        0
    );
}

void Browser::ExecuteJavaScriptFunction(const char* functionName, std::vector<std::string> parameters)
{
    auto javaScriptString = _javaScriptFunctionCallBuilder->Build(functionName, parameters);

    ExecuteJavaScriptString(javaScriptString.c_str());
}

bool Browser::IsReady()
{
    return !_browser->IsLoading();
}

void Browser::Update()
{
}

std::string Browser::GetCurrentUrl()
{
    return _browser->GetMainFrame()->GetURL();
}
