import qbs

StaticLibrary {
   name: "libdota"

   Depends {
      name: "cpp"
   }

   Depends {
      name: "libprotobuf"
   }

   Depends {
      name: "libsnappy"
   }

   Depends {
      name: "libutil"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "lib"
      qbs.install: true
   }

   files: [
      "*.cpp",
      "*.h"
   ]

   Group {
      name: "proto"
      prefix: "proto/"
      files: [
         "*.cc",
         "*.h"
      ]
   }

   Export {
      Depends { name: "cpp" }
      cpp.includePaths: ["."]
   }
}
