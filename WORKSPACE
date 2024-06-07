workspace(name = "scout")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# json
http_archive(
    name = "json",
    url = "https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.tar.gz",
    build_file = "@//third_party:json.BUILD",
    strip_prefix = "json-3.11.3",
)
