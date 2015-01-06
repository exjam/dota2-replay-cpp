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
        "bitstream.cpp",
        "demoparser.cpp",
        "demoparser.h",
        "entity.cpp",
        "entity.h",
        "main.cpp",
        "bitstream.h",
        "binarystream.h",
        "messages.cpp",
        "property.h",
        "propertyvariant.cpp",
        "propertyvariant.h",
        "receivetable.h",
        "sendtable.cpp",
        "sendtable.h",
        "stringtable.cpp",
        "stringtable.h",
        "util.cpp",
        "util.h",
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
