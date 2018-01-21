# Contributing guidelines

## How to become a contributor and submit your own code

### Contributing

If you have improvements to AdvPL Language Server, send us your pull requests! For those
just getting started, Github has a [howto](https://help.github.com/articles/using-pull-requests/).

AdvPL Language Server team members will be assigned to review your pull requests. Once the pull requests are approved and pass continuous integration checks, we will merge the pull requests.
For some pull requests, we will apply the patch for each pull request to our internal version control system first, and export the change out as a new commit later, at which point the original pull request will be closed. The commits in the pull request will be squashed into a single commit with the pull request creator as the author. These pull requests will be labeled as pending merge internally.

This is a list of things you can do to help us out (in no particular order). Each item will be expanded upon later in the document.

- [Report bugs](https://github.com/advpl/advpl-language-server-cxx/issues) at the issue tracker.
- Add feature requests to the [issue tracker](https://github.com/advpl/advpl-language-server-cxx/issues).
- Help us improve the [documentation](https://github.com/advpl/advpl-language-server-cxx/wiki).

### Contribution guidelines and standards

Before sending your pull request for
[review](https://github.com/advpl/advpl-language-server-cxx/pulls),
make sure your changes are consistent with the guidelines and follow the
AdvPL Language Server coding style.

#### General guidelines and philosophy for contribution

* Include unit tests when you contribute new features, as they help to
  a) prove that your code works correctly, b) guard against future breaking
  changes to lower the maintenance cost.
* Bug fixes also generally require unit tests, because the presence of bugs
  usually indicates insufficient test coverage.
* When you contribute a new feature to AdvPL Language Server, the maintenance burden is (by
  default) transferred to the AdvPL Language Server team. This means that benefit of
  contribution must be compared against the cost of maintaining the feature.
* Full new features (e.g., a new op implementing a cutting-edge algorithm)
  typically will live in
  [advpl-language-server-cxx
/dev](https://github.com/advpl/advpl-language-server-cxx/tree/dev)
  to get some airtime before decision is made regarding whether they are to be
  migrated to the core.

#### C++ coding style

Changes to AdvPL Language Server C++ code should conform to
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

Use `clang-tidy` to check your C/C++ changes. To install clang-tidy on ubuntu:16.04, do:

```bash
apt-get install -y clang-tidy
```

You can check a C/C++ file by doing:

```bash
clang-format <my_cc_file> --style=google > /tmp/my_cc_file.cc
diff <my_cc_file> /tmp/my_cc_file.cc
```

#### Coding style for other languages

* [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
* [Google JavaScript Style Guide](https://google.github.io/styleguide/jsguide.html)

#### Running unit tests

There are two ways to run TensorFlow unit tests.

1. Use Boost test framework before submitting.

   ```bash
   make test
   ```
