import qbs

Project {
   references: [
      "dota/libdota.qbs",
      "util/libutil.qbs",
      "replay/replay.qbs",
      "class-inspector/class-inspector.qbs",
      "client-class-generator/client-class-generator.qbs",
   ]
}

