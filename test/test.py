#
# test.py
#
# Copyright (c) 2020 F. Aragon. All rights reserved.
# Released under the BSD 3-Clause License (see the doc/LICENSE)
#

import sys
from ctypes import *

lib = cdll.LoadLibrary("../src/.libs/libexample.so")

def py_example_cb(b, bs, id):
	o = ""
	for i in range(bs): o += "%02x" % b[i]
	print("\tpy_example_cb> buffer: 0x" + o + " id: " + str(id))
	return bs

r = lib.example_void()
if r != 0: sys.exit(r)

r = lib.example_int(123)
if r != 123: sys.exit(r)

r = lib.example_str("hi, how are you?")
if r != 0: sys.exit(r)

b = create_string_buffer(b"abcdefghijklmnopqrstuvwxyz")
r = lib.example_buf(b, sizeof(b))
if r != 0: sys.exit(r)

T_example_cbf = CFUNCTYPE(c_int, POINTER(c_byte), c_uint, c_int)
r = lib.example_cb(b, sizeof(b), T_example_cbf(py_example_cb), 1234567890)
if r != 0: sys.exit(r)

sys.exit(0)
