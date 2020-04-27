# Overview

Demonstration of automatic build-and-test for Windows application using MSBuild and VSTest.Console.exe.

# Quick start

Fork this repository and setup a CircleCI project for your own copy.

## Notable deliverables from CircleCI jobs

* `HelloVCExe.exe` from `build` job: Consolidated executable - it will fill specified amount of RAM twice and then say `Hello world!`
* `wpr.etl` from `test` job: ETW log by WPR for tests
