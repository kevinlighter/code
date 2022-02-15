package(default_visibility = ["//visibility:public"])
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "yaml-cpp_internal",
    visibility = ["//:__subpackages__"],
    strip_include_prefix = "src",
    hdrs = glob(["src/**/*.h"]),
)

cc_library(
    name = "yaml-cpp",
    visibility = ["//visibility:public"],
    includes = ["include"],
    hdrs = glob(["include/**/*.h"]),
    srcs = glob(["src/**/*.cpp", "src/**/*.h"]),
)