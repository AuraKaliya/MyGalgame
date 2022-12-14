#############################################################################
# Makefile for building: Galgane3
# Generated by qmake (3.1) (Qt 5.9.9)
# Project:  Galgane3.pro
# Template: app
# Command: E:\QT\QTEXE\5.9.9\msvc2015\bin\qmake.exe -o Makefile Galgane3.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = E:\QT\QTEXE\5.9.9\msvc2015\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = E:\QT\QTEXE\5.9.9\msvc2015\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = E:\QT\QTEXE\5.9.9\msvc2015\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: Galgane3.pro ..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\win32-msvc\qmake.conf ..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\spec_pre.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\common\angle.conf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\common\msvc-desktop.conf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\qconfig.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3danimation.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3danimation_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dcore.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dcore_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dextras.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dextras_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dinput.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dinput_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dlogic.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dlogic_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquick.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquick_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3drender.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3drender_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_accessibility_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axbase.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axserver.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_charts.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_charts_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_core.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_core_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_datavisualization.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_datavisualization_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_dbus.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_dbus_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_designer.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_devicediscovery_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_egl_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_fb_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_fontdatabase_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gamepad.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gamepad_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gui.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_help.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_help_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_location.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_location_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_network.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_network_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_networkauth.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_networkauth_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_nfc.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_opengl.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_packetprotocol_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_platformcompositor_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_positioning.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_purchasing.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_purchasing_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qml.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmldebug_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quick.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quicktemplates2_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_scxml.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_scxml_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sensors.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialbus.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialbus_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialport.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sql.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_svg.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_testlib.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_theme_support_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_uiplugin.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_uitools.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webengine.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webengine_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginecore.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginecore_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_websockets.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webview.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webview_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_widgets.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_winextras.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xml.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_zlib_private.pri \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qt_functions.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qt_config.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\win32-msvc\qmake.conf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\spec_post.prf \
		.qmake.stash \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\exclusive_builds.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\common\msvc-version.conf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\toolchain.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\default_pre.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\default_pre.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\resolve_config.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\exclusive_builds_post.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\default_post.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qt.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\resources.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\moc.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\opengl.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\uic.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\dumpcpp.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qml_debug.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\precompile_header.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\warn_on.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qmake_use.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\file_copies.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\windows.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\testcase_targets.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\exceptions.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\yacc.prf \
		..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\lex.prf \
		Galgane3.pro \
		..\..\QT\QTEXE\5.9.9\msvc2015\lib\qtmaind.prl \
		..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5AxContainer.prl \
		..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5AxBase.prl \
		..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5Widgets.prl \
		..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5Gui.prl \
		..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5Core.prl
	$(QMAKE) -o Makefile Galgane3.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\spec_pre.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\common\angle.conf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\common\msvc-desktop.conf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\qconfig.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3danimation.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3danimation_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dcore.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dcore_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dextras.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dextras_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dinput.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dinput_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dlogic.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dlogic_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquick.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquick_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickanimation_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickextras_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickinput_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickrender_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3dquickscene2d_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3drender.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_3drender_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_accessibility_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axbase.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axserver.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_charts.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_charts_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_concurrent.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_core.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_core_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_datavisualization.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_datavisualization_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_dbus.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_dbus_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_designer.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_designer_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_devicediscovery_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_egl_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_fb_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_fontdatabase_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gamepad.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gamepad_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gui.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_gui_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_help.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_help_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_location.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_location_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimedia.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_network.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_network_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_networkauth.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_networkauth_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_nfc.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_opengl.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_packetprotocol_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_platformcompositor_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_positioning.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_printsupport.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_purchasing.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_purchasing_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qml.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qml_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmldebug_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmltest.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quick.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quick_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickcontrols2_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quicktemplates2_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_scxml.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_scxml_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sensors.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialbus.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialbus_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialport.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sql.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_sql_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_svg.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_svg_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_testlib.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_theme_support_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_uiplugin.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_uitools.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webchannel.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webengine.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webengine_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginecore.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginecore_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_websockets.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webview.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_webview_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_widgets.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_winextras.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xml.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xml_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\modules\qt_lib_zlib_private.pri:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qt_functions.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qt_config.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\win32-msvc\qmake.conf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\spec_post.prf:
.qmake.stash:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\exclusive_builds.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\common\msvc-version.conf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\toolchain.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\default_pre.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\default_pre.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\resolve_config.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\exclusive_builds_post.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\default_post.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qt.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\resources.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\moc.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\opengl.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\uic.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\dumpcpp.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qml_debug.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\precompile_header.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\warn_on.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\qmake_use.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\file_copies.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\win32\windows.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\testcase_targets.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\exceptions.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\yacc.prf:
..\..\QT\QTEXE\5.9.9\msvc2015\mkspecs\features\lex.prf:
Galgane3.pro:
..\..\QT\QTEXE\5.9.9\msvc2015\lib\qtmaind.prl:
..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5AxContainer.prl:
..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5AxBase.prl:
..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5Widgets.prl:
..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5Gui.prl:
..\..\QT\QTEXE\5.9.9\msvc2015\lib\Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile Galgane3.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
	-$(DEL_FILE) Galgane3.exp
	-$(DEL_FILE) Galgane3.vc.pdb
	-$(DEL_FILE) Galgane3.ilk
	-$(DEL_FILE) Galgane3.idb
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash Galgane3.lib Galgane3.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
