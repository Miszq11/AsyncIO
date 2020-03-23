#include <thread>
#include <memory>
#include <iostream>
#include "../include/async_input.h"
#include <chrono>
#include <iomanip>
int async_input = 1;
int main(int argc,char** argv){
    if(argc > 1)
        async_input = 0;
    std::shared_ptr<async_io> input = std::make_shared<async_io>();
    std::string opcje;
    std::thread io_thread(async_io::input_loop,input);
    auto now = std::chrono::system_clock::now();
    auto loop_time = now;
    auto print_time_now = std::chrono::system_clock::to_time_t(now);
    auto print_time_loop = print_time_now;
    while(opcje != std::string("exit")){
        opcje = std::string(input->get_input());
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        system("clear");
        loop_time = std::chrono::system_clock::now();
        print_time_loop = std::chrono::system_clock::to_time_t(loop_time);
        std::cout<<opcje <<" -wczytano"<<'\n'
                 <<"czas poczatku: "<<std::put_time(std::localtime(&print_time_now),"%F %T")<<'\n'
                 <<"czas petli: "<<std::put_time(std::localtime(&print_time_loop),"%F %T")<<'\n'
                 <<"dlugosc calkowita: "
                 <<std::chrono::duration_cast<std::chrono::milliseconds>(loop_time - now).count()<<" ms\n";
    }
    input->destruction_mode();
    if(io_thread.joinable()){
        io_thread.join();
    }
}