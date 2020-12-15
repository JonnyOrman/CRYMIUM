#include <windows.h>
#include "include/base/cef_scoped_ptr.h"
#include "renderer/ClientAppRenderer.h"

int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPTSTR lpCmdLine,
                      int nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);

  void* sandbox_info = NULL;

  CefSettings settings;
  settings.no_sandbox = true;

  CefMainArgs main_args(hInstance);

  CefRefPtr<CefApp> app = new ClientAppRenderer();

  return CefExecuteProcess(main_args, app, sandbox_info);
}