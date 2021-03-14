#!/usr/bin/env python3

import numpy

MR = 16
NR = 16
K = 16
ALPHA = 0.5

randf = lambda n: numpy.random.randint(0, 1000, size=n)

A = randf((MR, K)).astype(numpy.float32)
B = randf((K, NR)).astype(numpy.float32)
result = numpy.matmul(A, B*ALPHA)

def print_array(name, data, data_size, data_type='float', data_fmt='{}f', fold=8):
    print('{} {}[{}] = {{'.format(data_type, name, data_size))
    for i in range(0, len(data), fold):
        print('  ', ', '.join(data_fmt.format(x) for x in data[i:i+fold]), ',', sep='')
    print('};')

print('#define DIM_K ({})'.format(K))
print('#define ALPHA ({}f)'.format(ALPHA))
print_array('input_data_A', numpy.transpose(A).flatten(), MR * K)
print_array('input_data_B', B.flatten(), K * NR)
print_array('verify_data', result.flatten(), MR * NR)
