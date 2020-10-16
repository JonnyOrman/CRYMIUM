#include "JavaScriptExecutor.h"

JavaScriptExecutor::JavaScriptExecutor(
	IBrowser* crymiumBrowser
)
:
_crymiumBrowser(crymiumBrowser)
{
}

void JavaScriptExecutor::Execute(const char* javaScript)
{
	_crymiumBrowser->ExecuteJavaScriptString(javaScript);
}
