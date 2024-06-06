workspace(name = "scout")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# json
http_archive(
    name = "json",
    url = "https://github.com/nlohmann/json/commit/9cca280a4d0ccf0c08f47a99aa71d1b0e52f8d03",
    sha256 = "9bea4c8066ef4a1c206b2be5a36302f8926f7fdc6087af5d20b417d0cf103ea6",
    build_file = "@//third_party:json.BUILD",
)
