# for things that are also used by kwin libraries
configure_file(libkwineffects/kwinconfig.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/libkwineffects/kwinconfig.h)
configure_file(config-kwin.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-kwin.h)

set(kwin_effects_dbus_xml ${CMAKE_CURRENT_SOURCE_DIR}/org.kde.kwin.Effects.xml)
qt5_add_dbus_interface(effects_interface_SRCS ${kwin_effects_dbus_xml} kwineffects_interface)
add_library(KWinEffectsInterface STATIC ${effects_interface_SRCS})
target_link_libraries(KWinEffectsInterface Qt::DBus)

add_subdirectory(effects)
add_subdirectory(scripts)
add_subdirectory(tabbox)
add_subdirectory(scripting)
add_subdirectory(helpers)
add_subdirectory(qml)

add_subdirectory(libkwineffects)
if (KWIN_BUILD_KCMS)
    add_subdirectory(kcmkwin)
endif()

set(kwin_SRCS
    3rdparty/xcursor.c
    abstract_client.cpp
    abstract_opengl_context_attribute_builder.cpp
    abstract_output.cpp
    abstract_wayland_output.cpp
    activation.cpp
    appmenu.cpp
    atoms.cpp
    client_machine.cpp
    composite.cpp
    cursor.cpp
    dbusinterface.cpp
    debug_console.cpp
    decorations/decoratedclient.cpp
    decorations/decorationbridge.cpp
    decorations/decorationpalette.cpp
    decorations/decorationrenderer.cpp
    decorations/decorations_logging.cpp
    decorations/settings.cpp
    deleted.cpp
    dmabuftexture.cpp
    effectloader.cpp
    effects.cpp
    egl_context_attribute_builder.cpp
    events.cpp
    focuschain.cpp
    ftrace.cpp
    geometrytip.cpp
    gestures.cpp
    globalshortcuts.cpp
    group.cpp
    idle_inhibition.cpp
    input.cpp
    input_event.cpp
    input_event_spy.cpp
    inputmethod.cpp
    inputpanelv1client.cpp
    inputpanelv1integration.cpp
    internal_client.cpp
    keyboard_input.cpp
    keyboard_layout.cpp
    keyboard_layout_switching.cpp
    keyboard_repeat.cpp
    killwindow.cpp
    layers.cpp
    layershellv1client.cpp
    layershellv1integration.cpp
    libinput/connection.cpp
    libinput/context.cpp
    libinput/device.cpp
    libinput/events.cpp
    libinput/libinput_logging.cpp
    linux_dmabuf.cpp
    logind.cpp
    main.cpp
    modifier_only_shortcuts.cpp
    moving_client_x11_filter.cpp
    netinfo.cpp
    onscreennotification.cpp
    options.cpp
    osd.cpp
    outline.cpp
    overlaywindow.cpp
    placement.cpp
    platform.cpp
    plugin.cpp
    pluginmanager.cpp
    pointer_input.cpp
    popup_input_filter.cpp
    renderjournal.cpp
    renderloop.cpp
    rootinfo_filter.cpp
    rulebooksettings.cpp
    rules.cpp
    scene.cpp
    screenedge.cpp
    screenlockerwatcher.cpp
    screens.cpp
    scripting/dbuscall.cpp
    scripting/meta.cpp
    scripting/screenedgeitem.cpp
    scripting/scriptedeffect.cpp
    scripting/scripting.cpp
    scripting/scripting_logging.cpp
    scripting/scripting_model.cpp
    scripting/scriptingutils.cpp
    scripting/timer.cpp
    scripting/workspace_wrapper.cpp
    shadow.cpp
    sm.cpp
    subsurfacemonitor.cpp
    syncalarmx11filter.cpp
    tablet_input.cpp
    thumbnailitem.cpp
    toplevel.cpp
    touch_hide_cursor_spy.cpp
    touch_input.cpp
    udev.cpp
    unmanaged.cpp
    useractions.cpp
    utils.cpp
    virtualdesktops.cpp
    virtualdesktopsdbustypes.cpp
    virtualkeyboard_dbus.cpp
    was_user_interaction_x11_filter.cpp
    wayland_server.cpp
    waylandclient.cpp
    waylandshellintegration.cpp
    window_property_notify_x11_filter.cpp
    workspace.cpp
    x11client.cpp
    x11eventfilter.cpp
    xcbutils.cpp
    xcursortheme.cpp
    xdgshellclient.cpp
    xdgshellintegration.cpp
    xkb.cpp
    xwaylandclient.cpp
    xwl/xwayland_interface.cpp
)

if (HAVE_LINUX_VT_H)
    set(kwin_SRCS ${kwin_SRCS}
        virtual_terminal.cpp
    )
    set(KWIN_TTY_PREFIX "/dev/tty")
endif()

if(CMAKE_SYSTEM MATCHES "FreeBSD")
    # We know it has epoll, so supports VT as well
    set(kwin_SRCS ${kwin_SRCS}
        virtual_terminal.cpp
    )
    set(KWIN_TTY_PREFIX "/dev/ttyv")
endif()
if(KWIN_TTY_PREFIX)
    set_source_files_properties(virtual_terminal.cpp PROPERTIES COMPILE_DEFINITIONS KWIN_TTY_PREFIX="${KWIN_TTY_PREFIX}")
endif()

kconfig_add_kcfg_files(kwin_SRCS settings.kcfgc)
kconfig_add_kcfg_files(kwin_SRCS rulesettings.kcfgc)
kconfig_add_kcfg_files(kwin_SRCS rulebooksettingsbase.kcfgc)

qt5_add_dbus_adaptor(kwin_SRCS org.kde.KWin.xml dbusinterface.h KWin::DBusInterface)
qt5_add_dbus_adaptor(kwin_SRCS org.kde.kwin.Compositing.xml dbusinterface.h KWin::CompositorDBusInterface)
qt5_add_dbus_adaptor(kwin_SRCS ${kwin_effects_dbus_xml} effects.h KWin::EffectsHandlerImpl)
qt5_add_dbus_adaptor(kwin_SRCS org.kde.KWin.VirtualDesktopManager.xml dbusinterface.h KWin::VirtualDesktopManagerDBusInterface)
qt5_add_dbus_adaptor(kwin_SRCS org.kde.KWin.Session.xml sm.h KWin::SessionManager)
qt5_add_dbus_adaptor(kwin_SRCS org.kde.KWin.Plugins.xml dbusinterface.h KWin::PluginManagerDBusInterface)

qt5_add_dbus_interface(kwin_SRCS ${KSCREENLOCKER_DBUS_INTERFACES_DIR}/kf5_org.freedesktop.ScreenSaver.xml screenlocker_interface)
qt5_add_dbus_interface(kwin_SRCS ${KSCREENLOCKER_DBUS_INTERFACES_DIR}/org.kde.screensaver.xml kscreenlocker_interface)
qt5_add_dbus_interface(kwin_SRCS org.kde.kappmenu.xml appmenu_interface)

ki18n_wrap_ui(kwin_SRCS
    debug_console.ui
    shortcutdialog.ui
)

add_library(kwin SHARED ${kwin_SRCS})
if (Libinput_VERSION_STRING VERSION_GREATER 1.14)
    set_source_files_properties(libinput/connection.cpp PROPERTIES COMPILE_DEFINITIONS LIBINPUT_HAS_TOTEM)
endif ()

set_target_properties(kwin PROPERTIES
   VERSION ${PROJECT_VERSION}
   SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_link_libraries(kwin
    kwin4_effect_builtins
    kwineffects
    kwinglutils

    Qt::Concurrent
    Qt::DBus
    Qt::Quick
    Qt::Script

    KF5::ConfigCore
    KF5::ConfigWidgets
    KF5::CoreAddons
    KF5::GlobalAccel
    KF5::GlobalAccelPrivate
    KF5::I18n
    KF5::Notifications
    KF5::Package
    KF5::Plasma
    KF5::QuickAddons
    KF5::WaylandClient
    KF5::WindowSystem

    KDecoration2::KDecoration
    KDecoration2::KDecoration2Private

    PW::KScreenLocker
    Plasma::KWaylandServer

    XCB::COMPOSITE
    XCB::DAMAGE
    XCB::GLX
    XCB::ICCCM
    XCB::KEYSYMS
    XCB::RANDR
    XCB::RENDER
    XCB::SHAPE
    XCB::SHM
    XCB::SYNC
    XCB::XCB
    XCB::XFIXES

    Libinput::Libinput
    UDev::UDev
    XKB::XKB
    epoxy::epoxy

    ${CMAKE_THREAD_LIBS_INIT}
)

if (KWIN_BUILD_CMS)
    target_sources(kwin PRIVATE
        colordevice.cpp
        colormanager.cpp
    )
    target_link_libraries(kwin lcms2::lcms2)
endif()

if (KWIN_BUILD_ACTIVITIES)
    target_sources(kwin PRIVATE activities.cpp)
    target_link_libraries(kwin KF5::Activities)
endif()

if (KWIN_BUILD_TABBOX)
    target_sources(kwin PRIVATE
        tabbox/clientmodel.cpp
        tabbox/desktopchain.cpp
        tabbox/desktopmodel.cpp
        tabbox/switcheritem.cpp
        tabbox/tabbox.cpp
        tabbox/tabbox_logging.cpp
        tabbox/tabboxconfig.cpp
        tabbox/tabboxhandler.cpp
        tabbox/x11_filter.cpp
    )
    target_link_libraries(kwin Qt::GuiPrivate)
endif()

generate_export_header(kwin EXPORT_FILE_NAME kwin_export.h)

if(CMAKE_SYSTEM MATCHES "FreeBSD")
    # epoll is required, includes live under ${LOCALBASE}, separate library
    target_include_directories(kwin PUBLIC ${epoll_INCLUDE_DIRS})
    target_link_libraries(kwin ${epoll_LIBRARIES})
endif()

add_executable(kwin_x11 main_x11.cpp)
target_link_libraries(kwin_x11 kwin KF5::Crash Qt::X11Extras)

install(TARGETS kwin ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} LIBRARY NAMELINK_SKIP)
install(TARGETS kwin_x11 ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

ecm_qt_declare_logging_category(xwaylandlogging_SOURCES
    HEADER
        xwayland_logging.h
    IDENTIFIER
        KWIN_XWL
    CATEGORY_NAME
        kwin_xwl
    DEFAULT_SEVERITY
        Warning
)
add_library(KWinXwaylandServerModule OBJECT
    xwl/clipboard.cpp
    xwl/databridge.cpp
    xwl/dnd.cpp
    xwl/drag.cpp
    xwl/drag_wl.cpp
    xwl/drag_x.cpp
    xwl/selection.cpp
    xwl/selection_source.cpp
    xwl/transfer.cpp
    xwl/xwayland.cpp

    ${xwaylandlogging_SOURCES}
)
target_link_libraries(KWinXwaylandServerModule PUBLIC kwin)

add_executable(kwin_wayland
    main_wayland.cpp
    tabletmodemanager.cpp
)
target_link_libraries(kwin_wayland
    kwin
    KF5::Crash
    KWinXwaylandServerModule
)
if (HAVE_LIBCAP)
    target_link_libraries(kwin_wayland ${Libcap_LIBRARIES})
endif()

install(TARGETS kwin_wayland ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
if (HAVE_LIBCAP)
    install(
    CODE "execute_process(
            COMMAND
                ${SETCAP_EXECUTABLE}
                CAP_SYS_NICE=+ep
                \$ENV{DESTDIR}${CMAKE_INSTALL_FULL_BINDIR}/kwin_wayland)"
    )
endif()

add_subdirectory(platformsupport)
add_subdirectory(plugins)

target_link_libraries(kwin_wayland
    KWinQpaPlugin
    KF5GlobalAccelKWinPlugin
    KF5WindowSystemKWinPlugin
    KF5IdleTimeKWinPlugin
)

if (PipeWire_FOUND)
    target_link_libraries(kwin_wayland KWinScreencastPlugin)
endif()

install(FILES kwin.kcfg DESTINATION ${KDE_INSTALL_KCFGDIR} RENAME ${KWIN_NAME}.kcfg)
install(FILES kwin.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFY5RCDIR} RENAME ${KWIN_NAME}.notifyrc)
install(
    FILES
        org.kde.KWin.VirtualDesktopManager.xml
        org.kde.KWin.xml
        org.kde.kwin.Compositing.xml
        org.kde.kwin.Effects.xml
        org.kde.KWin.Plugins.xml
    DESTINATION
        ${KDE_INSTALL_DBUSINTERFACEDIR}
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/kwin_export.h DESTINATION ${KDE_INSTALL_INCLUDEDIR} COMPONENT Devel)

# Install the KWin/Script service type
install(FILES scripting/kwinscript.desktop DESTINATION ${KDE_INSTALL_KSERVICETYPES5DIR})