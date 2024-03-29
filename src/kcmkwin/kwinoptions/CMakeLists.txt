########### next target ###############
# KI18N Translation Domain for this library
add_definitions(-DTRANSLATION_DOMAIN=\"kcmkwm\")

set(kcm_kwinoptions_PART_SRCS
    ${KWin_SOURCE_DIR}/src/effects/effect_builtins.cpp
    main.cpp
    mouse.cpp
    windows.cpp
)

ki18n_wrap_ui(kcm_kwinoptions_PART_SRCS
    actions.ui
    advanced.ui
    focus.ui
    mouse.ui
    moving.ui
)

kcmutils_generate_module_data(
    kcm_kwinoptions_PART_SRCS
    MODULE_DATA_HEADER kwinoptionsdata.h
    MODULE_DATA_CLASS_NAME KWinOptionsData
    SETTINGS_HEADERS kwinoptions_settings.h kwinoptions_kdeglobals_settings.h
    SETTINGS_CLASSES KWinOptionsSettings KWinOptionsKDEGlobalsSettings
)

kconfig_add_kcfg_files(kcm_kwinoptions_PART_SRCS kwinoptions_settings.kcfgc GENERATE_MOC)
kconfig_add_kcfg_files(kcm_kwinoptions_PART_SRCS kwinoptions_kdeglobals_settings.kcfgc GENERATE_MOC)

qt_add_dbus_interface(kcm_kwinoptions_PART_SRCS ${KWin_SOURCE_DIR}/src/org.kde.kwin.Effects.xml kwin_effects_interface)
add_library(kcm_kwinoptions MODULE ${kcm_kwinoptions_PART_SRCS})
target_link_libraries(kcm_kwinoptions kwin Qt::DBus KF5::KCMUtils KF5::Completion KF5::I18n KF5::ConfigWidgets KF5::Service KF5::WindowSystem)
install(TARGETS kcm_kwinoptions DESTINATION ${KDE_INSTALL_PLUGINDIR})

########### install files ###############

install(
    FILES
        kwinoptions.desktop
    DESTINATION
        ${KDE_INSTALL_KSERVICES5DIR}
)
