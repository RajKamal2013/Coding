 Setting up 
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

    https://rustup.rs

    https://code.visualstudio.com/docs/languages/rust

    https://doc.rust-lang.org/book/ch01-03-hello-cargo.html

    https://rust-analyzer.github.io/manual.html#vs-code-2

Learning
    https://doc.rust-lang.org/book/title-page.html

    https://doc.rust-lang.org/book/title-page.html
    https://doc.rust-lang.org/book/ch03-05-control-flow.html
    Educative.io 

    Cargo 
        https://doc.rust-lang.org/cargo/


Group
    https://users.rust-lang.org
 

Cargo and bazel setup 
    https://www.tweag.io/blog/2023-07-27-building-rust-workspace-with-bazel/

    https://github.com/rwf2/Rocket/blob/master/Cargo.toml

    https://stackoverflow.com/questions/53133637/how-to-build-multi-workspace-cargo-project-in-rust

    https://earthly.dev/blog/bazel-with-rust/

    https://heeten.github.io/hello-monorepo-bazel/03b_rust_hello_world.html


Bazel Rust rules 

    Rust Workspace 
    https://github.com/bazelbuild/rules_rust/releases

    https://bazelbuild.github.io/rules_rust/

    https://bazelbuild.github.io/rules_rust/flatten.html#rust_register_toolchains

    rust_binary 
    http://bazelbuild.github.io/rules_rust/flatten.html

    https://bazelbuild.github.io/rules_rust/defs.html#rust_binary

    https://github.com/bazelbuild/rules_rust/issues/840

    https://bazelbuild.github.io/rules_rust/crate_universe.html

    Future 

        https://github.com/google/cargo-raze

    Sample 

        https://github.com/laramiel/bazel-example-rust/tree/master

        https://github.com/keith/bazel-rust-mobile-demo/blob/main/WORKSPACE

    Rust rules

        https://github.com/bazelbuild/rules_rust

Required 
    install cargo 
    install rustup 
    Set up Rust and Environment 
    1. brew install rust 
    2. curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
    3. source "$HOME/.cargo/env"
    
    Set up project 
    mkdir projects
    cargo new <project-name>
    cd <project-name>
    cargo build 
    cargo run 

    Setting up workspace 
    create Cargo.toml 
    ```
    [workspace]

    resolver = "2"

    members = [
        "projects/hello_world",
    ]
    ```
    Install rust-analyzer VSCODE extension 
    Set up vscode following : 
        https://code.visualstudio.com/docs/languages/rust
    
        https://doc.rust-lang.org/book/ch01-03-hello-cargo.html

        https://rust-analyzer.github.io/manual.html#vs-code-2

    Setting up bazel 
    1. Create WORKSPACE file 
    2. Create bazel file 