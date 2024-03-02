Setting UP BUILD
1. Gradle using IntelliJi 
2. Bazel 
   1. Create WORKSPACE File
   2. Create BUILD File 

Running
Using Bazel
```
    bazelisk build //...
    bazelisk build //:Main 
```

Using Gradle
```
    gradle clean build
    ./gradlew run 
    ./gradlew clean test

```
    


# Links
```
Gradle
https://docs.gradle.org/current/userguide/partr1_gradle_init.html
```

```
# Bazel : https://github.com/bazelbuild
# Bazel Working: https://bazel.build/external/overview
# Bazel learning: https://bazel.build/run/build
# Using Bazel: https://docs.bazel.build/versions/0.19.1/build-ref.html
# Bazel Overview:
# Workspace: https://bazel.build/concepts/build-ref
# Workspace Rules: https://docs.bazel.build/versions/0.19.1/be/workspace.html
# Workspace Rules (HTTP): https://bazel.build/rules/lib/repo/http
# Workspace Rules (GIT): https://bazel.build/rules/lib/repo/git
# Workspace Rules (Utils): https://bazel.build/rules/lib/repo/utils
# Rules JVM external: https://github.com/bazelbuild/rules_jvm_external/releases/tag/6.0
# Rules Java:https://github.com/bazelbuild/rules_java/releases/tag/7.4.0
# Contrib Rules Jvm : https://github.com/bazel-contrib/rules_jvm/releases
# Maven install -> https://github.com/bazelbuild/rules_jvm_external
# BUILD File rules -> https://bazel.build/reference/be/overview
# BUILD File Java -> https://bazel.build/reference/be/java
# Sample Java Setup using Bazel -> https://bazel.build/start/java
# Migrating from Maven to Bazel -> https://bazel.build/migrate/maven
# Bazel Skylib -> https://github.com/bazelbuild/bazel-skylib/releases
# Java test sample: https://github.com/bazelbuild/bazel/blob/master/src/test/java/com/google/devtools/common/options/BUILD
# Java test : https://github.com/junit-team/junit5-samples/blob/main/junit5-jupiter-starter-bazel/BUILD
# use module instead of workspace
# JUnit : https://github.com/junit-team

```