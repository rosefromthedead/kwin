add_definitions(-DKWIN_UNIT_TEST)
remove_definitions(-DQT_USE_QSTRINGBUILDER)
add_subdirectory(libkwineffects)
add_subdirectory(libxrenderutils)
add_subdirectory(integration)
add_subdirectory(libinput)
add_subdirectory(tabbox)

########################################################
# Test ScreenPaintData
########################################################
set(testScreenPaintData_SRCS test_screen_paint_data.cpp)
add_executable(testScreenPaintData ${testScreenPaintData_SRCS})
target_link_libraries(testScreenPaintData kwineffects Qt::Test Qt::Widgets KF5::WindowSystem)
add_test(NAME kwin-testScreenPaintData COMMAND testScreenPaintData)
ecm_mark_as_test(testScreenPaintData)

########################################################
# Test WindowPaintData
########################################################
set(testWindowPaintData_SRCS test_window_paint_data.cpp)
add_executable(testWindowPaintData ${testWindowPaintData_SRCS})
target_link_libraries(testWindowPaintData kwineffects Qt::Widgets Qt::Test )
add_test(NAME kwin-testWindowPaintData COMMAND testWindowPaintData)
ecm_mark_as_test(testWindowPaintData)

########################################################
# Test VirtualDesktopManager
########################################################
set(testVirtualDesktops_SRCS
    ../src/virtualdesktops.cpp
    test_virtual_desktops.cpp
)
add_executable(testVirtualDesktops ${testVirtualDesktops_SRCS})

target_link_libraries(testVirtualDesktops
    Qt::Test
    Qt::Widgets

    KF5::ConfigCore
    KF5::GlobalAccel
    KF5::I18n
    Plasma::KWaylandServer
    KF5::WindowSystem
)
add_test(NAME kwin-testVirtualDesktops COMMAND testVirtualDesktops)
ecm_mark_as_test(testVirtualDesktops)

########################################################
# Test ClientMachine
########################################################
set(testClientMachine_SRCS
    ../src/client_machine.cpp
    test_client_machine.cpp
)
add_executable(testClientMachine ${testClientMachine_SRCS})
set_target_properties(testClientMachine PROPERTIES COMPILE_DEFINITIONS "NO_NONE_WINDOW")

target_link_libraries(testClientMachine
    Qt::Concurrent
    Qt::Test
    Qt::Widgets
    Qt::X11Extras

    KF5::ConfigCore
    KF5::WindowSystem

    XCB::XCB
    XCB::XFIXES

    ${X11_X11_LIB} # to make jenkins happy
)
add_test(NAME kwin-testClientMachine COMMAND testClientMachine)
ecm_mark_as_test(testClientMachine)

########################################################
# Test XcbWrapper
########################################################
set(testXcbWrapper_SRCS
    test_xcb_wrapper.cpp
)
add_executable(testXcbWrapper ${testXcbWrapper_SRCS})

target_link_libraries(testXcbWrapper
    Qt::Test
    Qt::Widgets
    Qt::X11Extras

    KF5::ConfigCore
    KF5::WindowSystem

    XCB::XCB
)
add_test(NAME kwin-testXcbWrapper COMMAND testXcbWrapper)
ecm_mark_as_test(testXcbWrapper)

if (XCB_ICCCM_FOUND)
    add_executable(testXcbSizeHints test_xcb_size_hints.cpp)
    set_target_properties(testXcbSizeHints PROPERTIES COMPILE_DEFINITIONS "NO_NONE_WINDOW")
    target_link_libraries(testXcbSizeHints
        Qt::Test
        Qt::Widgets
        Qt::X11Extras

        KF5::ConfigCore
        KF5::WindowSystem

        XCB::ICCCM
        XCB::XCB
    )
    add_test(NAME kwin-testXcbSizeHints COMMAND testXcbSizeHints)
    ecm_mark_as_test(testXcbSizeHints)
endif()

########################################################
# Test XcbWindow
########################################################
set(testXcbWindow_SRCS
    test_xcb_window.cpp
)
add_executable(testXcbWindow ${testXcbWindow_SRCS})

target_link_libraries(testXcbWindow
    Qt::Test
    Qt::Widgets
    Qt::X11Extras

    KF5::ConfigCore
    KF5::WindowSystem

    XCB::XCB
)
add_test(NAME kwin-testXcbWindow COMMAND testXcbWindow)
ecm_mark_as_test(testXcbWindow)

########################################################
# Test BuiltInEffectLoader
########################################################
set(testBuiltInEffectLoader_SRCS
    ../src/effectloader.cpp
    mock_effectshandler.cpp
    test_builtin_effectloader.cpp
)
add_executable(testBuiltInEffectLoader ${testBuiltInEffectLoader_SRCS})
set_target_properties(testBuiltInEffectLoader PROPERTIES COMPILE_DEFINITIONS "NO_NONE_WINDOW")

target_link_libraries(testBuiltInEffectLoader
    Qt::Concurrent
    Qt::Qml
    Qt::Test
    Qt::X11Extras

    KF5::Package

    kwineffects
    kwin4_effect_builtins
)

add_test(NAME kwin-testBuiltInEffectLoader COMMAND testBuiltInEffectLoader)
ecm_mark_as_test(testBuiltInEffectLoader)

########################################################
# Test ScriptedEffectLoader
########################################################
include_directories(${KWin_SOURCE_DIR}/src)
set(testScriptedEffectLoader_SRCS
    ../src/effectloader.cpp
    ../src/cursor.cpp
    ../src/screens.cpp
    ../src/scripting/scriptedeffect.cpp
    ../src/scripting/scripting_logging.cpp
    ../src/scripting/scriptingutils.cpp
    mock_abstract_client.cpp
    mock_effectshandler.cpp
    mock_workspace.cpp
    test_scripted_effectloader.cpp
)
kconfig_add_kcfg_files(testScriptedEffectLoader_SRCS ../src/settings.kcfgc)
add_executable(testScriptedEffectLoader ${testScriptedEffectLoader_SRCS})

target_link_libraries(testScriptedEffectLoader
    Qt::Concurrent
    Qt::Qml
    Qt::Test
    Qt::X11Extras

    KF5::ConfigGui
    KF5::GlobalAccel
    KF5::I18n
    KF5::Notifications
    KF5::Package

    XCB::CURSOR

    kwineffects
    kwin4_effect_builtins
)

add_test(NAME kwin-testScriptedEffectLoader COMMAND testScriptedEffectLoader)
ecm_mark_as_test(testScriptedEffectLoader)

########################################################
# Test PluginEffectLoader
########################################################
set(testPluginEffectLoader_SRCS
    ../src/effectloader.cpp
    mock_effectshandler.cpp
    test_plugin_effectloader.cpp
)
add_executable(testPluginEffectLoader ${testPluginEffectLoader_SRCS})

target_link_libraries(testPluginEffectLoader
    Qt::Concurrent
    Qt::Qml
    Qt::Test
    Qt::X11Extras

    KF5::Package

    kwineffects
    kwin4_effect_builtins
)

add_test(NAME kwin-testPluginEffectLoader COMMAND testPluginEffectLoader)
ecm_mark_as_test(testPluginEffectLoader)

########################################################
# FakeEffectPlugin
########################################################
add_library(fakeeffectplugin MODULE fakeeffectplugin.cpp)
set_target_properties(fakeeffectplugin PROPERTIES PREFIX "")
target_link_libraries(fakeeffectplugin kwineffects)

########################################################
# FakeEffectPlugin-Version
########################################################
add_library(effectversionplugin MODULE fakeeffectplugin_version.cpp)
set_target_properties(effectversionplugin PROPERTIES PREFIX "")
target_link_libraries(effectversionplugin kwineffects)

########################################################
# Test OnScreenNotification
########################################################
set(testOnScreenNotification_SRCS
    ../src/input_event_spy.cpp
    ../src/onscreennotification.cpp
    onscreennotificationtest.cpp
)
add_executable(testOnScreenNotification ${testOnScreenNotification_SRCS})

target_link_libraries(testOnScreenNotification
    Qt::DBus
    Qt::Quick
    Qt::Test
    Qt::Widgets # QAction include

    KF5::ConfigCore
)

add_test(NAME kwin-testOnScreenNotification COMMAND testOnScreenNotification)
ecm_mark_as_test(testOnScreenNotification)

########################################################
# Test Gestures
########################################################
set(testGestures_SRCS
    ../src/gestures.cpp
    test_gestures.cpp
)
add_executable(testGestures ${testGestures_SRCS})

target_link_libraries(testGestures
    Qt::Test
)

add_test(NAME kwin-testGestures COMMAND testGestures)
ecm_mark_as_test(testGestures)

########################################################
# Test X11 TimestampUpdate
########################################################
add_executable(testX11TimestampUpdate test_x11_timestamp_update.cpp)
target_link_libraries(testX11TimestampUpdate
    KF5::CoreAddons
    Qt::Test
    kwin
)
add_test(NAME kwin-testX11TimestampUpdate COMMAND testX11TimestampUpdate)
ecm_mark_as_test(testX11TimestampUpdate)

set(testOpenGLContextAttributeBuilder_SRCS
    ../src/abstract_opengl_context_attribute_builder.cpp
    ../src/egl_context_attribute_builder.cpp
    opengl_context_attribute_builder_test.cpp
)

if (HAVE_EPOXY_GLX)
    set(testOpenGLContextAttributeBuilder_SRCS ${testOpenGLContextAttributeBuilder_SRCS} ../src/plugins/platforms/x11/standalone/glx_context_attribute_builder.cpp)
endif()
add_executable(testOpenGLContextAttributeBuilder ${testOpenGLContextAttributeBuilder_SRCS})
target_link_libraries(testOpenGLContextAttributeBuilder Qt::Test)
add_test(NAME kwin-testOpenGLContextAttributeBuilder COMMAND testOpenGLContextAttributeBuilder)
ecm_mark_as_test(testOpenGLContextAttributeBuilder)

set(testXkb_SRCS
    ../src/xkb.cpp
    test_xkb.cpp
)
add_executable(testXkb ${testXkb_SRCS})
target_link_libraries(testXkb
    Qt::Gui
    Qt::Test
    Qt::Widgets

    KF5::ConfigCore
    Plasma::KWaylandServer
    KF5::WindowSystem

    XKB::XKB
    Qt5::XkbCommonSupportPrivate
)
add_test(NAME kwin-testXkb COMMAND testXkb)
ecm_mark_as_test(testXkb)

########################################################
# Test FTrace
########################################################
add_executable(testFtrace test_ftrace.cpp)
target_link_libraries(testFtrace
    Qt::Test
    kwin
)
add_test(NAME kwin-testFtrace COMMAND testFtrace)
ecm_mark_as_test(testFtrace)
