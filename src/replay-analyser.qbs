import qbs

CppApplication {
   name: "replay-analyser"
   type: "application"
   consoleApplication: true

   Depends {
      name: "libprotobuf"
   }

   Depends {
      name: "libsnappy"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "bin"
      qbs.install: true
   }

   cpp.includePaths: [
      "../lib",
      "../lib/snappy",
      "../lib/protobuf/src"
   ]

   files: [
      "main.cpp",
      "bitstream.h",
      "binarystream.h"
   ]

   Group {
      name: "proto"
      prefix: "proto/"
      files: [
         "ai_activity.pb.cc",
         "demo.pb.cc",
         "dota_commonmessages.pb.cc",
         "dota_modifiers.pb.cc",
         "dota_usermessages.pb.cc",
         "netmessages.pb.cc",
         "network_connection.pb.cc",
         "networkbasetypes.pb.cc",
         "usermessages.pb.cc"
      ]
   }
}
