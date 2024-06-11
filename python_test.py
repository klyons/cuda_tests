import ctypes
import numpy as np

# Load the DLL
dll = ctypes.CDLL(r"C:\ws\C_homework\x64\Debug\C_homework.dll")

# Define the return types and argument types of the function
dll.process_arrays.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.POINTER(ctypes.c_ushort)), ctypes.POINTER(ctypes.POINTER(ctypes.c_double))]

# Create the arrays
nLen = 10
result_array = (ctypes.c_double * nLen)()
ushort_array = ctypes.POINTER(ctypes.c_ushort)()
double_array = ctypes.POINTER(ctypes.c_double)()

# Call the function
dll.process_arrays(nLen, result_array, ctypes.byref(ushort_array), ctypes.byref(double_array))

# Convert the returned arrays to numpy arrays for easier manipulation in Python
ushort_array_np = np.ctypeslib.as_array(ushort_array, (nLen,))
double_array_np = np.ctypeslib.as_array(double_array, (nLen,))
print(ushort_array_np)
print(double_array_np)
# Don't forget to free the memory when you're done with the arrays
#dll.free_memory(ushort_array)
#dll.free_memory(double_array)
