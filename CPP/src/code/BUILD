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

cc_library(
    name = "unit_test_string_lib",
    srcs = ["unit_test/sample2.cc"],
    hdrs = ["unit_test/sample2.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "queue_lib",
    hdrs = ["queue/queue.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "counter_lib",
    hdrs = ["misc/counter.h"],
    srcs = ["misc/counter.cc"],
    visibility = ["//visibility:public"],
)
