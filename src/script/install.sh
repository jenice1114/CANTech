#!/bin/bash

echo "Updating package lists..."
sudo apt-get update

# Install CMake if not installed
if ! command -v cmake &> /dev/null; then
    echo "Installing CMake..."
    sudo apt-get install -y cmake
else
    echo "CMake is already installed."
fi

# Install GCC and G++
if ! command -v gcc &> /dev/null || ! command -v g++ &> /dev/null; then
    echo "Installing GCC and G++..."
    sudo apt-get install -y gcc g++
else
    echo "GCC and G++ are already installed."
fi

# Install build-essential
if ! dpkg -s build-essential &> /dev/null; then
    echo "Installing build-essential..."
    sudo apt-get install -y build-essential
else
    echo "build-essential is already installed."
fi

# Install ncurses if not installed
if ! dpkg -s libncurses5-dev libncursesw5-dev &> /dev/null; then
    echo "Installing ncurses library..."
    sudo apt-get install -y libncurses5-dev libncursesw5-dev
else
    echo "ncurses library is already installed."
fi

# Clear CMake cache
if [ -f CMakeCache.txt ]; then
    echo "Clearing CMake cache..."
    rm -rf CMakeCache.txt CMakeFiles/
fi

echo "✅ Success: All required dependencies have been installed."
