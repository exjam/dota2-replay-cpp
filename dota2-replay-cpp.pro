TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH = \
   $$PWD/lib/protobuf/pkg/include \
   $$PWD/lib/snappy/pkg/include

LIBS = \
   -L$$PWD/lib/protobuf/pkg/lib -lprotobuf \
   -L$$PWD/lib/snappy/pkg/lib -lsnappy

SOURCES += \
   main.cpp \
   proto/cpp/ai_activity.pb.cc \
   proto/cpp/demo.pb.cc \
   proto/cpp/dota_commonmessages.pb.cc \
   proto/cpp/dota_modifiers.pb.cc \
   proto/cpp/dota_usermessages.pb.cc \
   proto/cpp/netmessages.pb.cc \
   proto/cpp/network_connection.pb.cc \
   proto/cpp/networkbasetypes.pb.cc \
   proto/cpp/usermessages.pb.cc

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
   proto/cpp/ai_activity.pb.h \
   proto/cpp/demo.pb.h \
   proto/cpp/dota_commonmessages.pb.h \
   proto/cpp/dota_modifiers.pb.h \
   proto/cpp/dota_usermessages.pb.h \
   proto/cpp/netmessages.pb.h \
   proto/cpp/network_connection.pb.h \
   proto/cpp/networkbasetypes.pb.h \
   proto/cpp/usermessages.pb.h \
   binarystream.h \
   bitstream.h
