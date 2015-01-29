import qbs

CppApplication {
   name: "proxy"
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

   cpp.includePaths: [
      "D:\\Programming\\Libraries\\winpcap\\Include"
   ]

   cpp.libraryPaths: [
      "D:\\Programming\\Libraries\\winpcap\\Lib\\x64"
   ]

   cpp.dynamicLibraries: [
      "wpcap",
      "Packet",
      "ws2_32"
   ]
}
