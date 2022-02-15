load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "type_one_derived",
    srcs = ["type_one_derived.cc"],
    hdrs = ["type_one_derived.h"],
    deps = ["//src:type_one_base"],
    visibility = ["//src:__pkg__"],
)