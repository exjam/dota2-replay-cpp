import qbs

CppApplication {
   name: "inspector"
   type: "application"
   consoleApplication: true

   Depends {
      name: "libdota"
   }

   Depends {
      name: "libutil"
   }

   Depends {
      name: "Qt";
      submodules: ["widgets"]
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "bin"
      qbs.install: true
   }

   files: [
        "abstracttreemodel.cpp",
        "abstracttreemodel.h",
        "main.cpp",
        "mainwindow.cpp",
        "mainwindow.h",
        "mainwindow.ui",
    ]
}
