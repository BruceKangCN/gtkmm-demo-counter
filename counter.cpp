#include <format>

#include <counter.hpp>

namespace gtk_demo {

Counter::Counter()
    : m_box(Gtk::Orientation::VERTICAL, 10)
    , m_label("0")
    , m_minusButton("-")
    , m_plusButton("+")
{
    set_title("Counter");
    set_default_size(300, 200);

    m_minusButton.signal_clicked().connect([this] { setCount(m_count - 1); });
    m_plusButton.signal_clicked().connect([this] { setCount(m_count + 1); });
    m_signal_countUpdated.connect(sigc::mem_fun(*this, &Counter::updateLabel));

    set_child(m_box);

    m_box.set_margin(10);
    m_box.append(m_minusButton);
    m_box.append(m_label);
    m_box.append(m_plusButton);

    m_label.set_expand(true);
    m_label.set_halign(Gtk::Align::CENTER);
    m_label.set_valign(Gtk::Align::CENTER);
}

void Counter::setCount(int count) noexcept
{
    m_count = count;
    m_signal_countUpdated.emit(m_count);
}

void Counter::updateLabel(int count) noexcept
{
    // m_label.set_text(Glib::ustring::format(count));
    m_label.set_text(std::format("{}", count));
}

} // namespace gtk_demo
