Overview
--------

This repo is an attempt to design and document requirements as described
[here](docs/Take-home_interview_embedded_engineer_interview_-_May_2024.pdf)

Buidling
--------

The cpp deliverables are built using bazel and its in-built rules. The repo
comes equipped with the build environment the cpp code was built and tested
with in form of a docker container. This is optional however. If a host
has required deps then the deliverables can be built with standard bazel
build commands outside the container as well.

Following is bazel target that should build and demonstrate basic function:
```
bazel test --cache_test_results=no //libs/ScoutVhal:scout_vhal_test
```

To use the supplied build environment, please use:
```
# build and start the container for the build environment
make env

# run bazel test
bazel test --cache_test_results=no //libs/ScoutVhal:scout_vhal_test
```
For additional bonus features, please run:
```
make help
```

Deliverables
------------
Of 3 requested deliverables, currently there are 2 implemented:
- Mock Vehicle Hardware is implemented as [library](libs/MockHw/)
- VHAL is defined as abstraction and "Scout VHAL" is implemented as [library](libs/ScoutVhal/)
- CLI requirment is not implemented. This is because its nature seems to require implementing
  a gRPC service and a client for it (which would be the requested utility). The author tried
  integrating gRPC in bazel without success and for that reason had to abandon the effort for
  sake of time restrictions. However, it should be noted that except for "subscribe speed"
  requirements, all other requirements are adequately demonstrated with a cc_test() (the
  aforementioned bazel target).

Also note that, the code is sufficiently documented in terms of assumptions made and to convey
the design intent.
