# Double Storage Sorter – Classical and STL-based C++ Programs

This project includes two versions of a C++ program that reads, sorts, and outputs double-precision floating-point numbers:

1. **Classical Version** – Uses raw pointers (manual memory allocation)
2. **STL Version** – Uses `std::vector` and `std::sort`

---

## 🧱 Features

- Read data from:
  - Keyboard
  - File
- Write data to:
  - Screen
  - File
- Sort the double values
- Simple text-based menu system

---

## 📁 Files Included

| File Name             | Description                                 |
|----------------------|---------------------------------------------|
| `classical_combined.cpp` | Classical version with dynamic arrays       |
| `stl_combined.cpp`        | STL version using vector and algorithm     |
| `generate_data.py`    | Python script to generate test input data   |
| `Makefile`            | For easy compilation                        |
| `README.md`           | This documentation                         |
| `report.txt`          | Performance comparison and result analysis |

---

## 🛠️ Compilation

### With g++ (Linux/WSL)

```bash
make          # or manually: g++ classical_combined.cpp -o classical
make stl      # or manually: g++ stl_combined.cpp -o stl_combined -std=c++11
````

---

## 🚀 Usage

### Classical Version

```bash
./classical
```

### STL Version

```bash
./stl_combined
```

Each version provides a simple prompt:

1. Choose input source (keyboard or file)
2. Enter or load numbers
3. Sort them automatically
4. Choose output (screen or file)

---

## 🧪 Generating Test Data

Use the following script to create large input files:

```bash
python3 generate_data.py 10000
```

This generates a `data.txt` file with 10,000 random double values.

---

## 📄 Sample Input File (`data.txt`)

```
3.2
1.5
4.7
0.8
2.1
```

## 📑 **report.txt**

# Performance Comparison Report

## 📌 Objective

Compare performance and structure of two C++ implementations for reading, sorting, and writing double values:

1. Classical approach with raw pointers and bubble sort
2. STL-based approach with std::vector and std::sort

---

## 🧪 Test Setup

- **Platform:** WSL2 Ubuntu 22.04 on Windows 11
- **Compiler:** g++ (Ubuntu 11.4.0)
- **Input file:** 10,000 random double values
- **Generated using:** `generate_data.py`

---

## ⏱️ Timing Results (Manual Stopwatch)

| Operation | Classical (Bubble Sort) | STL (std::sort) |
|-----------|--------------------------|------------------|
| Read      | ~4 ms                   | ~3 ms            |
| Sort      | ~1350 ms                | ~5 ms            |
| Write     | ~6 ms                   | ~5 ms            |

*Note: Timings may vary depending on system load.*

---

## ✅ Observations

- **Reading and writing times** are nearly identical for both versions.
- **Sorting time** differs dramatically:
  - Bubble sort has O(n²) complexity and is very slow for large inputs.
  - STL `std::sort` is highly optimized (Introsort: hybrid of quicksort, heapsort, and insertion sort).
- **STL-based code** is shorter, safer (no manual memory), and easier to maintain.
- **Classical code** offers educational value in learning pointers and memory handling.

---

## 📌 Conclusion

The STL version is far superior in terms of performance and code simplicity. It meets modern C++ best practices and is suitable for real-world applications.

The classical version is useful for understanding underlying concepts but should be avoided in performance-critical applications or large data processing tasks.

---
