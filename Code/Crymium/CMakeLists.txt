cmake_minimum_required (VERSION 3.14)
set(CRYENGINE_DIR "C:/Program Files (x86)/Crytek/CRYENGINE Launcher/Crytek/CRYENGINE_5.6" CACHE STRING "CRYENGINE root directory.")
set(TOOLS_CMAKE_DIR "${CRYENGINE_DIR}/Tools/CMake")

set(PROJECT_BUILD 1)
set(PROJECT_DIR "${CMAKE_SOURCE_DIR}/../")

include("${TOOLS_CMAKE_DIR}/InitialSetup.cmake")
include("${TOOLS_CMAKE_DIR}/CommonOptions.cmake")

add_subdirectory("${CRYENGINE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/CRYENGINE")

include("${TOOLS_CMAKE_DIR}/Configure.cmake")

start_sources()

sources_platform(ALL)

add_sources("Browsers_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Browsers
		"Browsers/Browser.cpp"
        "Browsers/BrowserSettingsCreator.cpp"
        "Browsers/WindowInfoCreator.cpp"
        "Browsers/Browser.h"
        "Browsers/BrowserSettingsCreator.h"
        "Browsers/WindowInfoCreator.h"
)

add_sources("Browsers_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Browsers\\\\Core
		"Browsers/Core/IBrowser.h"
        "Browsers/Core/IBrowserSettingsCreator.h"
        "Browsers/Core/IWindowInfoCreator.h"
)

add_sources("Buffer_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Buffer
        "Buffer/BufferProvider.cpp"
        "Buffer/BufferRenderHandler.cpp"
        "Buffer/BufferSettings.cpp"
        "Buffer/BufferSizeProvider.cpp"
        "Buffer/BufferProvider.h"
        "Buffer/BufferRenderHandler.h"
        "Buffer/BufferSettings.h"
        "Buffer/BufferSizeProvider.h"
)

add_sources("Buffer_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Buffer\\\\Core
        "Buffer/Core/IBufferProvider.h"
        "Buffer/Core/IBufferSettings.h"
        "Buffer/Core/IBufferSizeProvider.h"
)

add_sources("Cef_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Cef
        "Cef/CefRectSettings.cpp"
        "Cef/CefCaptureFrameListener.cpp"
		"Cef/CefBrowserClient.cpp"
		"Cef/CefInitialiser.cpp"
        "Cef/CefInputEventListener.cpp"
        "Cef/CrymiumCefApp.cpp"
        "Cef/CrymiumCefInitialiser.cpp"
        "Cef/MessageHandler.cpp"
        "Cef/CrymiumCefSettingsCreator.cpp"
        "Cef/CrymiumCefMainArgsCreator.cpp"
        "Cef/CrymiumSandboxInfoCreator.cpp"
        "Cef/CrymiumCefSettings.cpp"
		"Cef/CefBrowserClient.h"
		"Cef/CefInitialiser.h"
        "Cef/CefCaptureFrameListener.h"
        "Cef/CefRectSettings.h"
        "Cef/CefInputEventListener.h"
        "Cef/CrymiumCefApp.h"
        "Cef/CrymiumCefInitialiser.h"
        "Cef/MessageHandler.h"
        "Cef/CrymiumCefSettingsCreator.h"
        "Cef/CrymiumCefMainArgsCreator.h"
        "Cef/CrymiumSandboxInfoCreator.h"
        "Cef/CrymiumCefSettings.h"
)

add_sources("Cef_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Cef\\\\Core
		"Cef/Core/ICefInitialiser.h"
        "Cef/Core/ICefRectSettings.h"
        "Cef/Core/ICefMessageHandler.h"
        "Cef/Core/ICrymiumCefInitialiser.h"
        "Cef/Core/ICrymiumCefSettingsCreator.h"
        "Cef/Core/ICrymiumCefMainArgsCreator.h"
        "Cef/Core/ICrymiumSandboxInfoCreator.h"
        "Cef/Core/ICrymiumCefSettings.h"
)

add_sources("Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Core
        "Core/ICrymiumContainer.h"
        "Core/IInitialiser.h"
)

add_sources("Cry_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Cry
		"Cry/CryInitialiser.cpp"
        "Cry/CryInitialiser.h"
)

add_sources("Cry_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Cry\\\\Core
		"Cry/Core/ICryInitialiser.h"
)

add_sources("Inputs_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Inputs
        "Inputs/InputInitialiser.cpp"
		"Inputs/InputMapper.cpp"
        "Inputs/InputStateMapper.cpp"
        "Inputs/KeyIdMapper.cpp"
        "Inputs/InputInitialiser.h"
        "Inputs/InputMapper.h"
        "Inputs/InputStateMapper.h"
        "Inputs/KeyIdMapper.h"
)

add_sources("Inputs_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Inputs\\\\Core
        "Inputs/Core/IInputInitialiser.h"
		"Inputs/Core/IInputMapper.h"
		"Inputs/Core/IInputStateMapper.h"
		"Inputs/Core/IKeyIdMapper.h"
)

add_sources("JavaScrip_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP JavaScript
        "JavaScript/JavaScriptFunctionCallBuilder.cpp"
        "JavaScript/JavaScriptExecutor.cpp"
        "JavaScript/JavaScriptFunctionExecutor.cpp"
        "JavaScript/JavaScriptFunctionCallBuilder.h"
        "JavaScript/JavaScriptExecutor.h"
        "JavaScript/JavaScriptFunctionExecutor.h"
)

add_sources("JavaScript_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP JavaScript\\\\Core
        "JavaScript/Core/IJavaScriptFunctionCallBuilder.h"
        "JavaScript/Core/IJavaScriptExecutor.h"
        "JavaScript/Core/IJavaScriptFunctionExecutor.h"
)

add_sources("Rendering_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Rendering
        "Rendering/CrymiumRenderer.cpp"
        "Rendering/CrymiumRendererInitialiser.cpp"
		"Rendering/RendererProvider.cpp"
        "Rendering/RendererSettings.cpp"
        "Rendering/CrymiumRenderer.h"
        "Rendering/CrymiumRendererInitialiser.h"
        "Rendering/RendererProvider.h"
        "Rendering/RendererSettings.h"
)

add_sources("Rendering_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Rendering\\\\Core
        "Rendering/Core/ICrymiumRenderer.h"
        "Rendering/Core/ICrymiumRendererInitialiser.h"
		"Rendering/Core/IRendererProvider.h"
        "Rendering/Core/IRendererSettings.h"
)

add_sources("Textures_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Textures
        "Textures/TextureSettings.cpp"
		"Textures/TextureUpdater.cpp"
        "Textures/TextureRemover.cpp"
        "Textures/TextureCreator.cpp"
        "Textures/TextureDrawer.cpp"
        "Textures/TextureRenderer.cpp"
        "Textures/TextureProvider.cpp"
        "Textures/TextureSettings.h"
        "Textures/TextureUpdater.h"
        "Textures/TextureRemover.h"
        "Textures/TextureCreator.h"
        "Textures/TextureDrawer.h"
        "Textures/TextureRenderer.h"
        "Textures/TextureProvider.h"
)

add_sources("Textures_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Textures\\\\Core
        "Textures/Core/ITextureSettings.h"
		"Textures/Core/ITextureUpdater.h"
        "Textures/Core/ITextureRemover.h"
        "Textures/Core/ITextureCreator.h"
        "Textures/Core/ITextureDrawer.h"
        "Textures/Core/ITextureRenderer.h"
        "Textures/Core/ITextureProvider.h"
)

add_sources("Uis_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Uis
        "Uis/CryUiDirectoryProvider.cpp"
        "Uis/UiActivator.cpp"
        "Uis/UiCloser.cpp"
        "Uis/UiDirectoryProvider.cpp"
        "Uis/UiPathResolver.cpp"
        "Uis/UiSettings.cpp"
        "Uis/CryUiDirectoryProvider.h"
        "Uis/UiActivator.h"
        "Uis/UiCloser.h"
        "Uis/UiDirectoryProvider.h"
        "Uis/UiPathResolver.h"
        "Uis/UiSettings.h"
)

add_sources("Uis_Core_uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Uis\\\\Core
        "Uis/Core/IUiActivator.h"
        "Uis/Core/IUiCloser.h"
        "Uis/Core/IUiDirectoryProvider.h"
        "Uis/Core/IUiPathResolver.h"
        "Uis/Core/IUiSettings.h"
)

add_sources("uber.cpp"
    PROJECTS Crymium
    SOURCE_GROUP Root
        "CrymiumPlugin.cpp"
		"StdAfx.cpp"
        "CrymiumPlugin.h"
		"StdAfx.h"
        "CrymiumContainer.cpp"
        "CrymiumContainerComposer.cpp"
        "CrymiumInitialiser.cpp"
        "CrymiumContainer.h"
        "CrymiumContainerComposer.h"
        "CrymiumInitialiser.h"
)

end_sources()

CryGameModule(Crymium FORCE_SHARED PCH "StdAfx.cpp" SOLUTION_FOLDER)

target_include_directories(${THIS_PROJECT}

PRIVATE
    "${CRYENGINE_DIR}/Code/CryEngine/CryCommon"
    "${CRYENGINE_DIR}/Code/CryEngine/CryAction"
	"../../code/"
    "../../build/third_party/cef/cef_binary_79.1.27+gd2449e5+chromium-79.0.3945.117_windows64"
)

set_target_properties(Crymium PROPERTIES
            CXX_STANDARD 17
            )

target_link_libraries(Crymium PUBLIC "../third_party/cef/cef_binary_79.1.27+gd2449e5+chromium-79.0.3945.117_windows64/Debug/libcef")
target_link_libraries(Crymium PUBLIC "../libcef_dll_wrapper/Debug/libcef_dll_wrapper")