load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "create_proto",
    srcs = [
        "create_proto.cc",
        "create_proto.h",
    ],
    deps = [
        "//messages:simple_example_cc_proto",
    ],
)

cc_binary(
    name = "json_proto_converter",
    srcs = [
        "json_proto_converter.cc",
    ],
    deps = [
        "create_proto",
    ],
)

cc_library(
    name = "yaml_reader",
    srcs = [
        "yaml_reader.h",
    ],
    deps = [
        "//yaml-cpp-yaml-cpp-0.7.0:yaml-cpp"
    ],
)

cc_binary(
    name = "yaml_reader_main",
    srcs = [
        "yaml_reader_main.cc",
    ],
    deps = [
        "yaml_reader",
    ],
)
