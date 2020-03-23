#include <iostream>
#include <mutex>
#include <chrono>
#include <memory>

class async_io{
private:   
    std::string m_input;
    std::mutex m_input_mutex;
    int destruct;
    int joined;
public:
    async_io();
    virtual ~async_io();
    std::string input_val;
    static void input_loop(std::shared_ptr<async_io> obj_holder);
    void draw(std::string& buff) const;
    std::mutex& get_input_mutex();
    const char* get_input();
    void destruction_mode();
};