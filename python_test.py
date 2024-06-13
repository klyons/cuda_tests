import ctypes
import numpy as np

# Load the DLL
dll = ctypes.CDLL(r"x64\Debug\C_homework.dll")


nLen = 10
# Define a custom type for a pointer to a pointer
PP_c_ushort = ctypes.POINTER(ctypes.POINTER(ctypes.c_ushort))
PP_c_double = ctypes.POINTER(ctypes.POINTER(ctypes.c_double))

# Define the return types and argument types of the function
dll.process_arrays.argtypes = [ctypes.c_int, PP_c_ushort, PP_c_double]

# Create null pointers
ushort_array = ctypes.POINTER(ctypes.c_ushort)()
double_array = ctypes.POINTER(ctypes.c_double)()

# Call the function
dll.process_arrays(nLen, ctypes.byref(ushort_array), ctypes.byref(double_array))

# Now ushort_array and double_array should point to the arrays created in C++
# Convert the returned arrays to numpy arrays for easier manipulation in Python
ushort_array_np = np.ctypeslib.as_array(ushort_array, shape=(nLen,))
double_array_np = np.ctypeslib.as_array(double_array, shape=(nLen,))
print(ushort_array_np)
print(double_array_np)

######
#problem 2
# Define a custom type for a pointer to a pointer
PP_c_double2 = ctypes.POINTER(ctypes.POINTER(ctypes.c_double))

# Define the return types and argument types of the function
dll.add_to_arrays.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_double), PP_c_double2]

# Create null pointers
pArray = ctypes.pointer(ctypes.c_double())
pRefResult = ctypes.pointer(ctypes.c_double())

# Call the function
dll.add_to_arrays(nLen, pArray, ctypes.byref(pRefResult))

# Now pRefResult should point to the array created in C++
# Convert the returned array to a numpy array for easier manipulation in Python
pRefResult_np = np.ctypeslib.as_array(pRefResult, shape=(nLen,))
print(pRefResult_np)