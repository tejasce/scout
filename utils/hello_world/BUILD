# This tells bazel to load the rust_binary rule from the rules_rust package
load("@rules_rust//rust:defs.bzl", "rust_binary")

rust_binary(
    #We are going to call the target/binary summation
    name = "rust_hello_world",
    #The list of src files it needs (just main.rs)
    srcs = ["main.rs"],
    #Any libraries/crates it depends on, for now we'll leave this blank
    deps = [],
    #The crate_root file, this would default to main.rs but we put it in for clarity
    crate_root = "main.rs",
)
