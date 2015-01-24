import qbs

CppApplication {
   name: "client-class-generator"
   type: "application"
   consoleApplication: true

   Depends {
      name: "cpp"
   }

   Depends {
      name: "libdota"
   }

   Depends {
      name: "libutil"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "bin"
      qbs.install: true
   }

   files: [
      "main.cpp",
   ]
}