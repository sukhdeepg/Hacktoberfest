# Python Quine Program.
# For those that don't know Quine is a snazzy computer program which takes no input and outputs only a copy of its own source code.

Q='Q=%r;print(Q%%Q)';print(Q%Q)
