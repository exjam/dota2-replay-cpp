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
        "gameevent.cpp",
        "gameevent.h",
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
         "*.cc",
         "*.h"
      ]
   }
}
