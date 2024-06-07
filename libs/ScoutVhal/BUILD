
cc_library(
    name = "scout_vhal",
    srcs = [
        "src/ScoutVhal.cpp",
        "src/ScoutVhalImpl.cpp",
        "src/ScoutVhalImpl.hpp",
        "src/Vhal.hpp",
        "src/TimestampIndex.hpp",
    ],
    hdrs = [
        "public/ScoutVhal.hpp",
    ],
    deps = [
        "//libs/MockHw:mock_hw",
        "@json//:main",
    ],
    strip_include_prefix = "public",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "scout_vhal_test",
    srcs = [
        "test/ScoutVhal_Test.cpp",
    ],
    deps = [
        ":scout_vhal",
        "@googletest//:gtest_main",
    ],
)
