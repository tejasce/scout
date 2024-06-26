# Copyright 2020 the gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

licenses(["notice"])
package(default_visibility = ["//visibility:public"])


cc_library(
    name = "route_guide_helper",
    srcs = [
        "helper.cc",
        "helper.h",
    ],
    defines = ["BAZEL_BUILD"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "//utils/route_guide/proto:route_guide_cc_grpc",
    ],
)

cc_binary(
    name = "route_guide_client",
    srcs = [
        "route_guide_client.cc",
    ],
    data = ["route_guide_db.json"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":route_guide_helper",
        "@com_github_grpc_grpc//:grpc++",
        "//utils/route_guide/proto:route_guide_cc_grpc",
    ],
)

cc_binary(
    name = "route_guide_server",
    srcs = [
        "route_guide_server.cc",
    ],
    data = ["route_guide_db.json"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":route_guide_helper",
        "@com_github_grpc_grpc//:grpc++",
        "//utils/route_guide/proto:route_guide_cc_grpc",
    ],
)

cc_binary(
    name = "route_guide_callback_client",
    srcs = [
        "route_guide_callback_client.cc",
    ],
    data = ["route_guide_db.json"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":route_guide_helper",
        "@com_github_grpc_grpc//:grpc++",
        "//utils/route_guide/proto:route_guide_cc_grpc",
    ],
)

cc_binary(
    name = "route_guide_callback_server",
    srcs = [
        "route_guide_callback_server.cc",
    ],
    data = ["route_guide_db.json"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":route_guide_helper",
        "@com_github_grpc_grpc//:grpc++",
        "//utils/route_guide/proto:route_guide_cc_grpc",
    ],
)
