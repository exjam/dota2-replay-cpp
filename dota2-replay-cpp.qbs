import qbs

Project {
   references: [
      "lib/protobuf.qbs",
      "lib/snappy.qbs",
      "src/replay-analyser.qbs"
   ]
}
