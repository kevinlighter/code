load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "base",
    srcs = ["base.cc"],
    hdrs = ["base.h"],
    deps = ["//proto:all_protos"],
    visibility = ["//src:__pkg__"],
)

cc_library(
    name = "type_one_base",
    srcs = ["type_one_base.cc"],
    hdrs = ["type_one_base.h"],
    deps = [":base"],
    visibility = [
        "//src:__pkg__",
        "//src/type_one:__pkg__"
    ],
)

cc_library(
    name = "type_two_base",
    srcs = ["type_two_base.cc"],
    hdrs = ["type_two_base.h"],
    deps = [":base"],
    visibility = [
        "//src:__pkg__",
        "//src/type_two:__pkg__"
    ],
)

