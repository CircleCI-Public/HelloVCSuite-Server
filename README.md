# HelloVCSuite-Server

Demonstration of automatic build-and-test for Windows applications using MSBuild and VSTest.Console.exe.

**Note**: This is for CircleCI Server (the "on-premises" version of CircleCI). For use in our cloud service https://circleci.com/, please refer to [`HelloVCSuite-Cloud`](https://github.com/CircleCI-Public/HelloVCSuite-Cloud).

# Quick start

Fork this repository and setup a CircleCI project for your own copy.

## Artifacts

The CircleCI workflow defined in `.circleci/config.yml` yields two artifacts:

* `HelloVCExe.exe` from `build` job: Consolidated executable - it will fill specified amount of RAM twice and then say `Hello world!`
* `wpr.etl` from `test` job: ETW log by WPR for tests

# Deep dive

## Codebase architecture

This "suite" consists of three parts.

* `HelloVC`: Core logic. Compiled into a static libary.
* `HelloVCExe`: A wrapper to create an executable `.exe` file.
* `HelloVCTest`: Unit tests for `HelloVC`.

The core logic and a wrapper executable are separated because unit tests cannot be applied on an executable file. Keeping the wrapper (`HelloVCExe` for this example) as simple as possible will enhance trustworthiness of test results. Additional E2E tests agains a generated `.exe` file is also a good idea.

## Have your own code on it!

Open `HelloVCSuite.sln` with your Visual Studio (the full-featured ones, not VSCode), and the rest will be taken care by VS. At the time of this writing the solution is tested with VS2019.
