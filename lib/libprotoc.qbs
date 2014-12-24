import qbs

StaticLibrary {
   name: "libprotoc"

   Depends {
      name: "cpp"
   }

   Group {
      fileTagsFilter: product.type
      qbs.installDir: "lib"
      qbs.install: true
   }

   cpp.defines: [
      "LIBPROTOC_EXPORTS"
   ]

   cpp.includePaths: {
      var paths = [ "protobuf/src" ];

      if (qbs.targetOS.contains("windows")) {
         paths.push("protobuf/vsprojects");
      }

      return paths;
   }

   files: [
      "protobuf/src/google/protobuf/compiler/code_generator.cc",
      "protobuf/src/google/protobuf/compiler/command_line_interface.cc",
      "protobuf/src/google/protobuf/compiler/plugin.cc",
      "protobuf/src/google/protobuf/compiler/plugin.pb.cc",
      "protobuf/src/google/protobuf/compiler/subprocess.cc",
      "protobuf/src/google/protobuf/compiler/zip_writer.cc",

      // cpp
      "protobuf/src/google/protobuf/compiler/cpp/cpp_enum.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_enum_field.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_extension.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_field.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_file.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_generator.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_helpers.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_map_field.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_message.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_message_field.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_primitive_field.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_service.cc",
      "protobuf/src/google/protobuf/compiler/cpp/cpp_string_field.cc",

      // java
      "protobuf/src/google/protobuf/compiler/java/java_context.cc",
      "protobuf/src/google/protobuf/compiler/java/java_doc_comment.cc",
      "protobuf/src/google/protobuf/compiler/java/java_enum.cc",
      "protobuf/src/google/protobuf/compiler/java/java_enum_field.cc",
      "protobuf/src/google/protobuf/compiler/java/java_extension.cc",
      "protobuf/src/google/protobuf/compiler/java/java_field.cc",
      "protobuf/src/google/protobuf/compiler/java/java_file.cc",
      "protobuf/src/google/protobuf/compiler/java/java_generator.cc",
      "protobuf/src/google/protobuf/compiler/java/java_generator_factory.cc",
      "protobuf/src/google/protobuf/compiler/java/java_helpers.cc",
      "protobuf/src/google/protobuf/compiler/java/java_lazy_message_field.cc",
      "protobuf/src/google/protobuf/compiler/java/java_map_field.cc",
      "protobuf/src/google/protobuf/compiler/java/java_message.cc",
      "protobuf/src/google/protobuf/compiler/java/java_message_field.cc",
      "protobuf/src/google/protobuf/compiler/java/java_name_resolver.cc",
      "protobuf/src/google/protobuf/compiler/java/java_primitive_field.cc",
      "protobuf/src/google/protobuf/compiler/java/java_service.cc",
      "protobuf/src/google/protobuf/compiler/java/java_shared_code_generator.cc",
      "protobuf/src/google/protobuf/compiler/java/java_string_field.cc",

      // java nano
      "protobuf/src/google/protobuf/compiler/javanano/javanano_enum.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_enum_field.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_extension.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_field.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_file.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_generator.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_helpers.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_message.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_message_field.cc",
      "protobuf/src/google/protobuf/compiler/javanano/javanano_primitive_field.cc",

      // python
      "protobuf/src/google/protobuf/compiler/python/python_generator.cc",

      // ruby
      "protobuf/src/google/protobuf/compiler/ruby/ruby_generator.cc",
   ]
}
