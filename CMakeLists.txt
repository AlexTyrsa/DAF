cmake_minimum_required(VERSION 3.16)

project(DAF VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appDAF
    main.cpp
    data/QDataI.h
    data/QDataI.cpp
    data/QDataDevicesI.h
    data/QDataDevicesI.cpp
    data/QDataDAF.h
    data/QDataDAF.cpp
    data/QDataDevicesDAF.h
    data/QDataDevicesDAF.cpp
    sample_processor/QSampleProcessor.h
    sample_processor/QSampleProcessor.cpp
    circular_iterator/circular_iterator.h
    circular_iterator/private/circular_iterator_type.h
    circular_iterator/private/circular_iterator_data.h
    circular_iterator/private/circular_iterator_impl.h
    view/QViewI.h
    view/QViewI.cpp
    view/QViewDevicesI.h
    view/QViewDevicesI.cpp
    view/audio/QViewAudio.h
    view/audio/QViewAudio.cpp
    view/audio/QViewRecorder.h
    view/audio/QViewRecorder.cpp
    view/audio/QViewPlayer.h
    view/audio/QViewPlayer.cpp
    view/audio/QViewMediaDevices.h
    view/audio/QViewMediaDevices.cpp
)

qt_add_qml_module(appDAF
    URI DAF
    VERSION 1.0
    QML_FILES main.qml
              view/QCViewItem.qml
              view/QCViewDevicesItem.qml
)

set_target_properties(appDAF PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appDAF PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)
target_link_libraries(appDAF
    PRIVATE Qt6::Quick
            Qt6::Multimedia
)
