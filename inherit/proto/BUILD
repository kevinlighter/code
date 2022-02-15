load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

cc_library(
    name = "all_protos",
    deps = [
        ":common_cc_proto",
        ":type_one_config_cc_proto",
        ":type_two_config_cc_proto",
    ],
    visibility = ["//src:__pkg__"],
)

# Convention:
# A cc_proto_library that wraps a proto_library named foo_proto
# should be called foo_cc_proto.
cc_proto_library(
    name = "common_cc_proto",
    deps = [
        ":common_proto",],
    visibility = ["//src:__pkg__"],
)

cc_proto_library(
    name = "type_one_config_cc_proto",
    deps = [
        ":type_one_config_proto",],
    visibility = ["//src:__pkg__"],
)

cc_proto_library(
    name = "type_two_config_cc_proto",
    deps = [
        ":type_two_config_proto",],
    visibility = ["//src:__pkg__"],
)

# Conventions:
# 1. One proto_library rule per .proto file.
# 2. A file named foo.proto will be in a rule named foo_proto.
proto_library(
    name = "common_proto",
    srcs = ["common.proto"],
    deps = [
        # Well known protos should be included as deps in the
        # proto_library rules of the source files importing them.
        # A list of all @com_google_protobuf well known protos can
        # seen with:
        # `bazel query 'kind(proto_library, @com_google_protobuf//:all)'`
        "@com_google_protobuf//:any_proto",
    ],
)

proto_library(
    name = "type_one_config_proto",
    srcs = ["type_one_config.proto"],
    deps = [
        # Well known protos should be included as deps in the
        # proto_library rules of the source files importing them.
        # A list of all @com_google_protobuf well known protos can
        # seen with:
        # `bazel query 'kind(proto_library, @com_google_protobuf//:all)'`
        "@com_google_protobuf//:any_proto",
    ],
)

proto_library(
    name = "type_two_config_proto",
    srcs = ["type_two_config.proto"],
    deps = [
        # Well known protos should be included as deps in the
        # proto_library rules of the source files importing them.
        # A list of all @com_google_protobuf well known protos can
        # seen with:
        # `bazel query 'kind(proto_library, @com_google_protobuf//:all)'`
        "@com_google_protobuf//:any_proto",
    ],
)