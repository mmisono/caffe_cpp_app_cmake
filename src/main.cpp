#include "config.hpp"

#include <iostream>
#include <caffe/caffe.hpp>

int main(int argc, char* argv[]){
    auto mode = caffe::Caffe::CPU;
#ifndef CPU_ONLY
    if(argc >= 2){
        mode = caffe::Caffe::GPU;
    }
#endif
    caffe::Caffe::set_mode(mode);

    if (mode == caffe::Caffe::CPU){
        std::cout << "cpu mode" << std::endl;
    }else{
        std::cout << "gpu mode" << std::endl;
    }
    return 0;
}

