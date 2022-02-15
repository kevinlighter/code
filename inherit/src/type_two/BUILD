load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "type_two_derived",
    srcs = ["type_two_derived.cc"],
    hdrs = ["type_two_derived.h"],
    deps = ["//src:type_two_base"],
    visibility = ["//src:__pkg__"],
)