set(SUBPROCESS_RENDERER_SRCS
  renderer/ClientRenderDelegate.cpp
  renderer/ClientRenderDelegate.h
  renderer/IDelegate.h
  renderer/IDelegateCollection.h
  renderer/DelegateCollection.h
  renderer/DelegateCollection.cpp
  renderer/V8Handler.cpp
  renderer/V8Handler.h
  renderer/ClientAppRenderer.cpp
  renderer/ClientAppRenderer.h
  )
source_group(Crymium.SubProcess\\\\renderer FILES ${SUBPROCESS_RENDERER_SRCS})

set(SUBPROCESS_WINDOWS_SRCS
  SubProcess.cpp
  )
source_group(Crymium.SubProcess FILES ${SUBPROCESS_WINDOWS_SRCS})

set(SUBPROCESS_WINDOWS_SRCS
  ${SUBPROCESS_WINDOWS_SRCS}
  )

set(CEF_TARGET "Crymium.SubProcess")
ADD_LOGICAL_TARGET("libcef_lib" "${CEF_LIB_DEBUG}" "${CEF_LIB_RELEASE}")

SET_CEF_TARGET_OUT_DIR()

  set(SUBPROCESS_SRCS
    ${SUBPROCESS_RENDERER_SRCS}
    ${SUBPROCESS_WINDOWS_SRCS}
    )

  add_executable(${CEF_TARGET} WIN32 ${SUBPROCESS_SRCS})
  SET_EXECUTABLE_TARGET_PROPERTIES(${CEF_TARGET})
  add_dependencies(${CEF_TARGET} libcef_dll_wrapper)
  target_link_libraries(${CEF_TARGET} libcef_lib libcef_dll_wrapper ${CEF_STANDARD_LIBS} d3d11.lib glu32.lib imm32.lib opengl32.lib)

  if(USE_ATL)
    target_link_libraries(${CEF_TARGET} oleacc.lib)
  endif()

  if(USE_SANDBOX)
    ADD_LOGICAL_TARGET("cef_sandbox_lib" "${CEF_SANDBOX_LIB_DEBUG}" "${CEF_SANDBOX_LIB_RELEASE}")
    target_link_libraries(${CEF_TARGET} cef_sandbox_lib ${CEF_SANDBOX_STANDARD_LIBS})
  endif()

  ADD_WINDOWS_MANIFEST("${CMAKE_CURRENT_SOURCE_DIR}/resources/win" "${CEF_TARGET}" "exe")

  COPY_FILES("${CEF_TARGET}" "${CEF_BINARY_FILES}" "${CEF_BINARY_DIR}" "${CEF_TARGET_OUT_DIR}")
  COPY_FILES("${CEF_TARGET}" "${CEF_RESOURCE_FILES}" "${CEF_RESOURCE_DIR}" "${CEF_TARGET_OUT_DIR}")

  set_target_properties(Crymium.SubProcess PROPERTIES
            CXX_STANDARD 17
            )