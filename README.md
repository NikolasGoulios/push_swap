# **Push Swap Documentation**

## **1. Introduction**
Push Swap is a sorting algorithm project implemented in **C**, designed to efficiently sort a stack of integers with a limited set of stack operations. It follows the **Turk Algorithm** for optimal sorting efficiency. The purpose of the project is to print the exact sequence of steps the algorithm executes to sort the numbers successfully. 

The current algorithm has a time complexity of **O(N²)** in the worst case and a space complexity of **O(N)** due to stack storage. This implementation is optimized for small stacks of numbers, meeting and surpassing the benchmark criteria for the assignment.


## **2. Project Structure**
The repository consists of multiple source files, each responsible for a different aspect of the program:

📁 Push_swap/
│── 📁 lib/                
│   ├── 📁 libft/              # Custom libft library submodule
│
│── 📁 include/               
│   ├── 📜 push_swap.h        # Header file defining structures and function prototypes
│
│── 📁 src/                   
│   ├── 📁 algorithm/         # Sorting algorithm logic
│   │   ├── 📜 alg_sorting.c
│   │   ├── 📜 alg_targetA.c
│   │   ├── 📜 alg_targetB.c
│   │   ├── 📜 alg_tools.c
│   │   ├── 📜 alg_utils.c
│   │   ├── 📜 alg_rotations.c
│   │
│   ├── 📁 commands/          # Stack operations (push, swap, rotate, reverse rotate)
│   │   ├── 📜 cmd_push.c
│   │   ├── 📜 cmd_swap.c
│   │   ├── 📜 cmd_rotate.c
│   │   ├── 📜 cmd_revrotate.c
│   │
│   ├── 📁 parsing/              # Stack initialization and parsing
│   │   ├── 📜 parsing.c
│   │   ├── 📜 set_stack.c
│   │   ├── 📜 sort_init.c
│   │
│   ├── 📁 utils/             # Utility functions
│   │   ├── 📜 utils.c
│   │   ├── 📜 validity.c
│   │   ├── 📜 free.c
│   │
│   ├── 📜 main.c             # Main entry point
```

---

## **3. Installation**
To compile the program, ensure you have **Makefile**

``` make
```

---

## **4. Usage**
Run the program with a sequence of integers:

```sh
./push_swap 4 67 3 87 23
```

If the input is valid, the program prints a sequence of operations to sort the numbers using the fewest moves.

---

## **5. Code Breakdown**
### **5.1 Header File: `push_swap.h`**
Defines the core **`t_node`** structure for doubly linked lists and function prototypes.

```c
typedef struct s_node {
    int nbr;
    int index;
    int push_cost;
    bool above_median;
    bool cheapest;
    struct s_node *target_node;
    struct s_node *next;
    struct s_node *prev;
} t_node;
```

It also defines **FORWARD** and **REVERSE** macros for rotations.

---

### **5.2 Main Execution Flow**
1. **`main.c`**  
   - Calls `parsing_arguments()` to process user input.
   - Initializes stack A using `init_stack_a()`.
   - If already sorted, it exits.
   - Otherwise, sorting is initiated using `sort_fine_tuning()`.

2. **`parsing.c`**  
   - Handles single/multiple argument parsing.
   - Uses `ft_split()` for space-separated input.
   - Calls `is_valid_integer()` to validate input.

3. **`set_stack.c`**  
   - Converts string input into stack A.
   - Calls `append_node()` and checks for duplicates.

---

### **5.3 Sorting Algorithm**
Implemented in **`alg_sorting.c`**, which uses **Turk Algorithm**:

```c
void sort_turk(t_node **a, t_node **b, int size)
```

- Pushes elements from A to B until only three remain.
- Sorts the remaining three using `sort_three()`.
- Pushes elements back to A in sorted order.

---

### **5.4 Targeting System**
Each node is assigned a target position before being pushed.

- **`alg_targetA.c`**  
  - `init_nodes_a()` determines target nodes for stack A.

- **`alg_targetB.c`**  
  - `init_nodes_b()` determines target nodes for stack B.

These functions ensure the most efficient movements.

---

### **5.5 Stack Operations**
Push Swap operations follow a standard structure:

#### **Push Commands (`cmd_push.c`)**
- **`pa()`**: Push top element of B to A.
- **`pb()`**: Push top element of A to B.

```c
void pb(t_node **b, t_node **a) {
    push(a, b);
    ft_printf("pb\n");
}
```

#### **Swap Commands (`cmd_swap.c`)**
- **`sa()`**: Swap top two elements of A.

```c
void sa(t_node **a) {
    swap(a);
    ft_printf("sa\n");
}
```

#### **Rotate Commands (`cmd_rotate.c`)**
- **`ra()`**: Rotate A (move first element to the end).
- **`rb()`**: Rotate B.
- **`rr()`**: Rotate both.

#### **Reverse Rotate Commands (`cmd_revrotate.c`)**
- **`rra()`**: Reverse rotate A (move last element to the top).
- **`rrb()`**: Reverse rotate B.
- **`rrr()`**: Reverse rotate both.

---

### **5.6 Utilities**
**`utils.c`** provides helper functions:
- `find_max()`, `find_min()`
- `stack_size()`
- `find_last()`

**`alg_tools.c`** and **`alg_utils.c`** include:
- **`set_cheapest()`**: Marks the node with the lowest push cost.
- **`rotate_to_top()`**: Moves the best node to the top.

---

### **5.7 Memory Management**
To prevent **memory leaks**, `free.c` deallocates all used memory:
- `free_stack()`
- `free_args()`
- `free_av_arr()`

---

## **6. Error Handling**
If an error is detected (e.g., invalid input, duplicates), the program:
1. Prints `"Error"` to **STDERR**.
2. Frees allocated memory.
3. Exits gracefully.

Example (from `free.c`):

```c
void error_indicator(t_node **a) {
    write(STDERR_FILENO, "Error\n", 6);
    free_stack(a);
}
```

---

## **7. Conclusion**
This project efficiently sorts integers with minimal operations, following the **Turk Algorithm**. The modular design ensures clarity, while the **memory-safe implementation** prevents leaks.

Additionally, this project passed with **100%**, successfully meeting performance benchmarks:
- Sorting **100 numbers** in **less than 700 steps** (average: **550 steps**).
- Sorting **500 numbers** in **less than 5500 operations** (achieved: **~5000 steps**).

This ensures an optimized implementation with efficient sorting operations.

## **8. Known Issues & Ongoing Improvements**
This section tracks active bugs and areas of improvement if any.

### **Active Bugs**
- **[Segmentation Fault]**  
  _Description:_ There is an issue with the free logic even though always I follow a cetralized architecture for memory managment, in case of inputing a single space in quotes the program seems to crash and not properly handle this empty case.  
  _Status:_ In progress / Under investigation.  
  _Potential Fixes:_ The parsing part seems causing this issue.

### **Planned Improvements**
- Improve error handling and input validation.
---
