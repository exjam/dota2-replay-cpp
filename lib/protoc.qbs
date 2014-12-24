import qbs

CppApplication {
   name: "protoc"
   type: "application"
   consoleApplication: true

   Depends {
      name: "libprotoc"
   }

   Depends {
      name: "libprotobuf"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "bin"
      qbs.install: true
   }

   cpp.includePaths: {
      var paths = [ "protobuf/src" ];

      if (qbs.targetOS.contains("windows")) {
         paths.push("protobuf/vsprojects");
      }

      return paths;
   }

   files: [
      "protobuf/src/google/protobuf/compiler/main.cc",
   ]
}
