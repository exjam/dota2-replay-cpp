import qbs

StaticLibrary {
   name: "libutil"

   Depends {
      name: "cpp"
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

   Export {
      Depends { name: "cpp" }
      cpp.includePaths: ["."]
   }
}
