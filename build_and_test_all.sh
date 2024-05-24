cd build && cmake -GNinja -DCMAKE_CXX_STANDARD=11 .. && ninja && ctest --output-on-failure && cd ..
cd build && cmake -GNinja -DCMAKE_CXX_STANDARD=14 .. && ninja && ctest --output-on-failure && cd ..
cd build && cmake -GNinja -DCMAKE_CXX_STANDARD=17 .. && ninja && ctest --output-on-failure && cd ..
cd build && cmake -GNinja -DCMAKE_CXX_STANDARD=20 .. && ninja && ctest --output-on-failure && cd ..
cd build && cmake -GNinja -DCMAKE_CXX_STANDARD=23 .. && ninja && ctest --output-on-failure && cd ..