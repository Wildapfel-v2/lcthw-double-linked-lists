*quicknotes*

# quicker wd change
```
cd Workbench/learn-c-the-hard-way-revisited/v2/exercises/part03-implementations/ex32-double-linked-lists/
clear
```

# found a bug in the book
- I didnt validate his test-code, but I found when breaking from his order, I got:
    - `free() invalid pointer`, in his test suite, because you cannot free varibles that are 
      not on the heap !!!
- Strincly speaking, he is freeing a string literal which lives on the ro-data of the program !!!

# I belive that i have in list_destroy a bug !!!
- I beleive I dont free last in list, i think I will check tomorrow with soem debugger or and 
  extensive memeory profiling if iam right

# Evaluation problem of NULL
- i cannot to this: `list->last == NULL` (or first), because the pointer is pointing somehwere 
  into the list struct, so its clearly not correct

# fsanitize
- `libubsan`, `libasan` missing in fedora silverblue base image (toolbox requried) 
- I received an error: 
  - `==318552==ERROR: AddressSanitizer: SEGV on unknown address (pc 0x00000040339b bp 0x7bea6d7e0040 sp 0x7fffd7b4ef20 T0)` (never have seens so low-level)
- I had to ask the chatbots here
- Solution:
  - use Calloc instead of cast+malloc, but i have no idea what this means (TODO!!!)
