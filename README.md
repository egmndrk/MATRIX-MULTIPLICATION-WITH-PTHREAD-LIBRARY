**Size of the Problem Table**

![image](https://github.com/egmndrk/MATRIX-MULTIPLICATION-WITH-PTHREAD-LIBRARY/assets/161582959/65356d2e-6104-4fef-90bf-02095c57e995)

The table shows the running time (in milliseconds) of parallel matrix multiplication code for different matrix sizes. Larger matrices take longer to multiply in parallel, but the speedup compared to a sequential implementation increases.

**Speed Up**

![image](https://github.com/egmndrk/MATRIX-MULTIPLICATION-WITH-PTHREAD-LIBRARY/assets/161582959/7bdde2de-b6b5-4319-8738-eae97fdbd0ef)
![image](https://github.com/egmndrk/MATRIX-MULTIPLICATION-WITH-PTHREAD-LIBRARY/assets/161582959/a4b3e715-1b44-4cac-8a78-dca692a7c269)

The table shows the speedup achieved by a parallel matrix multiplication algorithm compared to a sequential implementation, for various matrix sizes and numbers of threads. The speedup is calculated by dividing the execution time of the sequential implementation by the execution time of the parallel implementation. For instance, with a matrix size of 64x64 and 16 threads, the parallel implementation runs at 1.697 times the speed of the sequential implementation. Overall, the table indicates that speedup increases with more threads.

**Efficiency**

![image](https://github.com/egmndrk/MATRIX-MULTIPLICATION-WITH-PTHREAD-LIBRARY/assets/161582959/d63fc52a-b831-4573-a3a2-562d66da3915)
![image](https://github.com/egmndrk/MATRIX-MULTIPLICATION-WITH-PTHREAD-LIBRARY/assets/161582959/ed805738-a762-476b-8e36-2e5e0dc52622)

The table shows the efficiency of different parallel matrix multiplication algorithms for various matrix sizes. The efficiency is measured in terms of execution time in milliseconds, with a value of 1 representing the baseline sequential execution time.  Generally, the efficiency improves with more threads, but there are some variations.

**Scalability Analysis**

If we increase the number of processes/threads and keep the efficiency fixed without increasing the problem size, the problem is strongly scalable. As seen in the Efficiency Table graphic, lines tend to be straight line, which means the efficiency score of this project tends to be stable so that can be said that this project is strongly scalable.
