#include "../include/async_input.h"
#include <thread>


async_io::async_io():
m_input("clear\n"),
input_val(m_input),
m_input_mutex()
{
    joined = 0;
    destruct = 0;
}
async_io::~async_io(){
    destruct = 1;
    while(!joined);
    std::cout<<"loop completed, exiting\n";
}

void async_io::input_loop(std::shared_ptr<async_io> obj_holder){
    while(obj_holder->destruct==0){
        std::getline(std::cin,obj_holder->m_input);
        bool selflock = 0;
        while(!selflock)
        {
            selflock = obj_holder->m_input_mutex.try_lock();
            if(selflock){
                obj_holder->input_val = obj_holder->m_input;
                obj_holder->m_input = "";
                obj_holder->m_input_mutex.unlock();
            }
        }
    }
    obj_holder->joined =1;
    return;
}

const char* async_io::get_input(){
    bool selflock = 0;
    while(!selflock){
        selflock = m_input_mutex.try_lock();
        if(selflock){
        const char* copy = input_val.c_str();
        m_input_mutex.unlock();
        return copy;
        }
    }
    return " ";
}

void async_io::destruction_mode(){
    destruct = 1;
}