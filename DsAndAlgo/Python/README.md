Coding Guidelines 
https://www.techversantinfotech.com/python-naming-conventions-points-you-should-know/

Managing Python versions 
pyenv 


Compilation 
1. Bazel 
2. Python 

Bazel
https://github.com/bazelbuild/rules_python/releases

https://rules-python.readthedocs.io/en/stable/

https://android.googlesource.com/platform/external/bazelbuild-rules_python/


# Directory Structure 
project_name/
├── src/
│   ├── package_name/
│   │   ├── __init__.py
│   │   ├── module1.py
│   │   ├── module2.py
│   │   └── ...
│   └── ...
├── tests/
│   ├── __init__.py
│   ├── test_module1.py
│   ├── test_module2.py
│   └── ...
├── README.md
├── setup.py 
└── ...

```
src: This directory houses the actual source code of the project.
package_name: It represents the main package or library name.
__init__.py: An empty file that signifies the directory as a Python package.
module1.py, module2.py, etc.: Python modules containing the code.
tests: This directory contains all test-related files.
__init__.py: Enables running tests as a package.
test_module1.py, test_module2.py, etc.: Test files corresponding to the modules in the src directory.
README.md: Provides a description of the project, usage instructions, and other relevant information.
setup.py: Used for packaging and distributing the project.


```