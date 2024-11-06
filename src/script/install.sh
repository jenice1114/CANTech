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

# Install GCC if not installed
if ! command -v gcc &> /dev/null; then
    echo "Installing GCC..."
    sudo apt-get install -y build-essential
else
    echo "GCC is already installed."
fi

# Install ncurses if not installed
if ! dpkg -s libncurses5-dev libncursesw5-dev &> /dev/null; then
    echo "Installing ncurses library..."
    sudo apt-get install -y libncurses5-dev libncursesw5-dev
else
    echo "ncurses library is already installed."
fi

echo "✅ Success: All required dependencies have been installed."