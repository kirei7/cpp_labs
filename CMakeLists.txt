cmake_minimum_required(VERSION 3.7)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lab7/main.cpp lab7/shops/Shop.cpp lab7/shops/EquipmentShop.cpp lab7/data/Product.h lab7/actors/Wife.cpp lab7/actors/Husband.cpp lab7/shops/ProductsShop.cpp lab7/data/OrderResult.h)
add_executable(untitled ${SOURCE_FILES})