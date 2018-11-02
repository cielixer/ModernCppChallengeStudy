
mkdir -p build;
cd build
    cmake ../  -DBUILD_SHARED_LIBS=true -DCMAKE_BUILD_TYPE=Debug;
    make -j10;
    make install;
cd ..
