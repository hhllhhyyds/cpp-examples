cd build && cmake -GNinja -DCMAKE_CXX_STANDARD=11 .. && ninja && ctest --output-on-failure && cd ..