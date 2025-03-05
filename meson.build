project(
    'gtkmm-demo',
    'cpp',
    version: '1.0.0',
    default_options: [
        'warning_level=3',
        'cpp_std=c++20',
    ],
)

gtkmm4_dep = dependency('gtkmm-4.0', include_type: 'system')

executable(
    'gtkmm-demo',
    'main.cpp', 'counter.cpp',
    dependencies: [gtkmm4_dep],
)
