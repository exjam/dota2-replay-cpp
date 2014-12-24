import qbs

StaticLibrary {
   name: "libprotobuf"

   Depends {
      name: "cpp"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "lib"
      qbs.install: true
   }

   cpp.defines: [
      "LIBPROTOBUF_EXPORTS"
   ]

   cpp.includePaths: {
      var paths = [ "protobuf/src" ];

      if (qbs.targetOS.contains("windows")) {
         paths.push("protobuf/vsprojects");
      }

      return paths;
   }

   files: [
      "protobuf/src/google/protobuf/arena.cc",
      "protobuf/src/google/protobuf/arenastring.cc",
      "protobuf/src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc",
      "protobuf/src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc",
      "protobuf/src/google/protobuf/io/coded_stream.cc",
      "protobuf/src/google/protobuf/stubs/common.cc",
      "protobuf/src/google/protobuf/descriptor.cc",
      "protobuf/src/google/protobuf/descriptor.pb.cc",
      "protobuf/src/google/protobuf/descriptor_database.cc",
      "protobuf/src/google/protobuf/dynamic_message.cc",
      "protobuf/src/google/protobuf/extension_set.cc",
      "protobuf/src/google/protobuf/extension_set_heavy.cc",
      "protobuf/src/google/protobuf/generated_message_reflection.cc",
      "protobuf/src/google/protobuf/generated_message_util.cc",
      "protobuf/src/google/protobuf/io/gzip_stream.cc",
      "protobuf/src/google/protobuf/compiler/importer.cc",
      "protobuf/src/google/protobuf/map_field.cc",
      "protobuf/src/google/protobuf/message.cc",
      "protobuf/src/google/protobuf/message_lite.cc",
      "protobuf/src/google/protobuf/stubs/once.cc",
      "protobuf/src/google/protobuf/compiler/parser.cc",
      "protobuf/src/google/protobuf/io/printer.cc",
      "protobuf/src/google/protobuf/reflection_ops.cc",
      "protobuf/src/google/protobuf/repeated_field.cc",
      "protobuf/src/google/protobuf/service.cc",
      "protobuf/src/google/protobuf/stubs/stringprintf.cc",
      "protobuf/src/google/protobuf/io/strtod.cc",
      "protobuf/src/google/protobuf/stubs/structurally_valid.cc",
      "protobuf/src/google/protobuf/stubs/strutil.cc",
      "protobuf/src/google/protobuf/stubs/substitute.cc",
      "protobuf/src/google/protobuf/text_format.cc",
      "protobuf/src/google/protobuf/io/tokenizer.cc",
      "protobuf/src/google/protobuf/unknown_field_set.cc",
      "protobuf/src/google/protobuf/wire_format.cc",
      "protobuf/src/google/protobuf/wire_format_lite.cc",
      "protobuf/src/google/protobuf/io/zero_copy_stream.cc",
      "protobuf/src/google/protobuf/io/zero_copy_stream_impl.cc",
      "protobuf/src/google/protobuf/io/zero_copy_stream_impl_lite.cc"
   ]
}
