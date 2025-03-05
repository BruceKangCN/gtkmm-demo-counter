#include <counter.hpp>

int main(int argc, char** argv)
{
    auto app = Gtk::Application::create("org.bkcloud.demo.counter");
    return app->make_window_and_run<gtk_demo::Counter>(argc, argv);
}
