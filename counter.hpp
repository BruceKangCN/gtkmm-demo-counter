#pragma once

#include <gtkmm-4.0/gtkmm/applicationwindow.h>
#include <gtkmm-4.0/gtkmm/box.h>
#include <gtkmm-4.0/gtkmm/label.h>
#include <gtkmm-4.0/gtkmm/button.h>

namespace gtk_demo {

class Counter : public Gtk::ApplicationWindow {
public:
    Counter();
    Counter(Counter&&) noexcept = default;
    Counter& operator=(Counter&&) noexcept = default;
    ~Counter() = default;

protected:
    void updateLabel(int count) noexcept;

    void setCount(int count) noexcept;

private:
    Gtk::Box m_box;
    Gtk::Label m_label;
    Gtk::Button m_minusButton;
    Gtk::Button m_plusButton;

    sigc::signal<void(int)> m_signal_countUpdated;

    int m_count = 0;
};

} // namespace gtk_demo
