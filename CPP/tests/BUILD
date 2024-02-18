cc_test(
    name = "greetings_tests",
    srcs = ["greetings_test.cc", "hello_test.cc"],
    deps = [
        "//src/lib:greetings_lib",
        "@com_google_googletest//:gtest_main"
    ],
)
cc_test(
    name = "unit_test_samples_tests",
    srcs = ["unit_test/sample_test.cc"],
    deps = [
        "//src/main:unit_test_samples_lib",
        "@com_google_googletest//:gtest_main"
    ],
)

cc_test(
    name = "unit_test_string_tests",
    srcs = ["unit_test/sample2_test.cc"],
    deps = [
        "//src/main:unit_test_string_lib",
        "@com_google_googletest//:gtest_main"
    ],
)

cc_test(
    name = "queue_tests",
    srcs = ["queue_test.cc"],
    deps = [
        "//src/main:queue_lib",
        "@com_google_googletest//:gtest_main"
    ],
)

cc_test(
    name = "counter_tests",
    srcs = ["counter_test.cc"],
    deps = [
        "//src/main:counter_lib",
        "@com_google_googletest//:gtest_main"
    ],
)