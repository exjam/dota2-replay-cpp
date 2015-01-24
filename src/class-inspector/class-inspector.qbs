import qbs

CppApplication {
   name: "class-inspector"
   type: "application"
   consoleApplication: false

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
        "classtreeitem.h",
        "main.cpp",
        "mainwindow.cpp",
        "mainwindow.h",
        "mainwindow.ui",
        "propertytreeitem.h",
    ]
}
