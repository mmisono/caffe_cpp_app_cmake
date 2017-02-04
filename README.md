# What's this
CMake templates for creating app using caffe with C++

## How to build
1. clone this repository
```
$ git clone --recursive https://github.com/mmisono/caffe_cpp_app_cmake.git
$ cd caffe_cpp_app_cmake
```

2. build caffe
```
$ cd caffe
$ cp Makefile.config.template Makefile.config
$ vim Makefile.config # edit
$ make
```

3. build application
```
$ mkdir build
$ cd buld
$ cmake -DCPU_ONLY=ON -DCMAKE_BUILD_TYPE=Release ..
$ make
```

