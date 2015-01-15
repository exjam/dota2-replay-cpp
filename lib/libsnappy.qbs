import qbs

StaticLibrary {
   name: "libsnappy"

   Depends {
      name: "cpp"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "lib"
      qbs.install: true
   }

   Export {
      Depends { name: "cpp" }
      cpp.includePaths: ["snappy/", "."]
   }

   cpp.includePaths: [
      "."
   ]

   cpp.defines: {
      var paths = [ "SNAPPY_EXPORTS" ];

      if (qbs.targetOS.contains("windows")) {
         paths.push("HAVE_WINDOWS_H");
         paths.push("WIN32");
      }

      if (qbs.architecture.contains("x86_64")) {
         paths.push("__x86_64__");
      }

      return paths;
   }

   files: [
      "snappy/snappy-c.cc",
      "snappy/snappy-c.h",
      "snappy/snappy-internal.h",
      "snappy/snappy-sinksource.cc",
      "snappy/snappy-sinksource.h",
      "snappy/snappy-stubs-internal.cc",
      "snappy/snappy-stubs-internal.h",
      "snappy/snappy.cc",
      "snappy/snappy.h",
      "snappy-stubs-public.h"
   ]
}

