PDC Lab – Experiment 8: CUDA Execution Steps (Windows)

1. Open Windows PowerShell.
2. Initialize the Visual Studio C++ compiler environment by running:

```
cmd.exe /k '"C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars64.bat"'
```

3\. A new Command Prompt window will open. Verify the compiler:

```
where cl
nvcc --version
```

4\. Navigate to the exam folder:

```
cd /d F:\BTech\PDC\Exam\8
```

5\. Check the files in the folder:

```
dir
```

6\. Compile the CUDA program. For example, to compile Hello CUDA:

```
nvcc hello.cu -o hello.exe
```

7\. Execute the program:

```
hello.exe
```

8\. Repeat the compilation and execution steps for the other CUDA programs.

Commands for each experiment:

Vector Addition

```
nvcc vector_add.cu -o vector_add.exe
vector_add.exe
```

Vector Subtraction

```
nvcc vector_subtract.cu -o vector_subtract.exe
vector_subtract.exe
```

Vector Multiplication

```
nvcc vector_multiply.cu -o vector_multiply.exe
vector_multiply.exe
```

Maximum Element in an Array

```
nvcc array_max.cu -o array_max.exe
array_max.exe
```

Matrix Addition

```
nvcc matrix_add.cu -o matrix_add.exe
matrix_add.exe
```

Matrix Multiplication

```
nvcc matrix_multiply.cu -o matrix_multiply.exe
matrix_multiply.exe
```

Important: Always open the compiler-enabled Command Prompt before compiling. Make sure the required `.cu` file is present in `F:\BTech\PDC\Exam\8`.