workspace(name = "scout")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# json
http_archive(
    name = "json",
    url = "https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.tar.gz",
    build_file = "@//third_party:json.BUILD",
    strip_prefix = "json-3.11.3",
)

#
# https://stackoverflow.com/questions/73542982/bazel-protobuf-how-to-choose-a-specific-protoc-version
#
## protocolbuffers v26.1 (from gRPC v1.61.1) points to following version of rules_proto:
##  https://github.com/protocolbuffers/protobuf/blob/2434ef2adf0c74149b9d547ac5fb545a1ff8b6b5/protobuf_deps.bzl#L86
http_archive(
    name = "com_google_protobuf",
    # sha256 = "387478260190c540388839a3449c635a69708d92fc38ea6e2364b1196db90ea5",
    strip_prefix = "protobuf-2434ef2adf0c74149b9d547ac5fb545a1ff8b6b5",
    # strip_prefix = "protobuf-11bc195441adfbc87ff0349f1c4be7a239d1daad",
    urls = [
        # # https://github.com/protocolbuffers/protobuf/commits/v26.1
        "https://storage.googleapis.com/grpc-bazel-mirror/github.com/protocolbuffers/protobuf/archive/2434ef2adf0c74149b9d547ac5fb545a1ff8b6b5.tar.gz",
        "https://github.com/protocolbuffers/protobuf/archive/2434ef2adf0c74149b9d547ac5fb545a1ff8b6b5.tar.gz",

        # https://github.com/protocolbuffers/protobuf/commits/v21.10
        # "https://storage.googleapis.com/grpc-bazel-mirror/github.com/protocolbuffers/protobuf/archive/11bc195441adfbc87ff0349f1c4be7a239d1daad.tar.gz",
        # "https://github.com/protocolbuffers/protobuf/archive/11bc195441adfbc87ff0349f1c4be7a239d1daad.tar.gz",
    ],
    # patches = [
    #     "@com_github_grpc_grpc//third_party:protobuf.patch",
    # ],
    # patch_args = ["-p1"],
)
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()


http_archive(
    name = "rules_proto",
    sha256 = "dc3fb206a2cb3441b485eb1e423165b231235a1ea9b031b4433cf7bc1fa460dd",
    strip_prefix = "rules_proto-5.3.0-21.7",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/5.3.0-21.7.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()


##### gRPC Rules for Bazel
##### See https://github.com/grpc/grpc/blob/master/src/cpp/README.md#make
## gRPC v1.61.1 points to following version of protocolbuffers:
##  https://github.com/grpc/grpc/blob/d79949179d13140011ebc979b7ce5bfc79aaae8c/bazel/grpc_deps.bzl#L213
http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        # "https://github.com/grpc/grpc/archive/de893acb6aef88484a427e64b96727e4926fdcfd.tar.gz",
        "https://github.com/grpc/grpc/archive/refs/tags/v1.64.1.tar.gz",
    ],
    strip_prefix = "grpc-1.64.1",
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
# Not mentioned in official docs... mentioned here https://github.com/grpc/grpc/issues/20511
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()
