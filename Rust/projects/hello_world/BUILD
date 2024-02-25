load("@rules_rust//rust:defs.bzl", "rust_binary")

rust_binary(
    name = "hello_world",
    #The list of src files it needs (just main.rs)
    srcs = ["src/main.rs"],
    #Any libraries/crates it depends on, for now we'll leave this blank
    deps = [],
    #The crate_root file, this would default to main.rs but we put it in for clarity
    crate_root = "src/main.rs",
    # Specifies the Rust edition to use for this binary.
    edition = "2021"
)