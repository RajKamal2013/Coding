# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "greetings_main",
    srcs = ["main.cc"],
    deps = ["//src/lib:greetings_lib"],
)

cc_library(
    name = "unit_test_samples_lib",
    srcs = ["unit_test/sample1.cc"],
    hdrs = ["unit_test/sample1.h"],
    visibility = ["//visibility:public"],
)