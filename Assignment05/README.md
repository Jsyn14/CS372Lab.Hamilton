# Assignment05 — O(n^2) vs O(n log n) Sorting Timings

## Build (Windows, CMake)
```powershell
# From this folder
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

The executable is placed in `build\app\sort_bench.exe` (or `build\Release\sort_bench.exe` depending on generator).

## Run
```powershell
# From repo root
./build/app/sort_bench.exe > timings.csv
```

Outputs CSV columns: `size,algorithm,milliseconds`.

## Excel chart
Use the provided `docs/SortTimings.xlsx` and paste the CSV (incl. header) into the **Timings** sheet A1.
The **Chart** sheet updates automatically.
```

## Repo layout
```
Assignment05/
  app/                 # main program (sort runner)
    main.cpp
  include/             # public headers
    sort_algorithms.hpp
  src/                 # implementations
    sort_algorithms.cpp
  docs/                # report assets
    SortTimings.xlsx
  CMakeLists.txt
  README.md
  .gitignore
```

## Notes
- Three O(n^2): Bubble, Selection, Insertion. One O(n log n): Quicksort (iterative).
- For very large n, n^2 sorts are skipped by default (>100k). Adjust in `main.cpp` if required by rubric.
